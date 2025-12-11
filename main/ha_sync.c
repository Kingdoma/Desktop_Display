/*
 * Home Assistant synchronizer:
 * - WebSocket subscribe to state_changed events to receive updates in real time.
 * - Optional REST poll remains for initial/fallback refresh (poll_interval_ms).
 * - Local changes are pushed via REST PUT /api/states/<entity_id>.
 */

#include "ha_sync.h"

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "esp_http_client.h"
#include "esp_websocket_client.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "esp_check.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "cJSON.h"

#define HA_TAG "ha_sync"
#define HA_HTTP_BUF_SIZE 2048
#define HA_TASK_STACK_BYTES 8192
#define WIFI_CONNECTED_BIT BIT0
#define HA_ENTITY_ID_MAX_LEN 96
#define HA_STATE_MAX_LEN 32
#define HA_LAST_CHANGED_MAX_LEN 48

typedef struct {
    char *entity_id;
    ha_state_cb_t on_remote_state;
    void *user_ctx;
    bool skip_poll;
} ha_entity_t;

typedef struct {
    char *base_url;
    char *auth_header;  // "Bearer <token>"
    char *auth_token;   // raw token for websocket auth
    uint32_t poll_ms;
    ha_entity_t *entities;
    size_t entity_count;
    TaskHandle_t task;
    QueueHandle_t queue;
    esp_websocket_client_handle_t ws;
    bool ws_authed;
} ha_sync_ctx_t;

typedef enum {
    HA_MSG_PUSH_STATE = 0,
    HA_MSG_EVENT_STATE,
} ha_msg_type_t;

typedef struct {
    ha_msg_type_t type;
    char entity_id[HA_ENTITY_ID_MAX_LEN];
    char state[HA_STATE_MAX_LEN];
    char last_changed[HA_LAST_CHANGED_MAX_LEN];
    bool has_temperature;
    float temperature;
} ha_msg_t;

static ha_sync_ctx_t g_ctx = {0};
static EventGroupHandle_t g_net_events;
static esp_event_handler_instance_t g_ip_handler;
static esp_event_handler_instance_t g_wifi_handler;

static bool json_get_temperature(cJSON *state_obj, float *out_temp)
{
    if (!state_obj || !out_temp) {
        return false;
    }
    cJSON *attrs = cJSON_GetObjectItemCaseSensitive(state_obj, "attributes");
    cJSON *temp = attrs ? cJSON_GetObjectItemCaseSensitive(attrs, "temperature") : NULL;
    if (cJSON_IsNumber(temp)) {
        *out_temp = (float)temp->valuedouble;
        return true;
    }
    return false;
}

static void ha_free_ctx(void)
{
    if (g_ctx.queue) {
        vQueueDelete(g_ctx.queue);
        g_ctx.queue = NULL;
    }
    if (g_ctx.ws) {
        esp_websocket_client_stop(g_ctx.ws);
        esp_websocket_client_destroy(g_ctx.ws);
        g_ctx.ws = NULL;
    }
    free(g_ctx.base_url);
    g_ctx.base_url = NULL;
    free(g_ctx.auth_header);
    g_ctx.auth_header = NULL;
    free(g_ctx.auth_token);
    g_ctx.auth_token = NULL;
    if (g_ctx.entities) {
        for (size_t i = 0; i < g_ctx.entity_count; ++i) {
            free(g_ctx.entities[i].entity_id);
        }
        free(g_ctx.entities);
        g_ctx.entities = NULL;
    }
    g_ctx.entity_count = 0;
    g_ctx.task = NULL;

    if (g_net_events) {
        if (g_ip_handler) {
            esp_event_handler_instance_unregister(IP_EVENT, IP_EVENT_STA_GOT_IP, g_ip_handler);
            g_ip_handler = NULL;
        }
        if (g_wifi_handler) {
            esp_event_handler_instance_unregister(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, g_wifi_handler);
            g_wifi_handler = NULL;
        }
        vEventGroupDelete(g_net_events);
        g_net_events = NULL;
    }
}

static char *dup_string(const char *in)
{
    if (!in) {
        return NULL;
    }
    size_t len = strlen(in);
    char *out = malloc(len + 1);
    if (out) {
        memcpy(out, in, len + 1);
    }
    return out;
}

