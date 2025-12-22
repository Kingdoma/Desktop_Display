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



int HA_dark_digital_clock_time_min_value = 48;
int HA_dark_digital_clock_time_hour_value = 18;
int HA_dark_digital_clock_time_sec_value = 11;
void setup_scr_HA_dark(lv_ui *ui)
{
    //Write codes HA_dark
    ui->HA_dark = lv_obj_create(NULL);
    lv_obj_set_size(ui->HA_dark, 480, 320);
    lv_obj_set_scrollbar_mode(ui->HA_dark, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark, lv_color_hex(0x232429), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_printer_card
    ui->HA_dark_printer_card = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_printer_card, 15, 251);
    lv_obj_set_size(ui->HA_dark_printer_card, 450, 50);
    lv_obj_set_scrollbar_mode(ui->HA_dark_printer_card, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_printer_card, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_printer_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_printer_card, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_printer_card, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_printer_card, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_printer_card, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_printer_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_printer_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_printer_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_printer_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_printer_card, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_printer_card, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_printer_card, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_printer_card, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_printer_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_printer_card, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_printer_slider
    ui->HA_dark_printer_slider = lv_slider_create(ui->HA_dark_printer_card);
    lv_slider_set_range(ui->HA_dark_printer_slider, 0, 100);
    lv_slider_set_mode(ui->HA_dark_printer_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->HA_dark_printer_slider, 1, LV_ANIM_OFF);
    lv_obj_set_pos(ui->HA_dark_printer_slider, 103, 14);
    lv_obj_set_size(ui->HA_dark_printer_slider, 336, 23);

    //Write style for HA_dark_printer_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_printer_slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_printer_slider, lv_color_hex(0x717171), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_printer_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_printer_slider, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->HA_dark_printer_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_printer_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_printer_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_printer_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_printer_slider, lv_color_hex(0xf5bb0d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_printer_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_printer_slider, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for HA_dark_printer_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_printer_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_printer_slider, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_printer_info
    ui->HA_dark_printer_info = lv_spangroup_create(ui->HA_dark_printer_card);
    lv_spangroup_set_align(ui->HA_dark_printer_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_printer_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_printer_info, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_printer_info_span = lv_spangroup_new_span(ui->HA_dark_printer_info);
    lv_span_set_text(ui->HA_dark_printer_info_span, "A1");
    lv_style_set_text_color(&ui->HA_dark_printer_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_printer_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_printer_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_printer_info_span = lv_spangroup_new_span(ui->HA_dark_printer_info);
    lv_span_set_text(ui->HA_dark_printer_info_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_printer_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_printer_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_printer_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_printer_info_span = lv_spangroup_new_span(ui->HA_dark_printer_info);
    lv_span_set_text(ui->HA_dark_printer_info_span, "10h45min");
    lv_style_set_text_color(&ui->HA_dark_printer_info_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_printer_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_printer_info_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_printer_info, 10, 30);
    lv_obj_set_size(ui->HA_dark_printer_info, 165, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_printer_info_main_main_default
    static lv_style_t style_HA_dark_printer_info_main_main_default;
    ui_init_style(&style_HA_dark_printer_info_main_main_default);

    lv_style_set_border_width(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_printer_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_printer_info_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_printer_info, &style_HA_dark_printer_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_printer_info);

    //Write codes HA_dark_printer_title
    ui->HA_dark_printer_title = lv_label_create(ui->HA_dark_printer_card);
    lv_label_set_text(ui->HA_dark_printer_title, "3D Printer\n");
    lv_label_set_long_mode(ui->HA_dark_printer_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_printer_title, 10, 10);
    lv_obj_set_size(ui->HA_dark_printer_title, 104, 17);

    //Write style for HA_dark_printer_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_printer_title, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_printer_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_printer_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_printer_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_printer_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_temperature_card
    ui->HA_dark_temperature_card = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_temperature_card, 15, 131);
    lv_obj_set_size(ui->HA_dark_temperature_card, 180, 50);
    lv_obj_set_scrollbar_mode(ui->HA_dark_temperature_card, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_temperature_card, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_temperature_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_temperature_card, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_temperature_card, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_temperature_card, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_temperature_card, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_temperature_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_temperature_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_temperature_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_temperature_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_temperature_card, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_temperature_card, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_temperature_card, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_temperature_card, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_temperature_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_temperature_card, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_temp_title
    ui->HA_dark_temp_title = lv_label_create(ui->HA_dark_temperature_card);
    lv_label_set_text(ui->HA_dark_temp_title, "Temperature");
    lv_label_set_long_mode(ui->HA_dark_temp_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_temp_title, 55, 10);
    lv_obj_set_size(ui->HA_dark_temp_title, 108, 19);

    //Write style for HA_dark_temp_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_temp_title, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_temp_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_temp_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_temp_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_temp_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_temp_info
    ui->HA_dark_temp_info = lv_spangroup_create(ui->HA_dark_temperature_card);
    lv_spangroup_set_align(ui->HA_dark_temp_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_temp_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_temp_info, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_temp_info_span = lv_spangroup_new_span(ui->HA_dark_temp_info);
    lv_span_set_text(ui->HA_dark_temp_info_span, "21");
    lv_style_set_text_color(&ui->HA_dark_temp_info_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_temp_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_temp_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_temp_info_span = lv_spangroup_new_span(ui->HA_dark_temp_info);
    lv_span_set_text(ui->HA_dark_temp_info_span, "°C");
    lv_style_set_text_color(&ui->HA_dark_temp_info_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_temp_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_temp_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_temp_info_span = lv_spangroup_new_span(ui->HA_dark_temp_info);
    lv_span_set_text(ui->HA_dark_temp_info_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_temp_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_temp_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_temp_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_temp_info_span = lv_spangroup_new_span(ui->HA_dark_temp_info);
    lv_span_set_text(ui->HA_dark_temp_info_span, "5min");
    lv_style_set_text_color(&ui->HA_dark_temp_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_temp_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_temp_info_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_temp_info, 55, 30);
    lv_obj_set_size(ui->HA_dark_temp_info, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_temp_info_main_main_default
    static lv_style_t style_HA_dark_temp_info_main_main_default;
    ui_init_style(&style_HA_dark_temp_info_main_main_default);

    lv_style_set_border_width(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_temp_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_temp_info_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_temp_info, &style_HA_dark_temp_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_temp_info);

    //Write codes HA_dark_temp_icon
    ui->HA_dark_temp_icon = lv_label_create(ui->HA_dark_temperature_card);
    lv_label_set_text(ui->HA_dark_temp_icon, " ");
    lv_label_set_long_mode(ui->HA_dark_temp_icon, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_temp_icon, 8, 8);
    lv_obj_set_size(ui->HA_dark_temp_icon, 35, 35);

    //Write style for HA_dark_temp_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_temp_icon, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_temp_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_temp_icon, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_temp_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_temp_icon, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_temp_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_temp_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_temp_icon, lv_color_hex(0xff5700), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_temp_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HA_dark_temp_icon, &_temperature_35x35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HA_dark_temp_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_temp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_humidity_card
    ui->HA_dark_humidity_card = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_humidity_card, 15, 191);
    lv_obj_set_size(ui->HA_dark_humidity_card, 180, 50);
    lv_obj_set_scrollbar_mode(ui->HA_dark_humidity_card, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_humidity_card, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_humidity_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_humidity_card, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_humidity_card, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_humidity_card, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_humidity_card, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_humidity_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_humidity_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_humidity_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_humidity_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_humidity_card, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_humidity_card, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_humidity_card, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_humidity_card, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_humidity_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_humidity_card, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_hum_info
    ui->HA_dark_hum_info = lv_spangroup_create(ui->HA_dark_humidity_card);
    lv_spangroup_set_align(ui->HA_dark_hum_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_hum_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_hum_info, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_hum_info_span = lv_spangroup_new_span(ui->HA_dark_hum_info);
    lv_span_set_text(ui->HA_dark_hum_info_span, "70");
    lv_style_set_text_color(&ui->HA_dark_hum_info_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_hum_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_hum_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_hum_info_span = lv_spangroup_new_span(ui->HA_dark_hum_info);
    lv_span_set_text(ui->HA_dark_hum_info_span, "%");
    lv_style_set_text_color(&ui->HA_dark_hum_info_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_hum_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_hum_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_hum_info_span = lv_spangroup_new_span(ui->HA_dark_hum_info);
    lv_span_set_text(ui->HA_dark_hum_info_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_hum_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_hum_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_hum_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_hum_info_span = lv_spangroup_new_span(ui->HA_dark_hum_info);
    lv_span_set_text(ui->HA_dark_hum_info_span, "6min");
    lv_style_set_text_color(&ui->HA_dark_hum_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_hum_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_hum_info_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_hum_info, 55, 31);
    lv_obj_set_size(ui->HA_dark_hum_info, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_hum_info_main_main_default
    static lv_style_t style_HA_dark_hum_info_main_main_default;
    ui_init_style(&style_HA_dark_hum_info_main_main_default);

    lv_style_set_border_width(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_hum_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_hum_info_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_hum_info, &style_HA_dark_hum_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_hum_info);

    //Write codes HA_dark_hum_title
    ui->HA_dark_hum_title = lv_label_create(ui->HA_dark_humidity_card);
    lv_label_set_text(ui->HA_dark_hum_title, "Humidity");
    lv_label_set_long_mode(ui->HA_dark_hum_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_hum_title, 55, 10);
    lv_obj_set_size(ui->HA_dark_hum_title, 98, 19);

    //Write style for HA_dark_hum_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_hum_title, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_hum_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_hum_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_hum_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_hum_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_hum_icon
    ui->HA_dark_hum_icon = lv_label_create(ui->HA_dark_humidity_card);
    lv_label_set_text(ui->HA_dark_hum_icon, " ");
    lv_label_set_long_mode(ui->HA_dark_hum_icon, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_hum_icon, 9, 7);
    lv_obj_set_size(ui->HA_dark_hum_icon, 35, 35);

    //Write style for HA_dark_hum_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_hum_icon, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_hum_icon, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_hum_icon, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_hum_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_hum_icon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_hum_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_hum_icon, lv_color_hex(0x00a1ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_hum_icon, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_hum_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_hum_icon_f
    ui->HA_dark_hum_icon_f = lv_img_create(ui->HA_dark_humidity_card);
    lv_obj_add_flag(ui->HA_dark_hum_icon_f, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HA_dark_hum_icon_f, &_humidity_alpha_28x28);
    lv_img_set_pivot(ui->HA_dark_hum_icon_f, 50,50);
    lv_img_set_angle(ui->HA_dark_hum_icon_f, 0);
    lv_obj_set_pos(ui->HA_dark_hum_icon_f, 13, 11);
    lv_obj_set_size(ui->HA_dark_hum_icon_f, 28, 28);

    //Write style for HA_dark_hum_icon_f, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HA_dark_hum_icon_f, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HA_dark_hum_icon_f, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_hum_icon_f, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HA_dark_hum_icon_f, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_switch_card_2
    ui->HA_dark_switch_card_2 = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_switch_card_2, 290, 76);
    lv_obj_set_size(ui->HA_dark_switch_card_2, 175, 45);
    lv_obj_set_scrollbar_mode(ui->HA_dark_switch_card_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_switch_card_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_switch_card_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_switch_card_2, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_switch_card_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_switch_card_2, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_switch_card_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_switch_card_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_switch_card_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_switch_card_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_switch_card_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_switch_card_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_switch_card_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_switch_card_2, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_switch_card_2, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_switch_card_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_switch_card_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_sw_info_2
    ui->HA_dark_sw_info_2 = lv_spangroup_create(ui->HA_dark_switch_card_2);
    lv_spangroup_set_align(ui->HA_dark_sw_info_2, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_sw_info_2, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_sw_info_2, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_sw_info_2_span = lv_spangroup_new_span(ui->HA_dark_sw_info_2);
    lv_span_set_text(ui->HA_dark_sw_info_2_span, "On");
    lv_style_set_text_color(&ui->HA_dark_sw_info_2_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_sw_info_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_sw_info_2_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_sw_info_2_span = lv_spangroup_new_span(ui->HA_dark_sw_info_2);
    lv_span_set_text(ui->HA_dark_sw_info_2_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_sw_info_2_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_sw_info_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_sw_info_2_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_sw_info_2_span = lv_spangroup_new_span(ui->HA_dark_sw_info_2);
    lv_span_set_text(ui->HA_dark_sw_info_2_span, "20hour");
    lv_style_set_text_color(&ui->HA_dark_sw_info_2_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_sw_info_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_sw_info_2_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_sw_info_2, 71, 27);
    lv_obj_set_size(ui->HA_dark_sw_info_2, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_sw_info_2_main_main_default
    static lv_style_t style_HA_dark_sw_info_2_main_main_default;
    ui_init_style(&style_HA_dark_sw_info_2_main_main_default);

    lv_style_set_border_width(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_sw_info_2_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_sw_info_2, &style_HA_dark_sw_info_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_sw_info_2);

    //Write codes HA_dark_sw_title_2
    ui->HA_dark_sw_title_2 = lv_label_create(ui->HA_dark_switch_card_2);
    lv_label_set_text(ui->HA_dark_sw_title_2, "Switch");
    lv_label_set_long_mode(ui->HA_dark_sw_title_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_sw_title_2, 71, 5);
    lv_obj_set_size(ui->HA_dark_sw_title_2, 98, 19);

    //Write style for HA_dark_sw_title_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_sw_title_2, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_sw_title_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_sw_title_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_sw_title_2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_sw_title_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_sw_2
    ui->HA_dark_sw_2 = lv_switch_create(ui->HA_dark_switch_card_2);
    lv_obj_set_pos(ui->HA_dark_sw_2, 13, 11);
    lv_obj_set_size(ui->HA_dark_sw_2, 44, 25);

    //Write style for HA_dark_sw_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_2, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_2, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_sw_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_sw_2, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_2, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_2, lv_color_hex(0xffc700), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_sw_2, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for HA_dark_sw_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_2, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_2, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_switch_card_1
    ui->HA_dark_switch_card_1 = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_switch_card_1, 290, 21);
    lv_obj_set_size(ui->HA_dark_switch_card_1, 175, 45);
    lv_obj_set_scrollbar_mode(ui->HA_dark_switch_card_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_switch_card_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_switch_card_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_switch_card_1, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_switch_card_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_switch_card_1, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_switch_card_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_switch_card_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_switch_card_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_switch_card_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_switch_card_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_switch_card_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_switch_card_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_switch_card_1, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_switch_card_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_switch_card_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_switch_card_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_sw_info_1
    ui->HA_dark_sw_info_1 = lv_spangroup_create(ui->HA_dark_switch_card_1);
    lv_spangroup_set_align(ui->HA_dark_sw_info_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_sw_info_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_sw_info_1, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_sw_info_1_span = lv_spangroup_new_span(ui->HA_dark_sw_info_1);
    lv_span_set_text(ui->HA_dark_sw_info_1_span, "On");
    lv_style_set_text_color(&ui->HA_dark_sw_info_1_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_sw_info_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_sw_info_1_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_sw_info_1_span = lv_spangroup_new_span(ui->HA_dark_sw_info_1);
    lv_span_set_text(ui->HA_dark_sw_info_1_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_sw_info_1_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_sw_info_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_sw_info_1_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_sw_info_1_span = lv_spangroup_new_span(ui->HA_dark_sw_info_1);
    lv_span_set_text(ui->HA_dark_sw_info_1_span, "10min");
    lv_style_set_text_color(&ui->HA_dark_sw_info_1_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_sw_info_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_sw_info_1_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_sw_info_1, 71, 27);
    lv_obj_set_size(ui->HA_dark_sw_info_1, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_sw_info_1_main_main_default
    static lv_style_t style_HA_dark_sw_info_1_main_main_default;
    ui_init_style(&style_HA_dark_sw_info_1_main_main_default);

    lv_style_set_border_width(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_sw_info_1_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_sw_info_1, &style_HA_dark_sw_info_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_sw_info_1);

    //Write codes HA_dark_sw_title_1
    ui->HA_dark_sw_title_1 = lv_label_create(ui->HA_dark_switch_card_1);
    lv_label_set_text(ui->HA_dark_sw_title_1, "Switch");
    lv_label_set_long_mode(ui->HA_dark_sw_title_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_sw_title_1, 72, 6);
    lv_obj_set_size(ui->HA_dark_sw_title_1, 98, 19);

    //Write style for HA_dark_sw_title_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_sw_title_1, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_sw_title_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_sw_title_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_sw_title_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_sw_title_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_sw_1
    ui->HA_dark_sw_1 = lv_switch_create(ui->HA_dark_switch_card_1);
    lv_obj_set_pos(ui->HA_dark_sw_1, 13, 11);
    lv_obj_set_size(ui->HA_dark_sw_1, 44, 25);

    //Write style for HA_dark_sw_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_1, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_sw_1, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_1, lv_color_hex(0xffc700), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for HA_dark_sw_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_1, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_1, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_ac_card
    ui->HA_dark_ac_card = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_ac_card, 205, 131);
    lv_obj_set_size(ui->HA_dark_ac_card, 260, 110);
    lv_obj_set_scrollbar_mode(ui->HA_dark_ac_card, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_ac_card, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_ac_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_card, 15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_card, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_card, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_card, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_ac_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_ac_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_ac_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_ac_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_card, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_ac_card, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_ac_card, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_ac_card, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_ac_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_ac_card, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_temp_slider
    ui->HA_dark_temp_slider = lv_slider_create(ui->HA_dark_ac_card);
    lv_slider_set_range(ui->HA_dark_temp_slider, 15, 35);
    lv_slider_set_mode(ui->HA_dark_temp_slider, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->HA_dark_temp_slider, 16, LV_ANIM_OFF);
    lv_obj_set_pos(ui->HA_dark_temp_slider, 10, 45);
    lv_obj_set_size(ui->HA_dark_temp_slider, 240, 23);

    //Write style for HA_dark_temp_slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_temp_slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_temp_slider, lv_color_hex(0x717171), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_temp_slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_temp_slider, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->HA_dark_temp_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_temp_slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_temp_slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_temp_slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_temp_slider, lv_color_hex(0x292929), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_temp_slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_temp_slider, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for HA_dark_temp_slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_temp_slider, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_temp_slider, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_ac_temp_label
    ui->HA_dark_ac_temp_label = lv_label_create(ui->HA_dark_ac_card);
    lv_label_set_text(ui->HA_dark_ac_temp_label, "°C");
    lv_label_set_long_mode(ui->HA_dark_ac_temp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_ac_temp_label, 212, 16);
    lv_obj_set_size(ui->HA_dark_ac_temp_label, 30, 24);

    //Write style for HA_dark_ac_temp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_ac_temp_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_ac_temp_label, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_temp_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_ac_temp_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_temp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_ac_temp
    ui->HA_dark_ac_temp = lv_label_create(ui->HA_dark_ac_card);
    lv_label_set_text(ui->HA_dark_ac_temp, "16");
    lv_label_set_long_mode(ui->HA_dark_ac_temp, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_ac_temp, 143, 16);
    lv_obj_set_size(ui->HA_dark_ac_temp, 65, 24);

    //Write style for HA_dark_ac_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_ac_temp, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_ac_temp, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_ac_temp, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_ac_off
    ui->HA_dark_ac_off = lv_btn_create(ui->HA_dark_ac_card);
    lv_obj_add_flag(ui->HA_dark_ac_off, LV_OBJ_FLAG_CHECKABLE);
    ui->HA_dark_ac_off_label = lv_label_create(ui->HA_dark_ac_off);
    lv_label_set_text(ui->HA_dark_ac_off_label, "Off");
    lv_label_set_long_mode(ui->HA_dark_ac_off_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HA_dark_ac_off_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HA_dark_ac_off, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HA_dark_ac_off_label, LV_PCT(100));
    lv_obj_set_pos(ui->HA_dark_ac_off, 10, 75);
    lv_obj_set_size(ui->HA_dark_ac_off, 75, 28);

    //Write style for HA_dark_ac_off, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_off, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_off, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_ac_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_off, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_off, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_ac_off, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_ac_off, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_off, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_ac_off, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_ac_off, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_off, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_off, lv_color_hex(0x747474), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_off, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->HA_dark_ac_off, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->HA_dark_ac_off, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_off, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->HA_dark_ac_off, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->HA_dark_ac_off, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_off, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for HA_dark_ac_off, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_off, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_off, lv_color_hex(0x747474), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_off, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_ac_off, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->HA_dark_ac_off, 9, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_off, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->HA_dark_ac_off, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->HA_dark_ac_off, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_off, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes HA_dark_ac_cool
    ui->HA_dark_ac_cool = lv_btn_create(ui->HA_dark_ac_card);
    lv_obj_add_flag(ui->HA_dark_ac_cool, LV_OBJ_FLAG_CHECKABLE);
    ui->HA_dark_ac_cool_label = lv_label_create(ui->HA_dark_ac_cool);
    lv_label_set_text(ui->HA_dark_ac_cool_label, "Cool");
    lv_label_set_long_mode(ui->HA_dark_ac_cool_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HA_dark_ac_cool_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HA_dark_ac_cool, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HA_dark_ac_cool_label, LV_PCT(100));
    lv_obj_set_pos(ui->HA_dark_ac_cool, 92, 75);
    lv_obj_set_size(ui->HA_dark_ac_cool, 75, 28);

    //Write style for HA_dark_ac_cool, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_cool, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_cool, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_cool, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_ac_cool, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_cool, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_cool, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_ac_cool, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_ac_cool, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_cool, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_ac_cool, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_ac_cool, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_cool, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_cool, lv_color_hex(0x4b9ffe), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_cool, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->HA_dark_ac_cool, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->HA_dark_ac_cool, 6, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_cool, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->HA_dark_ac_cool, lv_color_hex(0xf1f1f1), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->HA_dark_ac_cool, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_cool, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for HA_dark_ac_cool, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_cool, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_cool, lv_color_hex(0x4b9ffe), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_cool, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_ac_cool, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->HA_dark_ac_cool, 9, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_cool, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->HA_dark_ac_cool, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->HA_dark_ac_cool, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_cool, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes HA_dark_ac_heat
    ui->HA_dark_ac_heat = lv_btn_create(ui->HA_dark_ac_card);
    lv_obj_add_flag(ui->HA_dark_ac_heat, LV_OBJ_FLAG_CHECKABLE);
    ui->HA_dark_ac_heat_label = lv_label_create(ui->HA_dark_ac_heat);
    lv_label_set_text(ui->HA_dark_ac_heat_label, "Heat");
    lv_label_set_long_mode(ui->HA_dark_ac_heat_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HA_dark_ac_heat_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HA_dark_ac_heat, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HA_dark_ac_heat_label, LV_PCT(100));
    lv_obj_set_pos(ui->HA_dark_ac_heat, 174, 75);
    lv_obj_set_size(ui->HA_dark_ac_heat, 75, 28);

    //Write style for HA_dark_ac_heat, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_heat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_heat, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_heat, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_ac_heat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_heat, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_heat, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_ac_heat, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_ac_heat, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_heat, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_ac_heat, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_ac_heat, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_heat, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_heat, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_heat, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->HA_dark_ac_heat, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->HA_dark_ac_heat, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_heat, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->HA_dark_ac_heat, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->HA_dark_ac_heat, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_heat, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for HA_dark_ac_heat, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_heat, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_ac_heat, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_ac_heat, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_ac_heat, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->HA_dark_ac_heat, 9, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_heat, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->HA_dark_ac_heat, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->HA_dark_ac_heat, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_heat, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes HA_dark_ac_info
    ui->HA_dark_ac_info = lv_spangroup_create(ui->HA_dark_ac_card);
    lv_spangroup_set_align(ui->HA_dark_ac_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_ac_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_ac_info, LV_SPAN_MODE_FIXED);
    //create span
    ui->HA_dark_ac_info_span = lv_spangroup_new_span(ui->HA_dark_ac_info);
    lv_span_set_text(ui->HA_dark_ac_info_span, "On");
    lv_style_set_text_color(&ui->HA_dark_ac_info_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_ac_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_ac_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_ac_info_span = lv_spangroup_new_span(ui->HA_dark_ac_info);
    lv_span_set_text(ui->HA_dark_ac_info_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_ac_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_ac_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_ac_info_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_ac_info_span = lv_spangroup_new_span(ui->HA_dark_ac_info);
    lv_span_set_text(ui->HA_dark_ac_info_span, "59min");
    lv_style_set_text_color(&ui->HA_dark_ac_info_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_ac_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_ac_info_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_ac_info, 14, 26);
    lv_obj_set_size(ui->HA_dark_ac_info, 139, 19);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_ac_info_main_main_default
    static lv_style_t style_HA_dark_ac_info_main_main_default;
    ui_init_style(&style_HA_dark_ac_info_main_main_default);

    lv_style_set_border_width(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_ac_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_ac_info_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_ac_info, &style_HA_dark_ac_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_ac_info);

    //Write codes HA_dark_ac_title
    ui->HA_dark_ac_title = lv_label_create(ui->HA_dark_ac_card);
    lv_label_set_text(ui->HA_dark_ac_title, "AC");
    lv_label_set_long_mode(ui->HA_dark_ac_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_ac_title, 14, 7);
    lv_obj_set_size(ui->HA_dark_ac_title, 98, 19);

    //Write style for HA_dark_ac_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_ac_title, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_ac_title, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_ac_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_ac_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_ac_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_time_card
    ui->HA_dark_time_card = lv_obj_create(ui->HA_dark);
    lv_obj_set_pos(ui->HA_dark_time_card, 15, 21);
    lv_obj_set_size(ui->HA_dark_time_card, 260, 100);
    lv_obj_set_scrollbar_mode(ui->HA_dark_time_card, LV_SCROLLBAR_MODE_OFF);

    //Write style for HA_dark_time_card, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_time_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_time_card, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_time_card, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_time_card, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_time_card, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_time_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_time_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_time_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_time_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_time_card, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->HA_dark_time_card, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->HA_dark_time_card, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->HA_dark_time_card, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->HA_dark_time_card, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->HA_dark_time_card, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_date
    ui->HA_dark_date = lv_spangroup_create(ui->HA_dark_time_card);
    lv_spangroup_set_align(ui->HA_dark_date, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_date, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_date, LV_SPAN_MODE_FIXED);
    //create span
    ui->HA_dark_date_span = lv_spangroup_new_span(ui->HA_dark_date);
    lv_span_set_text(ui->HA_dark_date_span, "Mon");
    lv_style_set_text_color(&ui->HA_dark_date_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_date_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_date_span->style, &lv_font_montserratMedium_17);
    ui->HA_dark_date_span = lv_spangroup_new_span(ui->HA_dark_date);
    lv_span_set_text(ui->HA_dark_date_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_date_span->style, lv_color_hex(0xe0e0e0));
    lv_style_set_text_decor(&ui->HA_dark_date_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_date_span->style, &lv_font_montserratMedium_17);
    ui->HA_dark_date_span = lv_spangroup_new_span(ui->HA_dark_date);
    lv_span_set_text(ui->HA_dark_date_span, "2025/12/8");
    lv_style_set_text_color(&ui->HA_dark_date_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_date_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_date_span->style, &lv_font_montserratMedium_17);
    lv_obj_set_pos(ui->HA_dark_date, 14, 77);
    lv_obj_set_size(ui->HA_dark_date, 155, 17);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_date_main_main_default
    static lv_style_t style_HA_dark_date_main_main_default;
    ui_init_style(&style_HA_dark_date_main_main_default);

    lv_style_set_border_width(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_date_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_date_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_date, &style_HA_dark_date_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_date);

    //Write codes HA_dark_digital_clock_time
    static bool HA_dark_digital_clock_time_timer_enabled = false;
    ui->HA_dark_digital_clock_time = lv_dclock_create(ui->HA_dark_time_card, "18:48:11");
    if (!HA_dark_digital_clock_time_timer_enabled) {
        lv_timer_create(HA_dark_digital_clock_time_timer, 1000, NULL);
        HA_dark_digital_clock_time_timer_enabled = true;
    }
    lv_obj_set_pos(ui->HA_dark_digital_clock_time, 16, 40);
    lv_obj_set_size(ui->HA_dark_digital_clock_time, 123, 33);

    //Write style for HA_dark_digital_clock_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_digital_clock_time, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_digital_clock_time, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_digital_clock_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_digital_clock_time, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_digital_clock_time, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_temp
    ui->HA_dark_temp = lv_spangroup_create(ui->HA_dark_time_card);
    lv_spangroup_set_align(ui->HA_dark_temp, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_temp, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_temp, LV_SPAN_MODE_FIXED);
    //create span
    ui->HA_dark_temp_span = lv_spangroup_new_span(ui->HA_dark_temp);
    lv_span_set_text(ui->HA_dark_temp_span, "26");
    lv_style_set_text_color(&ui->HA_dark_temp_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->HA_dark_temp_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_temp_span->style, &lv_font_montserratMedium_30);
    ui->HA_dark_temp_span = lv_spangroup_new_span(ui->HA_dark_temp);
    lv_span_set_text(ui->HA_dark_temp_span, "°C");
    lv_style_set_text_color(&ui->HA_dark_temp_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_temp_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_temp_span->style, &lv_font_montserratMedium_22);
    lv_obj_set_pos(ui->HA_dark_temp, 176, 68);
    lv_obj_set_size(ui->HA_dark_temp, 77, 27);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_temp_main_main_default
    static lv_style_t style_HA_dark_temp_main_main_default;
    ui_init_style(&style_HA_dark_temp_main_main_default);

    lv_style_set_border_width(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_temp_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_temp_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_temp, &style_HA_dark_temp_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_temp);

    //Write codes HA_dark_weather
    ui->HA_dark_weather = lv_img_create(ui->HA_dark_time_card);
    lv_obj_add_flag(ui->HA_dark_weather, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HA_dark_weather, &_cloudy_alpha_60x60);
    lv_img_set_pivot(ui->HA_dark_weather, 50,50);
    lv_img_set_angle(ui->HA_dark_weather, 0);
    lv_obj_set_pos(ui->HA_dark_weather, 176, 2);
    lv_obj_set_size(ui->HA_dark_weather, 60, 60);

    //Write style for HA_dark_weather, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->HA_dark_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HA_dark_weather, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_weather, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HA_dark_weather, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_menu
    ui->HA_dark_menu = lv_dropdown_create(ui->HA_dark);
    lv_dropdown_set_options(ui->HA_dark_menu, "HA\nPC\nOP");
    lv_obj_set_pos(ui->HA_dark_menu, 27, 32);
    lv_obj_set_size(ui->HA_dark_menu, 59, 30);

    //Write style for HA_dark_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->HA_dark_menu, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_menu, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_menu, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_menu, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_menu, lv_color_hex(0x3E3F43), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_HA_dark_menu_extra_list_selected_checked
    static lv_style_t style_HA_dark_menu_extra_list_selected_checked;
    ui_init_style(&style_HA_dark_menu_extra_list_selected_checked);

    lv_style_set_border_width(&style_HA_dark_menu_extra_list_selected_checked, 0);
    lv_style_set_radius(&style_HA_dark_menu_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_HA_dark_menu_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_HA_dark_menu_extra_list_selected_checked, lv_color_hex(0x4F5159));
    lv_style_set_bg_grad_dir(&style_HA_dark_menu_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->HA_dark_menu), &style_HA_dark_menu_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_menu_extra_list_main_default
    static lv_style_t style_HA_dark_menu_extra_list_main_default;
    ui_init_style(&style_HA_dark_menu_extra_list_main_default);

    lv_style_set_max_height(&style_HA_dark_menu_extra_list_main_default, 130);
    lv_style_set_text_color(&style_HA_dark_menu_extra_list_main_default, lv_color_hex(0xebebeb));
    lv_style_set_text_font(&style_HA_dark_menu_extra_list_main_default, &lv_font_montserratMedium_15);
    lv_style_set_text_opa(&style_HA_dark_menu_extra_list_main_default, 255);
    lv_style_set_border_width(&style_HA_dark_menu_extra_list_main_default, 0);
    lv_style_set_radius(&style_HA_dark_menu_extra_list_main_default, 7);
    lv_style_set_bg_opa(&style_HA_dark_menu_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_HA_dark_menu_extra_list_main_default, lv_color_hex(0x3E3F43));
    lv_style_set_bg_grad_dir(&style_HA_dark_menu_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->HA_dark_menu), &style_HA_dark_menu_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of HA_dark.


    //Update current screen layout.
    lv_obj_update_layout(ui->HA_dark);

    //Init events for screen.
    events_init_HA_dark(ui);
}
