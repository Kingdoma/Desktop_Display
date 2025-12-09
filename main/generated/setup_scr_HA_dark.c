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



int HA_dark_digital_clock_1_min_value = 25;
int HA_dark_digital_clock_1_hour_value = 11;
int HA_dark_digital_clock_1_sec_value = 50;
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

    //Write codes HA_dark_label_10
    ui->HA_dark_label_10 = lv_label_create(ui->HA_dark_printer_card);
    lv_label_set_text(ui->HA_dark_label_10, "3D Printer\n");
    lv_label_set_long_mode(ui->HA_dark_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_10, 10, 10);
    lv_obj_set_size(ui->HA_dark_label_10, 104, 17);

    //Write style for HA_dark_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_10, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_10, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_10, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_8
    ui->HA_dark_spangroup_8 = lv_spangroup_create(ui->HA_dark_printer_card);
    lv_spangroup_set_align(ui->HA_dark_spangroup_8, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_8, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_8, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_spangroup_8_span = lv_spangroup_new_span(ui->HA_dark_spangroup_8);
    lv_span_set_text(ui->HA_dark_spangroup_8_span, "A1");
    lv_style_set_text_color(&ui->HA_dark_spangroup_8_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_8_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_8_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_8_span = lv_spangroup_new_span(ui->HA_dark_spangroup_8);
    lv_span_set_text(ui->HA_dark_spangroup_8_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_8_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_8_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_8_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_8_span = lv_spangroup_new_span(ui->HA_dark_spangroup_8);
    lv_span_set_text(ui->HA_dark_spangroup_8_span, "10h45min");
    lv_style_set_text_color(&ui->HA_dark_spangroup_8_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_8_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_8_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_spangroup_8, 10, 30);
    lv_obj_set_size(ui->HA_dark_spangroup_8, 165, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_8_main_main_default
    static lv_style_t style_HA_dark_spangroup_8_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_8_main_main_default);

    lv_style_set_bg_opa(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_border_width(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_8_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_8, &style_HA_dark_spangroup_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_8);

    //Write codes HA_dark_slider_2
    ui->HA_dark_slider_2 = lv_slider_create(ui->HA_dark_printer_card);
    lv_slider_set_range(ui->HA_dark_slider_2, 15, 35);
    lv_slider_set_mode(ui->HA_dark_slider_2, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->HA_dark_slider_2, 26, LV_ANIM_OFF);
    lv_obj_set_pos(ui->HA_dark_slider_2, 103, 14);
    lv_obj_set_size(ui->HA_dark_slider_2, 336, 23);

    //Write style for HA_dark_slider_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_slider_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_slider_2, lv_color_hex(0x717171), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_slider_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_slider_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->HA_dark_slider_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_slider_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_slider_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_slider_2, lv_color_hex(0xf5bb0d), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_slider_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_slider_2, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for HA_dark_slider_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_slider_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_slider_2, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

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

    //Write codes HA_dark_label_9
    ui->HA_dark_label_9 = lv_label_create(ui->HA_dark_temperature_card);
    lv_label_set_text(ui->HA_dark_label_9, "Temperature");
    lv_label_set_long_mode(ui->HA_dark_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_9, 55, 10);
    lv_obj_set_size(ui->HA_dark_label_9, 108, 19);

    //Write style for HA_dark_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_9, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_9, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_7
    ui->HA_dark_spangroup_7 = lv_spangroup_create(ui->HA_dark_temperature_card);
    lv_spangroup_set_align(ui->HA_dark_spangroup_7, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_7, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_7, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_spangroup_7_span = lv_spangroup_new_span(ui->HA_dark_spangroup_7);
    lv_span_set_text(ui->HA_dark_spangroup_7_span, "21°C");
    lv_style_set_text_color(&ui->HA_dark_spangroup_7_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_7_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_7_span = lv_spangroup_new_span(ui->HA_dark_spangroup_7);
    lv_span_set_text(ui->HA_dark_spangroup_7_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_7_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_7_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_7_span = lv_spangroup_new_span(ui->HA_dark_spangroup_7);
    lv_span_set_text(ui->HA_dark_spangroup_7_span, "5min");
    lv_style_set_text_color(&ui->HA_dark_spangroup_7_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_7_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_7_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_spangroup_7, 55, 30);
    lv_obj_set_size(ui->HA_dark_spangroup_7, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_7_main_main_default
    static lv_style_t style_HA_dark_spangroup_7_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_7_main_main_default);

    lv_style_set_border_width(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_7_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_7, &style_HA_dark_spangroup_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_7);

    //Write codes HA_dark_label_8
    ui->HA_dark_label_8 = lv_label_create(ui->HA_dark_temperature_card);
    lv_label_set_text(ui->HA_dark_label_8, " ");
    lv_label_set_long_mode(ui->HA_dark_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_8, 8, 8);
    lv_obj_set_size(ui->HA_dark_label_8, 35, 35);

    //Write style for HA_dark_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_8, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_8, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_label_8, lv_color_hex(0xff5700), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HA_dark_label_8, &_temperature_35x35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HA_dark_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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

    //Write codes HA_dark_label_7
    ui->HA_dark_label_7 = lv_label_create(ui->HA_dark_humidity_card);
    lv_label_set_text(ui->HA_dark_label_7, "Humidity");
    lv_label_set_long_mode(ui->HA_dark_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_7, 55, 10);
    lv_obj_set_size(ui->HA_dark_label_7, 98, 19);

    //Write style for HA_dark_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_7, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_7, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_6
    ui->HA_dark_spangroup_6 = lv_spangroup_create(ui->HA_dark_humidity_card);
    lv_spangroup_set_align(ui->HA_dark_spangroup_6, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_6, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_6, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_spangroup_6_span = lv_spangroup_new_span(ui->HA_dark_spangroup_6);
    lv_span_set_text(ui->HA_dark_spangroup_6_span, "70%");
    lv_style_set_text_color(&ui->HA_dark_spangroup_6_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_6_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_6_span = lv_spangroup_new_span(ui->HA_dark_spangroup_6);
    lv_span_set_text(ui->HA_dark_spangroup_6_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_6_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_6_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_6_span = lv_spangroup_new_span(ui->HA_dark_spangroup_6);
    lv_span_set_text(ui->HA_dark_spangroup_6_span, "6min");
    lv_style_set_text_color(&ui->HA_dark_spangroup_6_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_6_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_6_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_spangroup_6, 55, 31);
    lv_obj_set_size(ui->HA_dark_spangroup_6, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_6_main_main_default
    static lv_style_t style_HA_dark_spangroup_6_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_6_main_main_default);

    lv_style_set_border_width(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_6_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_6, &style_HA_dark_spangroup_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_6);

    //Write codes HA_dark_label_6
    ui->HA_dark_label_6 = lv_label_create(ui->HA_dark_humidity_card);
    lv_label_set_text(ui->HA_dark_label_6, " ");
    lv_label_set_long_mode(ui->HA_dark_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_6, 9, 7);
    lv_obj_set_size(ui->HA_dark_label_6, 35, 35);

    //Write style for HA_dark_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_6, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->HA_dark_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->HA_dark_label_6, lv_color_hex(0x00a1ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->HA_dark_label_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_6, 18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_label_6, lv_color_hex(0x00a1ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->HA_dark_label_6, &_humidity_35x35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->HA_dark_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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

    //Write codes HA_dark_sw_4
    ui->HA_dark_sw_4 = lv_switch_create(ui->HA_dark_switch_card_2);
    lv_obj_set_pos(ui->HA_dark_sw_4, 13, 11);
    lv_obj_set_size(ui->HA_dark_sw_4, 44, 25);

    //Write style for HA_dark_sw_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_4, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_4, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_sw_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_sw_4, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_4, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_4, lv_color_hex(0xffc700), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_4, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_sw_4, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for HA_dark_sw_4, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_4, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_4, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_4, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_4, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_4, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_label_5
    ui->HA_dark_label_5 = lv_label_create(ui->HA_dark_switch_card_2);
    lv_label_set_text(ui->HA_dark_label_5, "Switch");
    lv_label_set_long_mode(ui->HA_dark_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_5, 71, 5);
    lv_obj_set_size(ui->HA_dark_label_5, 98, 19);

    //Write style for HA_dark_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_5, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_5, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_5
    ui->HA_dark_spangroup_5 = lv_spangroup_create(ui->HA_dark_switch_card_2);
    lv_spangroup_set_align(ui->HA_dark_spangroup_5, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_5, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_5, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_spangroup_5_span = lv_spangroup_new_span(ui->HA_dark_spangroup_5);
    lv_span_set_text(ui->HA_dark_spangroup_5_span, "On");
    lv_style_set_text_color(&ui->HA_dark_spangroup_5_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_5_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_5_span = lv_spangroup_new_span(ui->HA_dark_spangroup_5);
    lv_span_set_text(ui->HA_dark_spangroup_5_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_5_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_5_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_5_span = lv_spangroup_new_span(ui->HA_dark_spangroup_5);
    lv_span_set_text(ui->HA_dark_spangroup_5_span, "35W");
    lv_style_set_text_color(&ui->HA_dark_spangroup_5_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_5_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_5_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_spangroup_5, 71, 27);
    lv_obj_set_size(ui->HA_dark_spangroup_5, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_5_main_main_default
    static lv_style_t style_HA_dark_spangroup_5_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_5_main_main_default);

    lv_style_set_border_width(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_5_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_5, &style_HA_dark_spangroup_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_5);

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

    //Write codes HA_dark_sw_3
    ui->HA_dark_sw_3 = lv_switch_create(ui->HA_dark_switch_card_1);
    lv_obj_set_pos(ui->HA_dark_sw_3, 13, 11);
    lv_obj_set_size(ui->HA_dark_sw_3, 44, 25);

    //Write style for HA_dark_sw_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_3, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_3, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_sw_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_sw_3, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_3, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_3, lv_color_hex(0xffc700), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_3, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->HA_dark_sw_3, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for HA_dark_sw_3, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_sw_3, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_sw_3, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_sw_3, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_sw_3, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_sw_3, 10, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_label_4
    ui->HA_dark_label_4 = lv_label_create(ui->HA_dark_switch_card_1);
    lv_label_set_text(ui->HA_dark_label_4, "Switch");
    lv_label_set_long_mode(ui->HA_dark_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_4, 72, 6);
    lv_obj_set_size(ui->HA_dark_label_4, 98, 19);

    //Write style for HA_dark_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_4, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_4
    ui->HA_dark_spangroup_4 = lv_spangroup_create(ui->HA_dark_switch_card_1);
    lv_spangroup_set_align(ui->HA_dark_spangroup_4, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_4, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_4, LV_SPAN_MODE_BREAK);
    //create span
    ui->HA_dark_spangroup_4_span = lv_spangroup_new_span(ui->HA_dark_spangroup_4);
    lv_span_set_text(ui->HA_dark_spangroup_4_span, "On");
    lv_style_set_text_color(&ui->HA_dark_spangroup_4_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_4_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_4_span = lv_spangroup_new_span(ui->HA_dark_spangroup_4);
    lv_span_set_text(ui->HA_dark_spangroup_4_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_4_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_4_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_4_span = lv_spangroup_new_span(ui->HA_dark_spangroup_4);
    lv_span_set_text(ui->HA_dark_spangroup_4_span, "35W");
    lv_style_set_text_color(&ui->HA_dark_spangroup_4_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_4_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_4_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_spangroup_4, 71, 27);
    lv_obj_set_size(ui->HA_dark_spangroup_4, 104, 12);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_4_main_main_default
    static lv_style_t style_HA_dark_spangroup_4_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_4_main_main_default);

    lv_style_set_border_width(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_4_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_4, &style_HA_dark_spangroup_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_4);

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

    //Write codes HA_dark_label_3
    ui->HA_dark_label_3 = lv_label_create(ui->HA_dark_ac_card);
    lv_label_set_text(ui->HA_dark_label_3, "AC");
    lv_label_set_long_mode(ui->HA_dark_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_3, 14, 7);
    lv_obj_set_size(ui->HA_dark_label_3, 98, 19);

    //Write style for HA_dark_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_3, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_3
    ui->HA_dark_spangroup_3 = lv_spangroup_create(ui->HA_dark_ac_card);
    lv_spangroup_set_align(ui->HA_dark_spangroup_3, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_3, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_3, LV_SPAN_MODE_FIXED);
    //create span
    ui->HA_dark_spangroup_3_span = lv_spangroup_new_span(ui->HA_dark_spangroup_3);
    lv_span_set_text(ui->HA_dark_spangroup_3_span, "On");
    lv_style_set_text_color(&ui->HA_dark_spangroup_3_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_3_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_3_span = lv_spangroup_new_span(ui->HA_dark_spangroup_3);
    lv_span_set_text(ui->HA_dark_spangroup_3_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_3_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_3_span->style, &lv_font_montserratMedium_12);
    ui->HA_dark_spangroup_3_span = lv_spangroup_new_span(ui->HA_dark_spangroup_3);
    lv_span_set_text(ui->HA_dark_spangroup_3_span, "59min Ago");
    lv_style_set_text_color(&ui->HA_dark_spangroup_3_span->style, lv_color_hex(0x7b7b7b));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_3_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_3_span->style, &lv_font_montserratMedium_12);
    lv_obj_set_pos(ui->HA_dark_spangroup_3, 14, 26);
    lv_obj_set_size(ui->HA_dark_spangroup_3, 139, 19);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_3_main_main_default
    static lv_style_t style_HA_dark_spangroup_3_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_3_main_main_default);

    lv_style_set_border_width(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_3_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_3, &style_HA_dark_spangroup_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_3);

    //Write codes HA_dark_slider_1
    ui->HA_dark_slider_1 = lv_slider_create(ui->HA_dark_ac_card);
    lv_slider_set_range(ui->HA_dark_slider_1, 15, 35);
    lv_slider_set_mode(ui->HA_dark_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->HA_dark_slider_1, 26, LV_ANIM_OFF);
    lv_obj_set_pos(ui->HA_dark_slider_1, 10, 45);
    lv_obj_set_size(ui->HA_dark_slider_1, 240, 23);

    //Write style for HA_dark_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HA_dark_slider_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_slider_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_slider_1, lv_color_hex(0x717171), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->HA_dark_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_slider_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_slider_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for HA_dark_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_slider_1, 5, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes HA_dark_label_2
    ui->HA_dark_label_2 = lv_label_create(ui->HA_dark_ac_card);
    lv_label_set_text(ui->HA_dark_label_2, "26");
    lv_label_set_long_mode(ui->HA_dark_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_2, 143, 16);
    lv_obj_set_size(ui->HA_dark_label_2, 65, 24);

    //Write style for HA_dark_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_2, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_label_1
    ui->HA_dark_label_1 = lv_label_create(ui->HA_dark_ac_card);
    lv_label_set_text(ui->HA_dark_label_1, "°C");
    lv_label_set_long_mode(ui->HA_dark_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->HA_dark_label_1, 212, 16);
    lv_obj_set_size(ui->HA_dark_label_1, 30, 24);

    //Write style for HA_dark_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_label_1, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_label_1, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_label_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_btn_3
    ui->HA_dark_btn_3 = lv_btn_create(ui->HA_dark_ac_card);
    ui->HA_dark_btn_3_label = lv_label_create(ui->HA_dark_btn_3);
    lv_label_set_text(ui->HA_dark_btn_3_label, "Off");
    lv_label_set_long_mode(ui->HA_dark_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HA_dark_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HA_dark_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HA_dark_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->HA_dark_btn_3, 10, 75);
    lv_obj_set_size(ui->HA_dark_btn_3, 75, 28);

    //Write style for HA_dark_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->HA_dark_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_btn_3, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_btn_3, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_btn_3, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_btn_3, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->HA_dark_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->HA_dark_btn_3, lv_color_hex(0x747474), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->HA_dark_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->HA_dark_btn_3, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->HA_dark_btn_3, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->HA_dark_btn_3, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->HA_dark_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->HA_dark_btn_3, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes HA_dark_btn_2
    ui->HA_dark_btn_2 = lv_btn_create(ui->HA_dark_ac_card);
    ui->HA_dark_btn_2_label = lv_label_create(ui->HA_dark_btn_2);
    lv_label_set_text(ui->HA_dark_btn_2_label, "Cool");
    lv_label_set_long_mode(ui->HA_dark_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HA_dark_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HA_dark_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HA_dark_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->HA_dark_btn_2, 92, 75);
    lv_obj_set_size(ui->HA_dark_btn_2, 75, 28);

    //Write style for HA_dark_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_btn_2, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_btn_2, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_btn_2, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_btn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->HA_dark_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->HA_dark_btn_2, lv_color_hex(0x4b9ffe), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->HA_dark_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->HA_dark_btn_2, 6, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->HA_dark_btn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->HA_dark_btn_2, lv_color_hex(0xf1f1f1), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->HA_dark_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->HA_dark_btn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes HA_dark_btn_1
    ui->HA_dark_btn_1 = lv_btn_create(ui->HA_dark_ac_card);
    ui->HA_dark_btn_1_label = lv_label_create(ui->HA_dark_btn_1);
    lv_label_set_text(ui->HA_dark_btn_1_label, "Heat");
    lv_label_set_long_mode(ui->HA_dark_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->HA_dark_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->HA_dark_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->HA_dark_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->HA_dark_btn_1, 174, 75);
    lv_obj_set_size(ui->HA_dark_btn_1, 75, 28);

    //Write style for HA_dark_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->HA_dark_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->HA_dark_btn_1, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->HA_dark_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->HA_dark_btn_1, 9, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_btn_1, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for HA_dark_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->HA_dark_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->HA_dark_btn_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->HA_dark_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->HA_dark_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->HA_dark_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->HA_dark_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->HA_dark_btn_1, lv_color_hex(0xf5f5f5), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->HA_dark_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->HA_dark_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

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

    //Write codes HA_dark_spangroup_2
    ui->HA_dark_spangroup_2 = lv_spangroup_create(ui->HA_dark_time_card);
    lv_spangroup_set_align(ui->HA_dark_spangroup_2, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_2, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_2, LV_SPAN_MODE_FIXED);
    //create span
    ui->HA_dark_spangroup_2_span = lv_spangroup_new_span(ui->HA_dark_spangroup_2);
    lv_span_set_text(ui->HA_dark_spangroup_2_span, "Mon");
    lv_style_set_text_color(&ui->HA_dark_spangroup_2_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_2_span->style, &lv_font_montserratMedium_17);
    ui->HA_dark_spangroup_2_span = lv_spangroup_new_span(ui->HA_dark_spangroup_2);
    lv_span_set_text(ui->HA_dark_spangroup_2_span, " - ");
    lv_style_set_text_color(&ui->HA_dark_spangroup_2_span->style, lv_color_hex(0xe0e0e0));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_2_span->style, &lv_font_montserratMedium_17);
    ui->HA_dark_spangroup_2_span = lv_spangroup_new_span(ui->HA_dark_spangroup_2);
    lv_span_set_text(ui->HA_dark_spangroup_2_span, "2025/12/8");
    lv_style_set_text_color(&ui->HA_dark_spangroup_2_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_2_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_2_span->style, &lv_font_montserratMedium_17);
    lv_obj_set_pos(ui->HA_dark_spangroup_2, 14, 77);
    lv_obj_set_size(ui->HA_dark_spangroup_2, 155, 17);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_2_main_main_default
    static lv_style_t style_HA_dark_spangroup_2_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_2_main_main_default);

    lv_style_set_border_width(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_radius(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_2_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_2, &style_HA_dark_spangroup_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_2);

    //Write codes HA_dark_digital_clock_1
    static bool HA_dark_digital_clock_1_timer_enabled = false;
    ui->HA_dark_digital_clock_1 = lv_dclock_create(ui->HA_dark_time_card, "11:25:50");
    if (!HA_dark_digital_clock_1_timer_enabled) {
        lv_timer_create(HA_dark_digital_clock_1_timer, 1000, NULL);
        HA_dark_digital_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->HA_dark_digital_clock_1, 16, 40);
    lv_obj_set_size(ui->HA_dark_digital_clock_1, 123, 33);

    //Write style for HA_dark_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->HA_dark_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->HA_dark_digital_clock_1, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->HA_dark_digital_clock_1, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->HA_dark_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->HA_dark_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->HA_dark_digital_clock_1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_spangroup_1
    ui->HA_dark_spangroup_1 = lv_spangroup_create(ui->HA_dark_time_card);
    lv_spangroup_set_align(ui->HA_dark_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->HA_dark_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->HA_dark_spangroup_1, LV_SPAN_MODE_FIXED);
    //create span
    ui->HA_dark_spangroup_1_span = lv_spangroup_new_span(ui->HA_dark_spangroup_1);
    lv_span_set_text(ui->HA_dark_spangroup_1_span, "26");
    lv_style_set_text_color(&ui->HA_dark_spangroup_1_span->style, lv_color_hex(0xebebeb));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_1_span->style, &lv_font_montserratMedium_30);
    ui->HA_dark_spangroup_1_span = lv_spangroup_new_span(ui->HA_dark_spangroup_1);
    lv_span_set_text(ui->HA_dark_spangroup_1_span, "°C");
    lv_style_set_text_color(&ui->HA_dark_spangroup_1_span->style, lv_color_hex(0xe6e6e6));
    lv_style_set_text_decor(&ui->HA_dark_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->HA_dark_spangroup_1_span->style, &lv_font_montserratMedium_22);
    lv_obj_set_pos(ui->HA_dark_spangroup_1, 176, 68);
    lv_obj_set_size(ui->HA_dark_spangroup_1, 77, 27);

    //Write style state: LV_STATE_DEFAULT for &style_HA_dark_spangroup_1_main_main_default
    static lv_style_t style_HA_dark_spangroup_1_main_main_default;
    ui_init_style(&style_HA_dark_spangroup_1_main_main_default);

    lv_style_set_radius(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_pad_right(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_style_set_border_width(&style_HA_dark_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->HA_dark_spangroup_1, &style_HA_dark_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->HA_dark_spangroup_1);

    //Write codes HA_dark_img_1
    ui->HA_dark_img_1 = lv_img_create(ui->HA_dark_time_card);
    lv_obj_add_flag(ui->HA_dark_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->HA_dark_img_1, &_cloudy_alpha_60x60);
    lv_img_set_pivot(ui->HA_dark_img_1, 50,50);
    lv_img_set_angle(ui->HA_dark_img_1, 0);
    lv_obj_set_pos(ui->HA_dark_img_1, 176, 2);
    lv_obj_set_size(ui->HA_dark_img_1, 60, 60);

    //Write style for HA_dark_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->HA_dark_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->HA_dark_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->HA_dark_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->HA_dark_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes HA_dark_menu
    ui->HA_dark_menu = lv_dropdown_create(ui->HA_dark);
    lv_dropdown_set_options(ui->HA_dark_menu, "HA\nPC");
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

    lv_style_set_max_height(&style_HA_dark_menu_extra_list_main_default, 80);
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