static esp_err_t http_request(const char *url,
                              esp_http_client_method_t method,
                              const char *body,
                              char *out,
                              size_t out_len,
                              int *status_code)
{
    if (!url) {
        return ESP_ERR_INVALID_ARG;
    }

    esp_http_client_config_t cfg = {
        .url = url,
        .timeout_ms = 5000,
    };

    esp_http_client_handle_t client = esp_http_client_init(&cfg);
    if (!client) {
        return ESP_FAIL;
    }

    esp_http_client_set_method(client, method);
    if (g_ctx.auth_header) {
        esp_http_client_set_header(client, "Authorization", g_ctx.auth_header);
    }
    size_t body_len = body ? strlen(body) : 0;
    if (body) {
        esp_http_client_set_header(client, "Content-Type", "application/json");
    }

    esp_err_t err = esp_http_client_open(client, (int)body_len);
    if (err != ESP_OK) {
        ESP_LOGW(HA_TAG, "HTTP open failed: %s", esp_err_to_name(err));
        goto cleanup;
    }

    if (body_len > 0) {
        int written = esp_http_client_write(client, body, (int)body_len);
        if (written < 0) {
            ESP_LOGW(HA_TAG, "HTTP write failed");
            err = ESP_FAIL;
            goto cleanup_close;
        }
    }

    int64_t content_len = esp_http_client_fetch_headers(client);
    if (status_code) {
        *status_code = esp_http_client_get_status_code(client);
    }
    if (err != ESP_OK) {
        goto cleanup_close;
    }

    if (out && out_len > 0) {
        int total = 0;
        int r = 0;
        do {
            r = esp_http_client_read(client, out + total, (int)(out_len - 1 - total));
            if (r > 0) {
                total += r;
            }
        } while (r > 0 && total < (int)(out_len - 1));
        out[total] = '\0';

        if (content_len > 0 && content_len > total) {
            ESP_LOGW(HA_TAG, "HTTP body truncated (%d/%d bytes)", total, (int)content_len);
        }
    }

cleanup_close:
    esp_http_client_close(client);
cleanup:
    esp_http_client_cleanup(client);
    return err;
}

static esp_err_t ha_fetch_remote_state(const char *entity_id,
                                       char *state_buf,
                                       size_t state_len,
                                       char *last_changed_buf,
                                       size_t last_changed_len,
                                       float *temp_out,
                                       bool *has_temp_out)
{
    char url[256];
    int written = snprintf(url, sizeof(url), "%s/api/states/%s", g_ctx.base_url, entity_id);
    if (written <= 0 || written >= (int)sizeof(url)) {
        ESP_LOGE(HA_TAG, "URL too long");
        return ESP_ERR_INVALID_SIZE;
    }

    char resp[HA_HTTP_BUF_SIZE];
    int status = 0;
    esp_err_t err = http_request(url, HTTP_METHOD_GET, NULL, resp, sizeof(resp), &status);
    if (err != ESP_OK) {
        ESP_LOGW(HA_TAG, "GET failed: %s", esp_err_to_name(err));
        return err;
    }
    if (status != 200) {
        ESP_LOGW(HA_TAG, "GET %s returned HTTP %d", entity_id, status);
        return status == 404 ? ESP_ERR_NOT_FOUND : ESP_FAIL;
    }

    cJSON *root = cJSON_Parse(resp);
    if (!root) {
        ESP_LOGW(HA_TAG, "Failed to parse HA response (status=%d, len=%d): %s", status, (int)strlen(resp), resp);
        return ESP_FAIL;
    }

    esp_err_t ret = ESP_FAIL;
    if (has_temp_out) {
        *has_temp_out = false;
    }
    if (temp_out) {
        *temp_out = 0.0f;
    }
    if (last_changed_buf && last_changed_len > 0) {
        last_changed_buf[0] = '\0';
    }
    cJSON *state = cJSON_GetObjectItemCaseSensitive(root, "state");
    cJSON *last_changed = cJSON_GetObjectItemCaseSensitive(root, "last_changed");
    if (cJSON_IsString(state) && state->valuestring) {
        strlcpy(state_buf, state->valuestring, state_len);
        if (last_changed_buf && last_changed_len > 0 && cJSON_IsString(last_changed) && last_changed->valuestring) {
            strlcpy(last_changed_buf, last_changed->valuestring, last_changed_len);
        }
        if (temp_out && has_temp_out) {
            float t = 0.0f;
            if (json_get_temperature(root, &t)) {
                *temp_out = t;
                *has_temp_out = true;
            }
        }
        ret = ESP_OK;
    } else {
        ESP_LOGW(HA_TAG, "No state in HA response");
    }

    cJSON_Delete(root);
    return ret;
}

