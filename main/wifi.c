#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_wifi.h"
#include "esp_eap_client.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "esp_smartconfig.h"
#include "esp_mac.h"
#include "wifi.h"

#define WIFI_TAG "wifi_connect"

static TaskHandle_t s_smartconfig_task = NULL;
static void smartconfig_example_task(void * parm);
static void start_smartconfig_task(bool force);

static void wifi_init()
{
    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_t *sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK( esp_wifi_init(&cfg) );
}

static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        // station start, run smart config
        start_smartconfig_task(false);
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        // reconnect
        g_module_status.wifi_staus = DISCONNECT;
        g_module_status.need_update = true;

        esp_wifi_connect();
        xEventGroupClearBits(g_wifi_event_group, CONNECTED_BIT);

    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        // set connected
        xEventGroupSetBits(g_wifi_event_group, CONNECTED_BIT);

        g_module_status.wifi_staus = CONNECT;
        g_module_status.need_update = true;

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_SCAN_DONE) {
        ESP_LOGI(WIFI_TAG, "Scan done");

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_FOUND_CHANNEL) {
        ESP_LOGI(WIFI_TAG, "Found channel");

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_GOT_SSID_PSWD) {
        // smart config receive wifi data
        ESP_LOGI(WIFI_TAG, "Got SSID and password");
        smartconfig_event_got_ssid_pswd_t *evt = (smartconfig_event_got_ssid_pswd_t *)event_data;
        wifi_config_t wifi_config;
        uint8_t ssid[33] = { 0 };
        uint8_t password[65] = { 0 };
        uint8_t rvd_data[33] = { 0 };

        bzero(&wifi_config, sizeof(wifi_config_t));
        memcpy(wifi_config.sta.ssid, evt->ssid, sizeof(wifi_config.sta.ssid));
        memcpy(wifi_config.sta.password, evt->password, sizeof(wifi_config.sta.password));

        memcpy(ssid, evt->ssid, sizeof(evt->ssid));
        memcpy(password, evt->password, sizeof(evt->password));
        ESP_LOGI(WIFI_TAG, "SSID:%s", ssid);
        ESP_LOGI(WIFI_TAG, "PASSWORD:%s", password);
        if (evt->type == SC_TYPE_ESPTOUCH_V2) {
            // handel esptouch v2
            ESP_ERROR_CHECK( esp_smartconfig_get_rvd_data(rvd_data, sizeof(rvd_data)) );
            ESP_LOGI(WIFI_TAG, "RVD_DATA:");
            for (int i=0; i<33; i++) {
                printf("%02x ", rvd_data[i]);
            }
            printf("\n");
        }
        // reconnect with fresh config
        ESP_ERROR_CHECK( esp_wifi_disconnect() );
        ESP_ERROR_CHECK( esp_wifi_set_config(WIFI_IF_STA, &wifi_config) );
        esp_wifi_connect();

    } else if (event_base == SC_EVENT && event_id == SC_EVENT_SEND_ACK_DONE) {
        // SmartConfig set done bit
        xEventGroupSetBits(g_wifi_event_group, ESPTOUCH_DONE_BIT);
    }
}

static void smartconfig_example_task(void * parm)
{
    EventBits_t uxBits;
    wifi_config_t myconfig = {0};
    bool force = parm != NULL;

    ESP_LOGI(WIFI_TAG, "creat smartconfig_example_task");
    // get wifi config in nvs
    esp_err_t err = esp_wifi_get_config(ESP_IF_WIFI_STA, &myconfig);

    if (!force && err == ESP_OK && strlen((char*)myconfig.sta.ssid) > 0)
    {
        // has wifi configs, skip smartconfig
        ESP_LOGI(WIFI_TAG, "alrealy set, SSID is :%s,start connect", myconfig.sta.ssid);
        esp_wifi_connect();
        s_smartconfig_task = NULL;
        vTaskDelete(NULL);
    }
    else
    {
        ESP_LOGI(WIFI_TAG, "have no set, start to config");
        xEventGroupClearBits(g_wifi_event_group, CONNECTED_BIT | ESPTOUCH_DONE_BIT);
        esp_smartconfig_stop();
        ESP_ERROR_CHECK( esp_smartconfig_set_type(SC_TYPE_ESPTOUCH_AIRKISS) );
        smartconfig_start_config_t cfg = SMARTCONFIG_START_CONFIG_DEFAULT();
        ESP_ERROR_CHECK( esp_smartconfig_start(&cfg) );

        g_module_status.wifi_staus = WAITING;
        g_module_status.need_update = true;
    }

    while (1) {
        uxBits = xEventGroupWaitBits(g_wifi_event_group, CONNECTED_BIT | ESPTOUCH_DONE_BIT, true, false, portMAX_DELAY);
        if(uxBits & CONNECTED_BIT) {
            // ap connected
            ESP_LOGI(WIFI_TAG, "WiFi Connected to ap");
            break;
        }
        if(uxBits & ESPTOUCH_DONE_BIT) {
            // SmartConfig done
            ESP_LOGI(WIFI_TAG, "smartconfig over");

            esp_smartconfig_stop();
            break;
        }
    }

    s_smartconfig_task = NULL;
    vTaskDelete(NULL);
}

static void start_smartconfig_task(bool force)
{
    if (s_smartconfig_task != NULL) {
        ESP_LOGW(WIFI_TAG, "smartconfig task already running");
        return;
    }

    BaseType_t ok = xTaskCreate(
        smartconfig_example_task,
        "smartconfig_example_task",
        4096,
        (void *)(force ? 1 : 0),
        3,
        &s_smartconfig_task);

    if (ok != pdPASS) {
        s_smartconfig_task = NULL;
        ESP_LOGE(WIFI_TAG, "failed to create smartconfig task");
        
        g_module_status.wifi_staus = ERROR;
        g_module_status.need_update = true;
    }
}

void wifi_connect(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());

    g_wifi_event_group = xEventGroupCreate();

    wifi_init();

    // registe wifi event callback
    ESP_ERROR_CHECK( esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL) );
    ESP_ERROR_CHECK( esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL) );
    ESP_ERROR_CHECK( esp_event_handler_register(SC_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL) );

    // run wifi as STA
    ESP_ERROR_CHECK( esp_wifi_set_mode(WIFI_MODE_STA) );
    ESP_ERROR_CHECK( esp_wifi_start() );

}

void wifi_setting_clear()
{
    ESP_LOGI(WIFI_TAG, "Clear the wifi setting");
    ESP_ERROR_CHECK( esp_wifi_restore() );
}

void wifi_diconnect()
{
    xEventGroupClearBits(g_wifi_event_group, CONNECTED_BIT);
    ESP_LOGI(WIFI_TAG, "disconnecting");
    ESP_ERROR_CHECK( esp_wifi_disconnect() );
}

void wifi_reconnect()
{
    ESP_LOGI(WIFI_TAG, "restarting");
    esp_restart();
}