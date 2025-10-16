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
void setup_scr_Home(lv_ui *ui)
{
    //Write codes Home
    ui->Home = lv_obj_create(NULL);
    lv_obj_set_size(ui->Home, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Home, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home, lv_color_hex(0xb9c6d2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_time
    ui->Home_cont_time = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_time, 335, 31);
    lv_obj_set_size(ui->Home_cont_time, 130, 121);
    lv_obj_set_scrollbar_mode(ui->Home_cont_time, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_time, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_time, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_time, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_time, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_digital_clock_time
    static bool Home_digital_clock_time_timer_enabled = false;
    ui->Home_digital_clock_time = lv_dclock_create(ui->Home_cont_time, "11:25:50 AM");
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

    //Write codes Home_datetext_date
    ui->Home_datetext_date = lv_label_create(ui->Home_cont_time);
    lv_label_set_text(ui->Home_datetext_date, "2025/10/14");
    lv_obj_set_style_text_align(ui->Home_datetext_date, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->Home_datetext_date, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->Home_datetext_date, Home_datetext_date_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->Home_datetext_date, 23, 27);
    lv_obj_set_size(ui->Home_datetext_date, 81, 24);

    //Write style for Home_datetext_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Home_datetext_date, lv_color_hex(0xe2e2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_datetext_date, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_datetext_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_datetext_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_datetext_date, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_time_title
    ui->Home_time_title = lv_label_create(ui->Home_cont_time);
    lv_label_set_text(ui->Home_time_title, "Time");
    lv_label_set_long_mode(ui->Home_time_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_time_title, 0, 0);
    lv_obj_set_size(ui->Home_time_title, 130, 25);

    //Write style for Home_time_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_time_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_time_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_time_title, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_time_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_time_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_time_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_time_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_time_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_time_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_time_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_time_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_weekday
    ui->Home_weekday = lv_label_create(ui->Home_cont_time);
    lv_label_set_text(ui->Home_weekday, "Tuesday");
    lv_label_set_long_mode(ui->Home_weekday, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_weekday, 9, 87);
    lv_obj_set_size(ui->Home_weekday, 103, 22);

    //Write style for Home_weekday, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_weekday, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_weekday, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_weekday, lv_color_hex(0xe2e2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_cont_net
    ui->Home_cont_net = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_net, 335, 164);
    lv_obj_set_size(ui->Home_cont_net, 130, 144);
    lv_obj_set_scrollbar_mode(ui->Home_cont_net, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_net, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_net, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_net, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_net, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_net, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_net, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_speed_info
    ui->Home_speed_info = lv_obj_create(ui->Home_cont_net);
    lv_obj_set_pos(ui->Home_speed_info, 1, 33);
    lv_obj_set_size(ui->Home_speed_info, 120, 59);
    lv_obj_set_scrollbar_mode(ui->Home_speed_info, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_speed_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_speed_info, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_speed_info, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_speed_info, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_speed_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_download_icon
    ui->Home_download_icon = lv_img_create(ui->Home_speed_info);
    lv_obj_add_flag(ui->Home_download_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_download_icon, &_download_alpha_13x13);
    lv_img_set_pivot(ui->Home_download_icon, 50,50);
    lv_img_set_angle(ui->Home_download_icon, 0);
    lv_obj_set_pos(ui->Home_download_icon, 2, 25);
    lv_obj_set_size(ui->Home_download_icon, 13, 13);

    //Write style for Home_download_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_download_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_download_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_download_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_download_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_upload_icon
    ui->Home_upload_icon = lv_img_create(ui->Home_speed_info);
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

    //Write codes Home_speed_label
    ui->Home_speed_label = lv_label_create(ui->Home_speed_info);
    lv_label_set_text(ui->Home_speed_label, "Mbps\n");
    lv_label_set_long_mode(ui->Home_speed_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_speed_label, 79, 1);
    lv_obj_set_size(ui->Home_speed_label, 41, 24);

    //Write style for Home_speed_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_speed_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_speed_label, lv_color_hex(0xe3e3e3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_speed_label, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_speed_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_speed_label, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_speed_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_speed_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_speed_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_upload_data
    ui->Home_upload_data = lv_label_create(ui->Home_speed_info);
    lv_label_set_text(ui->Home_upload_data, "2200.50");
    lv_label_set_long_mode(ui->Home_upload_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_upload_data, 7, 1);
    lv_obj_set_size(ui->Home_upload_data, 67, 16);

    //Write style for Home_upload_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_upload_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_upload_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_upload_data, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_upload_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_upload_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_upload_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_upload_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_upload_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_download_data
    ui->Home_download_data = lv_label_create(ui->Home_speed_info);
    lv_label_set_text(ui->Home_download_data, "1200.50");
    lv_label_set_long_mode(ui->Home_download_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_download_data, 6, 24);
    lv_obj_set_size(ui->Home_download_data, 68, 16);

    //Write style for Home_download_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_download_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_download_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_download_data, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_download_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_download_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_download_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_download_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_download_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_8
    ui->Home_label_8 = lv_label_create(ui->Home_speed_info);
    lv_label_set_text(ui->Home_label_8, "Mbps\n");
    lv_label_set_long_mode(ui->Home_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_8, 79, 24);
    lv_obj_set_size(ui->Home_label_8, 41, 27);

    //Write style for Home_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_8, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_8, lv_color_hex(0xe3e3e3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_8, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_8, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_8, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_8, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ip_data
    ui->Home_ip_data = lv_label_create(ui->Home_cont_net);
    lv_label_set_text(ui->Home_ip_data, "China");
    lv_label_set_long_mode(ui->Home_ip_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ip_data, 44, 110);
    lv_obj_set_size(ui->Home_ip_data, 81, 16);

    //Write style for Home_ip_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ip_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ip_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ip_data, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ip_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ip_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ip_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ip_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ip_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ip_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ip_label
    ui->Home_ip_label = lv_label_create(ui->Home_cont_net);
    lv_label_set_text(ui->Home_ip_label, "IPloc:");
    lv_label_set_long_mode(ui->Home_ip_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ip_label, 7, 110);
    lv_obj_set_size(ui->Home_ip_label, 41, 22);

    //Write style for Home_ip_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ip_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ip_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ip_label, lv_color_hex(0xe3e3e3), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_ping_data
    ui->Home_ping_data = lv_label_create(ui->Home_cont_net);
    lv_label_set_text(ui->Home_ping_data, "200");
    lv_label_set_long_mode(ui->Home_ping_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ping_data, 47, 86);
    lv_obj_set_size(ui->Home_ping_data, 38, 22);

    //Write style for Home_ping_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ping_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ping_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ping_data, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ping_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ping_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ping_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ping_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ping_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_Ping_label
    ui->Home_Ping_label = lv_label_create(ui->Home_cont_net);
    lv_label_set_text(ui->Home_Ping_label, "Ping:");
    lv_label_set_long_mode(ui->Home_Ping_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_Ping_label, 7, 85);
    lv_obj_set_size(ui->Home_Ping_label, 46, 22);

    //Write style for Home_Ping_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_Ping_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_Ping_label, lv_color_hex(0xe3e3e3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_Ping_label, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_Ping_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_Ping_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_Ping_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_Ping_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_Ping_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_net_monitor_tit
    ui->Home_net_monitor_tit = lv_label_create(ui->Home_cont_net);
    lv_label_set_text(ui->Home_net_monitor_tit, "Network Monitor");
    lv_label_set_long_mode(ui->Home_net_monitor_tit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_net_monitor_tit, 0, 0);
    lv_obj_set_size(ui->Home_net_monitor_tit, 130, 26);

    //Write style for Home_net_monitor_tit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_net_monitor_tit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_net_monitor_tit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_net_monitor_tit, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_net_monitor_tit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_net_monitor_tit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_net_monitor_tit, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_net_monitor_tit, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_net_monitor_tit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_net_monitor_tit, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_net_monitor_tit, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_net_monitor_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ping_unit
    ui->Home_ping_unit = lv_label_create(ui->Home_cont_net);
    lv_label_set_text(ui->Home_ping_unit, "ms");
    lv_label_set_long_mode(ui->Home_ping_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ping_unit, 87, 86);
    lv_obj_set_size(ui->Home_ping_unit, 38, 22);

    //Write style for Home_ping_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ping_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ping_unit, lv_color_hex(0xe3e3e3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ping_unit, &lv_font_montserratMedium_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ping_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ping_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ping_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ping_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ping_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_cpu_monitor
    ui->Home_cont_cpu_monitor = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_cpu_monitor, 175, 31);
    lv_obj_set_size(ui->Home_cont_cpu_monitor, 146, 276);
    lv_obj_set_scrollbar_mode(ui->Home_cont_cpu_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_cpu_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_cpu_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_cpu_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_cpu_monitor, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_cpu_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_cpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_usage
    ui->Home_cpu_usage = lv_obj_create(ui->Home_cont_cpu_monitor);
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

    //Write codes Home_arc_1
    ui->Home_arc_1 = lv_arc_create(ui->Home_cpu_usage);
    lv_arc_set_mode(ui->Home_arc_1, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_1, 0, 100);
    lv_arc_set_bg_angles(ui->Home_arc_1, 90, 89);
    lv_arc_set_value(ui->Home_arc_1, 45);
    lv_arc_set_rotation(ui->Home_arc_1, 0);
    lv_obj_set_style_arc_rounded(ui->Home_arc_1, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Home_arc_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Home_arc_1, 6, 6);
    lv_obj_set_size(ui->Home_arc_1, 137, 126);

    //Write style for Home_arc_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_1, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_1, lv_color_hex(0xafafaf), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_cpu_percent_label
    ui->Home_cpu_percent_label = lv_label_create(ui->Home_cpu_usage);
    lv_label_set_text(ui->Home_cpu_percent_label, "%");
    lv_label_set_long_mode(ui->Home_cpu_percent_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_percent_label, 79, 51);
    lv_obj_set_size(ui->Home_cpu_percent_label, 31, 39);

    //Write style for Home_cpu_percent_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_percent_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_percent_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_percent_label, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_percent_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_percent_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_percent_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_percent_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_percent
    ui->Home_cpu_percent = lv_label_create(ui->Home_cpu_usage);
    lv_label_set_text(ui->Home_cpu_percent, "45");
    lv_label_set_long_mode(ui->Home_cpu_percent, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_percent, 16, 51);
    lv_obj_set_size(ui->Home_cpu_percent, 59, 39);

    //Write style for Home_cpu_percent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_percent, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_percent, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_percent, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_percent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_percent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_percent, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_percent, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_monitor_title
    ui->Home_cpu_monitor_title = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_monitor_title, "CPU Monitor");
    lv_label_set_long_mode(ui->Home_cpu_monitor_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_monitor_title, 0, 0);
    lv_obj_set_size(ui->Home_cpu_monitor_title, 146, 26);

    //Write style for Home_cpu_monitor_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_monitor_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_monitor_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_monitor_title, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_monitor_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_monitor_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cpu_monitor_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cpu_monitor_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_monitor_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_monitor_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_fequency_label
    ui->Home_cpu_fequency_label = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_fequency_label, "Freq:");
    lv_label_set_long_mode(ui->Home_cpu_fequency_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_fequency_label, 9, 167);
    lv_obj_set_size(ui->Home_cpu_fequency_label, 46, 23);

    //Write style for Home_cpu_fequency_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_fequency_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_fequency_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_fequency_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_fequency_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_fequency_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_fequency_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_fequency_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_fequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ram_label
    ui->Home_ram_label = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_ram_label, "RAM:");
    lv_label_set_long_mode(ui->Home_ram_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ram_label, 21, 224);
    lv_obj_set_size(ui->Home_ram_label, 46, 23);

    //Write style for Home_ram_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ram_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_ram_slider
    ui->Home_ram_slider = lv_slider_create(ui->Home_cont_cpu_monitor);
    lv_slider_set_range(ui->Home_ram_slider, 0, 100);
    lv_slider_set_mode(ui->Home_ram_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Home_ram_slider, 60, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_ram_slider, 9, 250);
    lv_obj_set_size(ui->Home_ram_slider, 124, 17);

    //Write style for Home_ram_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_ram_slider, 57, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_ram_slider, lv_color_hex(0xb5b5b5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_ram_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Home_ram_slider, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui->Home_ram_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui->Home_ram_slider, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_ram_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_ram_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_ram_slider, lv_color_hex(0x7cf156), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_ram_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_slider, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_ram_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_ram_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_slider, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_cpu_temp_label
    ui->Home_cpu_temp_label = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_temp_label, "Temp:");
    lv_label_set_long_mode(ui->Home_cpu_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_temp_label, 3, 195);
    lv_obj_set_size(ui->Home_cpu_temp_label, 64, 23);

    //Write style for Home_cpu_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_temp_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_temp_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_cpu_fequency_data
    ui->Home_cpu_fequency_data = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_fequency_data, "0.90");
    lv_label_set_long_mode(ui->Home_cpu_fequency_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_fequency_data, 54, 168);
    lv_obj_set_size(ui->Home_cpu_fequency_data, 41, 23);

    //Write style for Home_cpu_fequency_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_fequency_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_fequency_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_fequency_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_fequency_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_fequency_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_fequency_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_fequency_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_fequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_fequency_unit
    ui->Home_cpu_fequency_unit = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_fequency_unit, "Ghz");
    lv_label_set_long_mode(ui->Home_cpu_fequency_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_fequency_unit, 97, 168);
    lv_obj_set_size(ui->Home_cpu_fequency_unit, 41, 23);

    //Write style for Home_cpu_fequency_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_fequency_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_fequency_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_fequency_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_fequency_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_fequency_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_fequency_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_fequency_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_fequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_temp_unit
    ui->Home_cpu_temp_unit = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_temp_unit, "°C");
    lv_label_set_long_mode(ui->Home_cpu_temp_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_temp_unit, 104, 196);
    lv_obj_set_size(ui->Home_cpu_temp_unit, 41, 23);

    //Write style for Home_cpu_temp_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_temp_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_temp_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_temp_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_temp_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_temp_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_temp_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_temp_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cpu_temp_data
    ui->Home_cpu_temp_data = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_cpu_temp_data, "60");
    lv_label_set_long_mode(ui->Home_cpu_temp_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_cpu_temp_data, 69, 196);
    lv_obj_set_size(ui->Home_cpu_temp_data, 32, 20);

    //Write style for Home_cpu_temp_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cpu_temp_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_cpu_temp_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_cpu_temp_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_cpu_temp_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_cpu_temp_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_cpu_temp_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cpu_temp_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ram_unit
    ui->Home_ram_unit = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_ram_unit, "%");
    lv_label_set_long_mode(ui->Home_ram_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ram_unit, 106, 224);
    lv_obj_set_size(ui->Home_ram_unit, 41, 23);

    //Write style for Home_ram_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ram_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ram_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ram_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ram_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ram_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ram_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_ram_data
    ui->Home_ram_data = lv_label_create(ui->Home_cont_cpu_monitor);
    lv_label_set_text(ui->Home_ram_data, "60");
    lv_label_set_long_mode(ui->Home_ram_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_ram_data, 70, 224);
    lv_obj_set_size(ui->Home_ram_data, 32, 23);

    //Write style for Home_ram_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_ram_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_ram_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_ram_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_ram_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_ram_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_ram_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_ram_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_ram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_gpu_monitor
    ui->Home_cont_gpu_monitor = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_gpu_monitor, 17, 31);
    lv_obj_set_size(ui->Home_cont_gpu_monitor, 146, 276);
    lv_obj_set_scrollbar_mode(ui->Home_cont_gpu_monitor, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_gpu_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_gpu_monitor, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_gpu_monitor, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_gpu_monitor, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_gpu_monitor, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_gpu_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_usage
    ui->Home_gpu_usage = lv_obj_create(ui->Home_cont_gpu_monitor);
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

    //Write codes Home_arc_2
    ui->Home_arc_2 = lv_arc_create(ui->Home_gpu_usage);
    lv_arc_set_mode(ui->Home_arc_2, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_2, 0, 100);
    lv_arc_set_bg_angles(ui->Home_arc_2, 90, 89);
    lv_arc_set_value(ui->Home_arc_2, 50);
    lv_arc_set_rotation(ui->Home_arc_2, 0);
    lv_obj_set_style_arc_rounded(ui->Home_arc_2, 0,  LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui->Home_arc_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Home_arc_2, 6, 6);
    lv_obj_set_size(ui->Home_arc_2, 137, 126);

    //Write style for Home_arc_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_2, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_2, lv_color_hex(0xafafaf), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_2, 15, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_2, 170, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_2, lv_color_hex(0x00ff1d), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_2, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_gpu_percent_label
    ui->Home_gpu_percent_label = lv_label_create(ui->Home_gpu_usage);
    lv_label_set_text(ui->Home_gpu_percent_label, "%");
    lv_label_set_long_mode(ui->Home_gpu_percent_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_percent_label, 79, 51);
    lv_obj_set_size(ui->Home_gpu_percent_label, 31, 39);

    //Write style for Home_gpu_percent_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_percent_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_percent_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_percent_label, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_percent_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_percent_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_percent_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_percent_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_percent_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_percent
    ui->Home_gpu_percent = lv_label_create(ui->Home_gpu_usage);
    lv_label_set_text(ui->Home_gpu_percent, "50");
    lv_label_set_long_mode(ui->Home_gpu_percent, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_percent, 16, 51);
    lv_obj_set_size(ui->Home_gpu_percent, 59, 39);

    //Write style for Home_gpu_percent, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_percent, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_percent, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_percent, &lv_font_montserratMedium_35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_percent, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_percent, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_percent, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_percent, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_percent, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_monitor_title
    ui->Home_gpu_monitor_title = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_monitor_title, "GPU Monitor");
    lv_label_set_long_mode(ui->Home_gpu_monitor_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_monitor_title, 0, 0);
    lv_obj_set_size(ui->Home_gpu_monitor_title, 146, 26);

    //Write style for Home_gpu_monitor_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_monitor_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_monitor_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_monitor_title, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_monitor_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_monitor_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gpu_monitor_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gpu_monitor_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_monitor_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_monitor_title, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_frequency_label
    ui->Home_gpu_frequency_label = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_frequency_label, "Freq:");
    lv_label_set_long_mode(ui->Home_gpu_frequency_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_frequency_label, 4, 167);
    lv_obj_set_size(ui->Home_gpu_frequency_label, 46, 23);

    //Write style for Home_gpu_frequency_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_frequency_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_frequency_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_frequency_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_frequency_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_frequency_label, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_frequency_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_frequency_label, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_frequency_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gram_label
    ui->Home_gram_label = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gram_label, "GRAM:");
    lv_label_set_long_mode(ui->Home_gram_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gram_label, 1, 224);
    lv_obj_set_size(ui->Home_gram_label, 66, 23);

    //Write style for Home_gram_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gram_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gram_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_gram_slider
    ui->Home_gram_slider = lv_slider_create(ui->Home_cont_gpu_monitor);
    lv_slider_set_range(ui->Home_gram_slider, 0, 100);
    lv_slider_set_mode(ui->Home_gram_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Home_gram_slider, 90, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_gram_slider, 9, 250);
    lv_obj_set_size(ui->Home_gram_slider, 124, 17);

    //Write style for Home_gram_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_gram_slider, 57, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gram_slider, lv_color_hex(0xb5b5b5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gram_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_slider, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Home_gram_slider, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui->Home_gram_slider, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui->Home_gram_slider, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gram_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_gram_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_gram_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_gram_slider, lv_color_hex(0x7cf156), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_gram_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_slider, 4, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_gram_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_gram_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_slider, 3, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_gpu_temp_label
    ui->Home_gpu_temp_label = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_temp_label, "Temp:");
    lv_label_set_long_mode(ui->Home_gpu_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_temp_label, 3, 195);
    lv_obj_set_size(ui->Home_gpu_temp_label, 64, 23);

    //Write style for Home_gpu_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_temp_label, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_temp_label, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_gpu_frequency_data
    ui->Home_gpu_frequency_data = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_frequency_data, "2800");
    lv_label_set_long_mode(ui->Home_gpu_frequency_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_frequency_data, 52, 168);
    lv_obj_set_size(ui->Home_gpu_frequency_data, 45, 23);

    //Write style for Home_gpu_frequency_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_frequency_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_frequency_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_frequency_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_frequency_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_frequency_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_frequency_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_frequency_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_frequency_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_frequency_unit
    ui->Home_gpu_frequency_unit = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_frequency_unit, "Mhz");
    lv_label_set_long_mode(ui->Home_gpu_frequency_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_frequency_unit, 100, 168);
    lv_obj_set_size(ui->Home_gpu_frequency_unit, 41, 23);

    //Write style for Home_gpu_frequency_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_frequency_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_frequency_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_frequency_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_frequency_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_frequency_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_frequency_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_frequency_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_frequency_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_temp_unit
    ui->Home_gpu_temp_unit = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_temp_unit, "°C");
    lv_label_set_long_mode(ui->Home_gpu_temp_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_temp_unit, 104, 196);
    lv_obj_set_size(ui->Home_gpu_temp_unit, 41, 23);

    //Write style for Home_gpu_temp_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_temp_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_temp_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_temp_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_temp_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_temp_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_temp_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_temp_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_temp_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gpu_temp_data
    ui->Home_gpu_temp_data = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gpu_temp_data, "75");
    lv_label_set_long_mode(ui->Home_gpu_temp_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gpu_temp_data, 69, 196);
    lv_obj_set_size(ui->Home_gpu_temp_data, 32, 19);

    //Write style for Home_gpu_temp_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gpu_temp_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gpu_temp_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gpu_temp_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gpu_temp_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gpu_temp_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gpu_temp_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gpu_temp_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gpu_temp_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gram_unit
    ui->Home_gram_unit = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gram_unit, "%");
    lv_label_set_long_mode(ui->Home_gram_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gram_unit, 106, 224);
    lv_obj_set_size(ui->Home_gram_unit, 41, 23);

    //Write style for Home_gram_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_unit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gram_unit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gram_unit, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gram_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gram_unit, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gram_unit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gram_unit, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gram_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_gram_data
    ui->Home_gram_data = lv_label_create(ui->Home_cont_gpu_monitor);
    lv_label_set_text(ui->Home_gram_data, "90");
    lv_label_set_long_mode(ui->Home_gram_data, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_gram_data, 70, 224);
    lv_obj_set_size(ui->Home_gram_data, 32, 23);

    //Write style for Home_gram_data, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_gram_data, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_gram_data, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_gram_data, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_gram_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_gram_data, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_gram_data, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_gram_data, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_gram_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_home_title
    ui->Home_label_home_title = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_home_title, "Performance Monitor");
    lv_label_set_long_mode(ui->Home_label_home_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_home_title, 80, 5);
    lv_obj_set_size(ui->Home_label_home_title, 319, 20);

    //Write style for Home_label_home_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_home_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_home_title, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_home_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_home_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_home_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_menu
    ui->Home_btn_menu = lv_btn_create(ui->Home);
    ui->Home_btn_menu_label = lv_label_create(ui->Home_btn_menu);
    lv_label_set_text(ui->Home_btn_menu_label, "" LV_SYMBOL_RIGHT "  ");
    lv_label_set_long_mode(ui->Home_btn_menu_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_menu_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_menu, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_menu_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_menu, 0, 130);
    lv_obj_set_size(ui->Home_btn_menu, 27, 56);

    //Write style for Home_btn_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_menu, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_menu, &_home_bak_27x56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_menu, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_menu, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_menu, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_menu
    ui->Home_cont_menu = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_menu, 0, 0);
    lv_obj_set_size(ui->Home_cont_menu, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Home_cont_menu, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Home_cont_menu, LV_OBJ_FLAG_HIDDEN);

    //Write style for Home_cont_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_cont_menu, &_menu_bak_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_cont_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_tick
    ui->Home_img_tick = lv_img_create(ui->Home_cont_menu);
    lv_obj_add_flag(ui->Home_img_tick, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_tick, &_menu_bal_alpha_192x192);
    lv_img_set_pivot(ui->Home_img_tick, 50,50);
    lv_img_set_angle(ui->Home_img_tick, 0);
    lv_obj_set_pos(ui->Home_img_tick, -96, 53);
    lv_obj_set_size(ui->Home_img_tick, 192, 192);

    //Write style for Home_img_tick, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_tick, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_tick, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_tick, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_tick, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_phone
    ui->Home_btn_phone = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_phone_label = lv_label_create(ui->Home_btn_phone);
    lv_label_set_text(ui->Home_btn_phone_label, "");
    lv_label_set_long_mode(ui->Home_btn_phone_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_phone_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_phone, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_phone_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_phone, 8, 1);
    lv_obj_set_size(ui->Home_btn_phone, 54, 54);

    //Write style for Home_btn_phone, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_phone, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_phone, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_phone, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_phone, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_phone, &_menu_air_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_phone, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_phone, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_phone, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_phone, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_phone, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_phone, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_warning
    ui->Home_btn_warning = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_warning_label = lv_label_create(ui->Home_btn_warning);
    lv_label_set_text(ui->Home_btn_warning_label, "");
    lv_label_set_long_mode(ui->Home_btn_warning_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_warning_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_warning, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_warning_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_warning, 56, 26);
    lv_obj_set_size(ui->Home_btn_warning, 54, 54);

    //Write style for Home_btn_warning, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_warning, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_warning, &_menu_anfang_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_warning, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_warning, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_warning, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_warning, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_warning, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_warning, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_power
    ui->Home_btn_power = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_power_label = lv_label_create(ui->Home_btn_power);
    lv_label_set_text(ui->Home_btn_power_label, "");
    lv_label_set_long_mode(ui->Home_btn_power_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_power_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_power, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_power_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_power, 84, 75);
    lv_obj_set_size(ui->Home_btn_power, 54, 54);

    //Write style for Home_btn_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_power, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_power, &_menu_elevator_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_power, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_power, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_temp
    ui->Home_btn_temp = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_temp_label = lv_label_create(ui->Home_btn_temp);
    lv_label_set_text(ui->Home_btn_temp_label, "");
    lv_label_set_long_mode(ui->Home_btn_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_temp_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_temp, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_temp_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_temp, 96, 132);
    lv_obj_set_size(ui->Home_btn_temp, 54, 54);

    //Write style for Home_btn_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_temp, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_temp, &_menu_tem_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor(ui->Home_btn_temp, lv_color_hex(0xe5ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_temp, 216, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_temp, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_link
    ui->Home_btn_link = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_link_label = lv_label_create(ui->Home_btn_link);
    lv_label_set_text(ui->Home_btn_link_label, "");
    lv_label_set_long_mode(ui->Home_btn_link_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_link_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_link, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_link_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_link, 8, 254);
    lv_obj_set_size(ui->Home_btn_link, 54, 54);

    //Write style for Home_btn_link, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_link, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_link, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_link, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_link, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_link, &_menu_xiaofang_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_link, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_link, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_link, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_link, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_link, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_link, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_safe
    ui->Home_btn_safe = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_safe_label = lv_label_create(ui->Home_btn_safe);
    lv_label_set_text(ui->Home_btn_safe_label, "");
    lv_label_set_long_mode(ui->Home_btn_safe_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_safe_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_safe, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_safe_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_safe, 56, 231);
    lv_obj_set_size(ui->Home_btn_safe, 54, 54);

    //Write style for Home_btn_safe, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_safe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_safe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_safe, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_safe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_safe, &_menu_electricity_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_safe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_safe, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_safe, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_safe, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_safe, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_safe, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_btn_light
    ui->Home_btn_light = lv_btn_create(ui->Home_cont_menu);
    ui->Home_btn_light_label = lv_label_create(ui->Home_btn_light);
    lv_label_set_text(ui->Home_btn_light_label, "");
    lv_label_set_long_mode(ui->Home_btn_light_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Home_btn_light_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Home_btn_light, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Home_btn_light_label, LV_PCT(100));
    lv_obj_set_pos(ui->Home_btn_light, 84, 184);
    lv_obj_set_size(ui->Home_btn_light, 54, 54);

    //Write style for Home_btn_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_btn_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_btn_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_btn_light, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_btn_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Home_btn_light, &_menu_light_54x54, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Home_btn_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Home_btn_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_btn_light, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_btn_light, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_btn_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_btn_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_monitor
    ui->Home_label_monitor = lv_label_create(ui->Home_cont_menu);
    lv_label_set_text(ui->Home_label_monitor, "Monitoring");
    lv_label_set_long_mode(ui->Home_label_monitor, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_monitor, 4, 152);
    lv_obj_set_size(ui->Home_label_monitor, 72, 28);

    //Write style for Home_label_monitor, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_monitor, lv_color_hex(0xbbff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_monitor, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_monitor, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_monitor, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_monitor, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_monitor, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Home.


    //Update current screen layout.
    lv_obj_update_layout(ui->Home);

    //Init events for screen.
    events_init_Home(ui);
}
