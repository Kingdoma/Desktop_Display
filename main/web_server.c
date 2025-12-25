#include "web_server.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "esp_http_server.h"
#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ha_settings.h"
#include "app_main.h"

#define WEB_SERVER_TAG "web_server"
#define WEB_SERVER_MAX_BODY 1536
#define WEB_SERVER_MAX_ESCAPED 1536

static httpd_handle_t s_server = NULL;

extern const uint8_t _binary_settings_html_start[] asm("_binary_settings_html_start");
extern const uint8_t _binary_settings_html_end[] asm("_binary_settings_html_end");

static void url_decode_inplace(char *str)
{
    if (!str) {
        return;
    }

    char *src = str;
    char *dst = str;
    while (*src) {
        if (*src == '+') {
            *dst++ = ' ';
            src++;
            continue;
        }

        if (*src == '%' && isxdigit((unsigned char)src[1]) && isxdigit((unsigned char)src[2])) {
            int high = isdigit((unsigned char)src[1]) ? (src[1] - '0') : (tolower((unsigned char)src[1]) - 'a' + 10);
            int low = isdigit((unsigned char)src[2]) ? (src[2] - '0') : (tolower((unsigned char)src[2]) - 'a' + 10);
            *dst++ = (char)((high << 4) | low);
            src += 3;
            continue;
        }

        *dst++ = *src++;
    }
    *dst = '\0';
}

static void html_escape(const char *in, char *out, size_t out_len)
{
    if (!out || out_len == 0) {
        return;
    }
    out[0] = '\0';
    if (!in) {
        return;
    }

    size_t used = 0;
    for (const char *p = in; *p; ++p) {
        const char *rep = NULL;
        switch (*p) {
        case '&':
            rep = "&amp;";
            break;
        case '<':
            rep = "&lt;";
            break;
        case '>':
            rep = "&gt;";
            break;
        case '"':
            rep = "&quot;";
            break;
        case '\'':
            rep = "&#39;";
            break;
        default:
            break;
        }

        if (rep) {
            size_t rep_len = strlen(rep);
            if (used + rep_len + 1 >= out_len) {
                break;
            }
            memcpy(out + used, rep, rep_len);
            used += rep_len;
        } else {
            if (used + 2 >= out_len) {
                break;
            }
            out[used++] = *p;
        }
    }
    out[used] = '\0';
}

typedef enum {
    TOKEN_BASE_URL = 0,
    TOKEN_AUTH_TOKEN,
    TOKEN_POLL_MS,
    TOKEN_SNTP_SERVER,
    TOKEN_TIME_ZONE,
    TOKEN_ENTITY_SWITCH_1,
    TOKEN_ENTITY_SWITCH_2,
    TOKEN_ENTITY_AC,
    TOKEN_ENTITY_WEATHER,
    TOKEN_ENTITY_EXTRA_1,
    TOKEN_ENTITY_EXTRA_2,
    TOKEN_ENTITY_EXTRA_3,
    TOKEN_ENTITY_EXTRA_4,
    TOKEN_ENTITY_EXTRA_5,
    TOKEN_COUNT
} template_token_id_t;

typedef struct {
    const char *token;
    size_t token_len;
    template_token_id_t id;
} template_token_t;

static const template_token_t k_template_tokens[] = {
    { "{{BASE_URL}}", sizeof("{{BASE_URL}}") - 1, TOKEN_BASE_URL },
    { "{{AUTH_TOKEN}}", sizeof("{{AUTH_TOKEN}}") - 1, TOKEN_AUTH_TOKEN },
    { "{{POLL_INTERVAL_MS}}", sizeof("{{POLL_INTERVAL_MS}}") - 1, TOKEN_POLL_MS },
    { "{{SNTP_SERVER}}", sizeof("{{SNTP_SERVER}}") - 1, TOKEN_SNTP_SERVER },
    { "{{TIME_ZONE}}", sizeof("{{TIME_ZONE}}") - 1, TOKEN_TIME_ZONE },
    { "{{ENTITY_SWITCH_1}}", sizeof("{{ENTITY_SWITCH_1}}") - 1, TOKEN_ENTITY_SWITCH_1 },
    { "{{ENTITY_SWITCH_2}}", sizeof("{{ENTITY_SWITCH_2}}") - 1, TOKEN_ENTITY_SWITCH_2 },
    { "{{ENTITY_AC}}", sizeof("{{ENTITY_AC}}") - 1, TOKEN_ENTITY_AC },
    { "{{ENTITY_WEATHER}}", sizeof("{{ENTITY_WEATHER}}") - 1, TOKEN_ENTITY_WEATHER },
    { "{{ENTITY_EXTRA_1}}", sizeof("{{ENTITY_EXTRA_1}}") - 1, TOKEN_ENTITY_EXTRA_1 },
    { "{{ENTITY_EXTRA_2}}", sizeof("{{ENTITY_EXTRA_2}}") - 1, TOKEN_ENTITY_EXTRA_2 },
    { "{{ENTITY_EXTRA_3}}", sizeof("{{ENTITY_EXTRA_3}}") - 1, TOKEN_ENTITY_EXTRA_3 },
    { "{{ENTITY_EXTRA_4}}", sizeof("{{ENTITY_EXTRA_4}}") - 1, TOKEN_ENTITY_EXTRA_4 },
    { "{{ENTITY_EXTRA_5}}", sizeof("{{ENTITY_EXTRA_5}}") - 1, TOKEN_ENTITY_EXTRA_5 },
};

