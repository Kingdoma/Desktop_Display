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
#include "app_main.h"

esp_err_t tinyusb_cdc_driver_init(void);

esp_err_t tinyusb_cdc_rec(void);

#endif /* TINYUSB_CDC_H */
