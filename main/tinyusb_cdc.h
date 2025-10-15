#ifndef TINYUSB_CDC_H
#define TINYUSB_CDC_H

#include <stdint.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "tinyusb.h"
#include "tusb_cdc_acm.h"
#include "sdkconfig.h"

typedef struct {
    uint8_t buf[CONFIG_TINYUSB_CDC_RX_BUFSIZE + 1];     // Data buffer
    size_t  buf_len;                                    // Number of bytes received
    uint8_t itf;                                        // Index of CDC device interface
} app_message_t;

esp_err_t tinyusb_cdc_driver_init(void);

esp_err_t tinyusb_cdc_rec(void);

#endif /* TINYUSB_CDC_H */