static esp_err_t ha_push_state(const char *entity_id, const char *state)
{
    if (!state || !entity_id) {
        return ESP_ERR_INVALID_ARG;
    }

    char url[256];
    int written = snprintf(url, sizeof(url), "%s/api/states/%s", g_ctx.base_url, entity_id);
    if (written <= 0 || written >= (int)sizeof(url)) {
        ESP_LOGE(HA_TAG, "URL too long");
        return ESP_ERR_INVALID_SIZE;
    }

    char body[96];
    snprintf(body, sizeof(body), "{\"state\":\"%s\"}", state);

    int status = 0;
    esp_err_t err = http_request(url, HTTP_METHOD_PUT, body, NULL, 0, &status);
    if (err != ESP_OK || status >= 300) {
        ESP_LOGW(HA_TAG, "PUT failed: err=%s http=%d", esp_err_to_name(err), status);
        return ESP_FAIL;
    }
    return ESP_OK;
}

static ha_entity_t *find_entity(const char *entity_id)
{
    if (!entity_id) {
        return NULL;
    }
    for (size_t i = 0; i < g_ctx.entity_count; ++i) {
        if (strcmp(g_ctx.entities[i].entity_id, entity_id) == 0) {
            return &g_ctx.entities[i];
        }
    }
    return NULL;
}

static void enqueue_event(const char *entity_id,
                          const char *state,
                          const char *last_changed,
                          bool has_temperature,
                          float temperature)
{
    if (!g_ctx.queue || !entity_id || !state) {
        return;
    }
    ha_msg_t msg = {
        .type = HA_MSG_EVENT_STATE,
    };
    strlcpy(msg.entity_id, entity_id, sizeof(msg.entity_id));
    strlcpy(msg.state, state, sizeof(msg.state));
    msg.last_changed[0] = '\0';
    msg.has_temperature = has_temperature;
    msg.temperature = temperature;
    if (last_changed) {
        strlcpy(msg.last_changed, last_changed, sizeof(msg.last_changed));
    }
    xQueueSend(g_ctx.queue, &msg, 0);
}

static void on_ip_event(void *arg, esp_event_base_t base, int32_t id, void *data)
{
    (void)arg;
    (void)base;
    (void)data;
    if (id == IP_EVENT_STA_GOT_IP && g_net_events) {
        xEventGroupSetBits(g_net_events, WIFI_CONNECTED_BIT);
    }
}

static void on_wifi_event(void *arg, esp_event_base_t base, int32_t id, void *data)
{
    (void)arg;
    (void)data;
    if (base == WIFI_EVENT && id == WIFI_EVENT_STA_DISCONNECTED && g_net_events) {
        xEventGroupClearBits(g_net_events, WIFI_CONNECTED_BIT);
    }
}

static bool wait_for_wifi_connected(TickType_t wait_ticks)
{
    if (!g_net_events) {
        return true; // assume ready if we couldn't create tracking
    }
    EventBits_t bits = xEventGroupWaitBits(g_net_events, WIFI_CONNECTED_BIT, pdFALSE, pdFALSE, wait_ticks);
    if ((bits & WIFI_CONNECTED_BIT) != 0) {
        return true;
    }
    // Poll WiFi state in case we missed the event (e.g., handler not yet registered).
    wifi_ap_record_t ap = {0};
    if (esp_wifi_sta_get_ap_info(&ap) == ESP_OK) {
        xEventGroupSetBits(g_net_events, WIFI_CONNECTED_BIT);
        return true;
    }
    return false;
}

static esp_err_t enqueue_push(const char *entity_id, const char *state)
{
    if (!g_ctx.queue || !entity_id || !state) {
        return ESP_ERR_INVALID_STATE;
    }
    ha_msg_t msg = {
        .type = HA_MSG_PUSH_STATE,
    };
    strlcpy(msg.entity_id, entity_id, sizeof(msg.entity_id));
    strlcpy(msg.state, state, sizeof(msg.state));
    msg.last_changed[0] = '\0';
    msg.has_temperature = false;
    msg.temperature = 0.0f;
    return xQueueSend(g_ctx.queue, &msg, 0) == pdTRUE ? ESP_OK : ESP_ERR_TIMEOUT;
}

static void ws_send_text(const char *text)
{
    if (!g_ctx.ws || !text) {
        return;
    }
    esp_websocket_client_send_text(g_ctx.ws, text, strlen(text), pdMS_TO_TICKS(1000));
}

