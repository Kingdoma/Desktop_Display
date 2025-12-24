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
#include "ha_sync.h"
#include "wifi.h"
#include "ha_settings.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

uint8_t idx;
static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */

typedef struct {
    int8_t status;
    uint8_t temp;
} ac_info_t;

ac_info_t ac = {
    .status = -1,
    .temp = 26
};

static void Monitor_dark_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_clear_flag(guider_ui.Monitor_dark_cont_cpu_monitor, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Monitor_dark_cpu_usage, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Monitor_dark_cont_gpu_monitor, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Monitor_dark_gpu_usage, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Monitor_dark_cont_time, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Monitor_dark_cont_net, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_clear_flag(guider_ui.Monitor_dark_speed_info, LV_OBJ_FLAG_SCROLLABLE);

        break;
    }
    default:
        break;
    }
}

static void Monitor_dark_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint16_t id = lv_dropdown_get_selected(guider_ui.Monitor_dark_menu);
        idx = lv_dropdown_get_selected(guider_ui.Monitor_dark_menu);
        if(idx == 1) {
            ui_load_scr_animation(&guider_ui, &guider_ui.HA_dark, guider_ui.HA_dark_del, &guider_ui.Monitor_dark_del, setup_scr_HA_dark, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        if(idx == 2) {
            ui_load_scr_animation(&guider_ui, &guider_ui.Setting_dark, guider_ui.Setting_dark_del, &guider_ui.Monitor_dark_del, setup_scr_Setting_dark, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Monitor_dark (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Monitor_dark, Monitor_dark_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Monitor_dark_menu, Monitor_dark_menu_event_handler, LV_EVENT_ALL, ui);
}

static void HA_dark_sw_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        const bool on = lv_obj_has_state(guider_ui.HA_dark_sw_2, LV_STATE_CHECKED);
        // const ha_settings_t *settings = ha_settings_get();
        // if (settings && settings->entity_switch_2[0] != '\0') {
        //     ha_sync_set_local_state(settings->entity_switch_2, on ? "on" : "off");
        // }

        break;
    }
    default:
        break;
    }
}

static void HA_dark_sw_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * status_obj = lv_event_get_target(e);
        int status = lv_obj_has_state(status_obj, LV_STATE_CHECKED) ? true : false;
        const bool on = lv_obj_has_state(guider_ui.HA_dark_sw_1, LV_STATE_CHECKED);
        // const ha_settings_t *settings = ha_settings_get();
        // if (settings && settings->entity_switch_1[0] != '\0') {
        //     ha_sync_set_local_state(settings->entity_switch_1, on ? "on" : "off");
        // }
        break;
    }
    default:
        break;
    }
}

static void HA_dark_temp_slider_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        snprintf(buf, 4, "%lu", lv_slider_get_value(guider_ui.HA_dark_temp_slider));
        lv_label_set_text(guider_ui.HA_dark_ac_temp, buf);

        ac.temp = lv_slider_get_value(guider_ui.HA_dark_temp_slider);
        if(ac.status)
        {
            char buf[8];
            snprintf(buf, sizeof(buf), "%ld", (long)lv_slider_get_value(guider_ui.HA_dark_temp_slider));
            const ha_settings_t *settings = ha_settings_get();
            if (settings && settings->entity_ac[0] != '\0') {
                ha_sync_set_local_state(settings->entity_ac, buf);
            }
        }

        break;
    }
    default:
        break;
    }
}

static void HA_dark_ac_off_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(ac.status == 0)
        {
            // press cool at cool mode, keep cooling checked
            lv_obj_add_state(guider_ui.HA_dark_ac_off, LV_STATE_CHECKED);
        }
        else
        {
            // press off when cool/heat, reset the cool/heat, update status
            lv_obj_clear_state(guider_ui.HA_dark_ac_heat, LV_STATE_CHECKED);
            lv_obj_clear_state(guider_ui.HA_dark_ac_cool, LV_STATE_CHECKED);
            lv_obj_add_state(guider_ui.HA_dark_ac_off, LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(guider_ui.HA_dark_temp_slider, lv_color_hex(0x686868), LV_PART_INDICATOR|LV_STATE_DEFAULT);

            // update to ha server
            const ha_settings_t *settings = ha_settings_get();
            if (settings && settings->entity_ac[0] != '\0') {
                ha_sync_set_local_state(settings->entity_ac, "off");
            }

            ac.status = 0;
        }
        break;
    }
    default:
        break;
    }
}

