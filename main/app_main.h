#ifndef APP_MAIN_H
#define APP_MAIN_H

#include <stdint.h>
#include <stddef.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "sdkconfig.h"
#include "metrics.h"

typedef struct {
    uint8_t buf[CONFIG_TINYUSB_CDC_RX_BUFSIZE + 1];     // Data buffer
    size_t  buf_len;                                    // Number of bytes received
    uint8_t itf;                                        // Index of CDC device interface
} app_message_t;

typedef enum {
    CONNECT,
    DISCONNECT,
    WAITING,
    READY,
    ERROR
} app_status_t;

typedef struct {
    app_status_t wifi_staus;
    app_status_t cdc_status;
    app_status_t sntp_status;
    app_status_t ha_status;
    app_status_t web_status;
    bool need_update;
} app_module_status_t;

extern app_message_t g_msg_recv;

extern system_metrics_t g_latest_metrics;

extern app_module_status_t g_module_status;

extern EventGroupHandle_t g_wifi_event_group;
extern SemaphoreHandle_t g_net_lock;

extern const int CONNECTED_BIT;
extern const int ESPTOUCH_DONE_BIT;


#endif /* APP_MAIN_H */
