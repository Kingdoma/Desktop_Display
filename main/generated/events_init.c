/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


static void Home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_clear_flag(guider_ui.Home, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_time, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_net, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_speed_info, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_cpu_monitor, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cpu_usage, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_cont_gpu_monitor, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Home_gpu_usage, LV_OBJ_FLAG_SCROLLABLE);
        break;
    }
    default:
        break;
    }
}

static void Home_btn_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_clear_flag(guider_ui.Home_cont_menu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void Home_cont_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.Home_cont_menu, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void Home_btn_phone_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void Home_btn_warning_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void Home_btn_power_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void Home_btn_temp_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void Home_btn_link_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void Home_btn_safe_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

static void Home_btn_light_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

void events_init_Home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Home, Home_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_menu, Home_btn_menu_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_cont_menu, Home_cont_menu_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_phone, Home_btn_phone_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_warning, Home_btn_warning_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_power, Home_btn_power_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_temp, Home_btn_temp_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_link, Home_btn_link_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_safe, Home_btn_safe_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Home_btn_light, Home_btn_light_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