static void HA_dark_ac_cool_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(ac.status == 1)
        {
            // press cool at cool mode, keep cooling checked
            lv_obj_add_state(guider_ui.HA_dark_ac_cool, LV_STATE_CHECKED);
        }
        else
        {
            // press cool when off/heat, reset the off/heat, update status
            lv_obj_clear_state(guider_ui.HA_dark_ac_heat, LV_STATE_CHECKED);
            lv_obj_clear_state(guider_ui.HA_dark_ac_off, LV_STATE_CHECKED);
            lv_obj_add_state(guider_ui.HA_dark_ac_cool, LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(guider_ui.HA_dark_temp_slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);

            // update to ha server
            const ha_settings_t *settings = ha_settings_get();
            if (settings && settings->entity_ac[0] != '\0') {
                ha_sync_set_local_state(settings->entity_ac, "cool");
            }

            ac.status = 1;
        }
        break;
    }
    default:
        break;
    }
}

static void HA_dark_ac_heat_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(ac.status == 2)
        {
            // press heat at heat mode, keep heat checked
            lv_obj_add_state(guider_ui.HA_dark_ac_heat, LV_STATE_CHECKED);
        }
        else
        {
            // press heat when cool/off, reset the cool/off, update status
            lv_obj_clear_state(guider_ui.HA_dark_ac_off, LV_STATE_CHECKED);
            lv_obj_clear_state(guider_ui.HA_dark_ac_cool, LV_STATE_CHECKED);
            lv_obj_add_state(guider_ui.HA_dark_ac_heat, LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(guider_ui.HA_dark_temp_slider, lv_color_hex(0xea7b32), LV_PART_INDICATOR|LV_STATE_DEFAULT);

            // update to ha server
            const ha_settings_t *settings = ha_settings_get();
            if (settings && settings->entity_ac[0] != '\0') {
                ha_sync_set_local_state(settings->entity_ac, "heat");
            }

            ac.status = 2;
        }
        break;
    }
    default:
        break;
    }
}

static void HA_dark_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint16_t id = lv_dropdown_get_selected(guider_ui.HA_dark_menu);
        idx = lv_dropdown_get_selected(guider_ui.HA_dark_menu);
        if(idx == 1) {
            ui_load_scr_animation(&guider_ui, &guider_ui.Monitor_dark, guider_ui.Monitor_dark_del, &guider_ui.HA_dark_del, setup_scr_Monitor_dark, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        if(idx == 2) {
            ui_load_scr_animation(&guider_ui, &guider_ui.Setting_dark, guider_ui.Setting_dark_del, &guider_ui.HA_dark_del, setup_scr_Setting_dark, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_HA_dark (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->HA_dark_sw_2, HA_dark_sw_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->HA_dark_sw_1, HA_dark_sw_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->HA_dark_temp_slider, HA_dark_temp_slider_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->HA_dark_ac_off, HA_dark_ac_off_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->HA_dark_ac_cool, HA_dark_ac_cool_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->HA_dark_ac_heat, HA_dark_ac_heat_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->HA_dark_menu, HA_dark_menu_event_handler, LV_EVENT_ALL, ui);
}

static void Setting_dark_disconnect_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        wifi_diconnect();
        break;
    }
    default:
        break;
    }
}

static void Setting_dark_reconnect_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        wifi_reconnect();
        break;
    }
    default:
        break;
    }
}

static void Setting_dark_rest_btn_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        wifi_setting_clear();
        break;
    }
    default:
        break;
    }
}

static void Setting_dark_menu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        uint16_t id = lv_dropdown_get_selected(guider_ui.Setting_dark_menu);
        idx = lv_dropdown_get_selected(guider_ui.Setting_dark_menu);
        if(idx == 1) {
            ui_load_scr_animation(&guider_ui, &guider_ui.Monitor_dark, guider_ui.Monitor_dark_del, &guider_ui.Setting_dark_del, setup_scr_Monitor_dark, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        if(idx == 2) {
            ui_load_scr_animation(&guider_ui, &guider_ui.HA_dark, guider_ui.HA_dark_del, &guider_ui.Setting_dark_del, setup_scr_HA_dark, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_Setting_dark (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Setting_dark_disconnect_btn, Setting_dark_disconnect_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_dark_reconnect_btn, Setting_dark_reconnect_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_dark_rest_btn, Setting_dark_rest_btn_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Setting_dark_menu, Setting_dark_menu_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
