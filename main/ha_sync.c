#include "ha_sync.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "mqtt_client.h"

#define TAG "ha_sync"
#define HA_STATE_QUEUE_LEN 4

typedef struct {
    const char *temp_state;
    const char *hum_state;
    const char *switch1_state;
    const char *switch1_cmd;
    const char *switch2_state;
    const char *switch2_cmd;
    const char *climate_mode_state;
    const char *climate_mode_cmd;
    const char *climate_temp_state;
    const char *climate_temp_cmd;
    const char *printer_state;
    const char *printer_cmd;
} ha_topics_t;

static const ha_topics_t s_topics = {
    .temp_state = CONFIG_HA_MQTT_TEMP_STATE_TOPIC,
    .hum_state = CONFIG_HA_MQTT_HUM_STATE_TOPIC,
    .switch1_state = CONFIG_HA_MQTT_SWITCH1_STATE_TOPIC,
    .switch1_cmd = CONFIG_HA_MQTT_SWITCH1_COMMAND_TOPIC,
    .switch2_state = CONFIG_HA_MQTT_SWITCH2_STATE_TOPIC,
    .switch2_cmd = CONFIG_HA_MQTT_SWITCH2_COMMAND_TOPIC,
    .climate_mode_state = CONFIG_HA_MQTT_CLIMATE_MODE_STATE_TOPIC,
    .climate_mode_cmd = CONFIG_HA_MQTT_CLIMATE_MODE_COMMAND_TOPIC,
    .climate_temp_state = CONFIG_HA_MQTT_CLIMATE_TEMP_STATE_TOPIC,
    .climate_temp_cmd = CONFIG_HA_MQTT_CLIMATE_TEMP_COMMAND_TOPIC,
    .printer_state = CONFIG_HA_MQTT_PRINTER_STATE_TOPIC,
    .printer_cmd = CONFIG_HA_MQTT_PRINTER_COMMAND_TOPIC,
};

static esp_mqtt_client_handle_t s_client;
static QueueHandle_t s_state_queue;
static ha_state_t s_state;
static bool s_started;
static bool s_task_started;
static TaskHandle_t s_task_handle;

static inline bool topic_valid(const char *topic)
{
    return topic && topic[0] != '\0';
}

static void ensure_queue(void)
{
    if (!s_state_queue) {
        s_state_queue = xQueueCreate(HA_STATE_QUEUE_LEN, sizeof(ha_state_t));
    }
}

static void push_state_update(void)
{
    ensure_queue();
    if (!s_state_queue) {
        return;
    }

    if (xQueueSend(s_state_queue, &s_state, 0) == pdPASS) {
        return;
    }
    ha_state_t dropped;
    (void)xQueueReceive(s_state_queue, &dropped, 0);
    (void)xQueueSend(s_state_queue, &s_state, 0);
}

static bool topic_equals(const char *topic, int topic_len, const char *ref)
{
    if (!topic_valid(topic) || !topic_valid(ref)) {
        return false;
    }

    const size_t ref_len = strlen(ref);
    return (size_t)topic_len == ref_len && memcmp(topic, ref, ref_len) == 0;
}

static void copy_payload(char *dst, size_t dst_size, const char *data, int data_len)
{
    if (!dst || dst_size == 0) {
        return;
    }

    if (!data || data_len <= 0) {
        dst[0] = '\0';
        return;
    }

    const size_t copy_len = (data_len >= (int)dst_size) ? dst_size - 1 : (size_t)data_len;
    memcpy(dst, data, copy_len);
    dst[copy_len] = '\0';
}

static bool parse_on_off(const char *payload, bool *ok)
{
    if (ok) {
        *ok = false;
    }
    if (!payload) {
        return false;
    }

    if (strcasecmp(payload, "on") == 0 || strcmp(payload, "1") == 0 || strcasecmp(payload, "true") == 0) {
        if (ok) {
            *ok = true;
        }
        return true;
    }
    if (strcasecmp(payload, "off") == 0 || strcmp(payload, "0") == 0 || strcasecmp(payload, "false") == 0) {
        if (ok) {
            *ok = true;
        }
        return false;
    }
    return false;
}

static bool parse_float(const char *payload, float *out)
{
    if (!payload || !out) {
        return false;
    }

    char *endptr = NULL;
    const float value = strtof(payload, &endptr);
    if (endptr == payload) {
        return false;
    }
    *out = value;
    return true;
}

