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



void setup_scr_Setting_dark(lv_ui *ui)
{
    //Write codes Setting_dark
    ui->Setting_dark = lv_obj_create(NULL);
    lv_obj_set_size(ui->Setting_dark, 480, 320);
    lv_obj_set_scrollbar_mode(ui->Setting_dark, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_dark, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting_dark, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark, lv_color_hex(0x232429), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_wifi_cont
    ui->Setting_dark_wifi_cont = lv_obj_create(ui->Setting_dark);
    lv_obj_set_pos(ui->Setting_dark_wifi_cont, 26, 62);
    lv_obj_set_size(ui->Setting_dark_wifi_cont, 179, 239);
    lv_obj_set_scrollbar_mode(ui->Setting_dark_wifi_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_dark_wifi_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_wifi_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_wifi_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_wifi_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_wifi_cont, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_wifi_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_wifi_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_wifi_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_wifi_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_wifi_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_wifi_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Setting_dark_wifi_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Setting_dark_wifi_cont, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Setting_dark_wifi_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Setting_dark_wifi_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Setting_dark_wifi_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_disconnect_btn
    ui->Setting_dark_disconnect_btn = lv_btn_create(ui->Setting_dark_wifi_cont);
    ui->Setting_dark_disconnect_btn_label = lv_label_create(ui->Setting_dark_disconnect_btn);
    lv_label_set_text(ui->Setting_dark_disconnect_btn_label, "Disconnect");
    lv_label_set_long_mode(ui->Setting_dark_disconnect_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Setting_dark_disconnect_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Setting_dark_disconnect_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Setting_dark_disconnect_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->Setting_dark_disconnect_btn, 14, 191);
    lv_obj_set_size(ui->Setting_dark_disconnect_btn, 150, 30);

    //Write style for Setting_dark_disconnect_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting_dark_disconnect_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_disconnect_btn, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_disconnect_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Setting_dark_disconnect_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_disconnect_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_disconnect_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_disconnect_btn, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_disconnect_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_disconnect_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_disconnect_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_reconnect_btn
    ui->Setting_dark_reconnect_btn = lv_btn_create(ui->Setting_dark_wifi_cont);
    ui->Setting_dark_reconnect_btn_label = lv_label_create(ui->Setting_dark_reconnect_btn);
    lv_label_set_text(ui->Setting_dark_reconnect_btn_label, "Restart");
    lv_label_set_long_mode(ui->Setting_dark_reconnect_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Setting_dark_reconnect_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Setting_dark_reconnect_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Setting_dark_reconnect_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->Setting_dark_reconnect_btn, 14, 150);
    lv_obj_set_size(ui->Setting_dark_reconnect_btn, 150, 30);

    //Write style for Setting_dark_reconnect_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting_dark_reconnect_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_reconnect_btn, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_reconnect_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Setting_dark_reconnect_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_reconnect_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_reconnect_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_reconnect_btn, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_reconnect_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_reconnect_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_reconnect_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_rest_btn
    ui->Setting_dark_rest_btn = lv_btn_create(ui->Setting_dark_wifi_cont);
    ui->Setting_dark_rest_btn_label = lv_label_create(ui->Setting_dark_rest_btn);
    lv_label_set_text(ui->Setting_dark_rest_btn_label, "Clear Setting");
    lv_label_set_long_mode(ui->Setting_dark_rest_btn_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Setting_dark_rest_btn_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Setting_dark_rest_btn, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Setting_dark_rest_btn_label, LV_PCT(100));
    lv_obj_set_pos(ui->Setting_dark_rest_btn, 14, 105);
    lv_obj_set_size(ui->Setting_dark_rest_btn, 150, 30);

    //Write style for Setting_dark_rest_btn, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Setting_dark_rest_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_rest_btn, lv_color_hex(0x4F5159), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_rest_btn, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Setting_dark_rest_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_rest_btn, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_rest_btn, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_rest_btn, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_rest_btn, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_rest_btn, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_rest_btn, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_wifi_opt
    ui->Setting_dark_wifi_opt = lv_label_create(ui->Setting_dark_wifi_cont);
    lv_label_set_text(ui->Setting_dark_wifi_opt, "Option :");
    lv_label_set_long_mode(ui->Setting_dark_wifi_opt, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_dark_wifi_opt, 14, 74);
    lv_obj_set_size(ui->Setting_dark_wifi_opt, 126, 21);

    //Write style for Setting_dark_wifi_opt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_wifi_opt, lv_color_hex(0xCBCBCD), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_wifi_opt, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_wifi_opt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_wifi_opt, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_wifi_opt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_wifi_info
    ui->Setting_dark_wifi_info = lv_spangroup_create(ui->Setting_dark_wifi_cont);
    lv_spangroup_set_align(ui->Setting_dark_wifi_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Setting_dark_wifi_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Setting_dark_wifi_info, LV_SPAN_MODE_FIXED);
    //create span
    ui->Setting_dark_wifi_info_span = lv_spangroup_new_span(ui->Setting_dark_wifi_info);
    lv_span_set_text(ui->Setting_dark_wifi_info_span, "Status : ");
    lv_style_set_text_color(&ui->Setting_dark_wifi_info_span->style, lv_color_hex(0xCBCBCD));
    lv_style_set_text_decor(&ui->Setting_dark_wifi_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_wifi_info_span->style, &lv_font_montserratMedium_16);
    ui->Setting_dark_wifi_info_span = lv_spangroup_new_span(ui->Setting_dark_wifi_info);
    lv_span_set_text(ui->Setting_dark_wifi_info_span, "OK");
    lv_style_set_text_color(&ui->Setting_dark_wifi_info_span->style, lv_color_hex(0x64e09e));
    lv_style_set_text_decor(&ui->Setting_dark_wifi_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_wifi_info_span->style, &lv_font_montserratMedium_16);
    lv_obj_set_pos(ui->Setting_dark_wifi_info, 14, 43);
    lv_obj_set_size(ui->Setting_dark_wifi_info, 175, 35);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_dark_wifi_info_main_main_default
    static lv_style_t style_Setting_dark_wifi_info_main_main_default;
    ui_init_style(&style_Setting_dark_wifi_info_main_main_default);

    lv_style_set_border_width(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_radius(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_pad_top(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_pad_right(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_pad_left(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_Setting_dark_wifi_info_main_main_default, 0);
    lv_obj_add_style(ui->Setting_dark_wifi_info, &style_Setting_dark_wifi_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Setting_dark_wifi_info);

    //Write codes Setting_dark_wifi_label
    ui->Setting_dark_wifi_label = lv_label_create(ui->Setting_dark_wifi_cont);
    lv_label_set_text(ui->Setting_dark_wifi_label, "WIFI");
    lv_label_set_long_mode(ui->Setting_dark_wifi_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_dark_wifi_label, 33, 11);
    lv_obj_set_size(ui->Setting_dark_wifi_label, 126, 21);

    //Write style for Setting_dark_wifi_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_wifi_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_wifi_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_wifi_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_wifi_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_wifi_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_wifi_icon
    ui->Setting_dark_wifi_icon = lv_img_create(ui->Setting_dark_wifi_cont);
    lv_obj_add_flag(ui->Setting_dark_wifi_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_dark_wifi_icon, &_wifi_alpha_22x22);
    lv_img_set_pivot(ui->Setting_dark_wifi_icon, 50,50);
    lv_img_set_angle(ui->Setting_dark_wifi_icon, 0);
    lv_obj_set_pos(ui->Setting_dark_wifi_icon, 7, 7);
    lv_obj_set_size(ui->Setting_dark_wifi_icon, 22, 22);

    //Write style for Setting_dark_wifi_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_dark_wifi_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_dark_wifi_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_wifi_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_dark_wifi_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_usb_cont
    ui->Setting_dark_usb_cont = lv_obj_create(ui->Setting_dark);
    lv_obj_set_pos(ui->Setting_dark_usb_cont, 226, 62);
    lv_obj_set_size(ui->Setting_dark_usb_cont, 229, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_dark_usb_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_dark_usb_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_usb_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_usb_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_usb_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_usb_cont, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_usb_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_usb_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_usb_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_usb_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_usb_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_usb_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Setting_dark_usb_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Setting_dark_usb_cont, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Setting_dark_usb_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Setting_dark_usb_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Setting_dark_usb_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_usb_label
    ui->Setting_dark_usb_label = lv_label_create(ui->Setting_dark_usb_cont);
    lv_label_set_text(ui->Setting_dark_usb_label, "USB");
    lv_label_set_long_mode(ui->Setting_dark_usb_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_dark_usb_label, 33, 13);
    lv_obj_set_size(ui->Setting_dark_usb_label, 126, 21);

    //Write style for Setting_dark_usb_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_usb_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_usb_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_usb_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_dark_usb_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_usb_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_usb_info
    ui->Setting_dark_usb_info = lv_spangroup_create(ui->Setting_dark_usb_cont);
    lv_spangroup_set_align(ui->Setting_dark_usb_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Setting_dark_usb_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Setting_dark_usb_info, LV_SPAN_MODE_FIXED);
    //create span
    ui->Setting_dark_usb_info_span = lv_spangroup_new_span(ui->Setting_dark_usb_info);
    lv_span_set_text(ui->Setting_dark_usb_info_span, "Status : ");
    lv_style_set_text_color(&ui->Setting_dark_usb_info_span->style, lv_color_hex(0xCBCBCD));
    lv_style_set_text_decor(&ui->Setting_dark_usb_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_usb_info_span->style, &lv_font_montserratMedium_16);
    ui->Setting_dark_usb_info_span = lv_spangroup_new_span(ui->Setting_dark_usb_info);
    lv_span_set_text(ui->Setting_dark_usb_info_span, "Connected");
    lv_style_set_text_color(&ui->Setting_dark_usb_info_span->style, lv_color_hex(0x64e09e));
    lv_style_set_text_decor(&ui->Setting_dark_usb_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_usb_info_span->style, &lv_font_montserratMedium_16);
    lv_obj_set_pos(ui->Setting_dark_usb_info, 16, 40);
    lv_obj_set_size(ui->Setting_dark_usb_info, 199, 35);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_dark_usb_info_main_main_default
    static lv_style_t style_Setting_dark_usb_info_main_main_default;
    ui_init_style(&style_Setting_dark_usb_info_main_main_default);

    lv_style_set_border_width(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_radius(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_pad_top(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_pad_right(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_pad_left(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_Setting_dark_usb_info_main_main_default, 0);
    lv_obj_add_style(ui->Setting_dark_usb_info, &style_Setting_dark_usb_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Setting_dark_usb_info);

    //Write codes Setting_dark_usb_icon
    ui->Setting_dark_usb_icon = lv_img_create(ui->Setting_dark_usb_cont);
    lv_obj_add_flag(ui->Setting_dark_usb_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_dark_usb_icon, &_usb_alpha_22x22);
    lv_img_set_pivot(ui->Setting_dark_usb_icon, 50,50);
    lv_img_set_angle(ui->Setting_dark_usb_icon, 0);
    lv_obj_set_pos(ui->Setting_dark_usb_icon, 7, 8);
    lv_obj_set_size(ui->Setting_dark_usb_icon, 22, 22);

    //Write style for Setting_dark_usb_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_dark_usb_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Setting_dark_usb_icon, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_dark_usb_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_usb_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_dark_usb_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_ha_cont
    ui->Setting_dark_ha_cont = lv_obj_create(ui->Setting_dark);
    lv_obj_set_pos(ui->Setting_dark_ha_cont, 226, 230);
    lv_obj_set_size(ui->Setting_dark_ha_cont, 229, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_dark_ha_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_dark_ha_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_ha_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_ha_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_ha_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_ha_cont, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_ha_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_ha_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_ha_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_ha_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_ha_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_ha_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Setting_dark_ha_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Setting_dark_ha_cont, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Setting_dark_ha_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Setting_dark_ha_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Setting_dark_ha_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_ha_label
    ui->Setting_dark_ha_label = lv_label_create(ui->Setting_dark_ha_cont);
    lv_label_set_text(ui->Setting_dark_ha_label, "HOME ASSISTANT");
    lv_label_set_long_mode(ui->Setting_dark_ha_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_dark_ha_label, 33, 13);
    lv_obj_set_size(ui->Setting_dark_ha_label, 177, 21);

    //Write style for Setting_dark_ha_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_ha_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_ha_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_ha_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_dark_ha_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_ha_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_ha_info
    ui->Setting_dark_ha_info = lv_spangroup_create(ui->Setting_dark_ha_cont);
    lv_spangroup_set_align(ui->Setting_dark_ha_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Setting_dark_ha_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Setting_dark_ha_info, LV_SPAN_MODE_FIXED);
    //create span
    ui->Setting_dark_ha_info_span = lv_spangroup_new_span(ui->Setting_dark_ha_info);
    lv_span_set_text(ui->Setting_dark_ha_info_span, "Status : ");
    lv_style_set_text_color(&ui->Setting_dark_ha_info_span->style, lv_color_hex(0xCBCBCD));
    lv_style_set_text_decor(&ui->Setting_dark_ha_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_ha_info_span->style, &lv_font_montserratMedium_16);
    ui->Setting_dark_ha_info_span = lv_spangroup_new_span(ui->Setting_dark_ha_info);
    lv_span_set_text(ui->Setting_dark_ha_info_span, "Connected");
    lv_style_set_text_color(&ui->Setting_dark_ha_info_span->style, lv_color_hex(0x64e09e));
    lv_style_set_text_decor(&ui->Setting_dark_ha_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_ha_info_span->style, &lv_font_montserratMedium_16);
    lv_obj_set_pos(ui->Setting_dark_ha_info, 16, 40);
    lv_obj_set_size(ui->Setting_dark_ha_info, 199, 35);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_dark_ha_info_main_main_default
    static lv_style_t style_Setting_dark_ha_info_main_main_default;
    ui_init_style(&style_Setting_dark_ha_info_main_main_default);

    lv_style_set_border_width(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_radius(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_pad_top(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_pad_right(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_pad_left(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_Setting_dark_ha_info_main_main_default, 0);
    lv_obj_add_style(ui->Setting_dark_ha_info, &style_Setting_dark_ha_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Setting_dark_ha_info);

    //Write codes Setting_dark_ha_icon
    ui->Setting_dark_ha_icon = lv_img_create(ui->Setting_dark_ha_cont);
    lv_obj_add_flag(ui->Setting_dark_ha_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_dark_ha_icon, &_home_alpha_23x23);
    lv_img_set_pivot(ui->Setting_dark_ha_icon, 50,50);
    lv_img_set_angle(ui->Setting_dark_ha_icon, 0);
    lv_obj_set_pos(ui->Setting_dark_ha_icon, 7, 9);
    lv_obj_set_size(ui->Setting_dark_ha_icon, 23, 23);

    //Write style for Setting_dark_ha_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_dark_ha_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Setting_dark_ha_icon, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_dark_ha_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_ha_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_dark_ha_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_sntp_cont
    ui->Setting_dark_sntp_cont = lv_obj_create(ui->Setting_dark);
    lv_obj_set_pos(ui->Setting_dark_sntp_cont, 226, 146);
    lv_obj_set_size(ui->Setting_dark_sntp_cont, 229, 70);
    lv_obj_set_scrollbar_mode(ui->Setting_dark_sntp_cont, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_dark_sntp_cont, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_sntp_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_sntp_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_sntp_cont, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_sntp_cont, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_sntp_cont, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_sntp_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_sntp_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_sntp_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_sntp_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_sntp_cont, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Setting_dark_sntp_cont, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Setting_dark_sntp_cont, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Setting_dark_sntp_cont, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Setting_dark_sntp_cont, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Setting_dark_sntp_cont, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_sntp_label
    ui->Setting_dark_sntp_label = lv_label_create(ui->Setting_dark_sntp_cont);
    lv_label_set_text(ui->Setting_dark_sntp_label, "SNTP");
    lv_label_set_long_mode(ui->Setting_dark_sntp_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_dark_sntp_label, 33, 13);
    lv_obj_set_size(ui->Setting_dark_sntp_label, 177, 21);

    //Write style for Setting_dark_sntp_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_sntp_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_sntp_label, &lv_font_montserratMedium_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_sntp_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_dark_sntp_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_sntp_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_sntp_info
    ui->Setting_dark_sntp_info = lv_spangroup_create(ui->Setting_dark_sntp_cont);
    lv_spangroup_set_align(ui->Setting_dark_sntp_info, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Setting_dark_sntp_info, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Setting_dark_sntp_info, LV_SPAN_MODE_FIXED);
    //create span
    ui->Setting_dark_sntp_info_span = lv_spangroup_new_span(ui->Setting_dark_sntp_info);
    lv_span_set_text(ui->Setting_dark_sntp_info_span, "Status : ");
    lv_style_set_text_color(&ui->Setting_dark_sntp_info_span->style, lv_color_hex(0xCBCBCD));
    lv_style_set_text_decor(&ui->Setting_dark_sntp_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_sntp_info_span->style, &lv_font_montserratMedium_16);
    ui->Setting_dark_sntp_info_span = lv_spangroup_new_span(ui->Setting_dark_sntp_info);
    lv_span_set_text(ui->Setting_dark_sntp_info_span, "Connected");
    lv_style_set_text_color(&ui->Setting_dark_sntp_info_span->style, lv_color_hex(0x64e09e));
    lv_style_set_text_decor(&ui->Setting_dark_sntp_info_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Setting_dark_sntp_info_span->style, &lv_font_montserratMedium_16);
    lv_obj_set_pos(ui->Setting_dark_sntp_info, 16, 40);
    lv_obj_set_size(ui->Setting_dark_sntp_info, 199, 35);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_dark_sntp_info_main_main_default
    static lv_style_t style_Setting_dark_sntp_info_main_main_default;
    ui_init_style(&style_Setting_dark_sntp_info_main_main_default);

    lv_style_set_border_width(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_radius(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_bg_opa(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_pad_top(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_pad_right(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_pad_left(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_style_set_shadow_width(&style_Setting_dark_sntp_info_main_main_default, 0);
    lv_obj_add_style(ui->Setting_dark_sntp_info, &style_Setting_dark_sntp_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Setting_dark_sntp_info);

    //Write codes Setting_dark_sntp_icon
    ui->Setting_dark_sntp_icon = lv_img_create(ui->Setting_dark_sntp_cont);
    lv_obj_add_flag(ui->Setting_dark_sntp_icon, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->Setting_dark_sntp_icon, &_clock_alpha_20x20);
    lv_img_set_pivot(ui->Setting_dark_sntp_icon, 50,50);
    lv_img_set_angle(ui->Setting_dark_sntp_icon, 0);
    lv_obj_set_pos(ui->Setting_dark_sntp_icon, 8, 10);
    lv_obj_set_size(ui->Setting_dark_sntp_icon, 20, 20);

    //Write style for Setting_dark_sntp_icon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->Setting_dark_sntp_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor(ui->Setting_dark_sntp_icon, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->Setting_dark_sntp_icon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_sntp_icon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Setting_dark_sntp_icon, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_title
    ui->Setting_dark_title = lv_obj_create(ui->Setting_dark);
    lv_obj_set_pos(ui->Setting_dark_title, 95, 19);
    lv_obj_set_size(ui->Setting_dark_title, 360, 30);
    lv_obj_set_scrollbar_mode(ui->Setting_dark_title, LV_SCROLLBAR_MODE_OFF);

    //Write style for Setting_dark_title, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_title, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_title, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_title, lv_color_hex(0x323439), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_title, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_title, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui->Setting_dark_title, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui->Setting_dark_title, 30, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui->Setting_dark_title, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui->Setting_dark_title, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui->Setting_dark_title, 2, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_title_label
    ui->Setting_dark_title_label = lv_label_create(ui->Setting_dark_title);
    lv_label_set_text(ui->Setting_dark_title_label, "SETTINGS");
    lv_label_set_long_mode(ui->Setting_dark_title_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Setting_dark_title_label, 30, 5);
    lv_obj_set_size(ui->Setting_dark_title_label, 299, 21);

    //Write style for Setting_dark_title_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Setting_dark_title_label, lv_color_hex(0xebebeb), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_title_label, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_title_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Setting_dark_title_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_title_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Setting_dark_menu
    ui->Setting_dark_menu = lv_dropdown_create(ui->Setting_dark);
    lv_dropdown_set_options(ui->Setting_dark_menu, "OP\nPC\nHA");
    lv_obj_set_pos(ui->Setting_dark_menu, 26, 19);
    lv_obj_set_size(ui->Setting_dark_menu, 59, 30);

    //Write style for Setting_dark_menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Setting_dark_menu, lv_color_hex(0xd2d2d2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Setting_dark_menu, &lv_font_montserratMedium_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Setting_dark_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Setting_dark_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Setting_dark_menu, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Setting_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Setting_dark_menu, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Setting_dark_menu, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Setting_dark_menu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Setting_dark_menu, lv_color_hex(0x3E3F43), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Setting_dark_menu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Setting_dark_menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_CHECKED for &style_Setting_dark_menu_extra_list_selected_checked
    static lv_style_t style_Setting_dark_menu_extra_list_selected_checked;
    ui_init_style(&style_Setting_dark_menu_extra_list_selected_checked);

    lv_style_set_border_width(&style_Setting_dark_menu_extra_list_selected_checked, 0);
    lv_style_set_radius(&style_Setting_dark_menu_extra_list_selected_checked, 3);
    lv_style_set_bg_opa(&style_Setting_dark_menu_extra_list_selected_checked, 255);
    lv_style_set_bg_color(&style_Setting_dark_menu_extra_list_selected_checked, lv_color_hex(0x4F5159));
    lv_style_set_bg_grad_dir(&style_Setting_dark_menu_extra_list_selected_checked, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Setting_dark_menu), &style_Setting_dark_menu_extra_list_selected_checked, LV_PART_SELECTED|LV_STATE_CHECKED);

    //Write style state: LV_STATE_DEFAULT for &style_Setting_dark_menu_extra_list_main_default
    static lv_style_t style_Setting_dark_menu_extra_list_main_default;
    ui_init_style(&style_Setting_dark_menu_extra_list_main_default);

    lv_style_set_max_height(&style_Setting_dark_menu_extra_list_main_default, 130);
    lv_style_set_text_color(&style_Setting_dark_menu_extra_list_main_default, lv_color_hex(0xebebeb));
    lv_style_set_text_font(&style_Setting_dark_menu_extra_list_main_default, &lv_font_montserratMedium_15);
    lv_style_set_text_opa(&style_Setting_dark_menu_extra_list_main_default, 255);
    lv_style_set_border_width(&style_Setting_dark_menu_extra_list_main_default, 0);
    lv_style_set_radius(&style_Setting_dark_menu_extra_list_main_default, 7);
    lv_style_set_bg_opa(&style_Setting_dark_menu_extra_list_main_default, 255);
    lv_style_set_bg_color(&style_Setting_dark_menu_extra_list_main_default, lv_color_hex(0x3E3F43));
    lv_style_set_bg_grad_dir(&style_Setting_dark_menu_extra_list_main_default, LV_GRAD_DIR_NONE);
    lv_obj_add_style(lv_dropdown_get_list(ui->Setting_dark_menu), &style_Setting_dark_menu_extra_list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Setting_dark.


    //Update current screen layout.
    lv_obj_update_layout(ui->Setting_dark);

    //Init events for screen.
    events_init_Setting_dark(ui);
}
