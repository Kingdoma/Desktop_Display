#include "display_driver.h"

#include "display_config.h"

#include "esp_log.h"
#include "esp_check.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_st7796.h"
#include "esp_lcd_touch_ft5x06.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

static const char *TAG = "display_driver";

static SemaphoreHandle_t s_flush_ready;
static esp_lcd_i80_bus_handle_t s_i80_bus;
static esp_lcd_panel_io_handle_t s_panel_io;
static esp_lcd_panel_handle_t s_panel_handle;
static esp_lcd_touch_handle_t s_touch_handle;
static lv_disp_t *s_disp;
static lv_indev_t *s_input;
static lv_disp_draw_buf_t s_disp_buf;
static lv_disp_drv_t s_disp_drv;
static lv_indev_drv_t s_indev_drv;
static lv_color_t s_buf1[EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES];
static lv_color_t s_buf2[EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES];
static bool s_initialized;

static void display_wait_for_power(uint32_t delay_ms);
static esp_err_t display_init_touch(void);
IRAM_ATTR static bool display_panel_trans_done(esp_lcd_panel_io_handle_t panel_io,
                                               esp_lcd_panel_io_event_data_t *edata,
                                               void *user_ctx);
static void display_lvgl_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_map);
static void display_lvgl_touch_read(lv_indev_drv_t *drv, lv_indev_data_t *data);

esp_err_t display_driver_init(display_driver_handles_t *out_handles)
{
    if(s_initialized) {
        if(out_handles) {
            out_handles->panel = s_panel_handle;
            out_handles->disp = s_disp;
            out_handles->indev = s_input;
        }
        return ESP_OK;
    }

    s_flush_ready = xSemaphoreCreateBinary();
    if(s_flush_ready == NULL) {
        return ESP_ERR_NO_MEM;
    }

    /* On a cold boot the panel power rails rise slower than the MCU.
     * Give the ST7796 controller time to exit reset before sending commands. */
    // display_wait_for_power(200);

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
    ESP_RETURN_ON_ERROR(esp_lcd_new_i80_bus(&bus_config, &s_i80_bus), TAG, "create 8080 bus failed");

    esp_lcd_panel_io_i80_config_t io_config = ST7796_PANEL_IO_I80_CONFIG(
            EXAMPLE_PIN_NUM_LCD_CS,
            display_panel_trans_done,
            NULL);
    ESP_RETURN_ON_ERROR(esp_lcd_new_panel_io_i80(s_i80_bus, &io_config, &s_panel_io), TAG,
                        "install panel IO failed");

    static const st7796_lcd_init_cmd_t lcd_init_cmds[] = {
    // {cmd, { data }, data_size, delay_ms}
        {0x35, (uint8_t []){0x00}, 1, 0},
        {0x36, (uint8_t []){0x28}, 1, 0},
        {0xf0, (uint8_t []){0xc3}, 1, 0},
        {0xf0, (uint8_t []){0x96}, 1, 0},
        {0xb4, (uint8_t []){0x01}, 1, 0},
        {0xb7, (uint8_t []){0xc6}, 1, 0},
        {0xe8, (uint8_t []){0x40, 0x8a, 0x00, 0x00, 0x29, 0x19, 0xa5, 0x33}, 8, 0},
        {0xc1, (uint8_t []){0x06}, 1, 0},
        {0xc2, (uint8_t []){0xa7}, 1, 0},
        {0xc5, (uint8_t []){0x18}, 1, 0},
        {0xe0, (uint8_t []){0xf0, 0x09, 0x0b, 0x06, 0x04, 0x15, 0x2f, 0x54, 0x42, 0x3c, 0x17, 0x14, 0x18, 0x1b}, 14, 0},
        {0xe1, (uint8_t []){0xf0, 0x09, 0x0b, 0x06, 0x04, 0x03, 0x2d, 0x43, 0x42, 0x3b, 0x16, 0x14, 0x17, 0x1b}, 14, 0},
        {0xf0, (uint8_t []){0x3c}, 1, 0},
        {0xf0, (uint8_t []){0x69}, 1, 0},
    };

    st7796_vendor_config_t vendor_config = {  // Uncomment these lines if use custom initialization commands
        .init_cmds = lcd_init_cmds,
        .init_cmds_size = sizeof(lcd_init_cmds) / sizeof(st7796_lcd_init_cmd_t),
    };

    const esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = EXAMPLE_PIN_NUM_LCD_RST,
        .rgb_ele_order = LCD_RGB_ELEMENT_ORDER_BGR,
        .bits_per_pixel = EXAMPLE_LCD_BIT_PER_PIXEL,
        .vendor_config = &vendor_config,
    };
    ESP_RETURN_ON_ERROR(esp_lcd_new_panel_st7796(s_panel_io, &panel_config, &s_panel_handle), TAG,
                        "install st7796 panel failed");

    ESP_RETURN_ON_ERROR(esp_lcd_panel_reset(s_panel_handle), TAG, "panel reset failed");
    display_wait_for_power(120);
    ESP_RETURN_ON_ERROR(esp_lcd_panel_init(s_panel_handle), TAG, "panel init failed");
    display_wait_for_power(20);
    ESP_RETURN_ON_ERROR(esp_lcd_panel_swap_xy(s_panel_handle, true), TAG, "panel swap xy failed");
    ESP_RETURN_ON_ERROR(esp_lcd_panel_mirror(s_panel_handle, EXAMPLE_LCD_MIRROR_X, EXAMPLE_LCD_MIRROR_Y), TAG,
                        "panel mirror failed");
    ESP_RETURN_ON_ERROR(esp_lcd_panel_disp_on_off(s_panel_handle, true), TAG, "panel on failed");

    ESP_RETURN_ON_ERROR(display_init_touch(), TAG, "touch init failed");

    lv_disp_draw_buf_init(&s_disp_buf, s_buf1, s_buf2, EXAMPLE_LCD_H_RES * EXAMPLE_LCD_BUFFER_LINES);

    lv_disp_drv_init(&s_disp_drv);
    s_disp_drv.hor_res = EXAMPLE_LCD_H_RES;
    s_disp_drv.ver_res = EXAMPLE_LCD_V_RES;
    s_disp_drv.flush_cb = display_lvgl_flush;
    s_disp_drv.draw_buf = &s_disp_buf;
    s_disp_drv.user_data = s_panel_handle;
    s_disp = lv_disp_drv_register(&s_disp_drv);
    configASSERT(s_disp);

    lv_indev_drv_init(&s_indev_drv);
    s_indev_drv.type = LV_INDEV_TYPE_POINTER;
    s_indev_drv.read_cb = display_lvgl_touch_read;
    s_indev_drv.user_data = s_touch_handle;
    s_input = lv_indev_drv_register(&s_indev_drv);
    configASSERT(s_input);

    s_initialized = true;

    if(out_handles) {
        out_handles->panel = s_panel_handle;
        out_handles->disp = s_disp;
        out_handles->indev = s_input;
    }

    ESP_LOGI(TAG, "Display and touch initialized");
    return ESP_OK;
}

