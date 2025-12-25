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



void setup_scr_OTA(lv_ui *ui)
{
    //Write codes OTA
    ui->OTA = lv_obj_create(NULL);
    lv_obj_set_size(ui->OTA, 480, 320);
    lv_obj_set_scrollbar_mode(ui->OTA, LV_SCROLLBAR_MODE_OFF);

    //Write style for OTA, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->OTA, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->OTA, lv_color_hex(0x232429), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->OTA, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes OTA_bar_1
    ui->OTA_bar_1 = lv_bar_create(ui->OTA);
    lv_obj_set_style_anim_time(ui->OTA_bar_1, 1000, 0);
    lv_bar_set_mode(ui->OTA_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->OTA_bar_1, 0, 100);
    lv_bar_set_value(ui->OTA_bar_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->OTA_bar_1, 45, 158);
    lv_obj_set_size(ui->OTA_bar_1, 390, 33);

    //Write style for OTA_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->OTA_bar_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->OTA_bar_1, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->OTA_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->OTA_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->OTA_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for OTA_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->OTA_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->OTA_bar_1, lv_color_hex(0x3cf626), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->OTA_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->OTA_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes OTA_label_1
    ui->OTA_label_1 = lv_label_create(ui->OTA);
    lv_label_set_text(ui->OTA_label_1, "OTA ...");
    lv_label_set_long_mode(ui->OTA_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->OTA_label_1, 169, 100);
    lv_obj_set_size(ui->OTA_label_1, 141, 54);

    //Write style for OTA_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->OTA_label_1, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->OTA_label_1, &lv_font_montserratMedium_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->OTA_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->OTA_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->OTA_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes OTA_label_2
    ui->OTA_label_2 = lv_label_create(ui->OTA);
    lv_label_set_text(ui->OTA_label_2, "Don't Turn Off the Power During Process");
    lv_label_set_long_mode(ui->OTA_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->OTA_label_2, 30, 210);
    lv_obj_set_size(ui->OTA_label_2, 419, 34);

    //Write style for OTA_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->OTA_label_2, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->OTA_label_2, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->OTA_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->OTA_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->OTA_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of OTA.


    //Update current screen layout.
    lv_obj_update_layout(ui->OTA);

}