static const char *find_token(const char *haystack, size_t haystack_len, const char *needle, size_t needle_len)
{
    if (!haystack || !needle || needle_len == 0 || haystack_len < needle_len) {
        return NULL;
    }

    for (size_t i = 0; i + needle_len <= haystack_len; ++i) {
        if (memcmp(haystack + i, needle, needle_len) == 0) {
            return haystack + i;
        }
    }

    return NULL;
}

static const template_token_t *find_next_token(const char *cursor, size_t remaining, const char **out_pos)
{
    const template_token_t *best = NULL;
    const char *best_pos = NULL;

    for (size_t i = 0; i < sizeof(k_template_tokens) / sizeof(k_template_tokens[0]); ++i) {
        const template_token_t *token = &k_template_tokens[i];
        const char *pos = find_token(cursor, remaining, token->token, token->token_len);
        if (!pos) {
            continue;
        }
        if (!best_pos || pos < best_pos) {
            best_pos = pos;
            best = token;
        }
    }

    if (out_pos) {
        *out_pos = best_pos;
    }
    return best;
}

static esp_err_t send_chunk(httpd_req_t *req, const char *data, size_t len)
{
    esp_err_t err = httpd_resp_send_chunk(req, data, len);
    if (err != ESP_OK) {
        ESP_LOGW(WEB_SERVER_TAG, "Failed to send response chunk (%s)", esp_err_to_name(err));
    }
    return err;
}

static void template_value(const ha_settings_t *settings,
                           template_token_id_t id,
                           char *out,
                           size_t out_len)
{
    if (!out || out_len == 0) {
        return;
    }
    out[0] = '\0';
    if (!settings) {
        return;
    }

    const char *raw = "";
    char number_buf[16];

    switch (id) {
    case TOKEN_BASE_URL:
        raw = settings->base_url;
        break;
    case TOKEN_AUTH_TOKEN:
        raw = settings->auth_token;
        break;
    case TOKEN_POLL_MS:
        snprintf(number_buf, sizeof(number_buf), "%lu", (unsigned long)settings->poll_interval_ms);
        raw = number_buf;
        break;
    case TOKEN_SNTP_SERVER:
        raw = settings->sntp_server;
        break;
    case TOKEN_TIME_ZONE:
        raw = settings->time_zone;
        break;
    case TOKEN_ENTITY_SWITCH_1:
        raw = settings->entity_switch_1;
        break;
    case TOKEN_ENTITY_SWITCH_2:
        raw = settings->entity_switch_2;
        break;
    case TOKEN_ENTITY_AC:
        raw = settings->entity_ac;
        break;
    case TOKEN_ENTITY_WEATHER:
        raw = settings->entity_weather;
        break;
    case TOKEN_ENTITY_EXTRA_1:
        raw = settings->entity_extra[0];
        break;
    case TOKEN_ENTITY_EXTRA_2:
        raw = settings->entity_extra[1];
        break;
    case TOKEN_ENTITY_EXTRA_3:
        raw = settings->entity_extra[2];
        break;
    case TOKEN_ENTITY_EXTRA_4:
        raw = settings->entity_extra[3];
        break;
    case TOKEN_ENTITY_EXTRA_5:
        raw = settings->entity_extra[4];
        break;
    default:
        raw = "";
        break;
    }

    html_escape(raw, out, out_len);
}

