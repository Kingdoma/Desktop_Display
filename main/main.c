#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_sntp.h"
#include "esp_netif_sntp.h"
#include "protocol_examples_common.h"
#include "nvs_flash.h"
#include "lvgl.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"
#include "display_driver.h"
#include "tinyusb_cdc.h"
#include "metrics.h"
#include "app_main.h"
#include "esp_task_wdt.h"
#include "ha_sync.h"

#define TAG "app_main"
#define HA_TOKEN_PLACEHOLDER "YOUR_LONG_LIVED_ACCESS_TOKEN"
#define HA_EXTRA_ENTITY_SLOTS 5
#define HA_MAX_ENTITY_SLOTS (5 + HA_EXTRA_ENTITY_SLOTS)
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

lv_ui guider_ui;

static void lvgl_tick_cb(void *arg)
{
    lv_tick_inc(1);
}

static void time_sync_notification_cb(struct timeval *tv)
{
    ESP_LOGI(TAG, "SNTP time synchronized");
}

static void sntp_time_sync(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");

    ESP_ERROR_CHECK(nvs_flash_init());

    esp_err_t err = esp_netif_init();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_LOGE(TAG, "esp_netif_init failed: %s", esp_err_to_name(err));
        return;
    }

    err = esp_event_loop_create_default();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_LOGE(TAG, "esp_event_loop_create_default failed: %s", esp_err_to_name(err));
        return;
    }

    // connect to internet
    err = example_connect();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_LOGE(TAG, "esp_wifi_connect failed: %s", esp_err_to_name(err));
        return;
    }

    esp_sntp_config_t config = ESP_NETIF_SNTP_DEFAULT_CONFIG("pool.ntp.org");
    config.sync_cb = time_sync_notification_cb;
    esp_netif_sntp_init(&config);

    // wait for time to be set
    int retry = 0;
    const int retry_count = 15;
    while (esp_netif_sntp_sync_wait(2000 / portTICK_PERIOD_MS) == ESP_ERR_TIMEOUT && ++retry < retry_count) {
        ESP_LOGI(TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
    }

    esp_netif_sntp_deinit();
}

static bool update_wall_clock(system_metrics_t *metrics)
{
    if (!metrics) {
        return false;
    }

    time_t now = 0;
    struct tm timeinfo = {0};
    time(&now);

    /* Bail out if SNTP has not set the time yet */
    if (now < 1609459200) { // 2021-01-01
        return false;
    }

    if (!localtime_r(&now, &timeinfo)) {
        return false;
    }

    const uint16_t year = (uint16_t)(timeinfo.tm_year + 1900);
    const uint8_t month = (uint8_t)(timeinfo.tm_mon + 1);
    const uint8_t day = (uint8_t)timeinfo.tm_mday;
    const uint8_t hour = (uint8_t)timeinfo.tm_hour;
    const uint8_t minute = (uint8_t)timeinfo.tm_min;
    const uint8_t second = (uint8_t)timeinfo.tm_sec;
    const int8_t day_of_week = (int8_t)timeinfo.tm_wday;

    bool changed = false;
    changed |= !metrics->has_date || metrics->year != year || metrics->month != month || metrics->day != day;
    changed |= !metrics->has_time || metrics->hour != hour || metrics->minute != minute || metrics->second != second;
    changed |= !metrics->has_day_of_week || metrics->day_of_week != day_of_week;

    metrics->year = year;
    metrics->month = month;
    metrics->day = day;
    metrics->hour = hour;
    metrics->minute = minute;
    metrics->second = second;
    metrics->day_of_week = day_of_week;
    metrics->has_date = true;
    metrics->has_time = true;
    metrics->has_day_of_week = true;

    ESP_LOGD(TAG, "Y:%d,M:%d,D:%d,H:%d,M:%d,S:%d,WD:%d,HD:%d,HT:%d,HWD:%d",
        year, month, day, hour, minute, second, day_of_week, metrics->has_date, metrics->has_time, metrics->has_day_of_week);

    return changed;
}

static void sntp_task(void *arg)
{
    ESP_LOGI(TAG, "Initialize sntp sync");
    setenv("TZ", "CST-8", 1);
    tzset();
    sntp_time_sync();
    vTaskDelete(NULL);
}

static void ha_remote_state_sw(const char *state, void *user_ctx)
{
    (void)user_ctx;
    if (!state) {
        return;
    }
    ESP_LOGI(TAG, "HA Switch state update: %s", state);
    // TODO: apply to local light/relay.
}

