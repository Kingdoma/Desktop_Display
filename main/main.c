#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"
#include "display_driver.h"
#include "tinyusb_cdc.h"
#include "metrics.h"
#include "app_main.h"
#include "esp_task_wdt.h"
#include "ha_sync.h"
#include "time_sync.h"
#include "ha_ui.h"
#include "wifi.h"
#include "ha_settings.h"
#include "web_server.h"
// for benchmarking
// #include "lv_demos.h"

// for heap tracking
#include "esp_heap_task_info.h"

#define TAG "app_main"
#define HA_TOKEN_PLACEHOLDER "YOUR_LONG_LIVED_ACCESS_TOKEN"
#define HA_EXTRA_ENTITY_SLOTS 5
#define HA_MAX_ENTITY_SLOTS (5 + HA_EXTRA_ENTITY_SLOTS)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

app_module_status_t g_module_status = {
    .wifi_staus = DISCONNECT,
    .cdc_status = WAITING,
    .sntp_status = WAITING,
    .ha_status = WAITING,
    .web_status = DISCONNECT,
    .need_update = false
};

app_message_t g_msg_recv;
EventGroupHandle_t g_wifi_event_group;
const int CONNECTED_BIT = BIT0;
const int ESPTOUCH_DONE_BIT = BIT1;

lv_ui guider_ui;

static void lvgl_tick_cb(void *arg)
{
    lv_tick_inc(1);
}

static void ha_remote_state_sw(const char *state,
                               const char *last_changed,
                               bool has_temperature,
                               float temperature,
                               void *user_ctx)
{
    const char *entity_id = (const char *)user_ctx;
    if (!state) {
        return;
    }
    const char *ts = last_changed ? last_changed : "unknown";
    ESP_LOGI(TAG, "HA Switch state update: %s (changed %s)", state, ts);
    if (has_temperature) {
        ESP_LOGD(TAG, "HA Switch temperature: %.2f", temperature);
    }

    if (entity_id) {
        const ha_settings_t *settings = ha_settings_get();
        uint8_t lvgl_id = 1;
        if (settings && strcmp(entity_id, settings->entity_switch_2) == 0) {
            lvgl_id = 2;
        } else if (strcmp(entity_id, "switch.cuco_cn_959326664_v3_on_p_2_1") == 0) {
            lvgl_id = 1;
        }
        ha_ui_update_switch(lvgl_id, state, last_changed);
    }
}

static void ha_remote_state_ac(const char *state,
                               const char *last_changed,
                               bool has_temperature,
                               float temperature,
                               void *user_ctx)
{
    (void)user_ctx;
    if (!state) {
        return;
    }
    const char *ts = last_changed ? last_changed : "unknown";
    if (has_temperature) {
        ESP_LOGI(TAG, "HA AC state update: %s (changed %s, temp %.1f)", state, ts, temperature);
    } else {
        ESP_LOGI(TAG, "HA AC state update: %s (changed %s)", state, ts);
    }

    ha_ui_update_climate(0, temperature, state, last_changed);
}

static void ha_remote_state_weather(const char *state,
                                    const char *last_changed,
                                    bool has_temperature,
                                    float temperature,
                                    void *user_ctx)
{
    (void)user_ctx;
    if (!state) {
        return;
    }
    const char *ts = last_changed ? last_changed : "unknown";
    if (has_temperature) {
        ESP_LOGI(TAG, "HA weather state update: %s (changed %s, temp %.1f)", state, ts, temperature);
    } else {
        ESP_LOGI(TAG, "HA weather state update: %s (changed %s)", state, ts);
    }
    ha_ui_update_weather(temperature, state, last_changed);
}

static void ha_remote_state_generic(const char *state,
                                    const char *last_changed,
                                    bool has_temperature,
                                    float temperature,
                                    void *user_ctx)
{
    char *entity_id = (char *)user_ctx;
    if (!state || !entity_id) {
        return;
    }
    const char *ts = last_changed ? last_changed : "unknown";
    if (has_temperature) {
        ESP_LOGI(TAG, "HA state update (%s): %s (changed %s, temp %.1f)", entity_id, state, ts, temperature);
    } else {
        ESP_LOGI(TAG, "HA state update (%s): %s (changed %s)", entity_id, state, ts);
    }

    const char *delim = "_";
    char *token;

    char id[HA_SETTINGS_MAX_ENTITY_ID];

    strlcpy(id, entity_id, sizeof(id));

    token = strtok(id, delim);
    token = strtok(NULL, delim);
    if (!token) {
        return;
    }
    if(strcmp(token, "humidity") == 0)
    {
        ha_ui_update_sensor(state, last_changed, 1);
    }
    else if(strcmp(token, "temperature") == 0)
    {
        ha_ui_update_sensor(state, last_changed, 2);
    }
}

static void try_add_entity(ha_entity_config_t *entities,
                           size_t max_entities,
                           size_t *count,
                           const char *entity_id,
                           ha_state_cb_t cb)
{
    if (!entities || !count || !entity_id || entity_id[0] == '\0' || *count >= max_entities) {
        return;
    }
    entities[*count].entity_id = entity_id;
    entities[*count].on_remote_state = cb;
    entities[*count].user_ctx = (void *)entity_id;
    (*count)++;
}