static esp_err_t send_template(httpd_req_t *req,
                               const char *tmpl,
                               size_t tmpl_len,
                               const ha_settings_t *settings)
{
    static char replace_buf[WEB_SERVER_MAX_ESCAPED];

    const char *cursor = tmpl;
    size_t remaining = tmpl_len;

    while (remaining > 0) {
        const char *hit = NULL;
        const template_token_t *token = find_next_token(cursor, remaining, &hit);

        if (!token || !hit) {
            return send_chunk(req, cursor, remaining);
        }

        size_t prefix_len = (size_t)(hit - cursor);
        if (prefix_len > 0) {
            esp_err_t err = send_chunk(req, cursor, prefix_len);
            if (err != ESP_OK) {
                return err;
            }
        }

        template_value(settings, token->id, replace_buf, sizeof(replace_buf));
        if (replace_buf[0] != '\0') {
            esp_err_t err = send_chunk(req, replace_buf, strlen(replace_buf));
            if (err != ESP_OK) {
                return err;
            }
        }

        cursor = hit + token->token_len;
        remaining = tmpl_len - (size_t)(cursor - tmpl);
    }

    return ESP_OK;
}

static bool apply_form_kv(ha_settings_t *settings, const char *key, const char *value)
{
    if (!settings || !key || !value) {
        return false;
    }

    if (strcmp(key, "base_url") == 0) {
        strlcpy(settings->base_url, value, sizeof(settings->base_url));
        return true;
    }

    if (strcmp(key, "auth_token") == 0) {
        strlcpy(settings->auth_token, value, sizeof(settings->auth_token));
        return true;
    }

    if (strcmp(key, "poll_interval_ms") == 0) {
        char *end = NULL;
        unsigned long parsed = strtoul(value, &end, 10);
        if (end && end != value) {
            if (parsed > 600000UL) {
                parsed = 600000UL;
            }
            settings->poll_interval_ms = (uint32_t)parsed;
            return true;
        }
        return false;
    }

    if (strcmp(key, "sntp_server") == 0) {
        strlcpy(settings->sntp_server, value, sizeof(settings->sntp_server));
        return true;
    }

    if (strcmp(key, "time_zone") == 0) {
        strlcpy(settings->time_zone, value, sizeof(settings->time_zone));
        return true;
    }

    if (strcmp(key, "entity_switch_1") == 0) {
        strlcpy(settings->entity_switch_1, value, sizeof(settings->entity_switch_1));
        return true;
    }

    if (strcmp(key, "entity_switch_2") == 0) {
        strlcpy(settings->entity_switch_2, value, sizeof(settings->entity_switch_2));
        return true;
    }

    if (strcmp(key, "entity_ac") == 0) {
        strlcpy(settings->entity_ac, value, sizeof(settings->entity_ac));
        return true;
    }

    if (strcmp(key, "entity_weather") == 0) {
        strlcpy(settings->entity_weather, value, sizeof(settings->entity_weather));
        return true;
    }

    if (strcmp(key, "entity_extra_1") == 0) {
        strlcpy(settings->entity_extra[0], value, sizeof(settings->entity_extra[0]));
        return true;
    }

    if (strcmp(key, "entity_extra_2") == 0) {
        strlcpy(settings->entity_extra[1], value, sizeof(settings->entity_extra[1]));
        return true;
    }

    if (strcmp(key, "entity_extra_3") == 0) {
        strlcpy(settings->entity_extra[2], value, sizeof(settings->entity_extra[2]));
        return true;
    }

    if (strcmp(key, "entity_extra_4") == 0) {
        strlcpy(settings->entity_extra[3], value, sizeof(settings->entity_extra[3]));
        return true;
    }

    if (strcmp(key, "entity_extra_5") == 0) {
        strlcpy(settings->entity_extra[4], value, sizeof(settings->entity_extra[4]));
        return true;
    }

    return false;
}

static void restart_task(void *arg)
{
    (void)arg;
    vTaskDelay(pdMS_TO_TICKS(700));
    esp_restart();
}

static esp_err_t root_get_handler(httpd_req_t *req)
{
    const ha_settings_t *settings = ha_settings_get();

    httpd_resp_set_type(req, "text/html");
    httpd_resp_set_hdr(req, "Cache-Control", "no-store");

    const char *html = (const char *)_binary_settings_html_start;
    size_t html_len = (size_t)(_binary_settings_html_end - _binary_settings_html_start);

    esp_err_t err = send_template(req, html, html_len, settings);
    if (err != ESP_OK) {
        return err;
    }
    return httpd_resp_send_chunk(req, NULL, 0);
}