static void ha_remote_state_ac(const char *state, void *user_ctx)
{
    (void)user_ctx;
    if (!state) {
        return;
    }
    ESP_LOGI(TAG, "HA AC state update: %s", state);
    // TODO: apply to local fan control.
}

static void ha_remote_state_weather(const char *state, void *user_ctx)
{
    (void)user_ctx;
    if (!state) {
        return;
    }
    ESP_LOGI(TAG, "HA weather state update: %s", state);
    // TODO: apply to local fan control.
}

static void ha_remote_state_generic(const char *state, void *user_ctx)
{
    const char *entity_id = (const char *)user_ctx;
    if (!state || !entity_id) {
        return;
    }
    ESP_LOGI(TAG, "HA state update (%s): %s", entity_id, state);
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
    if (!CONFIG_HA_SYNC_ENABLE) {
        ESP_LOGI(TAG, "HA sync disabled (CONFIG_HA_SYNC_ENABLE=n)");
        return;
    }

    if (strlen(CONFIG_HA_BASE_URL) == 0) {
        ESP_LOGW(TAG, "HA sync disabled: CONFIG_HA_BASE_URL is empty");
        return;
    }

    if (strlen(CONFIG_HA_AUTH_TOKEN) == 0 || strcmp(CONFIG_HA_AUTH_TOKEN, HA_TOKEN_PLACEHOLDER) == 0) {
        ESP_LOGW(TAG, "HA sync disabled: set CONFIG_HA_AUTH_TOKEN to your long-lived access token");
        return;
    }

    ha_entity_config_t entities[HA_MAX_ENTITY_SLOTS];
    size_t entity_count = 0;

    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, CONFIG_HA_ENTITY_ID_SWITCH_1, ha_remote_state_sw);
    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, CONFIG_HA_ENTITY_ID_SWITCH_2, ha_remote_state_sw);

    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, CONFIG_HA_ENTITY_ID_AC, ha_remote_state_ac);
    
    try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, CONFIG_HA_ENTITY_ID_WEATHER, ha_remote_state_weather);

    const char *extra_entities[] = {
        CONFIG_HA_ENTITY_ID_1,
        CONFIG_HA_ENTITY_ID_2,
        CONFIG_HA_ENTITY_ID_3,
        CONFIG_HA_ENTITY_ID_4,
        CONFIG_HA_ENTITY_ID_5,
    };

    for (size_t i = 0; i < ARRAY_SIZE(extra_entities); ++i) {
        try_add_entity(entities, HA_MAX_ENTITY_SLOTS, &entity_count, extra_entities[i], ha_remote_state_generic);
    }

    if (entity_count == 0) {
        ESP_LOGW(TAG, "HA sync disabled: no entities configured");
        return;
    }

    ha_sync_config_t cfg = {
        .base_url = CONFIG_HA_BASE_URL,
        .auth_token = CONFIG_HA_AUTH_TOKEN,
        .poll_interval_ms = (uint32_t)CONFIG_HA_POLL_INTERVAL_MS,
        .entities = entities,
        .entity_count = entity_count,
    };

    esp_err_t err = ha_sync_start(&cfg);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to start HA sync: %s", esp_err_to_name(err));
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

    while (1) {
        while (metrics_queue_pop(&latest_metrics)) {
            needs_ui_update = true;
        }

        const TickType_t now = xTaskGetTickCount();
        if ((now - last_time_update) >= pdMS_TO_TICKS(1000)) {
            if (update_wall_clock(&latest_metrics)) {
                needs_ui_update = true;
            }
            last_time_update = now;
        }

        if (needs_ui_update) {
            custom_update_metrics(&guider_ui, &latest_metrics);
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

    const TickType_t delay = pdMS_TO_TICKS(10);
    while (1) {
        tinyusb_cdc_rec();
        vTaskDelay(delay);
    }
}

void app_main(void)
{
    // SNTP sync performs networking and logging; give it a real stack to avoid corruption.
    xTaskCreate(sntp_task, "sntp_task", 4096, NULL, 2, NULL);

    xTaskCreate(lvgl_task, "lvgl_task", 4096, NULL, 2, NULL);

    xTaskCreate(cdc_task, "cdc_task", 4096, NULL, 2, NULL);

    start_ha_sync();

    ESP_LOGI(TAG, "LVGL task started");
}
