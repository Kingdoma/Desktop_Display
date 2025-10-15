#include <stdio.h>
#include <stdbool.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"
#include "display_driver.h"
#include "tinyusb_cdc.h"
#include "app_main.h"

#define TAG "app_main"

lv_ui guider_ui;

static void lvgl_tick_cb(void *arg)
{
    lv_tick_inc(1);
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

    const TickType_t delay = pdMS_TO_TICKS(10);
    while (1) {
        lv_timer_handler();
        vTaskDelay(delay);
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

    xTaskCreate(lvgl_task, "lvgl_task", 4096, NULL, 2, NULL);

    xTaskCreate(cdc_task, "cdc_task", 4096, NULL, 2, NULL);

    ESP_LOGI(TAG, "LVGL task started");
}
