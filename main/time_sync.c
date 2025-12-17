#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "esp_netif_sntp.h"
#include "nvs_flash.h"
#include "protocol_examples_common.h"
#include "time_sync.h"

#define TIME_SYNC_TAG "time_sync"

static void time_sync_notification_cb(struct timeval *tv)
{
    (void)tv;
    ESP_LOGI(TIME_SYNC_TAG, "SNTP time synchronized");
}

static void sntp_time_sync(void)
{
    ESP_LOGI(TIME_SYNC_TAG, "Initializing SNTP");

    ESP_ERROR_CHECK(nvs_flash_init());

    esp_err_t err = esp_netif_init();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_LOGE(TIME_SYNC_TAG, "esp_netif_init failed: %s", esp_err_to_name(err));
        return;
    }

    err = esp_event_loop_create_default();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_LOGE(TIME_SYNC_TAG, "esp_event_loop_create_default failed: %s", esp_err_to_name(err));
        return;
    }

    // connect to internet
    err = example_connect();
    if (err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_LOGE(TIME_SYNC_TAG, "esp_wifi_connect failed: %s", esp_err_to_name(err));
        return;
    }

    esp_sntp_config_t config = ESP_NETIF_SNTP_DEFAULT_CONFIG("pool.ntp.org");
    config.sync_cb = time_sync_notification_cb;
    esp_netif_sntp_init(&config);

    // wait for time to be set
    int retry = 0;
    const int retry_count = 15;
    while (esp_netif_sntp_sync_wait(2000 / portTICK_PERIOD_MS) == ESP_ERR_TIMEOUT && ++retry < retry_count) {
        ESP_LOGI(TIME_SYNC_TAG, "Waiting for system time to be set... (%d/%d)", retry, retry_count);
    }

    esp_netif_sntp_deinit();
}

void sntp_task(void *arg)
{
    (void)arg;
    ESP_LOGI(TIME_SYNC_TAG, "Start SNTP sync task");
    setenv("TZ", "CST-8", 1);
    tzset();
    sntp_time_sync();
    vTaskDelete(NULL);
}

bool update_wall_clock(system_metrics_t *metrics)
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

    ESP_LOGD(TIME_SYNC_TAG, "Y:%d,M:%d,D:%d,H:%d,M:%d,S:%d,WD:%d,HD:%d,HT:%d,HWD:%d",
        year, month, day, hour, minute, second, day_of_week, metrics->has_date, metrics->has_time, metrics->has_day_of_week);

    return changed;
}
