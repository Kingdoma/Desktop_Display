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

    //Write codes Home_cont_dev_control
    ui->Home_cont_dev_control = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_dev_control, 187, 52);
    lv_obj_set_size(ui->Home_cont_dev_control, 272, 249);
    lv_obj_set_scrollbar_mode(ui->Home_cont_dev_control, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_dev_control, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_dev_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_dev_control, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_dev_control, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_dev_control, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_dev_control, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_dev_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_dev_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_dev_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_dev_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_dev_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_dev
    ui->Home_label_dev = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_dev, "Device Control");
    lv_label_set_long_mode(ui->Home_label_dev, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_dev, 0, 0);
    lv_obj_set_size(ui->Home_label_dev, 272, 26);

    //Write style for Home_label_dev, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_dev, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_dev, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_dev, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_dev, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_dev, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_dev, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_label_dev, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_label_dev, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_dev, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_dev, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_air_control
    ui->Home_label_air_control = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_air_control, "Air Condition");
    lv_label_set_long_mode(ui->Home_label_air_control, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_air_control, 13, 36);
    lv_obj_set_size(ui->Home_label_air_control, 73, 13);

    //Write style for Home_label_air_control, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_air_control, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_air_control, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_air_control, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_air_control, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_air_control, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_air_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_light_control
    ui->Home_label_light_control = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_light_control, "Light Control");
    lv_label_set_long_mode(ui->Home_label_light_control, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_light_control, 12, 161);
    lv_obj_set_size(ui->Home_label_light_control, 71, 11);

    //Write style for Home_label_light_control, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_light_control, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_light_control, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_light_control, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_light_control, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_light_control, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_light_control, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_air
    ui->Home_img_air = lv_img_create(ui->Home_cont_dev_control);
    lv_obj_add_flag(ui->Home_img_air, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_air, &_air_alpha_80x38);
    lv_img_set_pivot(ui->Home_img_air, 50,50);
    lv_img_set_angle(ui->Home_img_air, 0);
    lv_obj_set_pos(ui->Home_img_air, 18, 65);
    lv_obj_set_size(ui->Home_img_air, 80, 38);

    //Write style for Home_img_air, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_air, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Home_img_air, lv_color_hex(0xb1b1b1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_air, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_air, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_fan
    ui->Home_img_fan = lv_img_create(ui->Home_cont_dev_control);
    lv_obj_add_flag(ui->Home_img_fan, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_fan, &_air_fan_alpha_21x25);
    lv_img_set_pivot(ui->Home_img_fan, 50,50);
    lv_img_set_angle(ui->Home_img_fan, 0);
    lv_obj_set_pos(ui->Home_img_fan, 69, 108);
    lv_obj_set_size(ui->Home_img_fan, 21, 25);

    //Write style for Home_img_fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_fan, 245, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Home_img_fan, lv_color_hex(0xc1c1c1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_fan, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_electricity_usage
    ui->Home_label_electricity_usage = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_electricity_usage, "Electricity Usage        Top 3");
    lv_label_set_long_mode(ui->Home_label_electricity_usage, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_electricity_usage, 127, 34);
    lv_obj_set_size(ui->Home_label_electricity_usage, 127, 12);

    //Write style for Home_label_electricity_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_electricity_usage, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_electricity_usage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_electricity_usage, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_electricity_usage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_electricity_usage, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_electricity_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_1F
    ui->Home_label_1F = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_1F, "#001");
    lv_label_set_long_mode(ui->Home_label_1F, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_1F, 126, 62);
    lv_obj_set_size(ui->Home_label_1F, 28, 8);

    //Write style for Home_label_1F, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_1F, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_1F, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_1F, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_1F, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_1F, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_1F_usage
    ui->Home_label_1F_usage = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_1F_usage, "244kw/h");
    lv_label_set_long_mode(ui->Home_label_1F_usage, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_1F_usage, 234, 62);
    lv_obj_set_size(ui->Home_label_1F_usage, 37, 9);

    //Write style for Home_label_1F_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_1F_usage, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_1F_usage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_1F_usage, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_1F_usage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_1F_usage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_1F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_bar_1F
    ui->Home_bar_1F = lv_bar_create(ui->Home_cont_dev_control);
    lv_obj_set_style_anim_time(ui->Home_bar_1F, 1000, 0);
    lv_bar_set_mode(ui->Home_bar_1F, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Home_bar_1F, 0, 40);
    lv_bar_set_value(ui->Home_bar_1F, 40, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_bar_1F, 127, 75);
    lv_obj_set_size(ui->Home_bar_1F, 144, 2);

    //Write style for Home_bar_1F, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_1F, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_1F, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_1F, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_1F, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_bar_1F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_bar_1F, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_1F, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_1F, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_1F, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_1F, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Home_bar_2F
    ui->Home_bar_2F = lv_bar_create(ui->Home_cont_dev_control);
    lv_obj_set_style_anim_time(ui->Home_bar_2F, 1000, 0);
    lv_bar_set_mode(ui->Home_bar_2F, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Home_bar_2F, 0, 40);
    lv_bar_set_value(ui->Home_bar_2F, 40, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_bar_2F, 127, 102);
    lv_obj_set_size(ui->Home_bar_2F, 144, 2);

    //Write style for Home_bar_2F, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_2F, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_2F, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_2F, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_2F, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_bar_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_bar_2F, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_2F, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_2F, lv_color_hex(0x00ff2b), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_2F, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_2F, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Home_label_2F
    ui->Home_label_2F = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_2F, "#002");
    lv_label_set_long_mode(ui->Home_label_2F, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_2F, 126, 90);
    lv_obj_set_size(ui->Home_label_2F, 31, 8);

    //Write style for Home_label_2F, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_2F, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_2F, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_2F, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_2F, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_2F, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_2F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_2F_usage
    ui->Home_label_2F_usage = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_2F_usage, "244kw/h");
    lv_label_set_long_mode(ui->Home_label_2F_usage, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_2F_usage, 234, 88);
    lv_obj_set_size(ui->Home_label_2F_usage, 37, 9);

    //Write style for Home_label_2F_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_2F_usage, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_2F_usage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_2F_usage, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_2F_usage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_2F_usage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_2F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_bar_3F
    ui->Home_bar_3F = lv_bar_create(ui->Home_cont_dev_control);
    lv_obj_set_style_anim_time(ui->Home_bar_3F, 1000, 0);
    lv_bar_set_mode(ui->Home_bar_3F, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Home_bar_3F, 0, 40);
    lv_bar_set_value(ui->Home_bar_3F, 40, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Home_bar_3F, 127, 129);
    lv_obj_set_size(ui->Home_bar_3F, 144, 2);

    //Write style for Home_bar_3F, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_3F, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_3F, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_3F, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_3F, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_bar_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_bar_3F, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_bar_3F, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_bar_3F, lv_color_hex(0xffcd00), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_bar_3F, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_bar_3F, 6, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Home_label_3F
    ui->Home_label_3F = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_3F, "#003");
    lv_label_set_long_mode(ui->Home_label_3F, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_3F, 126, 116);
    lv_obj_set_size(ui->Home_label_3F, 30, 8);

    //Write style for Home_label_3F, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_3F, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_3F, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_3F, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_3F, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_3F, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_3F, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_3F_usage
    ui->Home_label_3F_usage = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_3F_usage, "244kw/h");
    lv_label_set_long_mode(ui->Home_label_3F_usage, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_3F_usage, 234, 114);
    lv_obj_set_size(ui->Home_label_3F_usage, 37, 9);

    //Write style for Home_label_3F_usage, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_3F_usage, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_3F_usage, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_3F_usage, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_3F_usage, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_3F_usage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_3F_usage, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_light
    ui->Home_img_light = lv_img_create(ui->Home_cont_dev_control);
    lv_obj_add_flag(ui->Home_img_light, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_light, &_menu_light_alpha_42x46);
    lv_img_set_pivot(ui->Home_img_light, 50,50);
    lv_img_set_angle(ui->Home_img_light, 0);
    lv_obj_set_pos(ui->Home_img_light, 7, 187);
    lv_obj_set_size(ui->Home_img_light, 42, 46);

    //Write style for Home_img_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_light, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Home_img_light, lv_color_hex(0xf1f1f1), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_light, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_light
    ui->Home_label_light = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_light, "38");
    lv_label_set_long_mode(ui->Home_label_light, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_light, 46, 205);
    lv_obj_set_size(ui->Home_label_light, 37, 20);

    //Write style for Home_label_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_light, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_light, lv_color_hex(0x90918f), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_light, &lv_font_Alatsi_Regular_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_light, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_light, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_17
    ui->Home_label_17 = lv_label_create(ui->Home_cont_dev_control);
    lv_label_set_text(ui->Home_label_17, "kw / h");
    lv_label_set_long_mode(ui->Home_label_17, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_17, 79, 214);
    lv_obj_set_size(ui->Home_label_17, 22, 12);

    //Write style for Home_label_17, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_17, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_17, lv_color_hex(0x969696), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_17, &lv_font_Alatsi_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_17, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_sw_air
    ui->Home_sw_air = lv_switch_create(ui->Home_cont_dev_control);
    lv_obj_set_pos(ui->Home_sw_air, 93, 34);
    lv_obj_set_size(ui->Home_sw_air, 16, 10);

    //Write style for Home_sw_air, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_air, 83, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_air, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_air, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_air, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_sw_air, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_sw_air, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Home_sw_air, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Home_sw_air, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_air, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Home_sw_air, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Home_sw_air, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_air, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_air, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_air, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_air, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_air, 6, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_img_snow
    ui->Home_img_snow = lv_img_create(ui->Home_cont_dev_control);
    lv_obj_add_flag(ui->Home_img_snow, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_snow, &_air_snow_alpha_12x12);
    lv_img_set_pivot(ui->Home_img_snow, 10,10);
    lv_img_set_angle(ui->Home_img_snow, 0);
    lv_obj_set_pos(ui->Home_img_snow, 24, 116);
    lv_obj_set_size(ui->Home_img_snow, 12, 12);

    //Write style for Home_img_snow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_snow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Home_img_snow, lv_color_hex(0xb3b3b3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_snow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_snow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_snow, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_snow_1
    ui->Home_img_snow_1 = lv_img_create(ui->Home_cont_dev_control);
    lv_obj_add_flag(ui->Home_img_snow_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_snow_1, &_air_snow_alpha_9x9);
    lv_img_set_pivot(ui->Home_img_snow_1, 8,8);
    lv_img_set_angle(ui->Home_img_snow_1, 0);
    lv_obj_set_pos(ui->Home_img_snow_1, 38, 108);
    lv_obj_set_size(ui->Home_img_snow_1, 9, 9);

    //Write style for Home_img_snow_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_snow_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Home_img_snow_1, lv_color_hex(0xb3b3b3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_snow_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_snow_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_snow_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_snow_2
    ui->Home_img_snow_2 = lv_img_create(ui->Home_cont_dev_control);
    lv_obj_add_flag(ui->Home_img_snow_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_snow_2, &_air_snow_alpha_7x7);
    lv_img_set_pivot(ui->Home_img_snow_2, 6,6);
    lv_img_set_angle(ui->Home_img_snow_2, 0);
    lv_obj_set_pos(ui->Home_img_snow_2, 51, 118);
    lv_obj_set_size(ui->Home_img_snow_2, 7, 7);

    //Write style for Home_img_snow_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_snow_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Home_img_snow_2, lv_color_hex(0xb3b3b3), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_snow_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_snow_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_snow_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_sw_light
    ui->Home_sw_light = lv_switch_create(ui->Home_cont_dev_control);
    lv_obj_set_pos(ui->Home_sw_light, 90, 161);
    lv_obj_set_size(ui->Home_sw_light, 16, 10);

    //Write style for Home_sw_light, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_light, 83, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_light, lv_color_hex(0xe6e2e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_light, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_light, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_sw_light, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_sw_light, Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->Home_sw_light, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->Home_sw_light, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_light, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->Home_sw_light, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);

    //Write style for Home_sw_light, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_sw_light, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_sw_light, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_sw_light, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_sw_light, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_sw_light, 6, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_cont_total_normal
    ui->Home_cont_total_normal = lv_obj_create(ui->Home_cont_dev_control);
    lv_obj_set_pos(ui->Home_cont_total_normal, 128, 160);
    lv_obj_set_size(ui->Home_cont_total_normal, 135, 70);
    lv_obj_set_scrollbar_mode(ui->Home_cont_total_normal, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_total_normal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_total_normal, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Home_cont_total_normal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Home_cont_total_normal, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Home_cont_total_normal, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_total_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_total_normal, 64, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_total_normal, lv_color_hex(0x065c9b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_total_normal, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_total_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_total_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_total_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_total_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_total_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_line_1
    ui->Home_line_1 = lv_line_create(ui->Home_cont_total_normal);
    static lv_point_t Home_line_1[] = {{0, 0},{0, 53},};
    lv_line_set_points(ui->Home_line_1, Home_line_1, 2);
    lv_obj_set_pos(ui->Home_line_1, 64, 10);
    lv_obj_set_size(ui->Home_line_1, 6, 52);

    //Write style for Home_line_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->Home_line_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->Home_line_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->Home_line_1, 173, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->Home_line_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_total
    ui->Home_label_total = lv_label_create(ui->Home_cont_total_normal);
    lv_label_set_text(ui->Home_label_total, "Total");
    lv_label_set_long_mode(ui->Home_label_total, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_total, 5, 8);
    lv_obj_set_size(ui->Home_label_total, 57, 12);

    //Write style for Home_label_total, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_total, lv_color_hex(0xe6f7ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_total, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_total, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_total, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_total, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_normal
    ui->Home_label_normal = lv_label_create(ui->Home_cont_total_normal);
    lv_label_set_text(ui->Home_label_normal, "Normal");
    lv_label_set_long_mode(ui->Home_label_normal, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_normal, 74, 8);
    lv_obj_set_size(ui->Home_label_normal, 57, 12);

    //Write style for Home_label_normal, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_normal, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_normal, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_normal, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_normal, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_normal, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_total_value
    ui->Home_label_total_value = lv_label_create(ui->Home_cont_total_normal);
    lv_label_set_text(ui->Home_label_total_value, "20");
    lv_label_set_long_mode(ui->Home_label_total_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_total_value, 9, 32);
    lv_obj_set_size(ui->Home_label_total_value, 36, 27);

    //Write style for Home_label_total_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_total_value, lv_color_hex(0x00bdff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_total_value, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_total_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_total_value, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_total_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_normal_value
    ui->Home_label_normal_value = lv_label_create(ui->Home_cont_total_normal);
    lv_label_set_text(ui->Home_label_normal_value, "20");
    lv_label_set_long_mode(ui->Home_label_normal_value, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_normal_value, 79, 30);
    lv_obj_set_size(ui->Home_label_normal_value, 38, 27);

    //Write style for Home_label_normal_value, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_normal_value, lv_color_hex(0x00ff6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_normal_value, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_normal_value, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_normal_value, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_normal_value, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_total_num
    ui->Home_label_total_num = lv_label_create(ui->Home_cont_total_normal);
    lv_label_set_text(ui->Home_label_total_num, "Num");
    lv_label_set_long_mode(ui->Home_label_total_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_total_num, 33, 44);
    lv_obj_set_size(ui->Home_label_total_num, 22, 10);

    //Write style for Home_label_total_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_total_num, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_total_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_total_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_total_num, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_total_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_normal_num
    ui->Home_label_normal_num = lv_label_create(ui->Home_cont_total_normal);
    lv_label_set_text(ui->Home_label_normal_num, "Num");
    lv_label_set_long_mode(ui->Home_label_normal_num, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_normal_num, 108, 44);
    lv_obj_set_size(ui->Home_label_normal_num, 22, 10);

    //Write style for Home_label_normal_num, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_normal_num, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_normal_num, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_normal_num, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_normal_num, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_normal_num, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_temp
    ui->Home_cont_temp = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_temp, 34, 52);
    lv_obj_set_size(ui->Home_cont_temp, 144, 120);
    lv_obj_set_scrollbar_mode(ui->Home_cont_temp, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_temp, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_temp, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_temp, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_temp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_temp_tit
    ui->Home_label_temp_tit = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_temp_tit, "Temperature Monitor");
    lv_label_set_long_mode(ui->Home_label_temp_tit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_temp_tit, 0, 0);
    lv_obj_set_size(ui->Home_label_temp_tit, 144, 26);

    //Write style for Home_label_temp_tit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_temp_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_temp_tit, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_temp_tit, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_temp_tit, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_temp_tit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_temp_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_temp_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_temp_tit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_temp_tit, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_label_temp_tit, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_label_temp_tit, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_temp_tit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_temp_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_temp_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_temp_tit, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_temp_tit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_arc_temp
    ui->Home_arc_temp = lv_arc_create(ui->Home_cont_temp);
    lv_arc_set_mode(ui->Home_arc_temp, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_temp, 0, 40);
    lv_arc_set_bg_angles(ui->Home_arc_temp, 0, 360);
    lv_arc_set_value(ui->Home_arc_temp, 20);
    lv_arc_set_rotation(ui->Home_arc_temp, 90);
    lv_obj_set_pos(ui->Home_arc_temp, 6, 37);
    lv_obj_set_size(ui->Home_arc_temp, 60, 60);

    //Write style for Home_arc_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_temp, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_temp, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_temp, lv_color_hex(0xe7e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_temp, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_temp, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_temp, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_temp, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_temp, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_temp, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_temp, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_temp, lv_color_hex(0x0eff85), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_temp, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_temp, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_arc_temp, lv_color_hex(0x0eff85), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_arc_temp, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_temp, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_arc_humi
    ui->Home_arc_humi = lv_arc_create(ui->Home_cont_temp);
    lv_arc_set_mode(ui->Home_arc_humi, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->Home_arc_humi, 0, 40);
    lv_arc_set_bg_angles(ui->Home_arc_humi, 0, 360);
    lv_arc_set_value(ui->Home_arc_humi, 10);
    lv_arc_set_rotation(ui->Home_arc_humi, 90);
    lv_obj_set_pos(ui->Home_arc_humi, 75, 37);
    lv_obj_set_size(ui->Home_arc_humi, 60, 60);

    //Write style for Home_arc_humi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Home_arc_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui->Home_arc_humi, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_humi, 45, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_humi, lv_color_hex(0xe7e8e8), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_arc_humi, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_arc_humi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_arc_humi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_arc_humi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_arc_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_arc_humi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Home_arc_humi, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->Home_arc_humi, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->Home_arc_humi, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->Home_arc_humi, lv_color_hex(0x00c8eb), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Home_arc_humi, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Home_arc_humi, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_arc_humi, lv_color_hex(0x00c8eb), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_arc_humi, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->Home_arc_humi, 4, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Home_label_temp_con
    ui->Home_label_temp_con = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_temp_con, "1F");
    lv_label_set_long_mode(ui->Home_label_temp_con, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_temp_con, 29, 58);
    lv_obj_set_size(ui->Home_label_temp_con, 24, 15);

    //Write style for Home_label_temp_con, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_temp_con, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_temp_con, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_temp_con, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_temp_con, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_temp_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_temp_val
    ui->Home_label_temp_val = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_temp_val, "28");
    lv_label_set_long_mode(ui->Home_label_temp_val, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_temp_val, 21, 79);
    lv_obj_set_size(ui->Home_label_temp_val, 22, 14);

    //Write style for Home_label_temp_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_temp_val, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_temp_val, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_temp_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_temp_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_temp_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_wet_val
    ui->Home_label_wet_val = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_wet_val, "50");
    lv_label_set_long_mode(ui->Home_label_wet_val, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_wet_val, 90, 75);
    lv_obj_set_size(ui->Home_label_wet_val, 20, 14);

    //Write style for Home_label_wet_val, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_wet_val, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_wet_val, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_wet_val, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_wet_val, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_wet_val, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_wet_con
    ui->Home_label_wet_con = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_wet_con, "1F");
    lv_label_set_long_mode(ui->Home_label_wet_con, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_wet_con, 103, 54);
    lv_obj_set_size(ui->Home_label_wet_con, 21, 16);

    //Write style for Home_label_wet_con, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_wet_con, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_wet_con, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_wet_con, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_wet_con, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_wet_con, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_temp
    ui->Home_img_temp = lv_img_create(ui->Home_cont_temp);
    lv_obj_add_flag(ui->Home_img_temp, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_temp, &_temp_alpha_25x25);
    lv_img_set_pivot(ui->Home_img_temp, 50,50);
    lv_img_set_angle(ui->Home_img_temp, 0);
    lv_obj_set_pos(ui->Home_img_temp, 15, 51);
    lv_obj_set_size(ui->Home_img_temp, 25, 25);

    //Write style for Home_img_temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_temp, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_humidity
    ui->Home_img_humidity = lv_img_create(ui->Home_cont_temp);
    lv_obj_add_flag(ui->Home_img_humidity, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_humidity, &_Humidity_alpha_19x24);
    lv_img_set_pivot(ui->Home_img_humidity, 50,50);
    lv_img_set_angle(ui->Home_img_humidity, 0);
    lv_obj_set_pos(ui->Home_img_humidity, 88, 49);
    lv_obj_set_size(ui->Home_img_humidity, 19, 24);

    //Write style for Home_img_humidity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_humidity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_humidity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_humidity, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_temp_unit2
    ui->Home_label_temp_unit2 = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_temp_unit2, "℃");
    lv_label_set_long_mode(ui->Home_label_temp_unit2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_temp_unit2, 34, 78);
    lv_obj_set_size(ui->Home_label_temp_unit2, 15, 12);

    //Write style for Home_label_temp_unit2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_temp_unit2, lv_color_hex(0xdbff54), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_temp_unit2, &lv_font_SourceHanSerifSC_Regular_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_temp_unit2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_temp_unit2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_temp_unit2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_temp_unit1
    ui->Home_label_temp_unit1 = lv_label_create(ui->Home_cont_temp);
    lv_label_set_text(ui->Home_label_temp_unit1, "%");
    lv_label_set_long_mode(ui->Home_label_temp_unit1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_temp_unit1, 103, 75);
    lv_obj_set_size(ui->Home_label_temp_unit1, 21, 15);

    //Write style for Home_label_temp_unit1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_temp_unit1, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_temp_unit1, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_temp_unit1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_temp_unit1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_temp_unit1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_cont_electricity
    ui->Home_cont_electricity = lv_obj_create(ui->Home);
    lv_obj_set_pos(ui->Home_cont_electricity, 36, 180);
    lv_obj_set_size(ui->Home_cont_electricity, 144, 120);
    lv_obj_set_scrollbar_mode(ui->Home_cont_electricity, LV_SCROLLBAR_MODE_OFF);

    //Write style for Home_cont_electricity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_cont_electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_cont_electricity, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_cont_electricity, 181, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_cont_electricity, lv_color_hex(0x154870), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_cont_electricity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_cont_electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_cont_electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_cont_electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_cont_electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_cont_electricity, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_ele_monitor_title
    ui->Home_label_ele_monitor_title = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_ele_monitor_title, "Electricity Monitor");
    lv_label_set_long_mode(ui->Home_label_ele_monitor_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_ele_monitor_title, 0, 0);
    lv_obj_set_size(ui->Home_label_ele_monitor_title, 144, 26);

    //Write style for Home_label_ele_monitor_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_ele_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_ele_monitor_title, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_ele_monitor_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_ele_monitor_title, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_ele_monitor_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_ele_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_ele_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_ele_monitor_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_ele_monitor_title, 59, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Home_label_ele_monitor_title, lv_color_hex(0x1e1e1e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Home_label_ele_monitor_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_ele_monitor_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_ele_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_ele_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_ele_monitor_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_ele_monitor_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_1_bak
    ui->Home_img_1_bak = lv_img_create(ui->Home_cont_electricity);
    lv_obj_add_flag(ui->Home_img_1_bak, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_1_bak, &_menu_icon_bak_alpha_54x54);
    lv_img_set_pivot(ui->Home_img_1_bak, 50,50);
    lv_img_set_angle(ui->Home_img_1_bak, 0);
    lv_obj_set_pos(ui->Home_img_1_bak, 3, 32);
    lv_obj_set_size(ui->Home_img_1_bak, 54, 54);

    //Write style for Home_img_1_bak, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_1_bak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_1_bak, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_1_bak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_1_bak, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_2_bak
    ui->Home_img_2_bak = lv_img_create(ui->Home_cont_electricity);
    lv_obj_add_flag(ui->Home_img_2_bak, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_2_bak, &_menu_icon_bak_alpha_54x54);
    lv_img_set_pivot(ui->Home_img_2_bak, 50,50);
    lv_img_set_angle(ui->Home_img_2_bak, 0);
    lv_obj_set_pos(ui->Home_img_2_bak, 48, 32);
    lv_obj_set_size(ui->Home_img_2_bak, 54, 54);

    //Write style for Home_img_2_bak, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_2_bak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_2_bak, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_2_bak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_2_bak, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_img_3_bak
    ui->Home_img_3_bak = lv_img_create(ui->Home_cont_electricity);
    lv_obj_add_flag(ui->Home_img_3_bak, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Home_img_3_bak, &_menu_icon_bak_alpha_54x54);
    lv_img_set_pivot(ui->Home_img_3_bak, 50,50);
    lv_img_set_angle(ui->Home_img_3_bak, 0);
    lv_obj_set_pos(ui->Home_img_3_bak, 91, 32);
    lv_obj_set_size(ui->Home_img_3_bak, 54, 54);

    //Write style for Home_img_3_bak, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Home_img_3_bak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Home_img_3_bak, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_img_3_bak, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Home_img_3_bak, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_1_NO
    ui->Home_label_1_NO = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_1_NO, "#001");
    lv_label_set_long_mode(ui->Home_label_1_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_1_NO, 13, 97);
    lv_obj_set_size(ui->Home_label_1_NO, 30, 15);

    //Write style for Home_label_1_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_1_NO, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_1_NO, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_1_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_1_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_1_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_ele_1
    ui->Home_label_ele_1 = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_ele_1, "28");
    lv_label_set_long_mode(ui->Home_label_ele_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_ele_1, 15, 50);
    lv_obj_set_size(ui->Home_label_ele_1, 30, 15);

    //Write style for Home_label_ele_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_ele_1, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_ele_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_ele_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_ele_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_ele_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_ele_2
    ui->Home_label_ele_2 = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_ele_2, "28");
    lv_label_set_long_mode(ui->Home_label_ele_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_ele_2, 62, 52);
    lv_obj_set_size(ui->Home_label_ele_2, 21, 16);

    //Write style for Home_label_ele_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_ele_2, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_ele_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_ele_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_ele_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_ele_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_2_NO
    ui->Home_label_2_NO = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_2_NO, "#002");
    lv_label_set_long_mode(ui->Home_label_2_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_2_NO, 58, 97);
    lv_obj_set_size(ui->Home_label_2_NO, 30, 15);

    //Write style for Home_label_2_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_2_NO, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_2_NO, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_2_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_2_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_2_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_3_NO
    ui->Home_label_3_NO = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_3_NO, "#003");
    lv_label_set_long_mode(ui->Home_label_3_NO, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_3_NO, 103, 97);
    lv_obj_set_size(ui->Home_label_3_NO, 30, 15);

    //Write style for Home_label_3_NO, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_3_NO, lv_color_hex(0xfafafa), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_3_NO, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_3_NO, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_3_NO, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_3_NO, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_ele_3
    ui->Home_label_ele_3 = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_ele_3, "28");
    lv_label_set_long_mode(ui->Home_label_ele_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_ele_3, 103, 52);
    lv_obj_set_size(ui->Home_label_ele_3, 30, 15);

    //Write style for Home_label_ele_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_ele_3, lv_color_hex(0xa8cb11), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_ele_3, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_ele_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_ele_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_ele_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_kwh_2
    ui->Home_label_kwh_2 = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_kwh_2, "kw/h");
    lv_label_set_long_mode(ui->Home_label_kwh_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_kwh_2, 63, 70);
    lv_obj_set_size(ui->Home_label_kwh_2, 21, 16);

    //Write style for Home_label_kwh_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_kwh_2, lv_color_hex(0xacacab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_kwh_2, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_kwh_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_kwh_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_kwh_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_kwh_3
    ui->Home_label_kwh_3 = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_kwh_3, "kw/h");
    lv_label_set_long_mode(ui->Home_label_kwh_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_kwh_3, 108, 70);
    lv_obj_set_size(ui->Home_label_kwh_3, 21, 16);

    //Write style for Home_label_kwh_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_kwh_3, lv_color_hex(0xacacab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_kwh_3, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_kwh_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_kwh_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_kwh_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_kwh_1
    ui->Home_label_kwh_1 = lv_label_create(ui->Home_cont_electricity);
    lv_label_set_text(ui->Home_label_kwh_1, "kw/h");
    lv_label_set_long_mode(ui->Home_label_kwh_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_kwh_1, 19, 68);
    lv_obj_set_size(ui->Home_label_kwh_1, 21, 16);

    //Write style for Home_label_kwh_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_kwh_1, lv_color_hex(0xacacab), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_kwh_1, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_label_kwh_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_label_kwh_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_label_kwh_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Home_label_home_title
    ui->Home_label_home_title = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_label_home_title, "Monitoring");
    lv_label_set_long_mode(ui->Home_label_home_title, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Home_label_home_title, 124, 16);
    lv_obj_set_size(ui->Home_label_home_title, 210, 20);

    //Write style for Home_label_home_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Home_label_home_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_label_home_title, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_label_home_title, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_datetext_date
    ui->Home_datetext_date = lv_label_create(ui->Home);
    lv_label_set_text(ui->Home_datetext_date, "2023/07/31");
    lv_obj_set_style_text_align(ui->Home_datetext_date, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->Home_datetext_date, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->Home_datetext_date, Home_datetext_date_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->Home_datetext_date, 349, 16);
    lv_obj_set_size(ui->Home_datetext_date, 58, 24);

    //Write style for Home_datetext_date, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Home_datetext_date, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_datetext_date, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
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

    //Write codes Home_digital_clock_time
    static bool Home_digital_clock_time_timer_enabled = false;
    ui->Home_digital_clock_time = lv_dclock_create(ui->Home, "11:25:50");
    if (!Home_digital_clock_time_timer_enabled) {
        lv_timer_create(Home_digital_clock_time_timer, 1000, NULL);
        Home_digital_clock_time_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Home_digital_clock_time, 386, 16);
    lv_obj_set_size(ui->Home_digital_clock_time, 58, 20);

    //Write style for Home_digital_clock_time, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Home_digital_clock_time, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Home_digital_clock_time, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Home_digital_clock_time, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Home_digital_clock_time, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Home_digital_clock_time, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Home_digital_clock_time, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

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