static void ws_send_auth(void)
{
    if (!g_ctx.auth_token) {
        ESP_LOGE(HA_TAG, "No auth token for websocket");
        return;
    }
    char msg[256];
    snprintf(msg, sizeof(msg), "{\"type\":\"auth\",\"access_token\":\"%s\"}", g_ctx.auth_token);
    ws_send_text(msg);
}

static void ws_send_subscribe(void)
{
    ws_send_text("{\"id\":1,\"type\":\"subscribe_events\",\"event_type\":\"state_changed\"}");
}

static void handle_ws_payload(const char *payload)
{
    if (!payload) {
        return;
    }

    cJSON *root = cJSON_Parse(payload);
    if (!root) {
        const size_t max_dump = 120;
        size_t len = strnlen(payload, max_dump);
        ESP_LOGW(HA_TAG, "WS JSON parse failed (len=%d): %.*s", (int)len, (int)len, payload);
        return;
    }

    cJSON *type = cJSON_GetObjectItemCaseSensitive(root, "type");
    if (cJSON_IsString(type) && type->valuestring) {
        if (strcmp(type->valuestring, "auth_required") == 0) {
            ws_send_auth();
        } else if (strcmp(type->valuestring, "auth_ok") == 0) {
            g_ctx.ws_authed = true;
            ws_send_subscribe();
            ESP_LOGI(HA_TAG, "WS authenticated");
        } else if (strcmp(type->valuestring, "event") == 0) {
            if (!g_ctx.ws_authed) {
                goto cleanup;
            }
            cJSON *event = cJSON_GetObjectItem(root, "event");
            cJSON *event_type = cJSON_GetObjectItem(event, "event_type");
            if (cJSON_IsString(event_type) && strcmp(event_type->valuestring, "state_changed") == 0) {
                cJSON *data = cJSON_GetObjectItem(event, "data");
                cJSON *entity = cJSON_GetObjectItem(data, "entity_id");
                cJSON *new_state = cJSON_GetObjectItem(data, "new_state");
                cJSON *state = new_state ? cJSON_GetObjectItem(new_state, "state") : NULL;
                cJSON *last_changed = new_state ? cJSON_GetObjectItemCaseSensitive(new_state, "last_changed") : NULL;
                const char *last_changed_str = NULL;
                if (cJSON_IsString(last_changed) && last_changed->valuestring) {
                    last_changed_str = last_changed->valuestring;
                }
                float temperature = 0.0f;
                bool has_temperature = json_get_temperature(new_state, &temperature);
                if (cJSON_IsString(entity) && cJSON_IsString(state)) {
                    if (find_entity(entity->valuestring)) {
                        enqueue_event(entity->valuestring,
                                      state->valuestring,
                                      last_changed_str,
                                      has_temperature,
                                      temperature);
                    }
                }
            }
        }
    }

cleanup:
    cJSON_Delete(root);
}

static void websocket_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    (void)handler_args;
    esp_websocket_event_data_t *data = (esp_websocket_event_data_t *)event_data;

    static char *ws_buf = NULL;
    static size_t ws_buf_cap = 0;

    switch (event_id) {
    case WEBSOCKET_EVENT_CONNECTED:
        ESP_LOGI(HA_TAG, "WS connected");
        g_ctx.ws_authed = false;
        break;
    case WEBSOCKET_EVENT_DISCONNECTED:
        ESP_LOGW(HA_TAG, "WS disconnected");
        g_ctx.ws_authed = false;
        break;
    case WEBSOCKET_EVENT_DATA: {
        // Handle fragmented frames: accumulate until full payload is received.
        size_t total_len = data->payload_len;
        size_t offset = data->payload_offset;
        size_t chunk_len = data->data_len;
        if (total_len == 0) {
            break;
        }
        if (ws_buf_cap < total_len + 1) {
            char *newbuf = realloc(ws_buf, total_len + 1);
            if (!newbuf) {
                ESP_LOGW(HA_TAG, "WS buffer alloc failed (%d bytes)", (int)(total_len + 1));
                break;
            }
            ws_buf = newbuf;
            ws_buf_cap = total_len + 1;
        }
        memcpy(ws_buf + offset, data->data_ptr, chunk_len);
        if ((offset + chunk_len) == total_len) {
            ws_buf[total_len] = '\0';
            handle_ws_payload(ws_buf);
        }
        break;
    }
    default:
        break;
    }
}