static bool parse_mode(const char *payload, ha_climate_mode_t *out_mode)
{
    if (!payload || !out_mode) {
        return false;
    }

    if (strcasecmp(payload, "off") == 0) {
        *out_mode = HA_CLIMATE_MODE_OFF;
        return true;
    }
    if (strcasecmp(payload, "cool") == 0) {
        *out_mode = HA_CLIMATE_MODE_COOL;
        return true;
    }
    if (strcasecmp(payload, "heat") == 0) {
        *out_mode = HA_CLIMATE_MODE_HEAT;
        return true;
    }
    return false;
}

static void handle_state_message(const char *topic, int topic_len, const char *data, int data_len)
{
    char payload[64];
    copy_payload(payload, sizeof(payload), data, data_len);

    bool updated = false;

    if (topic_equals(topic, topic_len, s_topics.temp_state)) {
        float value = 0.0f;
        if (parse_float(payload, &value)) {
            s_state.temperature_c = value;
            s_state.has_temperature = true;
            updated = true;
        }
    } else if (topic_equals(topic, topic_len, s_topics.hum_state)) {
        float value = 0.0f;
        if (parse_float(payload, &value)) {
            s_state.humidity_percent = value;
            s_state.has_humidity = true;
            updated = true;
        }
    } else if (topic_equals(topic, topic_len, s_topics.switch1_state)) {
        bool ok = false;
        const bool on = parse_on_off(payload, &ok);
        if (ok) {
            s_state.switch1_on = on;
            s_state.has_switch1 = true;
            updated = true;
        }
    } else if (topic_equals(topic, topic_len, s_topics.switch2_state)) {
        bool ok = false;
        const bool on = parse_on_off(payload, &ok);
        if (ok) {
            s_state.switch2_on = on;
            s_state.has_switch2 = true;
            updated = true;
        }
    } else if (topic_equals(topic, topic_len, s_topics.climate_mode_state)) {
        ha_climate_mode_t mode = HA_CLIMATE_MODE_OFF;
        if (parse_mode(payload, &mode)) {
            s_state.climate_mode = mode;
            s_state.has_climate_mode = true;
            updated = true;
        }
    } else if (topic_equals(topic, topic_len, s_topics.climate_temp_state)) {
        float value = 0.0f;
        if (parse_float(payload, &value)) {
            s_state.target_temp_c = value;
            s_state.has_target_temp = true;
            updated = true;
        }
    } else if (topic_equals(topic, topic_len, s_topics.printer_state)) {
        float value = 0.0f;
        if (parse_float(payload, &value)) {
            s_state.printer_progress = value;
            s_state.has_printer_progress = true;
            updated = true;
        }
    }

    if (updated) {
        push_state_update();
    }
}

static void subscribe_topics(void)
{
    if (!s_client) {
        return;
    }

    if (topic_valid(s_topics.temp_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.temp_state, 1);
    }
    if (topic_valid(s_topics.hum_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.hum_state, 1);
    }
    if (topic_valid(s_topics.switch1_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.switch1_state, 1);
    }
    if (topic_valid(s_topics.switch2_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.switch2_state, 1);
    }
    if (topic_valid(s_topics.climate_mode_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.climate_mode_state, 1);
    }
    if (topic_valid(s_topics.climate_temp_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.climate_temp_state, 1);
    }
    if (topic_valid(s_topics.printer_state)) {
        esp_mqtt_client_subscribe(s_client, s_topics.printer_state, 1);
    }
}

static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    (void)handler_args;
    (void)base;
    esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t)event_data;

    switch ((esp_mqtt_event_id_t)event_id) {
    case MQTT_EVENT_CONNECTED:
        ESP_LOGI(TAG, "MQTT connected");
        s_state.mqtt_connected = true;
        push_state_update();
        subscribe_topics();
        break;
    case MQTT_EVENT_DISCONNECTED:
        ESP_LOGW(TAG, "MQTT disconnected");
        s_state.mqtt_connected = false;
        push_state_update();
        break;
    case MQTT_EVENT_DATA:
        handle_state_message(event->topic, event->topic_len, event->data, event->data_len);
        break;
    default:
        break;
    }
}

