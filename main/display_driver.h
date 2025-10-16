#ifndef DISPLAY_DRIVER_H
#define DISPLAY_DRIVER_H

#include "esp_err.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_touch.h"
#include "lvgl.h"

typedef struct {
    esp_lcd_panel_handle_t panel;
    lv_disp_t *disp;
    lv_indev_t *indev;
} display_driver_handles_t;

esp_err_t display_driver_init(display_driver_handles_t *out_handles);

esp_err_t display_enable_backlight(void);

#endif /* DISPLAY_DRIVER_H */