static esp_err_t settings_post_handler(httpd_req_t *req)
{
    if (req->content_len <= 0) {
        httpd_resp_send_err(req, HTTPD_400_BAD_REQUEST, "Empty body");
        return ESP_FAIL;
    }

    if (req->content_len > WEB_SERVER_MAX_BODY) {
        httpd_resp_send_err(req, HTTPD_413_CONTENT_TOO_LARGE, "Body too large");
        return ESP_FAIL;
    }

    char *body = (char *)malloc((size_t)req->content_len + 1);
    if (!body) {
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Out of memory");
        return ESP_FAIL;
    }

    int received = 0;
    while (received < req->content_len) {
        int r = httpd_req_recv(req, body + received, req->content_len - received);
        if (r <= 0) {
            free(body);
            return ESP_FAIL;
        }
        received += r;
    }
    body[received] = '\0';

    ha_settings_t updated = *ha_settings_get();
    bool changed = false;

    char *cursor = body;
    while (cursor && *cursor) {
        char *pair = cursor;
        char *amp = strchr(pair, '&');
        if (amp) {
            *amp = '\0';
            cursor = amp + 1;
        } else {
            cursor = NULL;
        }

        char *eq = strchr(pair, '=');
        if (!eq) {
            continue;
        }
        *eq = '\0';
        char *key = pair;
        char *value = eq + 1;
        url_decode_inplace(key);
        url_decode_inplace(value);

        if (apply_form_kv(&updated, key, value)) {
            changed = true;
        }
    }

    if (!changed) {
        free(body);
        httpd_resp_sendstr(req, "No changes detected.");
        return ESP_OK;
    }

    if (!ha_settings_save(&updated)) {
        free(body);
        httpd_resp_send_err(req, HTTPD_500_INTERNAL_SERVER_ERROR, "Save failed");
        return ESP_FAIL;
    }

    free(body);
    httpd_resp_set_status(req, "303 See Other");
    httpd_resp_set_hdr(req, "Location", "/");
    httpd_resp_set_hdr(req, "Cache-Control", "no-store");
    httpd_resp_sendstr(req, "Saved. Rebooting...");
    xTaskCreate(restart_task, "restart_task", 2048, NULL, 1, NULL);
    return ESP_OK;
}

static esp_err_t settings_get_handler(httpd_req_t *req)
{
    httpd_resp_set_status(req, "302 Found");
    httpd_resp_set_hdr(req, "Location", "/");
    httpd_resp_sendstr(req, "Redirecting...");
    return ESP_OK;
}

void web_server_start(void)
{
    if (s_server) {
        return;
    }

    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.max_uri_handlers = 8;
    config.stack_size = 6144;

    esp_err_t err = httpd_start(&s_server, &config);
    if (err != ESP_OK) {
        ESP_LOGW(WEB_SERVER_TAG, "Failed to start server (%s)", esp_err_to_name(err));

        g_module_status.web_status = ERROR;
        g_module_status.need_update = true;

        return;
    }

    httpd_uri_t root = {
        .uri = "/",
        .method = HTTP_GET,
        .handler = root_get_handler,
        .user_ctx = NULL,
    };
    httpd_uri_t root_post = {
        .uri = "/",
        .method = HTTP_POST,
        .handler = settings_post_handler,
        .user_ctx = NULL,
    };
    httpd_uri_t settings_get = {
        .uri = "/settings",
        .method = HTTP_GET,
        .handler = settings_get_handler,
        .user_ctx = NULL,
    };
    httpd_uri_t settings = {
        .uri = "/settings",
        .method = HTTP_POST,
        .handler = settings_post_handler,
        .user_ctx = NULL,
    };

    httpd_register_uri_handler(s_server, &root);
    httpd_register_uri_handler(s_server, &root_post);
    httpd_register_uri_handler(s_server, &settings_get);
    httpd_register_uri_handler(s_server, &settings);

    ESP_LOGI(WEB_SERVER_TAG, "Settings server started");

    g_module_status.web_status = READY;
    g_module_status.need_update = true;
}

void web_server_stop(void)
{
    if (!s_server) {
        return;
    }

    esp_err_t err = httpd_stop(s_server);
    if (err != ESP_OK) {
        ESP_LOGW(WEB_SERVER_TAG, "Failed to stop server (%s)", esp_err_to_name(err));
        g_module_status.web_status = ERROR;
        g_module_status.need_update = true;
        return;
    }

    s_server = NULL;
    ESP_LOGI(WEB_SERVER_TAG, "Settings server stopped");

    g_module_status.web_status = DISCONNECT;
    g_module_status.need_update = true;
}

bool web_server_is_running(void)
{
    return s_server != NULL;
}
