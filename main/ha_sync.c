/*
 * Simple Home Assistant HTTP synchronizer:
 * - Periodically GET /api/states/<entity_id> to mirror remote state locally.
 * - When the application calls ha_sync_set_local_state(), PUTs the new state back to HA.
 */

#include "ha_sync.h"

#include <string.h>
#include <stdlib.h>
#include "esp_http_client.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "cJSON.h"

#define HA_TAG "ha_sync"

typedef struct {
    char *entity_id;
    ha_state_cb_t on_remote_state;
    void *user_ctx;
} ha_entity_t;

typedef struct {
    char *base_url;
    char *auth_header;  // "Bearer <token>"
    uint32_t poll_ms;
    ha_entity_t *entities;
    size_t entity_count;
    TaskHandle_t task;
    QueueHandle_t queue;
} ha_sync_ctx_t;

typedef struct {
    char entity_id[96];
    char state[32];
} ha_cmd_t;

static ha_sync_ctx_t g_ctx = {0};

static void ha_free_ctx(void)
{
    if (g_ctx.queue) {
        vQueueDelete(g_ctx.queue);
        g_ctx.queue = NULL;
    }
    free(g_ctx.base_url);
    g_ctx.base_url = NULL;
    free(g_ctx.auth_header);
    g_ctx.auth_header = NULL;
    if (g_ctx.entities) {
        for (size_t i = 0; i < g_ctx.entity_count; ++i) {
            free(g_ctx.entities[i].entity_id);
        }
        free(g_ctx.entities);
        g_ctx.entities = NULL;
    }
    g_ctx.entity_count = 0;
    g_ctx.task = NULL;
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
    if (body) {
        esp_http_client_set_header(client, "Content-Type", "application/json");
        esp_http_client_set_post_field(client, body, strlen(body));
    }

    esp_err_t err = esp_http_client_perform(client);
    if (err == ESP_OK) {
        if (status_code) {
            *status_code = esp_http_client_get_status_code(client);
        }
        if (out && out_len > 0) {
            int read = esp_http_client_read_response(client, out, out_len - 1);
            if (read < 0) {
                out[0] = '\0';
            } else {
                out[read] = '\0';
            }
        }
    }

    esp_http_client_cleanup(client);
    return err;
}

static esp_err_t ha_fetch_remote_state(const char *entity_id, char *state_buf, size_t state_len)
{
    char url[256];
    int written = snprintf(url, sizeof(url), "%s/api/states/%s", g_ctx.base_url, entity_id);
    if (written <= 0 || written >= (int)sizeof(url)) {
        ESP_LOGE(HA_TAG, "URL too long");
        return ESP_ERR_INVALID_SIZE;
    }

    char resp[512];
    int status = 0;
    esp_err_t err = http_request(url, HTTP_METHOD_GET, NULL, resp, sizeof(resp), &status);
    if (err != ESP_OK) {
        ESP_LOGW(HA_TAG, "GET failed: %s", esp_err_to_name(err));
        return err;
    }
    if (status != 200) {
        ESP_LOGW(HA_TAG, "GET returned HTTP %d", status);
        return ESP_FAIL;
    }

    cJSON *root = cJSON_Parse(resp);
    if (!root) {
        ESP_LOGW(HA_TAG, "Failed to parse HA response");
        return ESP_FAIL;
    }

    esp_err_t ret = ESP_FAIL;
    cJSON *state = cJSON_GetObjectItemCaseSensitive(root, "state");
    if (cJSON_IsString(state) && state->valuestring) {
        strlcpy(state_buf, state->valuestring, state_len);
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

static void ha_sync_task(void *arg)
{
    TickType_t last_poll = xTaskGetTickCount();
    char remote_state[32] = {0};

    for (;;) {
        // Periodic pull
        if (g_ctx.poll_ms > 0 && (xTaskGetTickCount() - last_poll) >= pdMS_TO_TICKS(g_ctx.poll_ms)) {
            for (size_t i = 0; i < g_ctx.entity_count; ++i) {
                if (ha_fetch_remote_state(g_ctx.entities[i].entity_id, remote_state, sizeof(remote_state)) == ESP_OK &&
                    g_ctx.entities[i].on_remote_state) {
                    g_ctx.entities[i].on_remote_state(remote_state, g_ctx.entities[i].user_ctx);
                }
            }
            last_poll = xTaskGetTickCount();
        }

        // Handle outbound updates
        ha_cmd_t cmd;
        if (xQueueReceive(g_ctx.queue, &cmd, pdMS_TO_TICKS(100)) == pdTRUE) {
            ha_push_state(cmd.entity_id, cmd.state);
        }
    }
}

esp_err_t ha_sync_set_local_state(const char *entity_id, const char *state)
{
    if (!state || !entity_id || !g_ctx.queue) {
        return ESP_ERR_INVALID_STATE;
    }
    ha_cmd_t cmd = {
    };
    strlcpy(cmd.entity_id, entity_id, sizeof(cmd.entity_id));
    strlcpy(cmd.state, state, sizeof(cmd.state));
    if (xQueueSend(g_ctx.queue, &cmd, 0) != pdTRUE) {
        return ESP_ERR_TIMEOUT;
    }
    return ESP_OK;
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

    g_ctx.poll_ms = config->poll_interval_ms ? config->poll_interval_ms : 5000;
    g_ctx.entity_count = config->entity_count;
    g_ctx.queue = xQueueCreate(8, sizeof(ha_cmd_t));

    if (!g_ctx.base_url || !g_ctx.entities || !g_ctx.auth_header || !g_ctx.queue) {
        ESP_LOGE(HA_TAG, "Failed to allocate HA sync resources");
        ha_free_ctx();
        return ESP_ERR_NO_MEM;
    }

    for (size_t i = 0; i < config->entity_count; ++i) {
        g_ctx.entities[i].entity_id = dup_string(config->entities[i].entity_id);
        g_ctx.entities[i].on_remote_state = config->entities[i].on_remote_state;
        g_ctx.entities[i].user_ctx = config->entities[i].user_ctx;
        if (!g_ctx.entities[i].entity_id) {
            ESP_LOGE(HA_TAG, "Failed to alloc entity %zu", i);
            ha_free_ctx();
            return ESP_ERR_NO_MEM;
        }
    }

    BaseType_t ok = xTaskCreate(ha_sync_task, "ha_sync", 4096, NULL, 3, &g_ctx.task);
    if (ok != pdPASS) {
        ESP_LOGE(HA_TAG, "Failed to start ha_sync task");
        ha_free_ctx();
        return ESP_FAIL;
    }

    ESP_LOGI(HA_TAG, "Started HA sync for %s", g_ctx.entity_id);
    return ESP_OK;
}
