#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_sntp.h"
#include "lvgl.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"
#include "display_driver.h"
#include "tinyusb_cdc.h"
#include "metrics.h"
#include "app_main.h"
#include "esp_task_wdt.h"

#define TAG "app_main"

lv_ui guider_ui;

static void lvgl_tick_cb(void *arg)
{
    lv_tick_inc(1);
}

static void time_sync_notification_cb(struct timeval *tv)
{
    ESP_LOGI(TAG, "SNTP time synchronized");
}

static void initialize_sntp(void)
{
    ESP_LOGI(TAG, "Initializing SNTP");

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

    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    esp_sntp_setservername(0, "pool.ntp.org");
    esp_sntp_set_time_sync_notification_cb(time_sync_notification_cb);
    esp_sntp_init();
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

    return changed;
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
        esp_task_wdt_reset();
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
    initialize_sntp();

    // ESP_LOGI(TAG, "Initialize LVGL");
    // lv_init();

    // ESP_ERROR_CHECK(display_driver_init(NULL));

    // const esp_timer_create_args_t tick_timer_args = {
    //     .callback = lvgl_tick_cb,
    //     .name = "lvgl_tick",
    // };
    // esp_timer_handle_t tick_timer = NULL;
    // ESP_ERROR_CHECK(esp_timer_create(&tick_timer_args, &tick_timer));
    // ESP_ERROR_CHECK(esp_timer_start_periodic(tick_timer, 1000)); // 1 ms tick

    // setup_ui(&guider_ui);
    // custom_init(&guider_ui);

    // vTaskDelay(pdMS_TO_TICKS(100));

    xTaskCreate(lvgl_task, "lvgl_task", 4096, NULL, 2, NULL);

    xTaskCreate(cdc_task, "cdc_task", 4096, NULL, 2, NULL);

    ESP_LOGI(TAG, "LVGL task started");
}
