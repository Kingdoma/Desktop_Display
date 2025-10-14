#include <stdio.h>
#include <stdbool.h>
#include "esp_mac.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_st7796.h"
#include "esp_lcd_touch.h"
#include "esp_lcd_touch_ft5x06.h"
#include "lvgl.h"
#include "generated/gui_guider.h"
#include "custom/custom.h"

#define TAG "st7796_lvgl"

#define EXAMPLE_LCD_H_RES              (480)
#define EXAMPLE_LCD_V_RES              (320)
#define EXAMPLE_LCD_BIT_PER_PIXEL      (16)
#define EXAMPLE_LCD_DATA_WIDTH         (8)
#define EXAMPLE_LCD_BUFFER_LINES       (40)
#define EXAMPLE_LCD_MIRROR_X           false
#define EXAMPLE_LCD_MIRROR_Y           false

#define EXAMPLE_TOUCH_I2C_PORT         (I2C_NUM_0)
#define EXAMPLE_TOUCH_I2C_SCL          (GPIO_NUM_1)  // Update to actual FT6336U SCL pin
#define EXAMPLE_TOUCH_I2C_SDA          (GPIO_NUM_2)  // Update to actual FT6336U SDA pin
#define EXAMPLE_TOUCH_I2C_CLK_HZ       (400000)
#define EXAMPLE_TOUCH_RST              (GPIO_NUM_NC)
#define EXAMPLE_TOUCH_INT              (GPIO_NUM_NC)
#define EXAMPLE_TOUCH_SWAP_XY          false
#define EXAMPLE_TOUCH_MIRROR_X         false
#define EXAMPLE_TOUCH_MIRROR_Y         false
#define EXAMPLE_TOUCH_PHYS_WIDTH       (320)
#define EXAMPLE_TOUCH_PHYS_HEIGHT      (480)

// Update these GPIO assignments so they match your hardware wiring.
#define EXAMPLE_PIN_NUM_LCD_CS         (GPIO_NUM_17)
#define EXAMPLE_PIN_NUM_LCD_DC         (GPIO_NUM_46)
#define EXAMPLE_PIN_NUM_LCD_WR         (GPIO_NUM_3)
#define EXAMPLE_PIN_NUM_LCD_DATA0      (GPIO_NUM_9)
#define EXAMPLE_PIN_NUM_LCD_DATA1      (GPIO_NUM_12)
#define EXAMPLE_PIN_NUM_LCD_DATA2      (GPIO_NUM_11)
#define EXAMPLE_PIN_NUM_LCD_DATA3      (GPIO_NUM_14)
#define EXAMPLE_PIN_NUM_LCD_DATA4      (GPIO_NUM_13)
#define EXAMPLE_PIN_NUM_LCD_DATA5      (GPIO_NUM_47)
#define EXAMPLE_PIN_NUM_LCD_DATA6      (GPIO_NUM_21)
#define EXAMPLE_PIN_NUM_LCD_DATA7      (GPIO_NUM_45)
#define EXAMPLE_PIN_NUM_LCD_DATA8      (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA9      (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA10     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA11     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA12     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA13     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA14     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_DATA15     (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_LCD_RST        (GPIO_NUM_NC)
#define EXAMPLE_PIN_NUM_BK_LIGHT       (-1)
#define EXAMPLE_BK_LIGHT_ON_LEVEL      (1)

lv_ui guider_ui;

static SemaphoreHandle_t lvgl_flush_ready = NULL;
static lv_disp_draw_buf_t lvgl_draw_buf;
static lv_color_t lvgl_buf1[EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES];
static lv_color_t lvgl_buf2[EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES];
static lv_disp_drv_t lvgl_disp_drv;
static lv_indev_drv_t lvgl_indev_drv;
static esp_lcd_touch_handle_t lvgl_touch_handle = NULL;

static void example_enable_backlight(void)
{
#if EXAMPLE_PIN_NUM_BK_LIGHT >= 0
    gpio_config_t bk_gpio_config = {
        .pin_bit_mask = 1ULL << EXAMPLE_PIN_NUM_BK_LIGHT,
        .mode = GPIO_MODE_OUTPUT,
    };
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));
    ESP_ERROR_CHECK(gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_BK_LIGHT_ON_LEVEL));
#endif
}

IRAM_ATTR static bool example_panel_trans_done(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    BaseType_t high_task_wakeup = pdFALSE;
    if (lvgl_flush_ready) {
        xSemaphoreGiveFromISR(lvgl_flush_ready, &high_task_wakeup);
    }
    return high_task_wakeup == pdTRUE;
}