static esp_err_t start_websocket(void)
{
    char ws_uri[256];

    const char *host = g_ctx.base_url;
    const char *scheme = "ws";
    if (strncmp(host, "https://", 8) == 0) {
        host += 8;
        scheme = "wss";
    } else if (strncmp(host, "http://", 7) == 0) {
        host += 7;
        scheme = "ws";
    }

    int n = snprintf(ws_uri, sizeof(ws_uri), "%s://%s/api/websocket", scheme, host);
    if (n <= 0 || n >= (int)sizeof(ws_uri)) {
        ESP_LOGE(HA_TAG, "WS URI too long");
        return ESP_ERR_INVALID_SIZE;
    }

    esp_websocket_client_config_t cfg = {
        .uri = ws_uri,
        .disable_auto_reconnect = false,
    };

    g_ctx.ws = esp_websocket_client_init(&cfg);
    if (!g_ctx.ws) {
        ESP_LOGE(HA_TAG, "Failed to init websocket");
        return ESP_FAIL;
    }

    ESP_ERROR_CHECK_WITHOUT_ABORT(esp_websocket_register_events(g_ctx.ws, WEBSOCKET_EVENT_ANY, websocket_event_handler, NULL));

    esp_err_t err = esp_websocket_client_start(g_ctx.ws);
    if (err != ESP_OK) {
        ESP_LOGE(HA_TAG, "Failed to start websocket: %s", esp_err_to_name(err));
        esp_websocket_client_destroy(g_ctx.ws);
        g_ctx.ws = NULL;
        return err;
    }

    ESP_LOGI(HA_TAG, "WS connecting to %s", ws_uri);
    return ESP_OK;
}

static void ha_sync_task(void *arg)
{
    TickType_t last_poll = xTaskGetTickCount();
    char remote_state[HA_STATE_MAX_LEN] = {0};
    char remote_last_changed[HA_LAST_CHANGED_MAX_LEN] = {0};
    float remote_temp = 0.0f;
    bool remote_has_temp = false;

    while (!wait_for_wifi_connected(pdMS_TO_TICKS(30000))) {
        ESP_LOGW(HA_TAG, "Waiting for WiFi connection before HA sync...");
    }

    // Initial pull to seed local state
    for (size_t i = 0; i < g_ctx.entity_count; ++i) {
        if (g_ctx.entities[i].skip_poll) {
            continue;
        }
        esp_err_t res = ha_fetch_remote_state(g_ctx.entities[i].entity_id,
                                              remote_state,
                                              sizeof(remote_state),
                                              remote_last_changed,
                                              sizeof(remote_last_changed),
                                              &remote_temp,
                                              &remote_has_temp);
        if (res == ESP_OK && g_ctx.entities[i].on_remote_state) {
            g_ctx.entities[i].on_remote_state(remote_state,
                                              remote_last_changed[0] ? remote_last_changed : NULL,
                                              remote_has_temp,
                                              remote_temp,
                                              g_ctx.entities[i].user_ctx);
        } else if (res == ESP_ERR_NOT_FOUND) {
            g_ctx.entities[i].skip_poll = true;
            ESP_LOGW(HA_TAG, "Disabling polling for missing entity: %s", g_ctx.entities[i].entity_id);
        }
    }

    // Start websocket listener
    if (start_websocket() != ESP_OK) {
        ESP_LOGW(HA_TAG, "WS start failed; relying on REST polling");
    }

    for (;;) {
        // Periodic pull
        if (g_ctx.poll_ms > 0 && (xTaskGetTickCount() - last_poll) >= pdMS_TO_TICKS(g_ctx.poll_ms)) {
            for (size_t i = 0; i < g_ctx.entity_count; ++i) {
                if (g_ctx.entities[i].skip_poll) {
                    continue;
                }
                esp_err_t res = ha_fetch_remote_state(g_ctx.entities[i].entity_id,
                                                      remote_state,
                                                      sizeof(remote_state),
                                                      remote_last_changed,
                                                      sizeof(remote_last_changed),
                                                      &remote_temp,
                                                      &remote_has_temp);
                if (res == ESP_OK && g_ctx.entities[i].on_remote_state) {
                    g_ctx.entities[i].on_remote_state(remote_state,
                                                      remote_last_changed[0] ? remote_last_changed : NULL,
                                                      remote_has_temp,
                                                      remote_temp,
                                                      g_ctx.entities[i].user_ctx);
                } else if (res == ESP_ERR_NOT_FOUND) {
                    g_ctx.entities[i].skip_poll = true;
                    ESP_LOGW(HA_TAG, "Disabling polling for missing entity: %s", g_ctx.entities[i].entity_id);
                }
            }
            last_poll = xTaskGetTickCount();
        }

        // Handle outbound updates
        ha_msg_t cmd;
        if (xQueueReceive(g_ctx.queue, &cmd, pdMS_TO_TICKS(100)) == pdTRUE) {
            switch (cmd.type) {
            case HA_MSG_PUSH_STATE:
                ha_push_state(cmd.entity_id, cmd.state);
                break;
            case HA_MSG_EVENT_STATE: {
                ha_entity_t *ent = find_entity(cmd.entity_id);
                if (ent && ent->on_remote_state) {
                    ent->on_remote_state(cmd.state,
                                         cmd.last_changed[0] ? cmd.last_changed : NULL,
                                         cmd.has_temperature,
                                         cmd.temperature,
                                         ent->user_ctx);
                }
                break;
            }
            default:
                break;
            }
        }
    }
}

