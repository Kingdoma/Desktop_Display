/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"
#include "esp_task_wdt.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define UI_YIELD()        \
    do {                  \
        esp_task_wdt_reset(); \
        vTaskDelay(pdMS_TO_TICKS(1)); \
    } while (0)



int Monitor_dark_digital_clock_time_min_value = 25;
int Monitor_dark_digital_clock_time_hour_value = 11;
int Monitor_dark_digital_clock_time_sec_value = 50;
char Monitor_dark_digital_clock_time_meridiem[] = "AM";
void setup_scr_Monitor_dark(lv_ui *ui)
{
    //Write codes Monitor_dark
    ui->Monitor_dark = lv_obj_create(NULL);
    lv_obj_set_size(ui->Monitor_dark, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark, lv_color_hex(0x232429), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    UI_YIELD();

    //Write codes Monitor_dark_cont_time
    ui->Monitor_dark_cont_time = lv_obj_create(ui->Monitor_dark);
    lv_obj_set_pos(ui->Monitor_dark_cont_time, 335, 31);
    lv_obj_set_size(ui->Monitor_dark_cont_time, 130, 121);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_cont_time, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_cont_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cont_time, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cont_time, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_cont_time, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_cont_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_digital_clock_time
    static bool Monitor_dark_digital_clock_time_timer_enabled = false;
    ui->Monitor_dark_digital_clock_time = lv_dclock_create(ui->Monitor_dark_cont_time, "11:25:50 AM");
    if (!Monitor_dark_digital_clock_time_timer_enabled) {
        lv_timer_create(Monitor_dark_digital_clock_time_timer, 1000, NULL);
        Monitor_dark_digital_clock_time_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Monitor_dark_digital_clock_time, 13, 57);
    lv_obj_set_size(ui->Monitor_dark_digital_clock_time, 98, 20);

    //Write style for Monitor_dark_digital_clock_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_digital_clock_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_digital_clock_time, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_digital_clock_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_digital_clock_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_digital_clock_time, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_datetext_date
    ui->Monitor_dark_datetext_date = lv_label_create(ui->Monitor_dark_cont_time);
    lv_label_set_text(ui->Monitor_dark_datetext_date, "2025/10/14");
    lv_obj_set_style_text_align(ui->Monitor_dark_datetext_date, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->Monitor_dark_datetext_date, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->Monitor_dark_datetext_date, Monitor_dark_datetext_date_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->Monitor_dark_datetext_date, 23, 27);
    lv_obj_set_size(ui->Monitor_dark_datetext_date, 81, 24);

    //Write style for Monitor_dark_datetext_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Monitor_dark_datetext_date, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_datetext_date, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_datetext_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_datetext_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_datetext_date, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_time_title
    ui->Monitor_dark_time_title = lv_label_create(ui->Monitor_dark_cont_time);
    lv_label_set_text(ui->Monitor_dark_time_title, "Time");
    lv_label_set_long_mode(ui->Monitor_dark_time_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_time_title, 0, 0);
    lv_obj_set_size(ui->Monitor_dark_time_title, 130, 25);

    //Write style for Monitor_dark_time_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_time_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_time_title, lv_color_hex(0xE9DABE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_time_title, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_time_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_time_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_time_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_time_title, lv_color_hex(0x44392D), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_time_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_time_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_time_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_weekday
    ui->Monitor_dark_weekday = lv_label_create(ui->Monitor_dark_cont_time);
    lv_label_set_text(ui->Monitor_dark_weekday, "Tuesday");
    lv_label_set_long_mode(ui->Monitor_dark_weekday, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_weekday, 9, 87);
    lv_obj_set_size(ui->Monitor_dark_weekday, 103, 22);

    //Write style for Monitor_dark_weekday, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_weekday, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_weekday, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_weekday, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_weekday, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_weekday, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_weekday, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_weekday, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    UI_YIELD();

    //Write codes Monitor_dark_cont_net
    ui->Monitor_dark_cont_net = lv_obj_create(ui->Monitor_dark);
    lv_obj_set_pos(ui->Monitor_dark_cont_net, 335, 164);
    lv_obj_set_size(ui->Monitor_dark_cont_net, 130, 144);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_cont_net, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_cont_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cont_net, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cont_net, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_cont_net, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_cont_net, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_speed_info
    ui->Monitor_dark_speed_info = lv_obj_create(ui->Monitor_dark_cont_net);
    lv_obj_set_pos(ui->Monitor_dark_speed_info, 1, 33);
    lv_obj_set_size(ui->Monitor_dark_speed_info, 120, 59);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_speed_info, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_speed_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_speed_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Monitor_dark_speed_info, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Monitor_dark_speed_info, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_download_icon
    ui->Monitor_dark_download_icon = lv_img_create(ui->Monitor_dark_speed_info);
    lv_obj_add_flag(ui->Monitor_dark_download_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Monitor_dark_download_icon, &_download_alpha_13x13);
    lv_img_set_pivot(ui->Monitor_dark_download_icon, 50,50);
    lv_img_set_angle(ui->Monitor_dark_download_icon, 0);
    lv_obj_set_pos(ui->Monitor_dark_download_icon, 2, 25);
    lv_obj_set_size(ui->Monitor_dark_download_icon, 13, 13);

    //Write style for Monitor_dark_download_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Monitor_dark_download_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Monitor_dark_download_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_download_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Monitor_dark_download_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_upload_icon
    ui->Monitor_dark_upload_icon = lv_img_create(ui->Monitor_dark_speed_info);
    lv_obj_add_flag(ui->Monitor_dark_upload_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Monitor_dark_upload_icon, &_upload_alpha_13x13);
    lv_img_set_pivot(ui->Monitor_dark_upload_icon, 50,50);
    lv_img_set_angle(ui->Monitor_dark_upload_icon, 0);
    lv_obj_set_pos(ui->Monitor_dark_upload_icon, 2, 3);
    lv_obj_set_size(ui->Monitor_dark_upload_icon, 13, 13);

    //Write style for Monitor_dark_upload_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Monitor_dark_upload_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Monitor_dark_upload_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_upload_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Monitor_dark_upload_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_upload_label
    ui->Monitor_dark_upload_label = lv_label_create(ui->Monitor_dark_speed_info);
    lv_label_set_text(ui->Monitor_dark_upload_label, "Mbps\n");
    lv_label_set_long_mode(ui->Monitor_dark_upload_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_upload_label, 79, 1);
    lv_obj_set_size(ui->Monitor_dark_upload_label, 41, 24);

    //Write style for Monitor_dark_upload_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_upload_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_upload_label, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_upload_label, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_upload_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_upload_label, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_upload_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_upload_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_upload_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_upload_data
    ui->Monitor_dark_upload_data = lv_label_create(ui->Monitor_dark_speed_info);
    lv_label_set_text(ui->Monitor_dark_upload_data, "2200.50");
    lv_label_set_long_mode(ui->Monitor_dark_upload_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_upload_data, 7, 1);
    lv_obj_set_size(ui->Monitor_dark_upload_data, 67, 16);

    //Write style for Monitor_dark_upload_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_upload_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_upload_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_upload_data, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_upload_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_upload_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_upload_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_upload_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_download_data
    ui->Monitor_dark_download_data = lv_label_create(ui->Monitor_dark_speed_info);
    lv_label_set_text(ui->Monitor_dark_download_data, "1200.50");
    lv_label_set_long_mode(ui->Monitor_dark_download_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_download_data, 6, 24);
    lv_obj_set_size(ui->Monitor_dark_download_data, 68, 16);

    //Write style for Monitor_dark_download_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_download_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_download_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_download_data, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_download_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_download_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_download_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_download_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_download_label
    ui->Monitor_dark_download_label = lv_label_create(ui->Monitor_dark_speed_info);
    lv_label_set_text(ui->Monitor_dark_download_label, "Mbps\n");
    lv_label_set_long_mode(ui->Monitor_dark_download_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_download_label, 79, 24);
    lv_obj_set_size(ui->Monitor_dark_download_label, 41, 27);

    //Write style for Monitor_dark_download_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_download_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_download_label, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_download_label, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_download_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_download_label, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_download_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_download_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_download_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ip_data
    ui->Monitor_dark_ip_data = lv_label_create(ui->Monitor_dark_cont_net);
    lv_label_set_text(ui->Monitor_dark_ip_data, "China");
    lv_label_set_long_mode(ui->Monitor_dark_ip_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ip_data, 44, 110);
    lv_obj_set_size(ui->Monitor_dark_ip_data, 81, 16);

    //Write style for Monitor_dark_ip_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ip_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ip_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ip_data, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ip_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ip_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ip_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ip_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ip_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ip_label
    ui->Monitor_dark_ip_label = lv_label_create(ui->Monitor_dark_cont_net);
    lv_label_set_text(ui->Monitor_dark_ip_label, "IPloc:");
    lv_label_set_long_mode(ui->Monitor_dark_ip_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ip_label, 7, 110);
    lv_obj_set_size(ui->Monitor_dark_ip_label, 41, 22);

    //Write style for Monitor_dark_ip_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ip_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ip_label, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ip_label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ip_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ip_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ip_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ip_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ping_data
    ui->Monitor_dark_ping_data = lv_label_create(ui->Monitor_dark_cont_net);
    lv_label_set_text(ui->Monitor_dark_ping_data, "200");
    lv_label_set_long_mode(ui->Monitor_dark_ping_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ping_data, 47, 86);
    lv_obj_set_size(ui->Monitor_dark_ping_data, 38, 22);

    //Write style for Monitor_dark_ping_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ping_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ping_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ping_data, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ping_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ping_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ping_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ping_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ping_label
    ui->Monitor_dark_ping_label = lv_label_create(ui->Monitor_dark_cont_net);
    lv_label_set_text(ui->Monitor_dark_ping_label, "Ping:");
    lv_label_set_long_mode(ui->Monitor_dark_ping_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ping_label, 7, 85);
    lv_obj_set_size(ui->Monitor_dark_ping_label, 46, 22);

    //Write style for Monitor_dark_ping_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ping_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ping_label, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ping_label, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ping_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ping_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ping_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ping_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_net_monitor_tit
    ui->Monitor_dark_net_monitor_tit = lv_label_create(ui->Monitor_dark_cont_net);
    lv_label_set_text(ui->Monitor_dark_net_monitor_tit, "Network Monitor");
    lv_label_set_long_mode(ui->Monitor_dark_net_monitor_tit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_net_monitor_tit, 0, 0);
    lv_obj_set_size(ui->Monitor_dark_net_monitor_tit, 130, 26);

    //Write style for Monitor_dark_net_monitor_tit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_net_monitor_tit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_net_monitor_tit, lv_color_hex(0xB6E0D9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_net_monitor_tit, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_net_monitor_tit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_net_monitor_tit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_net_monitor_tit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_net_monitor_tit, lv_color_hex(0x263C3D), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_net_monitor_tit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_net_monitor_tit, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_net_monitor_tit, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ping_unit
    ui->Monitor_dark_ping_unit = lv_label_create(ui->Monitor_dark_cont_net);
    lv_label_set_text(ui->Monitor_dark_ping_unit, "ms");
    lv_label_set_long_mode(ui->Monitor_dark_ping_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ping_unit, 87, 86);
    lv_obj_set_size(ui->Monitor_dark_ping_unit, 38, 22);

    //Write style for Monitor_dark_ping_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ping_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ping_unit, lv_color_hex(0xe3e3e3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ping_unit, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ping_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ping_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ping_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ping_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cont_cpu_monitor
    ui->Monitor_dark_cont_cpu_monitor = lv_obj_create(ui->Monitor_dark);
    lv_obj_set_pos(ui->Monitor_dark_cont_cpu_monitor, 175, 31);
    lv_obj_set_size(ui->Monitor_dark_cont_cpu_monitor, 146, 276);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_cont_cpu_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_cont_cpu_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cont_cpu_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cont_cpu_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_cont_cpu_monitor, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_cont_cpu_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_usage
    ui->Monitor_dark_cpu_usage = lv_obj_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_obj_set_pos(ui->Monitor_dark_cpu_usage, 0, 25);
    lv_obj_set_size(ui->Monitor_dark_cpu_usage, 143, 148);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_cpu_usage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_cpu_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_usage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Monitor_dark_cpu_usage, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Monitor_dark_cpu_usage, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_arc_1
    ui->Monitor_dark_arc_1 = lv_arc_create(ui->Monitor_dark_cpu_usage);
    lv_arc_set_mode(ui->Monitor_dark_arc_1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Monitor_dark_arc_1, 0, 100);
    lv_arc_set_bg_angles(ui->Monitor_dark_arc_1, 90, 89);
    lv_arc_set_value(ui->Monitor_dark_arc_1, 45);
    lv_arc_set_rotation(ui->Monitor_dark_arc_1, 0);
    lv_obj_set_style_arc_rounded(ui->Monitor_dark_arc_1, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Monitor_dark_arc_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Monitor_dark_arc_1, 6, 6);
    lv_obj_set_size(ui->Monitor_dark_arc_1, 137, 126);

    //Write style for Monitor_dark_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Monitor_dark_arc_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_dark_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_dark_arc_1, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_arc_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_arc_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Monitor_dark_arc_1, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_dark_arc_1, 202, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_dark_arc_1, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_arc_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Monitor_dark_arc_1, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_percent_label
    ui->Monitor_dark_cpu_percent_label = lv_label_create(ui->Monitor_dark_cpu_usage);
    lv_label_set_text(ui->Monitor_dark_cpu_percent_label, "%");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_percent_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_percent_label, 79, 51);
    lv_obj_set_size(ui->Monitor_dark_cpu_percent_label, 31, 39);

    //Write style for Monitor_dark_cpu_percent_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_percent_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_percent_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_percent_label, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_percent_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_percent_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_percent_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_percent_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_percent
    ui->Monitor_dark_cpu_percent = lv_label_create(ui->Monitor_dark_cpu_usage);
    lv_label_set_text(ui->Monitor_dark_cpu_percent, "45");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_percent, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_percent, 16, 51);
    lv_obj_set_size(ui->Monitor_dark_cpu_percent, 59, 39);

    //Write style for Monitor_dark_cpu_percent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_percent, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_percent, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_percent, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_percent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_percent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_percent, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_percent, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_monitor_title
    ui->Monitor_dark_cpu_monitor_title = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_monitor_title, "CPU Monitor");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_monitor_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_monitor_title, 0, 0);
    lv_obj_set_size(ui->Monitor_dark_cpu_monitor_title, 146, 26);

    //Write style for Monitor_dark_cpu_monitor_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_monitor_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_monitor_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_monitor_title, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_monitor_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_cpu_monitor_title, lv_color_hex(0x333f4f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_cpu_monitor_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_monitor_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_monitor_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_frequency_label
    ui->Monitor_dark_cpu_frequency_label = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_frequency_label, "Freq:");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_frequency_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_frequency_label, 9, 167);
    lv_obj_set_size(ui->Monitor_dark_cpu_frequency_label, 46, 23);

    //Write style for Monitor_dark_cpu_frequency_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_frequency_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_frequency_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_frequency_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_frequency_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_frequency_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_frequency_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_frequency_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ram_label
    ui->Monitor_dark_ram_label = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_ram_label, "RAM:");
    lv_label_set_long_mode(ui->Monitor_dark_ram_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ram_label, 21, 224);
    lv_obj_set_size(ui->Monitor_dark_ram_label, 46, 23);

    //Write style for Monitor_dark_ram_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ram_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ram_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ram_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ram_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ram_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ram_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ram_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ram_slider
    ui->Monitor_dark_ram_slider = lv_slider_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_slider_set_range(ui->Monitor_dark_ram_slider, 0, 100);
    lv_slider_set_mode(ui->Monitor_dark_ram_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Monitor_dark_ram_slider, 60, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Monitor_dark_ram_slider, 8, 249);
    lv_obj_set_size(ui->Monitor_dark_ram_slider, 126, 19);

    //Write style for Monitor_dark_ram_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ram_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_ram_slider, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_ram_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ram_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Monitor_dark_ram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_ram_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ram_slider, 212, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_ram_slider, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_ram_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ram_slider, 5, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_ram_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ram_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ram_slider, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_temp_label
    ui->Monitor_dark_cpu_temp_label = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_temp_label, "Temp:");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_temp_label, 3, 195);
    lv_obj_set_size(ui->Monitor_dark_cpu_temp_label, 64, 23);

    //Write style for Monitor_dark_cpu_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_temp_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_temp_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_temp_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_temp_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_temp_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_temp_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_temp_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_frequency_data
    ui->Monitor_dark_cpu_frequency_data = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_frequency_data, "0.90");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_frequency_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_frequency_data, 54, 168);
    lv_obj_set_size(ui->Monitor_dark_cpu_frequency_data, 41, 23);

    //Write style for Monitor_dark_cpu_frequency_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_frequency_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_frequency_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_frequency_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_frequency_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_frequency_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_frequency_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_frequency_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_frequency_unit
    ui->Monitor_dark_cpu_frequency_unit = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_frequency_unit, "Ghz");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_frequency_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_frequency_unit, 97, 168);
    lv_obj_set_size(ui->Monitor_dark_cpu_frequency_unit, 41, 23);

    //Write style for Monitor_dark_cpu_frequency_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_frequency_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_frequency_unit, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_frequency_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_frequency_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_frequency_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_frequency_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_frequency_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_temp_unit
    ui->Monitor_dark_cpu_temp_unit = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_temp_unit, "°C");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_temp_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_temp_unit, 104, 196);
    lv_obj_set_size(ui->Monitor_dark_cpu_temp_unit, 41, 23);

    //Write style for Monitor_dark_cpu_temp_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_temp_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_temp_unit, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_temp_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_temp_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_temp_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_temp_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_temp_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cpu_temp_data
    ui->Monitor_dark_cpu_temp_data = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_cpu_temp_data, "60");
    lv_label_set_long_mode(ui->Monitor_dark_cpu_temp_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_cpu_temp_data, 69, 196);
    lv_obj_set_size(ui->Monitor_dark_cpu_temp_data, 32, 20);

    //Write style for Monitor_dark_cpu_temp_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cpu_temp_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_cpu_temp_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_cpu_temp_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_cpu_temp_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_cpu_temp_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_cpu_temp_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cpu_temp_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ram_unit
    ui->Monitor_dark_ram_unit = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_ram_unit, "%");
    lv_label_set_long_mode(ui->Monitor_dark_ram_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ram_unit, 106, 224);
    lv_obj_set_size(ui->Monitor_dark_ram_unit, 41, 23);

    //Write style for Monitor_dark_ram_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ram_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ram_unit, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ram_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ram_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ram_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ram_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ram_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_ram_data
    ui->Monitor_dark_ram_data = lv_label_create(ui->Monitor_dark_cont_cpu_monitor);
    lv_label_set_text(ui->Monitor_dark_ram_data, "60");
    lv_label_set_long_mode(ui->Monitor_dark_ram_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_ram_data, 70, 224);
    lv_obj_set_size(ui->Monitor_dark_ram_data, 32, 23);

    //Write style for Monitor_dark_ram_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_ram_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_ram_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_ram_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_ram_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_ram_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_ram_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_ram_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_cont_gpu_monitor
    ui->Monitor_dark_cont_gpu_monitor = lv_obj_create(ui->Monitor_dark);
    lv_obj_set_pos(ui->Monitor_dark_cont_gpu_monitor, 17, 31);
    lv_obj_set_size(ui->Monitor_dark_cont_gpu_monitor, 146, 276);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_cont_gpu_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_cont_gpu_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_cont_gpu_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_cont_gpu_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_cont_gpu_monitor, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_cont_gpu_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_usage
    ui->Monitor_dark_gpu_usage = lv_obj_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_obj_set_pos(ui->Monitor_dark_gpu_usage, 0, 26);
    lv_obj_set_size(ui->Monitor_dark_gpu_usage, 143, 148);
    lv_obj_set_scrollbar_mode(ui->Monitor_dark_gpu_usage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Monitor_dark_gpu_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_usage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Monitor_dark_gpu_usage, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Monitor_dark_gpu_usage, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_arc_2
    ui->Monitor_dark_arc_2 = lv_arc_create(ui->Monitor_dark_gpu_usage);
    lv_arc_set_mode(ui->Monitor_dark_arc_2, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Monitor_dark_arc_2, 0, 100);
    lv_arc_set_bg_angles(ui->Monitor_dark_arc_2, 90, 89);
    lv_arc_set_value(ui->Monitor_dark_arc_2, 50);
    lv_arc_set_rotation(ui->Monitor_dark_arc_2, 0);
    lv_obj_set_style_arc_rounded(ui->Monitor_dark_arc_2, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Monitor_dark_arc_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Monitor_dark_arc_2, 6, 6);
    lv_obj_set_size(ui->Monitor_dark_arc_2, 137, 126);

    //Write style for Monitor_dark_arc_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Monitor_dark_arc_2, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_dark_arc_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_dark_arc_2, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_arc_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_arc_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Monitor_dark_arc_2, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Monitor_dark_arc_2, 170, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Monitor_dark_arc_2, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_arc_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_arc_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Monitor_dark_arc_2, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_percent_label
    ui->Monitor_dark_gpu_percent_label = lv_label_create(ui->Monitor_dark_gpu_usage);
    lv_label_set_text(ui->Monitor_dark_gpu_percent_label, "%");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_percent_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_percent_label, 79, 51);
    lv_obj_set_size(ui->Monitor_dark_gpu_percent_label, 31, 39);

    //Write style for Monitor_dark_gpu_percent_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_percent_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_percent_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_percent_label, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_percent_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_percent_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_percent_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_percent_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_percent
    ui->Monitor_dark_gpu_percent = lv_label_create(ui->Monitor_dark_gpu_usage);
    lv_label_set_text(ui->Monitor_dark_gpu_percent, "50");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_percent, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_percent, 16, 51);
    lv_obj_set_size(ui->Monitor_dark_gpu_percent, 59, 39);

    //Write style for Monitor_dark_gpu_percent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_percent, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_percent, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_percent, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_percent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_percent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_percent, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_percent, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_monitor_title
    ui->Monitor_dark_gpu_monitor_title = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_monitor_title, "GPU Monitor");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_monitor_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_monitor_title, 0, 0);
    lv_obj_set_size(ui->Monitor_dark_gpu_monitor_title, 146, 26);

    //Write style for Monitor_dark_gpu_monitor_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_monitor_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_monitor_title, lv_color_hex(0xD7CFED), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_monitor_title, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_monitor_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_gpu_monitor_title, lv_color_hex(0x322E43), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_gpu_monitor_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_monitor_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_monitor_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_frequency_label
    ui->Monitor_dark_gpu_frequency_label = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_frequency_label, "Freq:");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_frequency_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_frequency_label, 4, 167);
    lv_obj_set_size(ui->Monitor_dark_gpu_frequency_label, 46, 23);

    //Write style for Monitor_dark_gpu_frequency_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_frequency_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_frequency_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_frequency_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_frequency_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_frequency_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_frequency_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_frequency_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gram_label
    ui->Monitor_dark_gram_label = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gram_label, "GRAM:");
    lv_label_set_long_mode(ui->Monitor_dark_gram_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gram_label, 1, 224);
    lv_obj_set_size(ui->Monitor_dark_gram_label, 66, 23);

    //Write style for Monitor_dark_gram_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gram_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gram_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gram_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gram_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gram_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gram_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gram_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gram_slider
    ui->Monitor_dark_gram_slider = lv_slider_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_slider_set_range(ui->Monitor_dark_gram_slider, 0, 100);
    lv_slider_set_mode(ui->Monitor_dark_gram_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Monitor_dark_gram_slider, 90, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Monitor_dark_gram_slider, 8, 249);
    lv_obj_set_size(ui->Monitor_dark_gram_slider, 126, 19);

    //Write style for Monitor_dark_gram_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gram_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_gram_slider, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_gram_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gram_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Monitor_dark_gram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_gram_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gram_slider, 189, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_gram_slider, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_gram_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gram_slider, 5, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Monitor_dark_gram_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gram_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gram_slider, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_temp_label
    ui->Monitor_dark_gpu_temp_label = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_temp_label, "Temp:");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_temp_label, 3, 195);
    lv_obj_set_size(ui->Monitor_dark_gpu_temp_label, 64, 23);

    //Write style for Monitor_dark_gpu_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_temp_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_temp_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_temp_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_temp_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_temp_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_temp_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_temp_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_frequency_data
    ui->Monitor_dark_gpu_frequency_data = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_frequency_data, "2800");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_frequency_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_frequency_data, 52, 168);
    lv_obj_set_size(ui->Monitor_dark_gpu_frequency_data, 45, 23);

    //Write style for Monitor_dark_gpu_frequency_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_frequency_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_frequency_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_frequency_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_frequency_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_frequency_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_frequency_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_frequency_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_frequency_unit
    ui->Monitor_dark_gpu_frequency_unit = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_frequency_unit, "Mhz");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_frequency_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_frequency_unit, 100, 168);
    lv_obj_set_size(ui->Monitor_dark_gpu_frequency_unit, 41, 23);

    //Write style for Monitor_dark_gpu_frequency_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_frequency_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_frequency_unit, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_frequency_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_frequency_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_frequency_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_frequency_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_frequency_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gpu_temp_unit
    ui->Monitor_dark_gpu_temp_unit = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_temp_unit, "°C");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_temp_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_temp_unit, 104, 196);
    lv_obj_set_size(ui->Monitor_dark_gpu_temp_unit, 41, 23);

    //Write style for Monitor_dark_gpu_temp_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_temp_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_temp_unit, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_temp_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_temp_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_temp_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_temp_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_temp_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    UI_YIELD();

    //Write codes Monitor_dark_gpu_temp_data
    ui->Monitor_dark_gpu_temp_data = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gpu_temp_data, "75");
    lv_label_set_long_mode(ui->Monitor_dark_gpu_temp_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gpu_temp_data, 69, 196);
    lv_obj_set_size(ui->Monitor_dark_gpu_temp_data, 32, 19);

    //Write style for Monitor_dark_gpu_temp_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gpu_temp_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gpu_temp_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gpu_temp_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gpu_temp_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gpu_temp_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gpu_temp_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gpu_temp_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gram_unit
    ui->Monitor_dark_gram_unit = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gram_unit, "%");
    lv_label_set_long_mode(ui->Monitor_dark_gram_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gram_unit, 106, 224);
    lv_obj_set_size(ui->Monitor_dark_gram_unit, 41, 23);

    //Write style for Monitor_dark_gram_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gram_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gram_unit, lv_color_hex(0x8F9092), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gram_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gram_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gram_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gram_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gram_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_gram_data
    ui->Monitor_dark_gram_data = lv_label_create(ui->Monitor_dark_cont_gpu_monitor);
    lv_label_set_text(ui->Monitor_dark_gram_data, "90");
    lv_label_set_long_mode(ui->Monitor_dark_gram_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_gram_data, 70, 224);
    lv_obj_set_size(ui->Monitor_dark_gram_data, 32, 23);

    //Write style for Monitor_dark_gram_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_gram_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_gram_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_gram_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_gram_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_gram_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_gram_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_gram_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_label_home_title
    ui->Monitor_dark_label_home_title = lv_label_create(ui->Monitor_dark);
    lv_label_set_text(ui->Monitor_dark_label_home_title, "Performance Monitor");
    lv_label_set_long_mode(ui->Monitor_dark_label_home_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Monitor_dark_label_home_title, 80, 5);
    lv_obj_set_size(ui->Monitor_dark_label_home_title, 319, 20);

    //Write style for Monitor_dark_label_home_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Monitor_dark_label_home_title, lv_color_hex(0xe4e4e4), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_label_home_title, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_label_home_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Monitor_dark_label_home_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Monitor_dark_label_home_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Monitor_dark_menu
    ui->Monitor_dark_menu = lv_dropdown_create(ui->Monitor_dark);
    lv_dropdown_set_options(ui->Monitor_dark_menu, "PC\nHA");
    lv_obj_set_pos(ui->Monitor_dark_menu, 17, 5);
    lv_obj_set_size(ui->Monitor_dark_menu, 52, 24);

    //Write style for Monitor_dark_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Monitor_dark_menu, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Monitor_dark_menu, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Monitor_dark_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Monitor_dark_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Monitor_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Monitor_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Monitor_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Monitor_dark_menu, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Monitor_dark_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Monitor_dark_menu, lv_color_hex(0x3E3F43), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Monitor_dark_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Monitor_dark_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_Monitor_dark_menu_extra_list_selected_checked
    static lv_style_t style_Monitor_dark_menu_extra_list_selected_checked;
    ui_init_style(&style_Monitor_dark_menu_extra_list_selected_checked);

    lv_style_set_border_width(&style_Monitor_dark_menu_extra_list_selected_checked, 0);
    lv_style_set_radius(&style_Monitor_dark_menu_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_Monitor_dark_menu_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_Monitor_dark_menu_extra_list_selected_checked, lv_color_hex(0x4F5159));
    lv_style_set_bg_grad_dir(&style_Monitor_dark_menu_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Monitor_dark_menu), &style_Monitor_dark_menu_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_Monitor_dark_menu_extra_list_main_default
    static lv_style_t style_Monitor_dark_menu_extra_list_main_default;
    ui_init_style(&style_Monitor_dark_menu_extra_list_main_default);

    lv_style_set_max_height(&style_Monitor_dark_menu_extra_list_main_default, 80);
    lv_style_set_text_color(&style_Monitor_dark_menu_extra_list_main_default, lv_color_hex(0xebebeb));
    lv_style_set_text_font(&style_Monitor_dark_menu_extra_list_main_default, &lv_font_montserratMedium_15);
    lv_style_set_text_opa(&style_Monitor_dark_menu_extra_list_main_default, 255);
    lv_style_set_border_width(&style_Monitor_dark_menu_extra_list_main_default, 0);
    lv_style_set_radius(&style_Monitor_dark_menu_extra_list_main_default, 7);
    lv_style_set_bg_opa(&style_Monitor_dark_menu_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_Monitor_dark_menu_extra_list_main_default, lv_color_hex(0x3E3F43));
    lv_style_set_bg_grad_dir(&style_Monitor_dark_menu_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Monitor_dark_menu), &style_Monitor_dark_menu_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Monitor_dark.


    //Update current screen layout.
    lv_obj_update_layout(ui->Monitor_dark);

    //Init events for screen.
    events_init_Monitor_dark(ui);
}
