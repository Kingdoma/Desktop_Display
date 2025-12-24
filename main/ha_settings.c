#include "ha_settings.h"
#include <stdio.h>
#include <string.h>
#include "esp_err.h"
#include "esp_log.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "sdkconfig.h"

#define HA_SETTINGS_TAG "ha_settings"
#define HA_SETTINGS_NAMESPACE "ha_cfg"
#define HA_SETTINGS_PARTITION "app_nvs"
#define HA_SETTINGS_DEFAULT_SNTP_SERVER "pool.ntp.org"
#define HA_SETTINGS_DEFAULT_TIME_ZONE "CST-8"

static ha_settings_t g_settings;

static void settings_set_defaults(ha_settings_t *settings)
{
    if (!settings) {
        return;
    }

    strlcpy(settings->base_url, CONFIG_HA_BASE_URL, sizeof(settings->base_url));
    strlcpy(settings->auth_token, CONFIG_HA_AUTH_TOKEN, sizeof(settings->auth_token));
    settings->poll_interval_ms = (uint32_t)CONFIG_HA_POLL_INTERVAL_MS;
    strlcpy(settings->sntp_server, HA_SETTINGS_DEFAULT_SNTP_SERVER, sizeof(settings->sntp_server));
    strlcpy(settings->time_zone, HA_SETTINGS_DEFAULT_TIME_ZONE, sizeof(settings->time_zone));
    strlcpy(settings->entity_switch_1, CONFIG_HA_ENTITY_ID_SWITCH_1, sizeof(settings->entity_switch_1));
    strlcpy(settings->entity_switch_2, CONFIG_HA_ENTITY_ID_SWITCH_2, sizeof(settings->entity_switch_2));
    strlcpy(settings->entity_ac, CONFIG_HA_ENTITY_ID_AC, sizeof(settings->entity_ac));
    strlcpy(settings->entity_weather, CONFIG_HA_ENTITY_ID_WEATHER, sizeof(settings->entity_weather));
    strlcpy(settings->entity_extra[0], CONFIG_HA_ENTITY_ID_1, sizeof(settings->entity_extra[0]));
    strlcpy(settings->entity_extra[1], CONFIG_HA_ENTITY_ID_2, sizeof(settings->entity_extra[1]));
    strlcpy(settings->entity_extra[2], CONFIG_HA_ENTITY_ID_3, sizeof(settings->entity_extra[2]));
    strlcpy(settings->entity_extra[3], CONFIG_HA_ENTITY_ID_4, sizeof(settings->entity_extra[3]));
    strlcpy(settings->entity_extra[4], CONFIG_HA_ENTITY_ID_5, sizeof(settings->entity_extra[4]));
}

static void settings_load_from_nvs(ha_settings_t *settings)
{
    nvs_handle_t nvs;
    esp_err_t err = nvs_open_from_partition(HA_SETTINGS_PARTITION,
                                            HA_SETTINGS_NAMESPACE,
                                            NVS_READONLY,
                                            &nvs);
    if (err != ESP_OK) {
        if (err != ESP_ERR_NVS_NOT_FOUND) {
            ESP_LOGW(HA_SETTINGS_TAG, "Failed to open NVS (%s)", esp_err_to_name(err));
        }
        return;
    }

    size_t len = sizeof(settings->base_url);
    err = nvs_get_str(nvs, "base_url", settings->base_url, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read base_url (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->auth_token);
    err = nvs_get_str(nvs, "auth_token", settings->auth_token, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read auth_token (%s)", esp_err_to_name(err));
    }

    uint32_t poll_ms = 0;
    err = nvs_get_u32(nvs, "poll_ms", &poll_ms);
    if (err == ESP_OK) {
        settings->poll_interval_ms = poll_ms;
    } else if (err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read poll_ms (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->sntp_server);
    err = nvs_get_str(nvs, "sntp_server", settings->sntp_server, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read sntp_server (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->time_zone);
    err = nvs_get_str(nvs, "time_zone", settings->time_zone, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read time_zone (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->entity_switch_1);
    err = nvs_get_str(nvs, "sw1", settings->entity_switch_1, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read sw1 (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->entity_switch_2);
    err = nvs_get_str(nvs, "sw2", settings->entity_switch_2, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read sw2 (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->entity_ac);
    err = nvs_get_str(nvs, "ac", settings->entity_ac, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read ac (%s)", esp_err_to_name(err));
    }

    len = sizeof(settings->entity_weather);
    err = nvs_get_str(nvs, "weather", settings->entity_weather, &len);
    if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to read weather (%s)", esp_err_to_name(err));
    }

    for (size_t i = 0; i < HA_SETTINGS_EXTRA_COUNT; ++i) {
        char key[8];
        snprintf(key, sizeof(key), "extra%u", (unsigned)(i + 1));
        len = sizeof(settings->entity_extra[i]);
        err = nvs_get_str(nvs, key, settings->entity_extra[i], &len);
        if (err != ESP_OK && err != ESP_ERR_NVS_NOT_FOUND) {
            ESP_LOGW(HA_SETTINGS_TAG, "Failed to read %s (%s)", key, esp_err_to_name(err));
        }
    }

    nvs_close(nvs);
}

void ha_settings_init(void)
{
    settings_set_defaults(&g_settings);

    esp_err_t err = nvs_flash_init_partition(HA_SETTINGS_PARTITION);
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase_partition(HA_SETTINGS_PARTITION));
        err = nvs_flash_init_partition(HA_SETTINGS_PARTITION);
    }
    if (err != ESP_OK && err != ESP_ERR_NVS_INVALID_STATE) {
        ESP_LOGW(HA_SETTINGS_TAG, "NVS init failed (%s)", esp_err_to_name(err));
        return;
    }

    settings_load_from_nvs(&g_settings);
}

const ha_settings_t *ha_settings_get(void)
{
    return &g_settings;
}

bool ha_settings_save(const ha_settings_t *settings)
{
    if (!settings) {
        return false;
    }

    nvs_handle_t nvs;
    esp_err_t err = nvs_open_from_partition(HA_SETTINGS_PARTITION,
                                            HA_SETTINGS_NAMESPACE,
                                            NVS_READWRITE,
                                            &nvs);
    if (err != ESP_OK) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to open NVS for write (%s)", esp_err_to_name(err));
        return false;
    }

    err = nvs_set_str(nvs, "base_url", settings->base_url);
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "auth_token", settings->auth_token);
    }
    if (err == ESP_OK) {
        err = nvs_set_u32(nvs, "poll_ms", settings->poll_interval_ms);
    }
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "sntp_server", settings->sntp_server);
    }
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "time_zone", settings->time_zone);
    }
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "sw1", settings->entity_switch_1);
    }
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "sw2", settings->entity_switch_2);
    }
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "ac", settings->entity_ac);
    }
    if (err == ESP_OK) {
        err = nvs_set_str(nvs, "weather", settings->entity_weather);
    }
    for (size_t i = 0; i < HA_SETTINGS_EXTRA_COUNT && err == ESP_OK; ++i) {
        char key[8];
        snprintf(key, sizeof(key), "extra%u", (unsigned)(i + 1));
        err = nvs_set_str(nvs, key, settings->entity_extra[i]);
    }
    if (err == ESP_OK) {
        err = nvs_commit(nvs);
    }

    nvs_close(nvs);

    if (err != ESP_OK) {
        ESP_LOGW(HA_SETTINGS_TAG, "Failed to save settings (%s)", esp_err_to_name(err));
        return false;
    }

    g_settings = *settings;
    return true;
}
