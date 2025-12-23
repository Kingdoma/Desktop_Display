#ifndef APP_MAIN_H
#define APP_MAIN_H

#include <stdint.h>
#include <stddef.h>
#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "sdkconfig.h"

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
} APP_STATUS;

typedef struct {
    APP_STATUS wifi_staus;
    APP_STATUS cdc_status;
    APP_STATUS sntp_status;
    APP_STATUS ha_status;
    bool need_update;
} app_module_status_t;

extern app_message_t g_msg_recv;

extern app_module_status_t g_module_status;

extern EventGroupHandle_t g_wifi_event_group;

extern const int CONNECTED_BIT;
extern const int ESPTOUCH_DONE_BIT;


#endif /* APP_MAIN_H */