esp_err_t ha_sync_set_local_state(const char *entity_id, const char *state)
{
    if (!state || !entity_id || !g_ctx.queue) {
        return ESP_ERR_INVALID_STATE;
    }
    return enqueue_push(entity_id, state);
}

esp_err_t ha_sync_start(const ha_sync_config_t *config)
{
    if (!config || !config->base_url || !config->auth_token || !config->entities || config->entity_count == 0) {
        return ESP_ERR_INVALID_ARG;
    }
    if (g_ctx.task) {
        return ESP_ERR_INVALID_STATE;
    }

    memset(&g_ctx, 0, sizeof(g_ctx));
    g_ctx.base_url = dup_string(config->base_url);
    g_ctx.entities = calloc(config->entity_count, sizeof(ha_entity_t));

    const char bearer_prefix[] = "Bearer ";
    size_t hdr_len = strlen(bearer_prefix) + strlen(config->auth_token) + 1;
    g_ctx.auth_header = malloc(hdr_len);
    if (g_ctx.auth_header) {
        strcpy(g_ctx.auth_header, bearer_prefix);
        strcat(g_ctx.auth_header, config->auth_token);
    }
    g_ctx.auth_token = dup_string(config->auth_token);

    g_ctx.poll_ms = config->poll_interval_ms ? config->poll_interval_ms : 5000;
    g_ctx.entity_count = config->entity_count;
    g_ctx.queue = xQueueCreate(8, sizeof(ha_msg_t));
    g_net_events = xEventGroupCreate();

    if (!g_ctx.base_url || !g_ctx.entities || !g_ctx.auth_header || !g_ctx.auth_token || !g_ctx.queue) {
        ESP_LOGE(HA_TAG, "Failed to allocate HA sync resources");
        ha_free_ctx();
        return ESP_ERR_NO_MEM;
    }

    // Ensure the default event loop exists for WiFi/IP events.
    esp_event_loop_create_default();
    // Track WiFi connectivity so we don't hammer HA before network is ready.
    esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, on_ip_event, NULL, &g_ip_handler);
    esp_event_handler_instance_register(WIFI_EVENT, WIFI_EVENT_STA_DISCONNECTED, on_wifi_event, NULL, &g_wifi_handler);
    wifi_ap_record_t ap = {0};
    if (esp_wifi_sta_get_ap_info(&ap) == ESP_OK && g_net_events) {
        xEventGroupSetBits(g_net_events, WIFI_CONNECTED_BIT);
    }

    for (size_t i = 0; i < config->entity_count; ++i) {
        g_ctx.entities[i].entity_id = dup_string(config->entities[i].entity_id);
        g_ctx.entities[i].on_remote_state = config->entities[i].on_remote_state;
        g_ctx.entities[i].user_ctx = config->entities[i].user_ctx;
        g_ctx.entities[i].skip_poll = false;
        if (!g_ctx.entities[i].entity_id) {
            ESP_LOGE(HA_TAG, "Failed to alloc entity %zu", i);
            ha_free_ctx();
            return ESP_ERR_NO_MEM;
        }
    }

    BaseType_t ok = xTaskCreate(ha_sync_task, "ha_sync", HA_TASK_STACK_BYTES, NULL, 3, &g_ctx.task);
    if (ok != pdPASS) {
        ESP_LOGE(HA_TAG, "Failed to start ha_sync task");
        ha_free_ctx();
        return ESP_FAIL;
    }

    ESP_LOGI(HA_TAG, "Started HA sync for %zu entities", g_ctx.entity_count);
    return ESP_OK;
}