void ha_sync_start(void)
{
    if (s_started) {
        return;
    }
    s_started = true;

    if (!CONFIG_HA_MQTT_ENABLE) {
        ESP_LOGI(TAG, "Home Assistant MQTT sync disabled");
        return;
    }

    if (!topic_valid(CONFIG_HA_MQTT_BROKER_URI)) {
        ESP_LOGW(TAG, "MQTT broker URI is empty; skipping HA sync");
        return;
    }

    ensure_queue();

    const esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = CONFIG_HA_MQTT_BROKER_URI,
        .credentials.username = CONFIG_HA_MQTT_USERNAME,
        .credentials.authentication.password = CONFIG_HA_MQTT_PASSWORD,
    };

    s_client = esp_mqtt_client_init(&mqtt_cfg);
    if (!s_client) {
        ESP_LOGE(TAG, "Failed to init MQTT client");
        return;
    }

    esp_mqtt_client_register_event(s_client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    const esp_err_t err = esp_mqtt_client_start(s_client);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start MQTT client (%s)", esp_err_to_name(err));
    }
}

static void ha_sync_task(void *arg)
{
    (void)arg;
    ha_sync_start();
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void ha_sync_task_start(void)
{
    if (s_task_started) {
        return;
    }
    s_task_started = true;
    const BaseType_t rc = xTaskCreate(ha_sync_task, "ha_sync", 4096, NULL, 4, &s_task_handle);
    if (rc != pdPASS) {
        ESP_LOGE(TAG, "Failed to create ha_sync task");
        s_task_started = false;
    }
}

bool ha_sync_state_pop(ha_state_t *out)
{
    if (!out) {
        return false;
    }

    ensure_queue();
    if (!s_state_queue) {
        return false;
    }

    return xQueueReceive(s_state_queue, out, 0) == pdPASS;
}

static esp_err_t publish_simple(const char *topic, const char *payload)
{
    if (!s_client) {
        return ESP_ERR_INVALID_STATE;
    }
    if (!topic_valid(topic) || !payload) {
        return ESP_ERR_INVALID_ARG;
    }

    const int msg_id = esp_mqtt_client_publish(s_client, topic, payload, 0, 1, 0);
    if (msg_id < 0) {
        return ESP_FAIL;
    }
    return ESP_OK;
}

esp_err_t ha_sync_publish_switch(uint8_t index, bool on)
{
    const char *topic = NULL;
    if (index == 1) {
        topic = s_topics.switch1_cmd;
    } else if (index == 2) {
        topic = s_topics.switch2_cmd;
    }

    if (!topic_valid(topic)) {
        ESP_LOGW(TAG, "Switch %u command topic not set", (unsigned)index);
        return ESP_ERR_INVALID_ARG;
    }

    return publish_simple(topic, on ? "ON" : "OFF");
}

esp_err_t ha_sync_publish_climate_mode(ha_climate_mode_t mode)
{
    const char *topic = s_topics.climate_mode_cmd;
    if (!topic_valid(topic)) {
        ESP_LOGW(TAG, "Climate mode command topic not set");
        return ESP_ERR_INVALID_ARG;
    }

    const char *payload = "off";
    switch (mode) {
    case HA_CLIMATE_MODE_COOL:
        payload = "cool";
        break;
    case HA_CLIMATE_MODE_HEAT:
        payload = "heat";
        break;
    case HA_CLIMATE_MODE_OFF:
    default:
        payload = "off";
        break;
    }

    return publish_simple(topic, payload);
}

esp_err_t ha_sync_publish_climate_temp(float temp_c)
{
    const char *topic = s_topics.climate_temp_cmd;
    if (!topic_valid(topic)) {
        ESP_LOGW(TAG, "Climate temp command topic not set");
        return ESP_ERR_INVALID_ARG;
    }

    char payload[16];
    snprintf(payload, sizeof(payload), "%.1f", temp_c);
    return publish_simple(topic, payload);
}

esp_err_t ha_sync_publish_printer_progress(float progress)
{
    const char *topic = s_topics.printer_cmd;
    if (!topic_valid(topic)) {
        ESP_LOGW(TAG, "Printer command topic not set");
        return ESP_ERR_INVALID_ARG;
    }

    if (progress < 0.0f) {
        progress = 0.0f;
    } else if (progress > 100.0f) {
        progress = 100.0f;
    }

    char payload[16];
    snprintf(payload, sizeof(payload), "%.1f", progress);
    return publish_simple(topic, payload);
}