static void display_wait_for_power(uint32_t delay_ms)
{
    if(delay_ms == 0) {
        return;
    }

    vTaskDelay(pdMS_TO_TICKS(delay_ms));
}

esp_err_t display_enable_backlight(void)
{
#if EXAMPLE_PIN_NUM_BK_LIGHT >= 0
    gpio_config_t bk_gpio_config = {
        .pin_bit_mask = 1ULL << EXAMPLE_PIN_NUM_BK_LIGHT,
        .mode = GPIO_MODE_OUTPUT,
    };
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));
    ESP_ERROR_CHECK(gpio_set_level(EXAMPLE_PIN_NUM_BK_LIGHT, EXAMPLE_BK_LIGHT_ON_LEVEL));

    return ESP_OK;
#endif
}

IRAM_ATTR static bool display_panel_trans_done(esp_lcd_panel_io_handle_t panel_io,
                                               esp_lcd_panel_io_event_data_t *edata,
                                               void *user_ctx)
{
    BaseType_t high_task_wakeup = pdFALSE;
    if(s_flush_ready) {
        xSemaphoreGiveFromISR(s_flush_ready, &high_task_wakeup);
    }
    return high_task_wakeup == pdTRUE;
}

static void display_lvgl_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t)disp_drv->user_data;
    esp_err_t err = esp_lcd_panel_draw_bitmap(panel_handle,
                                              area->x1,
                                              area->y1,
                                              area->x2 + 1,
                                              area->y2 + 1,
                                              color_map);
    if(err != ESP_OK) {
        ESP_LOGE(TAG, "Panel draw failed (%s)", esp_err_to_name(err));
    } else if(s_flush_ready) {
        if(xSemaphoreTake(s_flush_ready, pdMS_TO_TICKS(1000)) != pdTRUE) {
            ESP_LOGW(TAG, "LVGL flush timeout");
        }
    }

    lv_disp_flush_ready(disp_drv);
}