static void example_lvgl_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)disp_drv->user_data;
    const int x1 = area->x1;
    const int y1 = area->y1;
    const int x2 = area->x2;
    const int y2 = area->y2;

    esp_err_t err = esp_lcd_panel_draw_bitmap(panel_handle,
                                              x1,
                                              y1,
                                              x2 + 1,
                                              y2 + 1,
                                              color_map);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Panel draw failed (%s)", esp_err_to_name(err));
    } else if (lvgl_flush_ready) {
        if (xSemaphoreTake(lvgl_flush_ready, pdMS_TO_TICKS(1000)) != pdTRUE) {
            ESP_LOGW(TAG, "LVGL flush timeout");
        }
    }

    lv_disp_flush_ready(disp_drv);
}

static void lvgl_tick_cb(void *arg)
{
    lv_tick_inc(1);
}

static void lvgl_task(void *arg)
{
    const TickType_t delay = pdMS_TO_TICKS(10);
    while (1) {
        lv_timer_handler();
        vTaskDelay(delay);
    }
}

static void lvgl_touch_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    (void)drv;
    if (!lvgl_touch_handle) {
        data->state = LV_INDEV_STATE_RELEASED;
        return;
    }

    esp_err_t ret = esp_lcd_touch_read_data(lvgl_touch_handle);    
    if (ret != ESP_OK) {
        ESP_LOGW(TAG, "Touch read failed (%s)", esp_err_to_name(ret));
    }
    uint16_t touch_x[1];
    uint16_t touch_y[1];
    uint8_t touch_points = 0;

    bool touched = esp_lcd_touch_get_coordinates(lvgl_touch_handle, touch_x, touch_y, NULL, &touch_points, 1);
    if (touched && touch_points > 0) {
        // Map raw portrait touch coordinates to the rotated landscape LCD space.
        uint16_t raw_x = touch_x[0];
        uint16_t raw_y = touch_y[0];

        if (raw_x >= EXAMPLE_TOUCH_PHYS_WIDTH) {
            raw_x = EXAMPLE_TOUCH_PHYS_WIDTH - 1;
        }
        if (raw_y >= EXAMPLE_TOUCH_PHYS_HEIGHT) {
            raw_y = EXAMPLE_TOUCH_PHYS_HEIGHT - 1;
        }

        uint16_t screen_x = raw_y;
        uint16_t screen_y = (EXAMPLE_TOUCH_PHYS_WIDTH - 1) - raw_x;
        if (screen_x >= EXAMPLE_LCD_H_RES) {
            screen_x = EXAMPLE_LCD_H_RES - 1;
        }
        if (screen_y >= EXAMPLE_LCD_V_RES) {
            screen_y = EXAMPLE_LCD_V_RES - 1;
        }

        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = screen_x;
        data->point.y = screen_y;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

static void example_init_touch(void)
{
    i2c_config_t i2c_conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = EXAMPLE_TOUCH_I2C_SDA,
        .scl_io_num = EXAMPLE_TOUCH_I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = EXAMPLE_TOUCH_I2C_CLK_HZ,
    };
    ESP_ERROR_CHECK(i2c_param_config(EXAMPLE_TOUCH_I2C_PORT, &i2c_conf));
    ESP_ERROR_CHECK(i2c_driver_install(EXAMPLE_TOUCH_I2C_PORT, i2c_conf.mode, 0, 0, 0));

    esp_lcd_panel_io_handle_t touch_io = NULL;
    esp_lcd_panel_io_i2c_config_t touch_io_config = ESP_LCD_TOUCH_IO_I2C_FT5x06_CONFIG();
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i2c(EXAMPLE_TOUCH_I2C_PORT, &touch_io_config, &touch_io));

    esp_lcd_touch_config_t touch_cfg = {
        .x_max = EXAMPLE_TOUCH_PHYS_WIDTH,
        .y_max = EXAMPLE_TOUCH_PHYS_HEIGHT,
        .rst_gpio_num = EXAMPLE_TOUCH_RST,
        .int_gpio_num = EXAMPLE_TOUCH_INT,
        .flags = {
            .swap_xy = EXAMPLE_TOUCH_SWAP_XY,
            .mirror_x = EXAMPLE_TOUCH_MIRROR_X,
            .mirror_y = EXAMPLE_TOUCH_MIRROR_Y,
        },
    };
    ESP_ERROR_CHECK(esp_lcd_touch_new_i2c_ft5x06(touch_io, &touch_cfg, &lvgl_touch_handle));
}