static void start_ha_sync(void)
{
    const ha_settings_t *settings = ha_settings_get();
    if (!CONFIG_HA_SYNC_ENABLE) {
        ESP_LOGI(TAG, "HA sync disabled (CONFIG_HA_SYNC_ENABLE=n)");

        g_module_status.ha_status = ERROR;
        g_module_status.need_update = true;

        return;
    }

    if (strlen(settings->base_url) == 0) {
        ESP_LOGW(TAG, "HA sync disabled: CONFIG_HA_BASE_URL is empty");

        g_module_status.ha_status = ERROR;
        g_module_status.need_update = true;

        return;
    }

    if (strlen(settings->auth_token) == 0 || strcmp(settings->auth_token, HA_TOKEN_PLACEHOLDER) == 0) {
        ESP_LOGW(TAG, "HA sync disabled: set CONFIG_HA_AUTH_TOKEN to your long-lived access token");
        
        g_module_status.ha_status = ERROR;
        g_module_status.need_update = true;

        return;
    }

    ha_entity_config_t entities[HA_MAX_ENTITY_SLOTS];
    size_t entity_count = 0;

    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, settings->entity_switch_1, ha_remote_state_sw);
    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, settings->entity_switch_2, ha_remote_state_sw);

    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, settings->entity_ac, ha_remote_state_ac);
    
    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, settings->entity_weather, ha_remote_state_weather);

    for (size_t i = 0; i < HA_SETTINGS_EXTRA_COUNT; ++i) {
        try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, settings->entity_extra[i], ha_remote_state_generic);
    }

    if (entity_count == 0) {
        ESP_LOGW(TAG, "HA sync disabled: no entities configured");
        return;
    }

    ha_sync_config_t cfg = {
        .base_url = settings->base_url,
        .auth_token = settings->auth_token,
        .poll_interval_ms = settings->poll_interval_ms,
        .entities = entities,
        .entity_count = entity_count,
    };

    esp_err_t err = ha_sync_start(&cfg);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to start HA sync: %s", esp_err_to_name(err));

        g_module_status.ha_status = ERROR;
        g_module_status.need_update = true;
        
    }
}

static void lvgl_task(void *arg)
{
    ESP_LOGI(TAG, "Initialize LVGL");
    lv_init();

    ESP_ERROR_CHECK(display_driver_init(NULL));

    const esp_timer_create_args_t tick_timer_args = {
        .callback = lvgl_tick_cb,
        .name = "lvgl_tick",
    };
    esp_timer_handle_t tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&tick_timer_args, &tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(tick_timer, 1000)); // 1 ms tick

    setup_ui(&guider_ui);
    custom_init(&guider_ui);
    ha_ui_set_ui(&guider_ui);

    vTaskDelay(pdMS_TO_TICKS(20));

    ESP_ERROR_CHECK(display_enable_backlight());

    metrics_queue_init();

    system_metrics_t latest_metrics = {0};
    latest_metrics.day_of_week = -1;
    TickType_t last_time_update = xTaskGetTickCount();
    bool needs_ui_update = update_wall_clock(&latest_metrics);
    esp_err_t wdt_err = esp_task_wdt_add(NULL);
    if (wdt_err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to add LVGL task to WDT (%s)", esp_err_to_name(wdt_err));
    }

    // lv_demo_benchmark();

    while (1) {
        // time data need update
        const TickType_t now = xTaskGetTickCount();
        if ((now - last_time_update) >= pdMS_TO_TICKS(1000)) {
            if (update_wall_clock(&latest_metrics)) {
                needs_ui_update = true;
            }
            last_time_update = now;
        }

        // pc info need update
        if (metrics_queue_pop(&latest_metrics)) {
            needs_ui_update = true;
        }

        // ha info need update
        if (sync_data->update == true){
            sync_data->update = false;
            needs_ui_update = true;
        }

        // setting info need update
        if (g_module_status.need_update) {
            needs_ui_update = true;
        }

        // If at Monitor panel then update the metrics and time
        if (screen_is_active(guider_ui.Monitor_dark) && needs_ui_update) {
            monitor_panel_update(&guider_ui, &latest_metrics);
            needs_ui_update = false;
        }
        // If at HA panel then update the homeassistant entry data and time
        else if (screen_is_active(guider_ui.HA_dark) && needs_ui_update) {
            ha_panel_update(&guider_ui, &latest_metrics);
            needs_ui_update = false;
        }
        else if (screen_is_active(guider_ui.Setting_dark) && needs_ui_update){
            setting_panel_update(&guider_ui);
            needs_ui_update = false;
        }

        lv_timer_handler();
        if (wdt_err == ESP_OK) {
            esp_task_wdt_reset();
        }

        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

static void cdc_task(void *arg)
{
    ESP_LOGI(TAG, "Initialize tinyusb cdc");
    ESP_ERROR_CHECK(tinyusb_cdc_driver_init());

    g_module_status.cdc_status = READY;
    g_module_status.need_update = true;

    const TickType_t delay = pdMS_TO_TICKS(10);
    while (1) {
        tinyusb_cdc_rec();
        vTaskDelay(delay);
    }
}

void app_main(void)
{
    ha_ui_sync_data_init();

    ha_settings_init();

    wifi_connect();

    // web_server_start();

    xTaskCreate(lvgl_task, "lvgl_task", 4096, NULL, 2, NULL);

    xTaskCreate(sntp_task, "sntp_task", 4096, NULL, 2, NULL);

    xTaskCreate(cdc_task, "cdc_task", 4096, NULL, 2, NULL);

    start_ha_sync();

    // heap_caps_print_all_task_stat_overview(stdout);

    ESP_LOGI(TAG, "LVGL task started");
}
