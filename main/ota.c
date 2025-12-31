#include "ota.h"

#include <string.h>

#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_https_ota.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#if CONFIG_MBEDTLS_CERTIFICATE_BUNDLE
#include "esp_crt_bundle.h"
#endif

#ifndef CONFIG_OTA_FIRMWARE_URL
#define CONFIG_OTA_FIRMWARE_URL ""
#endif

#define OTA_TASK_STACK_SIZE 8192
#define OTA_TASK_PRIORITY   5

static const char *TAG = "ota_task";
static TaskHandle_t s_ota_task;

static void ota_task(void *arg)
{
    (void)arg;

    const esp_http_client_config_t http_config = {
        .url = CONFIG_OTA_FIRMWARE_URL,
        .timeout_ms = 10000,
#if CONFIG_MBEDTLS_CERTIFICATE_BUNDLE
        .crt_bundle_attach = esp_crt_bundle_attach,
#endif
    };
    const esp_https_ota_config_t ota_config = {
        .http_config = &http_config,
    };

    ESP_LOGI(TAG, "Starting OTA from %s", CONFIG_OTA_FIRMWARE_URL);

    esp_err_t err = esp_https_ota(&ota_config);
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "OTA successful, restarting");
        vTaskDelay(pdMS_TO_TICKS(200));
        esp_restart();
    } else {
        ESP_LOGE(TAG, "OTA failed (%s)", esp_err_to_name(err));
    }

    s_ota_task = NULL;
    vTaskDelete(NULL);
}

void ota_start(void)
{
    if (s_ota_task != NULL) {
        ESP_LOGW(TAG, "OTA already running");
        return;
    }

    if (CONFIG_OTA_FIRMWARE_URL[0] == '\0') {
        ESP_LOGE(TAG, "OTA URL not configured (CONFIG_OTA_FIRMWARE_URL)");
        return;
    }

#if defined(CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP) && !CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP
    if (strncmp(CONFIG_OTA_FIRMWARE_URL, "http://", 7) == 0) {
        ESP_LOGE(TAG, "HTTP OTA disabled; use HTTPS or enable CONFIG_ESP_HTTPS_OTA_ALLOW_HTTP");
        return;
    }
#endif

    BaseType_t ok = xTaskCreate(ota_task, "ota_task", OTA_TASK_STACK_SIZE, NULL, OTA_TASK_PRIORITY, &s_ota_task);
    if (ok != pdPASS) {
        s_ota_task = NULL;
        ESP_LOGE(TAG, "Failed to start OTA task");
    }
}
