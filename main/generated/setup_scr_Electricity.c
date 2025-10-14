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



int Electricity_digital_clock_time_min_value = 25;
int Electricity_digital_clock_time_hour_value = 11;
int Electricity_digital_clock_time_sec_value = 50;
void setup_scr_Electricity(lv_ui *ui)
{
    //Write codes Electricity
    ui->Electricity = lv_obj_create(NULL);
    lv_obj_set_size(ui->Electricity, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Electricity, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity, &_sub_page_bak_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_btn_home
    ui->Electricity_btn_home = lv_btn_create(ui->Electricity);
    ui->Electricity_btn_home_label = lv_label_create(ui->Electricity_btn_home);
    lv_label_set_text(ui->Electricity_btn_home_label, "" LV_SYMBOL_HOME "   ");
    lv_label_set_long_mode(ui->Electricity_btn_home_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Electricity_btn_home_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Electricity_btn_home, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Electricity_btn_home_label, LV_PCT(100));
    lv_obj_set_pos(ui->Electricity_btn_home, -1, 130);
    lv_obj_set_size(ui->Electricity_btn_home, 25, 56);

    //Write style for Electricity_btn_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_btn_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Electricity_btn_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_btn_home, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_btn_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_btn_home, &_home_bak_25x56, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_btn_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_btn_home, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_btn_home, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_btn_home, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_btn_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_btn_home, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_tit
    ui->Electricity_label_tit = lv_label_create(ui->Electricity);
    lv_label_set_text(ui->Electricity_label_tit, "Building Electricity Monitoring");
    lv_label_set_long_mode(ui->Electricity_label_tit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_tit, 132, 13);
    lv_obj_set_size(ui->Electricity_label_tit, 216, 26);

    //Write style for Electricity_label_tit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_tit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_tit, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_tit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_tit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_tit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_1
    ui->Electricity_cont_1 = lv_obj_create(ui->Electricity);
    lv_obj_set_pos(ui->Electricity_cont_1, 156, 373);
    lv_obj_set_size(ui->Electricity_cont_1, 120, 42);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_cont_1, &_pos_120x42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_1_value
    ui->Electricity_label_1_value = lv_label_create(ui->Electricity_cont_1);
    lv_label_set_text(ui->Electricity_label_1_value, "35kw/h");
    lv_label_set_long_mode(ui->Electricity_label_1_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_1_value, 42, 16);
    lv_obj_set_size(ui->Electricity_label_1_value, 54, 11);

    //Write style for Electricity_label_1_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_1_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_1_value, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_1_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_1_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_1_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_1_NO
    ui->Electricity_label_1_NO = lv_label_create(ui->Electricity_cont_1);
    lv_label_set_text(ui->Electricity_label_1_NO, "#01");
    lv_label_set_long_mode(ui->Electricity_label_1_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_1_NO, 6, 14);
    lv_obj_set_size(ui->Electricity_label_1_NO, 29, 15);

    //Write style for Electricity_label_1_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_1_NO, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_1_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_1_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_1_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_2
    ui->Electricity_cont_2 = lv_obj_create(ui->Electricity);
    lv_obj_set_pos(ui->Electricity_cont_2, 168, -66);
    lv_obj_set_size(ui->Electricity_cont_2, 120, 42);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_cont_2, &_pos_120x42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_2_value
    ui->Electricity_label_2_value = lv_label_create(ui->Electricity_cont_2);
    lv_label_set_text(ui->Electricity_label_2_value, "35kw/h");
    lv_label_set_long_mode(ui->Electricity_label_2_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_2_value, 45, 16);
    lv_obj_set_size(ui->Electricity_label_2_value, 54, 12);

    //Write style for Electricity_label_2_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_2_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_2_value, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_2_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_2_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_2_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_2_NO
    ui->Electricity_label_2_NO = lv_label_create(ui->Electricity_cont_2);
    lv_label_set_text(ui->Electricity_label_2_NO, "#02");
    lv_label_set_long_mode(ui->Electricity_label_2_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_2_NO, 7, 14);
    lv_obj_set_size(ui->Electricity_label_2_NO, 30, 14);

    //Write style for Electricity_label_2_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_2_NO, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_2_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_2_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_2_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_3
    ui->Electricity_cont_3 = lv_obj_create(ui->Electricity);
    lv_obj_set_pos(ui->Electricity_cont_3, 18, 340);
    lv_obj_set_size(ui->Electricity_cont_3, 120, 42);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_cont_3, &_pos_120x42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_3_value
    ui->Electricity_label_3_value = lv_label_create(ui->Electricity_cont_3);
    lv_label_set_text(ui->Electricity_label_3_value, "35kw/h");
    lv_label_set_long_mode(ui->Electricity_label_3_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_3_value, 45, 16);
    lv_obj_set_size(ui->Electricity_label_3_value, 52, 13);

    //Write style for Electricity_label_3_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_3_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_3_value, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_3_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_3_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_3_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_3_NO
    ui->Electricity_label_3_NO = lv_label_create(ui->Electricity_cont_3);
    lv_label_set_text(ui->Electricity_label_3_NO, "#03");
    lv_label_set_long_mode(ui->Electricity_label_3_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_3_NO, 5, 15);
    lv_obj_set_size(ui->Electricity_label_3_NO, 32, 18);

    //Write style for Electricity_label_3_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_3_NO, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_3_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_3_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_3_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_4
    ui->Electricity_cont_4 = lv_obj_create(ui->Electricity);
    lv_obj_set_pos(ui->Electricity_cont_4, 210, -146);
    lv_obj_set_size(ui->Electricity_cont_4, 120, 42);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_cont_4, &_pos_120x42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_4_value
    ui->Electricity_label_4_value = lv_label_create(ui->Electricity_cont_4);
    lv_label_set_text(ui->Electricity_label_4_value, "35kw/h");
    lv_label_set_long_mode(ui->Electricity_label_4_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_4_value, 44, 16);
    lv_obj_set_size(ui->Electricity_label_4_value, 55, 12);

    //Write style for Electricity_label_4_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_4_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_4_value, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_4_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_4_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_4_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_4_NO
    ui->Electricity_label_4_NO = lv_label_create(ui->Electricity_cont_4);
    lv_label_set_text(ui->Electricity_label_4_NO, "#04");
    lv_label_set_long_mode(ui->Electricity_label_4_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_4_NO, 6, 14);
    lv_obj_set_size(ui->Electricity_label_4_NO, 30, 16);

    //Write style for Electricity_label_4_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_4_NO, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_4_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_4_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_4_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_4_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_5
    ui->Electricity_cont_5 = lv_obj_create(ui->Electricity);
    lv_obj_set_pos(ui->Electricity_cont_5, 336, 353);
    lv_obj_set_size(ui->Electricity_cont_5, 120, 42);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_cont_5, &_pos_120x42, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_5_value
    ui->Electricity_label_5_value = lv_label_create(ui->Electricity_cont_5);
    lv_label_set_text(ui->Electricity_label_5_value, "35kw/h");
    lv_label_set_long_mode(ui->Electricity_label_5_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_5_value, 48, 16);
    lv_obj_set_size(ui->Electricity_label_5_value, 48, 13);

    //Write style for Electricity_label_5_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_5_value, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_5_value, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_5_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_5_value, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_5_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_5_NO
    ui->Electricity_label_5_NO = lv_label_create(ui->Electricity_cont_5);
    lv_label_set_text(ui->Electricity_label_5_NO, "#05");
    lv_label_set_long_mode(ui->Electricity_label_5_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_5_NO, 10, 15);
    lv_obj_set_size(ui->Electricity_label_5_NO, 24, 19);

    //Write style for Electricity_label_5_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_5_NO, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_5_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_5_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_5_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_5_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_digital_clock_time
    static bool Electricity_digital_clock_time_timer_enabled = false;
    ui->Electricity_digital_clock_time = lv_dclock_create(ui->Electricity, "11:25:50");
    if (!Electricity_digital_clock_time_timer_enabled) {
        lv_timer_create(Electricity_digital_clock_time_timer, 1000, NULL);
        Electricity_digital_clock_time_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Electricity_digital_clock_time, 414, 6);
    lv_obj_set_size(ui->Electricity_digital_clock_time, 58, 20);

    //Write style for Electricity_digital_clock_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_digital_clock_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_digital_clock_time, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_digital_clock_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_digital_clock_time, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_digital_clock_time, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_datetext_date
    ui->Electricity_datetext_date = lv_label_create(ui->Electricity);
    lv_label_set_text(ui->Electricity_datetext_date, "2023/07/31");
    lv_obj_set_style_text_align(ui->Electricity_datetext_date, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->Electricity_datetext_date, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->Electricity_datetext_date, Electricity_datetext_date_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->Electricity_datetext_date, 376, 6);
    lv_obj_set_size(ui->Electricity_datetext_date, 58, 24);

    //Write style for Electricity_datetext_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Electricity_datetext_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_datetext_date, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_datetext_date, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_datetext_date, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_datetext_date, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_datetext_date, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_img_logo
    ui->Electricity_img_logo = lv_img_create(ui->Electricity);
    lv_obj_add_flag(ui->Electricity_img_logo, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Electricity_img_logo, &_white_logo_alpha_36x13);
    lv_img_set_pivot(ui->Electricity_img_logo, 50,50);
    lv_img_set_angle(ui->Electricity_img_logo, 0);
    lv_obj_set_pos(ui->Electricity_img_logo, 21, 8);
    lv_obj_set_size(ui->Electricity_img_logo, 36, 13);

    //Write style for Electricity_img_logo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Electricity_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Electricity_img_logo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_img_logo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Electricity_img_logo, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_info_box
    ui->Electricity_cont_info_box = lv_obj_create(ui->Electricity);
    lv_obj_set_pos(ui->Electricity_cont_info_box, 0, 0);
    lv_obj_set_size(ui->Electricity_cont_info_box, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_info_box, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->Electricity_cont_info_box, LV_OBJ_FLAG_HIDDEN);

    //Write style for Electricity_cont_info_box, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_info_box, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_cont_info_box, lv_color_hex(0x020101), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_cont_info_box, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_info_box, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_info
    ui->Electricity_cont_info = lv_obj_create(ui->Electricity_cont_info_box);
    lv_obj_set_pos(ui->Electricity_cont_info, 98, 57);
    lv_obj_set_size(ui->Electricity_cont_info, 288, 213);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_info, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_info, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_cont_info, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_cont_info, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Electricity_cont_info, &_rect_bak_288x213, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Electricity_cont_info, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_info, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_23
    ui->Electricity_label_23 = lv_label_create(ui->Electricity_cont_info);
    lv_label_set_text(ui->Electricity_label_23, "" LV_SYMBOL_RIGHT "  Proportion of electrical equipment");
    lv_label_set_long_mode(ui->Electricity_label_23, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_23, 9, 16);
    lv_obj_set_size(ui->Electricity_label_23, 264, 14);

    //Write style for Electricity_label_23, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_23, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_23, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_23, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_conditioner
    ui->Electricity_cont_conditioner = lv_obj_create(ui->Electricity_cont_info);
    lv_obj_set_pos(ui->Electricity_cont_conditioner, 21, 34);
    lv_obj_set_size(ui->Electricity_cont_conditioner, 78, 157);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_conditioner, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_conditioner, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_conditioner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_conditioner, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_conditioner, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_cont_conditioner, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_cont_conditioner, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_conditioner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_conditioner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_conditioner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_conditioner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_conditioner, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_title
    ui->Electricity_label_cond_title = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_title, "Conditioner");
    lv_label_set_long_mode(ui->Electricity_label_cond_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_title, 0, 0);
    lv_obj_set_size(ui->Electricity_label_cond_title, 78, 26);

    //Write style for Electricity_label_cond_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_title, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_label_cond_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_label_cond_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_arc_cond
    ui->Electricity_arc_cond = lv_arc_create(ui->Electricity_cont_conditioner);
    lv_arc_set_mode(ui->Electricity_arc_cond, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Electricity_arc_cond, 0, 40);
    lv_arc_set_bg_angles(ui->Electricity_arc_cond, 40, 320);
    lv_arc_set_value(ui->Electricity_arc_cond, 20);
    lv_arc_set_rotation(ui->Electricity_arc_cond, 90);
    lv_obj_set_pos(ui->Electricity_arc_cond, 7, 32);
    lv_obj_set_size(ui->Electricity_arc_cond, 60, 60);

    //Write style for Electricity_arc_cond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_arc_cond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Electricity_arc_cond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Electricity_arc_cond, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Electricity_arc_cond, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Electricity_arc_cond, lv_color_hex(0xe7e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_arc_cond, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_arc_cond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_arc_cond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_arc_cond, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_arc_cond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_arc_cond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Electricity_arc_cond, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Electricity_arc_cond, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Electricity_arc_cond, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Electricity_arc_cond, lv_color_hex(0x0eff85), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Electricity_arc_cond, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_arc_cond, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_arc_cond, lv_color_hex(0x0eff85), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_arc_cond, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Electricity_arc_cond, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_NO
    ui->Electricity_label_cond_NO = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_NO, "10F");
    lv_label_set_long_mode(ui->Electricity_label_cond_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_NO, 29, 54);
    lv_obj_set_size(ui->Electricity_label_cond_NO, 24, 15);

    //Write style for Electricity_label_cond_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_NO, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_num
    ui->Electricity_label_cond_num = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_num, "28");
    lv_label_set_long_mode(ui->Electricity_label_cond_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_num, 22, 74);
    lv_obj_set_size(ui->Electricity_label_cond_num, 22, 14);

    //Write style for Electricity_label_cond_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_num, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_img_cond
    ui->Electricity_img_cond = lv_img_create(ui->Electricity_cont_conditioner);
    lv_obj_add_flag(ui->Electricity_img_cond, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Electricity_img_cond, &_temp_alpha_25x25);
    lv_img_set_pivot(ui->Electricity_img_cond, 50,50);
    lv_img_set_angle(ui->Electricity_img_cond, 0);
    lv_obj_set_pos(ui->Electricity_img_cond, 12, 46);
    lv_obj_set_size(ui->Electricity_img_cond, 25, 25);

    //Write style for Electricity_img_cond, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Electricity_img_cond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Electricity_img_cond, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_img_cond, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Electricity_img_cond, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_unit
    ui->Electricity_label_cond_unit = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_unit, "℃");
    lv_label_set_long_mode(ui->Electricity_label_cond_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_unit, 35, 73);
    lv_obj_set_size(ui->Electricity_label_cond_unit, 15, 12);

    //Write style for Electricity_label_cond_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_unit, lv_color_hex(0xdbff54), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_unit, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_proportion
    ui->Electricity_label_cond_proportion = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_proportion, "Proportion");
    lv_label_set_long_mode(ui->Electricity_label_cond_proportion, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_proportion, 3, 115);
    lv_obj_set_size(ui->Electricity_label_cond_proportion, 46, 10);

    //Write style for Electricity_label_cond_proportion, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_proportion, lv_color_hex(0x7ffeff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_proportion, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_proportion, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_proportion, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_pro_num
    ui->Electricity_label_cond_pro_num = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_pro_num, "35%");
    lv_label_set_long_mode(ui->Electricity_label_cond_pro_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_pro_num, 46, 114);
    lv_obj_set_size(ui->Electricity_label_cond_pro_num, 26, 12);

    //Write style for Electricity_label_cond_pro_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_pro_num, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_pro_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_pro_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_pro_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_power
    ui->Electricity_label_cond_power = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_power, "Power");
    lv_label_set_long_mode(ui->Electricity_label_cond_power, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_power, 9, 136);
    lv_obj_set_size(ui->Electricity_label_cond_power, 29, 10);

    //Write style for Electricity_label_cond_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_power, lv_color_hex(0x7cff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_power, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_cond_power_num
    ui->Electricity_label_cond_power_num = lv_label_create(ui->Electricity_cont_conditioner);
    lv_label_set_text(ui->Electricity_label_cond_power_num, "30kw/h");
    lv_label_set_long_mode(ui->Electricity_label_cond_power_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_cond_power_num, 37, 136);
    lv_obj_set_size(ui->Electricity_label_cond_power_num, 42, 12);

    //Write style for Electricity_label_cond_power_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_cond_power_num, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_cond_power_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_cond_power_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_cond_power_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_cond_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_light
    ui->Electricity_cont_light = lv_obj_create(ui->Electricity_cont_info);
    lv_obj_set_pos(ui->Electricity_cont_light, 105, 34);
    lv_obj_set_size(ui->Electricity_cont_light, 78, 157);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_light, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_light, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_light, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_cont_light, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_cont_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_title
    ui->Electricity_label_light_title = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_title, "Light");
    lv_label_set_long_mode(ui->Electricity_label_light_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_title, 0, 0);
    lv_obj_set_size(ui->Electricity_label_light_title, 78, 26);

    //Write style for Electricity_label_light_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_title, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_label_light_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_label_light_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_arc_light
    ui->Electricity_arc_light = lv_arc_create(ui->Electricity_cont_light);
    lv_arc_set_mode(ui->Electricity_arc_light, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Electricity_arc_light, 0, 40);
    lv_arc_set_bg_angles(ui->Electricity_arc_light, 40, 320);
    lv_arc_set_value(ui->Electricity_arc_light, 20);
    lv_arc_set_rotation(ui->Electricity_arc_light, 90);
    lv_obj_set_pos(ui->Electricity_arc_light, 7, 32);
    lv_obj_set_size(ui->Electricity_arc_light, 60, 60);

    //Write style for Electricity_arc_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_arc_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Electricity_arc_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Electricity_arc_light, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Electricity_arc_light, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Electricity_arc_light, lv_color_hex(0xe7e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_arc_light, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_arc_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_arc_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_arc_light, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_arc_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_arc_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Electricity_arc_light, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Electricity_arc_light, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Electricity_arc_light, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Electricity_arc_light, lv_color_hex(0xaad800), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Electricity_arc_light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_arc_light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_arc_light, lv_color_hex(0xaad800), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_arc_light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Electricity_arc_light, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_NO
    ui->Electricity_label_light_NO = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_NO, "10F");
    lv_label_set_long_mode(ui->Electricity_label_light_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_NO, 29, 54);
    lv_obj_set_size(ui->Electricity_label_light_NO, 24, 15);

    //Write style for Electricity_label_light_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_NO, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_num
    ui->Electricity_label_light_num = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_num, "28");
    lv_label_set_long_mode(ui->Electricity_label_light_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_num, 22, 74);
    lv_obj_set_size(ui->Electricity_label_light_num, 22, 14);

    //Write style for Electricity_label_light_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_num, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_img_light
    ui->Electricity_img_light = lv_img_create(ui->Electricity_cont_light);
    lv_obj_add_flag(ui->Electricity_img_light, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Electricity_img_light, &_temp_alpha_25x25);
    lv_img_set_pivot(ui->Electricity_img_light, 50,50);
    lv_img_set_angle(ui->Electricity_img_light, 0);
    lv_obj_set_pos(ui->Electricity_img_light, 12, 46);
    lv_obj_set_size(ui->Electricity_img_light, 25, 25);

    //Write style for Electricity_img_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Electricity_img_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Electricity_img_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_img_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Electricity_img_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_unit
    ui->Electricity_label_light_unit = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_unit, "℃");
    lv_label_set_long_mode(ui->Electricity_label_light_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_unit, 35, 73);
    lv_obj_set_size(ui->Electricity_label_light_unit, 15, 12);

    //Write style for Electricity_label_light_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_unit, lv_color_hex(0xdbff54), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_unit, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_proportion
    ui->Electricity_label_light_proportion = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_proportion, "Proportion");
    lv_label_set_long_mode(ui->Electricity_label_light_proportion, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_proportion, 3, 115);
    lv_obj_set_size(ui->Electricity_label_light_proportion, 46, 10);

    //Write style for Electricity_label_light_proportion, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_proportion, lv_color_hex(0x7ffeff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_proportion, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_proportion, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_proportion, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_pro_num
    ui->Electricity_label_light_pro_num = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_pro_num, "50%");
    lv_label_set_long_mode(ui->Electricity_label_light_pro_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_pro_num, 46, 114);
    lv_obj_set_size(ui->Electricity_label_light_pro_num, 26, 12);

    //Write style for Electricity_label_light_pro_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_pro_num, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_pro_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_pro_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_pro_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_power
    ui->Electricity_label_light_power = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_power, "Power");
    lv_label_set_long_mode(ui->Electricity_label_light_power, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_power, 9, 136);
    lv_obj_set_size(ui->Electricity_label_light_power, 29, 10);

    //Write style for Electricity_label_light_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_power, lv_color_hex(0x7cff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_power, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_light_power_num
    ui->Electricity_label_light_power_num = lv_label_create(ui->Electricity_cont_light);
    lv_label_set_text(ui->Electricity_label_light_power_num, "40kw/h");
    lv_label_set_long_mode(ui->Electricity_label_light_power_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_light_power_num, 37, 136);
    lv_obj_set_size(ui->Electricity_label_light_power_num, 42, 12);

    //Write style for Electricity_label_light_power_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_light_power_num, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_light_power_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_light_power_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_light_power_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_light_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_cont_elevator
    ui->Electricity_cont_elevator = lv_obj_create(ui->Electricity_cont_info);
    lv_obj_set_pos(ui->Electricity_cont_elevator, 189, 34);
    lv_obj_set_size(ui->Electricity_cont_elevator, 78, 157);
    lv_obj_set_scrollbar_mode(ui->Electricity_cont_elevator, LV_SCROLLBAR_MODE_OFF);

    //Write style for Electricity_cont_elevator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_cont_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_cont_elevator, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_cont_elevator, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_cont_elevator, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_cont_elevator, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_cont_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_cont_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_cont_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_cont_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_cont_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_title
    ui->Electricity_label_elevator_title = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_title, "Elevator");
    lv_label_set_long_mode(ui->Electricity_label_elevator_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_title, 0, 0);
    lv_obj_set_size(ui->Electricity_label_elevator_title, 78, 26);

    //Write style for Electricity_label_elevator_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_title, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_label_elevator_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_label_elevator_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_arc_elevator
    ui->Electricity_arc_elevator = lv_arc_create(ui->Electricity_cont_elevator);
    lv_arc_set_mode(ui->Electricity_arc_elevator, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Electricity_arc_elevator, 0, 40);
    lv_arc_set_bg_angles(ui->Electricity_arc_elevator, 40, 320);
    lv_arc_set_value(ui->Electricity_arc_elevator, 20);
    lv_arc_set_rotation(ui->Electricity_arc_elevator, 90);
    lv_obj_set_pos(ui->Electricity_arc_elevator, 7, 32);
    lv_obj_set_size(ui->Electricity_arc_elevator, 60, 60);

    //Write style for Electricity_arc_elevator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_arc_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Electricity_arc_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Electricity_arc_elevator, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Electricity_arc_elevator, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Electricity_arc_elevator, lv_color_hex(0xe7e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_arc_elevator, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_arc_elevator, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_arc_elevator, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_arc_elevator, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_arc_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_arc_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Electricity_arc_elevator, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Electricity_arc_elevator, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Electricity_arc_elevator, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Electricity_arc_elevator, lv_color_hex(0xff00fe), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Electricity_arc_elevator, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Electricity_arc_elevator, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Electricity_arc_elevator, lv_color_hex(0xff00fe), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Electricity_arc_elevator, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Electricity_arc_elevator, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_NO
    ui->Electricity_label_elevator_NO = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_NO, "10F");
    lv_label_set_long_mode(ui->Electricity_label_elevator_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_NO, 29, 54);
    lv_obj_set_size(ui->Electricity_label_elevator_NO, 24, 15);

    //Write style for Electricity_label_elevator_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_NO, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_NO, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_num
    ui->Electricity_label_elevator_num = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_num, "28");
    lv_label_set_long_mode(ui->Electricity_label_elevator_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_num, 22, 74);
    lv_obj_set_size(ui->Electricity_label_elevator_num, 22, 14);

    //Write style for Electricity_label_elevator_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_num, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_img_elevator
    ui->Electricity_img_elevator = lv_img_create(ui->Electricity_cont_elevator);
    lv_obj_add_flag(ui->Electricity_img_elevator, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Electricity_img_elevator, &_temp_alpha_25x25);
    lv_img_set_pivot(ui->Electricity_img_elevator, 50,50);
    lv_img_set_angle(ui->Electricity_img_elevator, 0);
    lv_obj_set_pos(ui->Electricity_img_elevator, 12, 46);
    lv_obj_set_size(ui->Electricity_img_elevator, 25, 25);

    //Write style for Electricity_img_elevator, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Electricity_img_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Electricity_img_elevator, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_img_elevator, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Electricity_img_elevator, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_unit
    ui->Electricity_label_elevator_unit = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_unit, "℃");
    lv_label_set_long_mode(ui->Electricity_label_elevator_unit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_unit, 35, 73);
    lv_obj_set_size(ui->Electricity_label_elevator_unit, 15, 12);

    //Write style for Electricity_label_elevator_unit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_unit, lv_color_hex(0xdbff54), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_unit, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_unit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_unit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_unit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_proportion
    ui->Electricity_label_elevator_proportion = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_proportion, "Proportion");
    lv_label_set_long_mode(ui->Electricity_label_elevator_proportion, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_proportion, 3, 115);
    lv_obj_set_size(ui->Electricity_label_elevator_proportion, 46, 10);

    //Write style for Electricity_label_elevator_proportion, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_proportion, lv_color_hex(0x7ffeff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_proportion, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_proportion, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_proportion, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_proportion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_pro_num
    ui->Electricity_label_elevator_pro_num = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_pro_num, "15%");
    lv_label_set_long_mode(ui->Electricity_label_elevator_pro_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_pro_num, 46, 114);
    lv_obj_set_size(ui->Electricity_label_elevator_pro_num, 26, 12);

    //Write style for Electricity_label_elevator_pro_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_pro_num, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_pro_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_pro_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_pro_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_pro_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_power
    ui->Electricity_label_elevator_power = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_power, "Power");
    lv_label_set_long_mode(ui->Electricity_label_elevator_power, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_power, 9, 136);
    lv_obj_set_size(ui->Electricity_label_elevator_power, 29, 10);

    //Write style for Electricity_label_elevator_power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_power, lv_color_hex(0x7cff00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_power, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Electricity_label_elevator_power_num
    ui->Electricity_label_elevator_power_num = lv_label_create(ui->Electricity_cont_elevator);
    lv_label_set_text(ui->Electricity_label_elevator_power_num, "10kw/h");
    lv_label_set_long_mode(ui->Electricity_label_elevator_power_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Electricity_label_elevator_power_num, 37, 136);
    lv_obj_set_size(ui->Electricity_label_elevator_power_num, 42, 12);

    //Write style for Electricity_label_elevator_power_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Electricity_label_elevator_power_num, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Electricity_label_elevator_power_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Electricity_label_elevator_power_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Electricity_label_elevator_power_num, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Electricity_label_elevator_power_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Electricity.


    //Update current screen layout.
    lv_obj_update_layout(ui->Electricity);

    //Init events for screen.
    events_init_Electricity(ui);
}
