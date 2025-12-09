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



int Home_digital_clock_time_min_value = 25;
int Home_digital_clock_time_hour_value = 11;
int Home_digital_clock_time_sec_value = 50;
char Home_digital_clock_time_meridiem[] = "AM";
int Home_digital_clock_2_min_value = 25;
int Home_digital_clock_2_hour_value = 11;
int Home_digital_clock_2_sec_value = 50;
void setup_scr_Home(lv_ui *ui)
{
    //Write codes Home
    ui->Home = lv_obj_create(NULL);
    lv_obj_set_size(ui->Home, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home, lv_color_hex(0x232429), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_tileview_1
    ui->Home_tileview_1 = lv_tileview_create(ui->Home);
    ui->Home_tileview_1_preformance_monitor = lv_tileview_add_tile(ui->Home_tileview_1, 0, 0, LV_DIR_BOTTOM);
    ui->Home_tileview_1_ha_table = lv_tileview_add_tile(ui->Home_tileview_1, 0, 1, LV_DIR_TOP);
    lv_obj_set_pos(ui->Home_tileview_1, 0, 0);
    lv_obj_set_size(ui->Home_tileview_1, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Home_tileview_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_tileview_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_tileview_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_tileview_1, lv_color_hex(0x232429), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_tileview_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_tileview_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_tileview_1, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_tileview_1, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_tileview_1, lv_color_hex(0xeaeff3), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_tileview_1, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_tileview_1, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);



    //Write codes Home_time_monitor
    ui->Home_time_monitor = lv_obj_create(ui->Home_tileview_1_preformance_monitor);
    lv_obj_set_pos(ui->Home_time_monitor, 335, 31);
    lv_obj_set_size(ui->Home_time_monitor, 130, 121);
    lv_obj_set_scrollbar_mode(ui->Home_time_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_time_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_time_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_time_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_time_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_time_monitor, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_time_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_time_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_time_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_time_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_time_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_time_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_time_monitor_label
    ui->Home_time_monitor_label = lv_label_create(ui->Home_time_monitor);
    lv_label_set_text(ui->Home_time_monitor_label, "Time");
    lv_label_set_long_mode(ui->Home_time_monitor_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_time_monitor_label, 0, 0);
    lv_obj_set_size(ui->Home_time_monitor_label, 130, 25);

    //Write style for Home_time_monitor_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_time_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_time_monitor_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_time_monitor_label, lv_color_hex(0xE9DABE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_time_monitor_label, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_time_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_time_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_time_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_time_monitor_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_time_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_time_monitor_label, lv_color_hex(0x44392D), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_time_monitor_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_time_monitor_label, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_time_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_time_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_time_monitor_label, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_time_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_digital_clock_time
    static bool Home_digital_clock_time_timer_enabled = false;
    ui->Home_digital_clock_time = lv_dclock_create(ui->Home_time_monitor, "11:25:50 AM");
    if (!Home_digital_clock_time_timer_enabled) {
        lv_timer_create(Home_digital_clock_time_timer, 1000, NULL);
        Home_digital_clock_time_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Home_digital_clock_time, 13, 57);
    lv_obj_set_size(ui->Home_digital_clock_time, 98, 20);

    //Write style for Home_digital_clock_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_digital_clock_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_digital_clock_time, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_digital_clock_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_digital_clock_time, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_digital_clock_time, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_weekday
    ui->Home_weekday = lv_label_create(ui->Home_time_monitor);
    lv_label_set_text(ui->Home_weekday, "Tuesday");
    lv_label_set_long_mode(ui->Home_weekday, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_weekday, 9, 87);
    lv_obj_set_size(ui->Home_weekday, 103, 22);

    //Write style for Home_weekday, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_weekday, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_weekday, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_weekday, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_weekday, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_weekday, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_weekday, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_weekday, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_date
    ui->Home_date = lv_label_create(ui->Home_time_monitor);
    lv_label_set_text(ui->Home_date, "2025/10/14");
    lv_obj_set_style_text_align(ui->Home_date, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->Home_date, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->Home_date, Home_date_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->Home_date, 23, 27);
    lv_obj_set_size(ui->Home_date, 81, 24);

    //Write style for Home_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Home_date, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_date, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_date, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_net_monitor
    ui->Home_net_monitor = lv_obj_create(ui->Home_tileview_1_preformance_monitor);
    lv_obj_set_pos(ui->Home_net_monitor, 335, 164);
    lv_obj_set_size(ui->Home_net_monitor, 130, 144);
    lv_obj_set_scrollbar_mode(ui->Home_net_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_net_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_net_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_net_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_net_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_net_monitor, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_net_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_net_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_net_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_net_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_net_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_net_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_net_speed
    ui->Home_net_speed = lv_obj_create(ui->Home_net_monitor);
    lv_obj_set_pos(ui->Home_net_speed, 1, 33);
    lv_obj_set_size(ui->Home_net_speed, 120, 59);
    lv_obj_set_scrollbar_mode(ui->Home_net_speed, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_net_speed, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_net_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_net_speed, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_net_speed, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_net_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_download_data
    ui->Home_download_data = lv_spangroup_create(ui->Home_net_speed);
    lv_spangroup_set_align(ui->Home_download_data, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_download_data, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_download_data, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_download_data_span = lv_spangroup_new_span(ui->Home_download_data);
    lv_span_set_text(ui->Home_download_data_span, "2400.50");
    lv_style_set_text_color(&ui->Home_download_data_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_download_data_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_download_data_span->style, &lv_font_montserratMedium_15);
    ui->Home_download_data_span = lv_spangroup_new_span(ui->Home_download_data);
    lv_span_set_text(ui->Home_download_data_span, " Mbps");
    lv_style_set_text_color(&ui->Home_download_data_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_download_data_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_download_data_span->style, &lv_font_montserratMedium_13);
    lv_obj_set_pos(ui->Home_download_data, 18, 22);
    lv_obj_set_size(ui->Home_download_data, 110, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_download_data_main_main_default
    static lv_style_t style_Home_download_data_main_main_default;
    ui_init_style(&style_Home_download_data_main_main_default);

    lv_style_set_border_width(&style_Home_download_data_main_main_default, 0);
    lv_style_set_radius(&style_Home_download_data_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_download_data_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_download_data_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_download_data_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_download_data_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_download_data_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_download_data_main_main_default, 0);
    lv_obj_add_style(ui->Home_download_data, &style_Home_download_data_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_download_data);

    //Write codes Home_download_icon
    ui->Home_download_icon = lv_img_create(ui->Home_net_speed);
    lv_obj_add_flag(ui->Home_download_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_download_icon, &_download_alpha_13x13);
    lv_img_set_pivot(ui->Home_download_icon, 50,50);
    lv_img_set_angle(ui->Home_download_icon, 0);
    lv_obj_set_pos(ui->Home_download_icon, 2, 28);
    lv_obj_set_size(ui->Home_download_icon, 13, 13);

    //Write style for Home_download_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_download_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_download_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_download_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_download_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_upload_data
    ui->Home_upload_data = lv_spangroup_create(ui->Home_net_speed);
    lv_spangroup_set_align(ui->Home_upload_data, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_upload_data, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_upload_data, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_upload_data_span = lv_spangroup_new_span(ui->Home_upload_data);
    lv_span_set_text(ui->Home_upload_data_span, "2400.50");
    lv_style_set_text_color(&ui->Home_upload_data_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_upload_data_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_upload_data_span->style, &lv_font_montserratMedium_15);
    ui->Home_upload_data_span = lv_spangroup_new_span(ui->Home_upload_data);
    lv_span_set_text(ui->Home_upload_data_span, " Mbps");
    lv_style_set_text_color(&ui->Home_upload_data_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_upload_data_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_upload_data_span->style, &lv_font_montserratMedium_13);
    lv_obj_set_pos(ui->Home_upload_data, 18, -2);
    lv_obj_set_size(ui->Home_upload_data, 110, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_upload_data_main_main_default
    static lv_style_t style_Home_upload_data_main_main_default;
    ui_init_style(&style_Home_upload_data_main_main_default);

    lv_style_set_border_width(&style_Home_upload_data_main_main_default, 0);
    lv_style_set_radius(&style_Home_upload_data_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_upload_data_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_upload_data_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_upload_data_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_upload_data_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_upload_data_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_upload_data_main_main_default, 0);
    lv_obj_add_style(ui->Home_upload_data, &style_Home_upload_data_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_upload_data);

    //Write codes Home_upload_icon
    ui->Home_upload_icon = lv_img_create(ui->Home_net_speed);
    lv_obj_add_flag(ui->Home_upload_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_upload_icon, &_upload_alpha_13x13);
    lv_img_set_pivot(ui->Home_upload_icon, 50,50);
    lv_img_set_angle(ui->Home_upload_icon, 0);
    lv_obj_set_pos(ui->Home_upload_icon, 2, 3);
    lv_obj_set_size(ui->Home_upload_icon, 13, 13);

    //Write style for Home_upload_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_upload_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_upload_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_upload_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_upload_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_net_monitor_label
    ui->Home_net_monitor_label = lv_label_create(ui->Home_net_monitor);
    lv_label_set_text(ui->Home_net_monitor_label, "Network Monitor");
    lv_label_set_long_mode(ui->Home_net_monitor_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_net_monitor_label, 0, 0);
    lv_obj_set_size(ui->Home_net_monitor_label, 130, 26);

    //Write style for Home_net_monitor_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_net_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_net_monitor_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_net_monitor_label, lv_color_hex(0xB6E0D9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_net_monitor_label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_net_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_net_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_net_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_net_monitor_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_net_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_net_monitor_label, lv_color_hex(0x263C3D), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_net_monitor_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_net_monitor_label, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_net_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_net_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_net_monitor_label, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_net_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ip_data
    ui->Home_ip_data = lv_label_create(ui->Home_net_monitor);
    lv_label_set_text(ui->Home_ip_data, "China");
    lv_label_set_long_mode(ui->Home_ip_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ip_data, 58, 109);
    lv_obj_set_size(ui->Home_ip_data, 81, 16);

    //Write style for Home_ip_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ip_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ip_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ip_data, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ip_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ip_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ip_data, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ip_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ip_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ip_label
    ui->Home_ip_label = lv_label_create(ui->Home_net_monitor);
    lv_label_set_text(ui->Home_ip_label, "IPloc:");
    lv_label_set_long_mode(ui->Home_ip_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ip_label, 13, 110);
    lv_obj_set_size(ui->Home_ip_label, 41, 22);

    //Write style for Home_ip_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ip_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ip_label, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ip_label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ip_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ip_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ip_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ip_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_net_ping
    ui->Home_net_ping = lv_spangroup_create(ui->Home_net_monitor);
    lv_spangroup_set_align(ui->Home_net_ping, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_net_ping, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_net_ping, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_net_ping_span = lv_spangroup_new_span(ui->Home_net_ping);
    lv_span_set_text(ui->Home_net_ping_span, "240");
    lv_style_set_text_color(&ui->Home_net_ping_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_net_ping_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_net_ping_span->style, &lv_font_montserratMedium_15);
    ui->Home_net_ping_span = lv_spangroup_new_span(ui->Home_net_ping);
    lv_span_set_text(ui->Home_net_ping_span, " ms");
    lv_style_set_text_color(&ui->Home_net_ping_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_net_ping_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_net_ping_span->style, &lv_font_montserratMedium_13);
    lv_obj_set_pos(ui->Home_net_ping, 59, 84);
    lv_obj_set_size(ui->Home_net_ping, 72, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_net_ping_main_main_default
    static lv_style_t style_Home_net_ping_main_main_default;
    ui_init_style(&style_Home_net_ping_main_main_default);

    lv_style_set_border_width(&style_Home_net_ping_main_main_default, 0);
    lv_style_set_radius(&style_Home_net_ping_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_net_ping_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_net_ping_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_net_ping_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_net_ping_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_net_ping_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_net_ping_main_main_default, 0);
    lv_obj_add_style(ui->Home_net_ping, &style_Home_net_ping_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_net_ping);

    //Write codes Home_net_ping_label
    ui->Home_net_ping_label = lv_label_create(ui->Home_net_monitor);
    lv_label_set_text(ui->Home_net_ping_label, "Ping:");
    lv_label_set_long_mode(ui->Home_net_ping_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_net_ping_label, 13, 85);
    lv_obj_set_size(ui->Home_net_ping_label, 46, 22);

    //Write style for Home_net_ping_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_net_ping_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_net_ping_label, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_net_ping_label, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_net_ping_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_net_ping_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_net_ping_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_net_ping_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_net_ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_monitor
    ui->Home_cpu_monitor = lv_obj_create(ui->Home_tileview_1_preformance_monitor);
    lv_obj_set_pos(ui->Home_cpu_monitor, 175, 31);
    lv_obj_set_size(ui->Home_cpu_monitor, 146, 276);
    lv_obj_set_scrollbar_mode(ui->Home_cpu_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cpu_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cpu_monitor, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cpu_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_usage
    ui->Home_cpu_usage = lv_obj_create(ui->Home_cpu_monitor);
    lv_obj_set_pos(ui->Home_cpu_usage, 0, 25);
    lv_obj_set_size(ui->Home_cpu_usage, 143, 148);
    lv_obj_set_scrollbar_mode(ui->Home_cpu_usage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cpu_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_usage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_cpu_usage, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_cpu_usage, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_2
    ui->Home_arc_2 = lv_arc_create(ui->Home_cpu_usage);
    lv_arc_set_mode(ui->Home_arc_2, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_2, 0, 100);
    lv_arc_set_bg_angles(ui->Home_arc_2, 90, 89);
    lv_arc_set_value(ui->Home_arc_2, 45);
    lv_arc_set_rotation(ui->Home_arc_2, 0);
    lv_obj_set_style_arc_rounded(ui->Home_arc_2, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Home_arc_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Home_arc_2, 9, 6);
    lv_obj_set_size(ui->Home_arc_2, 126, 126);

    //Write style for Home_arc_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_2, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_2, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_2, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_2, 202, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_2, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_2, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_cpu_percent
    ui->Home_cpu_percent = lv_spangroup_create(ui->Home_cpu_usage);
    lv_spangroup_set_align(ui->Home_cpu_percent, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_cpu_percent, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_cpu_percent, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_cpu_percent_span = lv_spangroup_new_span(ui->Home_cpu_percent);
    lv_span_set_text(ui->Home_cpu_percent_span, "30");
    lv_style_set_text_color(&ui->Home_cpu_percent_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_cpu_percent_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_cpu_percent_span->style, &lv_font_montserratMedium_35);
    ui->Home_cpu_percent_span = lv_spangroup_new_span(ui->Home_cpu_percent);
    lv_span_set_text(ui->Home_cpu_percent_span, "%");
    lv_style_set_text_color(&ui->Home_cpu_percent_span->style, lv_color_hex(0xd2d2d2));
    lv_style_set_text_decor(&ui->Home_cpu_percent_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_cpu_percent_span->style, &lv_font_montserratMedium_35);
    lv_obj_set_pos(ui->Home_cpu_percent, 32, 50);
    lv_obj_set_size(ui->Home_cpu_percent, 80, 41);

    //Write style state: LV_STATE_DEFAULT for &style_Home_cpu_percent_main_main_default
    static lv_style_t style_Home_cpu_percent_main_main_default;
    ui_init_style(&style_Home_cpu_percent_main_main_default);

    lv_style_set_border_width(&style_Home_cpu_percent_main_main_default, 0);
    lv_style_set_radius(&style_Home_cpu_percent_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_cpu_percent_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_cpu_percent_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_cpu_percent_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_cpu_percent_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_cpu_percent_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_cpu_percent_main_main_default, 0);
    lv_obj_add_style(ui->Home_cpu_percent, &style_Home_cpu_percent_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_cpu_percent);

    //Write codes Home_cpu_monitor_label
    ui->Home_cpu_monitor_label = lv_label_create(ui->Home_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_monitor_label, "CPU Monitor");
    lv_label_set_long_mode(ui->Home_cpu_monitor_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_monitor_label, 0, 0);
    lv_obj_set_size(ui->Home_cpu_monitor_label, 146, 26);

    //Write style for Home_cpu_monitor_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_monitor_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_monitor_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_monitor_label, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_monitor_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cpu_monitor_label, lv_color_hex(0x333f4f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cpu_monitor_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_monitor_label, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_monitor_label, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ram_slider
    ui->Home_ram_slider = lv_slider_create(ui->Home_cpu_monitor);
    lv_slider_set_range(ui->Home_ram_slider, 0, 100);
    lv_slider_set_mode(ui->Home_ram_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Home_ram_slider, 60, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_ram_slider, 8, 249);
    lv_obj_set_size(ui->Home_ram_slider, 126, 19);

    //Write style for Home_ram_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_ram_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_ram_slider, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_ram_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Home_ram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_ram_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_ram_slider, 212, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_ram_slider, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_ram_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_slider, 5, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_ram_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_ram_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_slider, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_ram_usage
    ui->Home_ram_usage = lv_spangroup_create(ui->Home_cpu_monitor);
    lv_spangroup_set_align(ui->Home_ram_usage, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_ram_usage, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_ram_usage, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_ram_usage_span = lv_spangroup_new_span(ui->Home_ram_usage);
    lv_span_set_text(ui->Home_ram_usage_span, "86");
    lv_style_set_text_color(&ui->Home_ram_usage_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_ram_usage_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_ram_usage_span->style, &lv_font_montserratMedium_17);
    ui->Home_ram_usage_span = lv_spangroup_new_span(ui->Home_ram_usage);
    lv_span_set_text(ui->Home_ram_usage_span, " %");
    lv_style_set_text_color(&ui->Home_ram_usage_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_ram_usage_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_ram_usage_span->style, &lv_font_montserratMedium_15);
    lv_obj_set_pos(ui->Home_ram_usage, 77, 225);
    lv_obj_set_size(ui->Home_ram_usage, 59, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_ram_usage_main_main_default
    static lv_style_t style_Home_ram_usage_main_main_default;
    ui_init_style(&style_Home_ram_usage_main_main_default);

    lv_style_set_border_width(&style_Home_ram_usage_main_main_default, 0);
    lv_style_set_radius(&style_Home_ram_usage_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_ram_usage_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_ram_usage_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_ram_usage_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_ram_usage_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_ram_usage_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_ram_usage_main_main_default, 0);
    lv_obj_add_style(ui->Home_ram_usage, &style_Home_ram_usage_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_ram_usage);

    //Write codes Home_ram_label
    ui->Home_ram_label = lv_label_create(ui->Home_cpu_monitor);
    lv_label_set_text(ui->Home_ram_label, "RAM:");
    lv_label_set_long_mode(ui->Home_ram_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ram_label, 21, 224);
    lv_obj_set_size(ui->Home_ram_label, 46, 23);

    //Write style for Home_ram_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ram_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ram_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ram_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ram_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ram_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ram_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_temp
    ui->Home_cpu_temp = lv_spangroup_create(ui->Home_cpu_monitor);
    lv_spangroup_set_align(ui->Home_cpu_temp, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_cpu_temp, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_cpu_temp, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_cpu_temp_span = lv_spangroup_new_span(ui->Home_cpu_temp);
    lv_span_set_text(ui->Home_cpu_temp_span, "60");
    lv_style_set_text_color(&ui->Home_cpu_temp_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_cpu_temp_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_cpu_temp_span->style, &lv_font_montserratMedium_17);
    ui->Home_cpu_temp_span = lv_spangroup_new_span(ui->Home_cpu_temp);
    lv_span_set_text(ui->Home_cpu_temp_span, " °C");
    lv_style_set_text_color(&ui->Home_cpu_temp_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_cpu_temp_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_cpu_temp_span->style, &lv_font_montserratMedium_15);
    lv_obj_set_pos(ui->Home_cpu_temp, 76, 195);
    lv_obj_set_size(ui->Home_cpu_temp, 65, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_cpu_temp_main_main_default
    static lv_style_t style_Home_cpu_temp_main_main_default;
    ui_init_style(&style_Home_cpu_temp_main_main_default);

    lv_style_set_border_width(&style_Home_cpu_temp_main_main_default, 0);
    lv_style_set_radius(&style_Home_cpu_temp_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_cpu_temp_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_cpu_temp_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_cpu_temp_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_cpu_temp_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_cpu_temp_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_cpu_temp_main_main_default, 0);
    lv_obj_add_style(ui->Home_cpu_temp, &style_Home_cpu_temp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_cpu_temp);

    //Write codes Home_cpu_temp_label
    ui->Home_cpu_temp_label = lv_label_create(ui->Home_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_temp_label, "Temp:");
    lv_label_set_long_mode(ui->Home_cpu_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_temp_label, 3, 195);
    lv_obj_set_size(ui->Home_cpu_temp_label, 64, 23);

    //Write style for Home_cpu_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_temp_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_temp_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_temp_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_temp_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_temp_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_temp_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_temp_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_frequency
    ui->Home_cpu_frequency = lv_spangroup_create(ui->Home_cpu_monitor);
    lv_spangroup_set_align(ui->Home_cpu_frequency, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_cpu_frequency, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_cpu_frequency, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_cpu_frequency_span = lv_spangroup_new_span(ui->Home_cpu_frequency);
    lv_span_set_text(ui->Home_cpu_frequency_span, "4.0");
    lv_style_set_text_color(&ui->Home_cpu_frequency_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_cpu_frequency_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_cpu_frequency_span->style, &lv_font_montserratMedium_17);
    ui->Home_cpu_frequency_span = lv_spangroup_new_span(ui->Home_cpu_frequency);
    lv_span_set_text(ui->Home_cpu_frequency_span, " GHz");
    lv_style_set_text_color(&ui->Home_cpu_frequency_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_cpu_frequency_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_cpu_frequency_span->style, &lv_font_montserratMedium_15);
    lv_obj_set_pos(ui->Home_cpu_frequency, 72, 168);
    lv_obj_set_size(ui->Home_cpu_frequency, 78, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_cpu_frequency_main_main_default
    static lv_style_t style_Home_cpu_frequency_main_main_default;
    ui_init_style(&style_Home_cpu_frequency_main_main_default);

    lv_style_set_border_width(&style_Home_cpu_frequency_main_main_default, 0);
    lv_style_set_radius(&style_Home_cpu_frequency_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_cpu_frequency_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_cpu_frequency_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_cpu_frequency_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_cpu_frequency_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_cpu_frequency_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_cpu_frequency_main_main_default, 0);
    lv_obj_add_style(ui->Home_cpu_frequency, &style_Home_cpu_frequency_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_cpu_frequency);

    //Write codes Home_cpu_freq_label
    ui->Home_cpu_freq_label = lv_label_create(ui->Home_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_freq_label, "Freq:");
    lv_label_set_long_mode(ui->Home_cpu_freq_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_freq_label, 21, 167);
    lv_obj_set_size(ui->Home_cpu_freq_label, 46, 23);

    //Write style for Home_cpu_freq_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_freq_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_freq_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_freq_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_freq_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_freq_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_freq_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_freq_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_monitor
    ui->Home_gpu_monitor = lv_obj_create(ui->Home_tileview_1_preformance_monitor);
    lv_obj_set_pos(ui->Home_gpu_monitor, 17, 31);
    lv_obj_set_size(ui->Home_gpu_monitor, 146, 276);
    lv_obj_set_scrollbar_mode(ui->Home_gpu_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_gpu_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gpu_monitor, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gpu_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_usage
    ui->Home_gpu_usage = lv_obj_create(ui->Home_gpu_monitor);
    lv_obj_set_pos(ui->Home_gpu_usage, 0, 26);
    lv_obj_set_size(ui->Home_gpu_usage, 143, 148);
    lv_obj_set_scrollbar_mode(ui->Home_gpu_usage, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_gpu_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_usage, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_gpu_usage, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_gpu_usage, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_1
    ui->Home_arc_1 = lv_arc_create(ui->Home_gpu_usage);
    lv_arc_set_mode(ui->Home_arc_1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_1, 0, 100);
    lv_arc_set_bg_angles(ui->Home_arc_1, 90, 89);
    lv_arc_set_value(ui->Home_arc_1, 50);
    lv_arc_set_rotation(ui->Home_arc_1, 0);
    lv_obj_set_style_arc_rounded(ui->Home_arc_1, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Home_arc_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Home_arc_1, 9, 6);
    lv_obj_set_size(ui->Home_arc_1, 126, 126);

    //Write style for Home_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_1, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_1, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_1, 170, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_1, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_1, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_gpu_percent
    ui->Home_gpu_percent = lv_spangroup_create(ui->Home_gpu_usage);
    lv_spangroup_set_align(ui->Home_gpu_percent, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_gpu_percent, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_gpu_percent, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_gpu_percent_span = lv_spangroup_new_span(ui->Home_gpu_percent);
    lv_span_set_text(ui->Home_gpu_percent_span, "90");
    lv_style_set_text_color(&ui->Home_gpu_percent_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_gpu_percent_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gpu_percent_span->style, &lv_font_montserratMedium_35);
    ui->Home_gpu_percent_span = lv_spangroup_new_span(ui->Home_gpu_percent);
    lv_span_set_text(ui->Home_gpu_percent_span, "%");
    lv_style_set_text_color(&ui->Home_gpu_percent_span->style, lv_color_hex(0xd2d2d2));
    lv_style_set_text_decor(&ui->Home_gpu_percent_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gpu_percent_span->style, &lv_font_montserratMedium_35);
    lv_obj_set_pos(ui->Home_gpu_percent, 32, 50);
    lv_obj_set_size(ui->Home_gpu_percent, 80, 41);

    //Write style state: LV_STATE_DEFAULT for &style_Home_gpu_percent_main_main_default
    static lv_style_t style_Home_gpu_percent_main_main_default;
    ui_init_style(&style_Home_gpu_percent_main_main_default);

    lv_style_set_border_width(&style_Home_gpu_percent_main_main_default, 0);
    lv_style_set_radius(&style_Home_gpu_percent_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_gpu_percent_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_gpu_percent_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_gpu_percent_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_gpu_percent_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_gpu_percent_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_gpu_percent_main_main_default, 0);
    lv_obj_add_style(ui->Home_gpu_percent, &style_Home_gpu_percent_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_gpu_percent);

    //Write codes Home_gpu_monitor_label
    ui->Home_gpu_monitor_label = lv_label_create(ui->Home_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_monitor_label, "GPU Monitor");
    lv_label_set_long_mode(ui->Home_gpu_monitor_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_monitor_label, 0, 0);
    lv_obj_set_size(ui->Home_gpu_monitor_label, 146, 26);

    //Write style for Home_gpu_monitor_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_monitor_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_monitor_label, lv_color_hex(0xD7CFED), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_monitor_label, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_monitor_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_monitor_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gpu_monitor_label, lv_color_hex(0x322E43), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gpu_monitor_label, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_monitor_label, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_monitor_label, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_monitor_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gram_slider
    ui->Home_gram_slider = lv_slider_create(ui->Home_gpu_monitor);
    lv_slider_set_range(ui->Home_gram_slider, 0, 100);
    lv_slider_set_mode(ui->Home_gram_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Home_gram_slider, 20, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_gram_slider, 8, 249);
    lv_obj_set_size(ui->Home_gram_slider, 126, 19);

    //Write style for Home_gram_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_gram_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gram_slider, lv_color_hex(0x636363), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gram_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Home_gram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_gram_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_gram_slider, 189, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gram_slider, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gram_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_slider, 5, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_gram_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_gram_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_slider, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_gram_usage
    ui->Home_gram_usage = lv_spangroup_create(ui->Home_gpu_monitor);
    lv_spangroup_set_align(ui->Home_gram_usage, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_gram_usage, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_gram_usage, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_gram_usage_span = lv_spangroup_new_span(ui->Home_gram_usage);
    lv_span_set_text(ui->Home_gram_usage_span, "20");
    lv_style_set_text_color(&ui->Home_gram_usage_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_gram_usage_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gram_usage_span->style, &lv_font_montserratMedium_17);
    ui->Home_gram_usage_span = lv_spangroup_new_span(ui->Home_gram_usage);
    lv_span_set_text(ui->Home_gram_usage_span, " %");
    lv_style_set_text_color(&ui->Home_gram_usage_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_gram_usage_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gram_usage_span->style, &lv_font_montserratMedium_15);
    lv_obj_set_pos(ui->Home_gram_usage, 75, 224);
    lv_obj_set_size(ui->Home_gram_usage, 68, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_gram_usage_main_main_default
    static lv_style_t style_Home_gram_usage_main_main_default;
    ui_init_style(&style_Home_gram_usage_main_main_default);

    lv_style_set_border_width(&style_Home_gram_usage_main_main_default, 0);
    lv_style_set_radius(&style_Home_gram_usage_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_gram_usage_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_gram_usage_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_gram_usage_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_gram_usage_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_gram_usage_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_gram_usage_main_main_default, 0);
    lv_obj_add_style(ui->Home_gram_usage, &style_Home_gram_usage_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_gram_usage);

    //Write codes Home_gram_label
    ui->Home_gram_label = lv_label_create(ui->Home_gpu_monitor);
    lv_label_set_text(ui->Home_gram_label, "GRAM:");
    lv_label_set_long_mode(ui->Home_gram_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gram_label, 2, 224);
    lv_obj_set_size(ui->Home_gram_label, 66, 23);

    //Write style for Home_gram_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gram_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gram_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gram_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gram_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gram_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gram_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_temp
    ui->Home_gpu_temp = lv_spangroup_create(ui->Home_gpu_monitor);
    lv_spangroup_set_align(ui->Home_gpu_temp, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_gpu_temp, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_gpu_temp, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_gpu_temp_span = lv_spangroup_new_span(ui->Home_gpu_temp);
    lv_span_set_text(ui->Home_gpu_temp_span, "75");
    lv_style_set_text_color(&ui->Home_gpu_temp_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_gpu_temp_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gpu_temp_span->style, &lv_font_montserratMedium_17);
    ui->Home_gpu_temp_span = lv_spangroup_new_span(ui->Home_gpu_temp);
    lv_span_set_text(ui->Home_gpu_temp_span, " °C");
    lv_style_set_text_color(&ui->Home_gpu_temp_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_gpu_temp_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gpu_temp_span->style, &lv_font_montserratMedium_15);
    lv_obj_set_pos(ui->Home_gpu_temp, 75, 196);
    lv_obj_set_size(ui->Home_gpu_temp, 67, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_gpu_temp_main_main_default
    static lv_style_t style_Home_gpu_temp_main_main_default;
    ui_init_style(&style_Home_gpu_temp_main_main_default);

    lv_style_set_border_width(&style_Home_gpu_temp_main_main_default, 0);
    lv_style_set_radius(&style_Home_gpu_temp_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_gpu_temp_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_gpu_temp_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_gpu_temp_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_gpu_temp_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_gpu_temp_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_gpu_temp_main_main_default, 0);
    lv_obj_add_style(ui->Home_gpu_temp, &style_Home_gpu_temp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_gpu_temp);

    //Write codes Home_gpu_temp_label
    ui->Home_gpu_temp_label = lv_label_create(ui->Home_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_temp_label, "Temp:");
    lv_label_set_long_mode(ui->Home_gpu_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_temp_label, 4, 196);
    lv_obj_set_size(ui->Home_gpu_temp_label, 64, 23);

    //Write style for Home_gpu_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_temp_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_temp_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_temp_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_temp_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_temp_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_temp_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_temp_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_frequency
    ui->Home_gpu_frequency = lv_spangroup_create(ui->Home_gpu_monitor);
    lv_spangroup_set_align(ui->Home_gpu_frequency, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_gpu_frequency, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_gpu_frequency, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_gpu_frequency_span = lv_spangroup_new_span(ui->Home_gpu_frequency);
    lv_span_set_text(ui->Home_gpu_frequency_span, "2400");
    lv_style_set_text_color(&ui->Home_gpu_frequency_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_gpu_frequency_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gpu_frequency_span->style, &lv_font_montserratMedium_17);
    ui->Home_gpu_frequency_span = lv_spangroup_new_span(ui->Home_gpu_frequency);
    lv_span_set_text(ui->Home_gpu_frequency_span, " MHz");
    lv_style_set_text_color(&ui->Home_gpu_frequency_span->style, lv_color_hex(0x8F9092));
    lv_style_set_text_decor(&ui->Home_gpu_frequency_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_gpu_frequency_span->style, &lv_font_montserratMedium_15);
    lv_obj_set_pos(ui->Home_gpu_frequency, 57, 169);
    lv_obj_set_size(ui->Home_gpu_frequency, 87, 23);

    //Write style state: LV_STATE_DEFAULT for &style_Home_gpu_frequency_main_main_default
    static lv_style_t style_Home_gpu_frequency_main_main_default;
    ui_init_style(&style_Home_gpu_frequency_main_main_default);

    lv_style_set_border_width(&style_Home_gpu_frequency_main_main_default, 0);
    lv_style_set_radius(&style_Home_gpu_frequency_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_gpu_frequency_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_gpu_frequency_main_main_default, 4);
    lv_style_set_pad_right(&style_Home_gpu_frequency_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_gpu_frequency_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_gpu_frequency_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_gpu_frequency_main_main_default, 0);
    lv_obj_add_style(ui->Home_gpu_frequency, &style_Home_gpu_frequency_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_gpu_frequency);

    //Write codes Home_gpu_freq_label
    ui->Home_gpu_freq_label = lv_label_create(ui->Home_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_freq_label, "Freq:");
    lv_label_set_long_mode(ui->Home_gpu_freq_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_freq_label, 5, 168);
    lv_obj_set_size(ui->Home_gpu_freq_label, 46, 23);

    //Write style for Home_gpu_freq_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_freq_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_freq_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_freq_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_freq_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_freq_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_freq_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_freq_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_freq_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_perform_title
    ui->Home_perform_title = lv_label_create(ui->Home_tileview_1_preformance_monitor);
    lv_label_set_text(ui->Home_perform_title, "Performance Monitor");
    lv_label_set_long_mode(ui->Home_perform_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_perform_title, 80, 5);
    lv_obj_set_size(ui->Home_perform_title, 319, 20);

    //Write style for Home_perform_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_perform_title, lv_color_hex(0xe4e4e4), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_perform_title, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_perform_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_perform_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_perform_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_perform_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    //Write codes Home_cont_14
    ui->Home_cont_14 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_14, 15, 251);
    lv_obj_set_size(ui->Home_cont_14, 450, 50);
    lv_obj_set_scrollbar_mode(ui->Home_cont_14, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_14, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_14, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_14, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_14, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_14, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_14, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_bar_1
    ui->Home_bar_1 = lv_bar_create(ui->Home_cont_14);
    lv_obj_set_style_anim_time(ui->Home_bar_1, 1000, 0);
    lv_bar_set_mode(ui->Home_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Home_bar_1, 0, 100);
    lv_bar_set_value(ui->Home_bar_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_bar_1, 103, 12);
    lv_obj_set_size(ui->Home_bar_1, 335, 28);

    //Write style for Home_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_1, 111, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_1, lv_color_hex(0xb1b1b1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_1, lv_color_hex(0xf5bb0d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Home_label_47
    ui->Home_label_47 = lv_label_create(ui->Home_cont_14);
    lv_label_set_text(ui->Home_label_47, "3D Printer\n");
    lv_label_set_long_mode(ui->Home_label_47, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_47, 10, 10);
    lv_obj_set_size(ui->Home_label_47, 104, 17);

    //Write style for Home_label_47, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_47, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_47, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_47, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_47, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_47, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_8
    ui->Home_spangroup_8 = lv_spangroup_create(ui->Home_cont_14);
    lv_spangroup_set_align(ui->Home_spangroup_8, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_8, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_8, LV_SPAN_MODE_BREAK);
    //create span
    ui->Home_spangroup_8_span = lv_spangroup_new_span(ui->Home_spangroup_8);
    lv_span_set_text(ui->Home_spangroup_8_span, "A1");
    lv_style_set_text_color(&ui->Home_spangroup_8_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_8_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_8_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_8_span = lv_spangroup_new_span(ui->Home_spangroup_8);
    lv_span_set_text(ui->Home_spangroup_8_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_8_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_8_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_8_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_8_span = lv_spangroup_new_span(ui->Home_spangroup_8);
    lv_span_set_text(ui->Home_spangroup_8_span, "10h45min");
    lv_style_set_text_color(&ui->Home_spangroup_8_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_8_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_8_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->Home_spangroup_8, 10, 30);
    lv_obj_set_size(ui->Home_spangroup_8, 165, 12);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_8_main_main_default
    static lv_style_t style_Home_spangroup_8_main_main_default;
    ui_init_style(&style_Home_spangroup_8_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_8_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_8_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_8, &style_Home_spangroup_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_8);

    //Write codes Home_cont_13
    ui->Home_cont_13 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_13, 15, 131);
    lv_obj_set_size(ui->Home_cont_13, 180, 50);
    lv_obj_set_scrollbar_mode(ui->Home_cont_13, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_13, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_13, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_13, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_13, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_13, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_13, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_46
    ui->Home_label_46 = lv_label_create(ui->Home_cont_13);
    lv_label_set_text(ui->Home_label_46, "Temperature");
    lv_label_set_long_mode(ui->Home_label_46, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_46, 55, 10);
    lv_obj_set_size(ui->Home_label_46, 108, 19);

    //Write style for Home_label_46, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_46, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_46, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_46, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_46, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_46, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_7
    ui->Home_spangroup_7 = lv_spangroup_create(ui->Home_cont_13);
    lv_spangroup_set_align(ui->Home_spangroup_7, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_7, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_7, LV_SPAN_MODE_BREAK);
    //create span
    ui->Home_spangroup_7_span = lv_spangroup_new_span(ui->Home_spangroup_7);
    lv_span_set_text(ui->Home_spangroup_7_span, "21°C");
    lv_style_set_text_color(&ui->Home_spangroup_7_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_7_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_7_span = lv_spangroup_new_span(ui->Home_spangroup_7);
    lv_span_set_text(ui->Home_spangroup_7_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_7_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_7_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_7_span = lv_spangroup_new_span(ui->Home_spangroup_7);
    lv_span_set_text(ui->Home_spangroup_7_span, "5min");
    lv_style_set_text_color(&ui->Home_spangroup_7_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_7_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->Home_spangroup_7, 55, 30);
    lv_obj_set_size(ui->Home_spangroup_7, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_7_main_main_default
    static lv_style_t style_Home_spangroup_7_main_main_default;
    ui_init_style(&style_Home_spangroup_7_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_7_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_7_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_7, &style_Home_spangroup_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_7);

    //Write codes Home_label_45
    ui->Home_label_45 = lv_label_create(ui->Home_cont_13);
    lv_label_set_text(ui->Home_label_45, " ");
    lv_label_set_long_mode(ui->Home_label_45, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_45, 8, 8);
    lv_obj_set_size(ui->Home_label_45, 35, 35);

    //Write style for Home_label_45, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_45, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_45, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_45, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_45, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_45, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_45, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_45, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_label_45, lv_color_hex(0xff5700), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_label_45, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_label_45, &_temperature_35x35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_label_45, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_45, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_12
    ui->Home_cont_12 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_12, 15, 191);
    lv_obj_set_size(ui->Home_cont_12, 180, 50);
    lv_obj_set_scrollbar_mode(ui->Home_cont_12, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_12, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_12, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_12, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_12, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_12, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_12, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_44
    ui->Home_label_44 = lv_label_create(ui->Home_cont_12);
    lv_label_set_text(ui->Home_label_44, "Humidity");
    lv_label_set_long_mode(ui->Home_label_44, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_44, 55, 10);
    lv_obj_set_size(ui->Home_label_44, 98, 19);

    //Write style for Home_label_44, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_44, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_44, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_44, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_44, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_44, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_6
    ui->Home_spangroup_6 = lv_spangroup_create(ui->Home_cont_12);
    lv_spangroup_set_align(ui->Home_spangroup_6, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_6, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_6, LV_SPAN_MODE_BREAK);
    //create span
    ui->Home_spangroup_6_span = lv_spangroup_new_span(ui->Home_spangroup_6);
    lv_span_set_text(ui->Home_spangroup_6_span, "70%");
    lv_style_set_text_color(&ui->Home_spangroup_6_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_6_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_6_span = lv_spangroup_new_span(ui->Home_spangroup_6);
    lv_span_set_text(ui->Home_spangroup_6_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_6_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_6_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_6_span = lv_spangroup_new_span(ui->Home_spangroup_6);
    lv_span_set_text(ui->Home_spangroup_6_span, "6min");
    lv_style_set_text_color(&ui->Home_spangroup_6_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_6_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->Home_spangroup_6, 55, 31);
    lv_obj_set_size(ui->Home_spangroup_6, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_6_main_main_default
    static lv_style_t style_Home_spangroup_6_main_main_default;
    ui_init_style(&style_Home_spangroup_6_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_6_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_6_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_6, &style_Home_spangroup_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_6);

    //Write codes Home_label_43
    ui->Home_label_43 = lv_label_create(ui->Home_cont_12);
    lv_label_set_text(ui->Home_label_43, " ");
    lv_label_set_long_mode(ui->Home_label_43, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_43, 9, 7);
    lv_obj_set_size(ui->Home_label_43, 35, 35);

    //Write style for Home_label_43, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_43, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_label_43, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_label_43, lv_color_hex(0x00a1ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_label_43, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_43, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_43, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_43, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_43, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_43, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_43, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_43, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_label_43, lv_color_hex(0x00a1ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_label_43, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_label_43, &_humidity_35x35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_label_43, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_43, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_11
    ui->Home_cont_11 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_11, 290, 76);
    lv_obj_set_size(ui->Home_cont_11, 175, 45);
    lv_obj_set_scrollbar_mode(ui->Home_cont_11, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_11, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_11, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_11, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_11, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_11, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_11, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_sw_2
    ui->Home_sw_2 = lv_switch_create(ui->Home_cont_11);
    lv_obj_set_pos(ui->Home_sw_2, 13, 11);
    lv_obj_set_size(ui->Home_sw_2, 44, 25);

    //Write style for Home_sw_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_2, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_sw_2, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Home_sw_2, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Home_sw_2, lv_color_hex(0xffc700), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Home_sw_2, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Home_sw_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_2, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_2, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_label_42
    ui->Home_label_42 = lv_label_create(ui->Home_cont_11);
    lv_label_set_text(ui->Home_label_42, "Switch");
    lv_label_set_long_mode(ui->Home_label_42, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_42, 71, 5);
    lv_obj_set_size(ui->Home_label_42, 98, 19);

    //Write style for Home_label_42, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_42, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_42, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_42, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_42, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_42, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_5
    ui->Home_spangroup_5 = lv_spangroup_create(ui->Home_cont_11);
    lv_spangroup_set_align(ui->Home_spangroup_5, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_5, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_5, LV_SPAN_MODE_BREAK);
    //create span
    ui->Home_spangroup_5_span = lv_spangroup_new_span(ui->Home_spangroup_5);
    lv_span_set_text(ui->Home_spangroup_5_span, "On");
    lv_style_set_text_color(&ui->Home_spangroup_5_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_5_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_5_span = lv_spangroup_new_span(ui->Home_spangroup_5);
    lv_span_set_text(ui->Home_spangroup_5_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_5_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_5_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_5_span = lv_spangroup_new_span(ui->Home_spangroup_5);
    lv_span_set_text(ui->Home_spangroup_5_span, "35W");
    lv_style_set_text_color(&ui->Home_spangroup_5_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_5_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->Home_spangroup_5, 71, 27);
    lv_obj_set_size(ui->Home_spangroup_5, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_5_main_main_default
    static lv_style_t style_Home_spangroup_5_main_main_default;
    ui_init_style(&style_Home_spangroup_5_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_5_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_5_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_5, &style_Home_spangroup_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_5);

    //Write codes Home_cont_10
    ui->Home_cont_10 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_10, 290, 21);
    lv_obj_set_size(ui->Home_cont_10, 175, 45);
    lv_obj_set_scrollbar_mode(ui->Home_cont_10, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_10, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_10, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_10, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_10, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_10, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_10, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_sw_1
    ui->Home_sw_1 = lv_switch_create(ui->Home_cont_10);
    lv_obj_set_pos(ui->Home_sw_1, 13, 11);
    lv_obj_set_size(ui->Home_sw_1, 44, 25);

    //Write style for Home_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Home_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Home_sw_1, lv_color_hex(0xffc700), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Home_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Home_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_label_41
    ui->Home_label_41 = lv_label_create(ui->Home_cont_10);
    lv_label_set_text(ui->Home_label_41, "Switch");
    lv_label_set_long_mode(ui->Home_label_41, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_41, 72, 6);
    lv_obj_set_size(ui->Home_label_41, 98, 19);

    //Write style for Home_label_41, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_41, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_41, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_41, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_41, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_41, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_4
    ui->Home_spangroup_4 = lv_spangroup_create(ui->Home_cont_10);
    lv_spangroup_set_align(ui->Home_spangroup_4, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_4, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_4, LV_SPAN_MODE_BREAK);
    //create span
    ui->Home_spangroup_4_span = lv_spangroup_new_span(ui->Home_spangroup_4);
    lv_span_set_text(ui->Home_spangroup_4_span, "On");
    lv_style_set_text_color(&ui->Home_spangroup_4_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_4_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_4_span = lv_spangroup_new_span(ui->Home_spangroup_4);
    lv_span_set_text(ui->Home_spangroup_4_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_4_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_4_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_4_span = lv_spangroup_new_span(ui->Home_spangroup_4);
    lv_span_set_text(ui->Home_spangroup_4_span, "35W");
    lv_style_set_text_color(&ui->Home_spangroup_4_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_4_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->Home_spangroup_4, 71, 27);
    lv_obj_set_size(ui->Home_spangroup_4, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_4_main_main_default
    static lv_style_t style_Home_spangroup_4_main_main_default;
    ui_init_style(&style_Home_spangroup_4_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_4_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_4_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_4, &style_Home_spangroup_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_4);

    //Write codes Home_cont_9
    ui->Home_cont_9 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_9, 205, 131);
    lv_obj_set_size(ui->Home_cont_9, 260, 110);
    lv_obj_set_scrollbar_mode(ui->Home_cont_9, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_9, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_9, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_9, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_9, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_9, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_40
    ui->Home_label_40 = lv_label_create(ui->Home_cont_9);
    lv_label_set_text(ui->Home_label_40, "AC");
    lv_label_set_long_mode(ui->Home_label_40, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_40, 14, 7);
    lv_obj_set_size(ui->Home_label_40, 98, 19);

    //Write style for Home_label_40, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_40, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_40, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_40, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_40, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_40, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_3
    ui->Home_spangroup_3 = lv_spangroup_create(ui->Home_cont_9);
    lv_spangroup_set_align(ui->Home_spangroup_3, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_3, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_3, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_spangroup_3_span = lv_spangroup_new_span(ui->Home_spangroup_3);
    lv_span_set_text(ui->Home_spangroup_3_span, "On");
    lv_style_set_text_color(&ui->Home_spangroup_3_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_3_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_3_span = lv_spangroup_new_span(ui->Home_spangroup_3);
    lv_span_set_text(ui->Home_spangroup_3_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_3_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_3_span->style, &lv_font_montserratMedium_12);
    ui->Home_spangroup_3_span = lv_spangroup_new_span(ui->Home_spangroup_3);
    lv_span_set_text(ui->Home_spangroup_3_span, "59min Ago");
    lv_style_set_text_color(&ui->Home_spangroup_3_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->Home_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_3_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->Home_spangroup_3, 14, 26);
    lv_obj_set_size(ui->Home_spangroup_3, 139, 19);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_3_main_main_default
    static lv_style_t style_Home_spangroup_3_main_main_default;
    ui_init_style(&style_Home_spangroup_3_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_3_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_3_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_3, &style_Home_spangroup_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_3);

    //Write codes Home_slider_3
    ui->Home_slider_3 = lv_slider_create(ui->Home_cont_9);
    lv_slider_set_range(ui->Home_slider_3, 15, 35);
    lv_slider_set_mode(ui->Home_slider_3, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Home_slider_3, 26, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_slider_3, 10, 45);
    lv_obj_set_size(ui->Home_slider_3, 240, 23);

    //Write style for Home_slider_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_slider_3, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_slider_3, lv_color_hex(0x717171), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_slider_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_slider_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Home_slider_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_slider_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_slider_3, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_slider_3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_slider_3, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_slider_3, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_slider_3, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_slider_3, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_slider_3, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_slider_3, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_label_39
    ui->Home_label_39 = lv_label_create(ui->Home_cont_9);
    lv_label_set_text(ui->Home_label_39, "26");
    lv_label_set_long_mode(ui->Home_label_39, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_39, 143, 16);
    lv_obj_set_size(ui->Home_label_39, 65, 24);

    //Write style for Home_label_39, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_39, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_39, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_39, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_39, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_39, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_38
    ui->Home_label_38 = lv_label_create(ui->Home_cont_9);
    lv_label_set_text(ui->Home_label_38, "°C");
    lv_label_set_long_mode(ui->Home_label_38, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_38, 212, 16);
    lv_obj_set_size(ui->Home_label_38, 30, 24);

    //Write style for Home_label_38, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_38, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_38, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_38, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_38, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_38, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_3
    ui->Home_btn_3 = lv_btn_create(ui->Home_cont_9);
    ui->Home_btn_3_label = lv_label_create(ui->Home_btn_3);
    lv_label_set_text(ui->Home_btn_3_label, "Off");
    lv_label_set_long_mode(ui->Home_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_3, 10, 75);
    lv_obj_set_size(ui->Home_btn_3, 75, 28);

    //Write style for Home_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_btn_3, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_3, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_3, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_btn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->Home_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->Home_btn_3, lv_color_hex(0x747474), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->Home_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->Home_btn_3, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Home_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Home_btn_3, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Home_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Home_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes Home_btn_2
    ui->Home_btn_2 = lv_btn_create(ui->Home_cont_9);
    ui->Home_btn_2_label = lv_label_create(ui->Home_btn_2);
    lv_label_set_text(ui->Home_btn_2_label, "Cool");
    lv_label_set_long_mode(ui->Home_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_2, 92, 75);
    lv_obj_set_size(ui->Home_btn_2, 75, 28);

    //Write style for Home_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_btn_2, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_2, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_2, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_btn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->Home_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->Home_btn_2, lv_color_hex(0x4b9ffe), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->Home_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->Home_btn_2, 6, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Home_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Home_btn_2, lv_color_hex(0xf1f1f1), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Home_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Home_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes Home_btn_1
    ui->Home_btn_1 = lv_btn_create(ui->Home_cont_9);
    ui->Home_btn_1_label = lv_label_create(ui->Home_btn_1);
    lv_label_set_text(ui->Home_btn_1_label, "Heat");
    lv_label_set_long_mode(ui->Home_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_1, 174, 75);
    lv_obj_set_size(ui->Home_btn_1, 75, 28);

    //Write style for Home_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_btn_1, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_1, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_1, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->Home_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->Home_btn_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->Home_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->Home_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->Home_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Home_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Home_btn_1, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Home_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Home_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes Home_cont_8
    ui->Home_cont_8 = lv_obj_create(ui->Home_tileview_1_ha_table);
    lv_obj_set_pos(ui->Home_cont_8, 15, 21);
    lv_obj_set_size(ui->Home_cont_8, 260, 100);
    lv_obj_set_scrollbar_mode(ui->Home_cont_8, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_8, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_8, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_8, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Home_cont_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Home_cont_8, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Home_cont_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Home_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Home_cont_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_2
    ui->Home_spangroup_2 = lv_spangroup_create(ui->Home_cont_8);
    lv_spangroup_set_align(ui->Home_spangroup_2, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_2, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_spangroup_2_span = lv_spangroup_new_span(ui->Home_spangroup_2);
    lv_span_set_text(ui->Home_spangroup_2_span, "Mon");
    lv_style_set_text_color(&ui->Home_spangroup_2_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_2_span->style, &lv_font_montserratMedium_17);
    ui->Home_spangroup_2_span = lv_spangroup_new_span(ui->Home_spangroup_2);
    lv_span_set_text(ui->Home_spangroup_2_span, " - ");
    lv_style_set_text_color(&ui->Home_spangroup_2_span->style, lv_color_hex(0xe0e0e0));
    lv_style_set_text_decor(&ui->Home_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_2_span->style, &lv_font_montserratMedium_17);
    ui->Home_spangroup_2_span = lv_spangroup_new_span(ui->Home_spangroup_2);
    lv_span_set_text(ui->Home_spangroup_2_span, "2025/12/8");
    lv_style_set_text_color(&ui->Home_spangroup_2_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_2_span->style, &lv_font_montserratMedium_17);
    lv_obj_set_pos(ui->Home_spangroup_2, 14, 77);
    lv_obj_set_size(ui->Home_spangroup_2, 139, 19);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_2_main_main_default
    static lv_style_t style_Home_spangroup_2_main_main_default;
    ui_init_style(&style_Home_spangroup_2_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_2_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_2_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_2, &style_Home_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_2);

    //Write codes Home_digital_clock_2
    static bool Home_digital_clock_2_timer_enabled = false;
    ui->Home_digital_clock_2 = lv_dclock_create(ui->Home_cont_8, "11:25:50");
    if (!Home_digital_clock_2_timer_enabled) {
        lv_timer_create(Home_digital_clock_2_timer, 1000, NULL);
        Home_digital_clock_2_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Home_digital_clock_2, 16, 40);
    lv_obj_set_size(ui->Home_digital_clock_2, 123, 33);

    //Write style for Home_digital_clock_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_digital_clock_2, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_digital_clock_2, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_digital_clock_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_digital_clock_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_digital_clock_2, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_digital_clock_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_spangroup_1
    ui->Home_spangroup_1 = lv_spangroup_create(ui->Home_cont_8);
    lv_spangroup_set_align(ui->Home_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Home_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Home_spangroup_1, LV_SPAN_MODE_FIXED);
    //create span
    ui->Home_spangroup_1_span = lv_spangroup_new_span(ui->Home_spangroup_1);
    lv_span_set_text(ui->Home_spangroup_1_span, "26");
    lv_style_set_text_color(&ui->Home_spangroup_1_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->Home_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_1_span->style, &lv_font_montserratMedium_30);
    ui->Home_spangroup_1_span = lv_spangroup_new_span(ui->Home_spangroup_1);
    lv_span_set_text(ui->Home_spangroup_1_span, "°C");
    lv_style_set_text_color(&ui->Home_spangroup_1_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->Home_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Home_spangroup_1_span->style, &lv_font_montserratMedium_22);
    lv_obj_set_pos(ui->Home_spangroup_1, 176, 68);
    lv_obj_set_size(ui->Home_spangroup_1, 77, 27);

    //Write style state: LV_STATE_DEFAULT for &style_Home_spangroup_1_main_main_default
    static lv_style_t style_Home_spangroup_1_main_main_default;
    ui_init_style(&style_Home_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_radius(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_pad_right(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_Home_spangroup_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_Home_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->Home_spangroup_1, &style_Home_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Home_spangroup_1);

    //Write codes Home_img_3
    ui->Home_img_3 = lv_img_create(ui->Home_cont_8);
    lv_obj_add_flag(ui->Home_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_3, &_cloudy_alpha_60x60);
    lv_img_set_pivot(ui->Home_img_3, 50,50);
    lv_img_set_angle(ui->Home_img_3, 0);
    lv_obj_set_pos(ui->Home_img_3, 176, 5);
    lv_obj_set_size(ui->Home_img_3, 60, 60);

    //Write style for Home_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Home.


    //Update current screen layout.
    lv_obj_update_layout(ui->Home);

    //Init events for screen.
    events_init_Home(ui);
}