static void display_lvgl_touch_read(lv_indev_drv_t *drv, lv_indev_data_t *data)
{
    (void)drv;
    if(!s_touch_handle) {
        data->state = LV_INDEV_STATE_RELEASED;
        return;
    }

    esp_err_t ret = esp_lcd_touch_read_data(s_touch_handle);
    if(ret != ESP_OK) {
        ESP_LOGW(TAG, "Touch read failed (%s)", esp_err_to_name(ret));
    }

    uint16_t touch_x[1];
    uint16_t touch_y[1];
    uint8_t touch_points = 0;
    bool touched = esp_lcd_touch_get_coordinates(s_touch_handle, touch_x, touch_y, NULL, &touch_points, 1);
    if(touched && touch_points > 0) {
        uint16_t raw_x = touch_x[0];
        uint16_t raw_y = touch_y[0];

        if(raw_x >= EXAMPLE_TOUCH_PHYS_WIDTH) {
            raw_x = EXAMPLE_TOUCH_PHYS_WIDTH - 1;
        }
        if(raw_y >= EXAMPLE_TOUCH_PHYS_HEIGHT) {
            raw_y = EXAMPLE_TOUCH_PHYS_HEIGHT - 1;
        }

        uint16_t screen_x = raw_y;
        uint16_t screen_y = (EXAMPLE_TOUCH_PHYS_WIDTH - 1) - raw_x;
        if(screen_x >= EXAMPLE_LCD_H_RES) {
            screen_x = EXAMPLE_LCD_H_RES - 1;
        }
        if(screen_y >= EXAMPLE_LCD_V_RES) {
            screen_y = EXAMPLE_LCD_V_RES - 1;
        }

        data->state = LV_INDEV_STATE_PRESSED;
        data->point.x = screen_x;
        data->point.y = screen_y;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
}

static esp_err_t display_init_touch(void)
{
    i2c_config_t i2c_conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = EXAMPLE_TOUCH_I2C_SDA,
        .scl_io_num = EXAMPLE_TOUCH_I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = EXAMPLE_TOUCH_I2C_CLK_HZ,
    };
    ESP_RETURN_ON_ERROR(i2c_param_config(EXAMPLE_TOUCH_I2C_PORT, &i2c_conf), TAG, "touch i2c config failed");

    esp_err_t err = i2c_driver_install(EXAMPLE_TOUCH_I2C_PORT, i2c_conf.mode, 0, 0, 0);
    if(err != ESP_OK && err != ESP_ERR_INVALID_STATE) {
        ESP_RETURN_ON_ERROR(err, TAG, "touch i2c install failed");
    }

    esp_lcd_panel_io_handle_t touch_io = NULL;
    esp_lcd_panel_io_i2c_config_t touch_io_config = ESP_LCD_TOUCH_IO_I2C_FT5x06_CONFIG();
    ESP_RETURN_ON_ERROR(esp_lcd_new_panel_io_i2c(EXAMPLE_TOUCH_I2C_PORT, &touch_io_config, &touch_io), TAG,
                        "touch IO create failed");

    esp_lcd_touch_config_t touch_cfg = {
        .x_max = EXAMPLE_TOUCH_PHYS_WIDTH,
        .y_max = EXAMPLE_TOUCH_PHYS_HEIGHT,
        .rst_gpio_num = EXAMPLE_TOUCH_RST,
        .int_gpio_num = EXAMPLE_TOUCH_INT,
        .levels = {
            .reset = 0,
            .interrupt = 0,
        },
        .flags = {
            .swap_xy = EXAMPLE_TOUCH_SWAP_XY,
            .mirror_x = EXAMPLE_TOUCH_MIRROR_X,
            .mirror_y = EXAMPLE_TOUCH_MIRROR_Y,
        },
    };
    return esp_lcd_touch_new_i2c_ft5x06(touch_io, &touch_cfg, &s_touch_handle);
}