void app_main(void)
{
    ESP_LOGI(TAG, "Initialize Intel 8080 bus (8-bit)");
    esp_lcd_i80_bus_handle_t i80_bus = NULL;
    esp_lcd_i80_bus_config_t bus_config = ST7796_PANEL_BUS_I80_CONFIG(
            EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES * EXAMPLE_LCD_BIT_PER_PIXEL / 8,
            EXAMPLE_LCD_DATA_WIDTH,
            EXAMPLE_PIN_NUM_LCD_DC,
            EXAMPLE_PIN_NUM_LCD_WR,
            EXAMPLE_PIN_NUM_LCD_DATA0,
            EXAMPLE_PIN_NUM_LCD_DATA1,
            EXAMPLE_PIN_NUM_LCD_DATA2,
            EXAMPLE_PIN_NUM_LCD_DATA3,
            EXAMPLE_PIN_NUM_LCD_DATA4,
            EXAMPLE_PIN_NUM_LCD_DATA5,
            EXAMPLE_PIN_NUM_LCD_DATA6,
            EXAMPLE_PIN_NUM_LCD_DATA7,
            EXAMPLE_PIN_NUM_LCD_DATA8,
            EXAMPLE_PIN_NUM_LCD_DATA9,
            EXAMPLE_PIN_NUM_LCD_DATA10,
            EXAMPLE_PIN_NUM_LCD_DATA11,
            EXAMPLE_PIN_NUM_LCD_DATA12,
            EXAMPLE_PIN_NUM_LCD_DATA13,
            EXAMPLE_PIN_NUM_LCD_DATA14,
            EXAMPLE_PIN_NUM_LCD_DATA15);
    ESP_ERROR_CHECK(esp_lcd_new_i80_bus(&bus_config, &i80_bus));

    ESP_LOGI(TAG, "Install panel IO");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_i80_config_t io_config = ST7796_PANEL_IO_I80_CONFIG(
            EXAMPLE_PIN_NUM_LCD_CS,
            example_panel_trans_done,
            NULL);
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_i80(i80_bus, &io_config, &io_handle));

    ESP_LOGI(TAG, "Install ST7796 panel driver");
    esp_lcd_panel_handle_t panel_handle = NULL;
    const esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_BGR,
        .bits_per_pixel = EXAMPLE_LCD_BIT_PER_PIXEL,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7796(io_handle, &panel_config, &panel_handle));

    ESP_LOGI(TAG, "Reset and initialize panel");
    ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));
    ESP_ERROR_CHECK(esp_lcd_panel_swap_xy(panel_handle, true));
    ESP_ERROR_CHECK(esp_lcd_panel_mirror(panel_handle, EXAMPLE_LCD_MIRROR_X, EXAMPLE_LCD_MIRROR_Y));
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    example_enable_backlight();

    ESP_LOGI(TAG, "Initialize FT6336U touch controller");
    example_init_touch();

    ESP_LOGI(TAG, "Initialize LVGL");
    lv_init();

    lvgl_flush_ready = xSemaphoreCreateBinary();
    configASSERT(lvgl_flush_ready);

    lv_disp_draw_buf_init(&lvgl_draw_buf, lvgl_buf1, lvgl_buf2, EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES);

    lv_disp_drv_init(&lvgl_disp_drv);
    lvgl_disp_drv.hor_res = EXAMPLE_LCD_H_RES;
    lvgl_disp_drv.ver_res = EXAMPLE_LCD_V_RES;
    lvgl_disp_drv.flush_cb = example_lvgl_flush;
    lvgl_disp_drv.draw_buf = &lvgl_draw_buf;
    lvgl_disp_drv.user_data = panel_handle;
    lv_disp_drv_register(&lvgl_disp_drv);

    lv_indev_drv_init(&lvgl_indev_drv);
    lvgl_indev_drv.type = LV_INDEV_TYPE_POINTER;
    lvgl_indev_drv.read_cb = lvgl_touch_read;
    lvgl_indev_drv.user_data = lvgl_touch_handle;
    lv_indev_drv_register(&lvgl_indev_drv);

    const esp_timer_create_args_t tick_timer_args = {
        .callback = lvgl_tick_cb,
        .name = "lvgl_tick",
    };
    esp_timer_handle_t tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&tick_timer_args, &tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(tick_timer, 1000)); // 1 ms tick

    setup_ui(&guider_ui);
    custom_init(&guider_ui);

    xTaskCreate(lvgl_task, "lvgl_task", 4096, NULL, 2, NULL);

    ESP_LOGI(TAG, "LVGL task started");
}
