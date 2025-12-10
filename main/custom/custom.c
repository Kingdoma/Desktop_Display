/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <stdbool.h>
#include "lvgl.h"
#include "custom.h"
#include "esp_log.h"

/*********************
 *      DEFINES
 *********************/
#define TAG "custom"

extern lv_ui guider_ui;

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**
 * Create a demo application
 */


void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

static int16_t clamp_percent(float value)
{
    if (value < 0.0f) {
        value = 0.0f;
    } else if (value > 100.0f) {
        value = 100.0f;
    }
    return (int16_t)(value + 0.5f);
}

static bool screen_is_active(const lv_obj_t *screen)
{
    return screen && lv_obj_is_valid(screen) && lv_scr_act() == screen;
}

static void spangroup_set(const lv_obj_t* obj, uint8_t idx, float data, uint8_t digits)
{
    lv_span_t* span;
    char data_text[16];

    span = lv_spangroup_get_child(obj, idx);

    if(digits == 0)
    {
        snprintf(data_text, sizeof(data_text), "%d" , (uint8_t)data);
    }
    else if(digits == 2)
    {
        snprintf(data_text, sizeof(data_text), "%.2f" , data);
    }
    else
    {
        snprintf(data_text, sizeof(data_text), "%.1f" , data);
    }

    lv_span_set_text(span, data_text);
    return;
}

static void spangroup_set_text_idx(const lv_obj_t *obj, uint8_t idx, const char *text)
{
    if (!obj || !text) {
        return;
    }

    lv_span_t *span = lv_spangroup_get_child(obj, idx);
    if (span) {
        lv_span_set_text(span, text);
        lv_spangroup_refr_mode(obj);
    }
}

static void monitor_panel_update(lv_ui *ui, const system_metrics_t *metrics)
{
    const int16_t cpu_usage = clamp_percent(metrics->cpu_usage_percent);
    if (ui->Monitor_dark_arc_1) {
        lv_arc_set_value(ui->Monitor_dark_arc_1, cpu_usage);
    }
    
    if (ui->Monitor_dark_cpu_percent) {
        spangroup_set(ui->Monitor_dark_cpu_percent, 0, cpu_usage, 0);
    }
    if (ui->Monitor_dark_cpu_freq) {
        spangroup_set(ui->Monitor_dark_cpu_freq, 1, metrics->cpu_freq_ghz, 2);
    }
    if (ui->Monitor_dark_cpu_temp) {
        spangroup_set(ui->Monitor_dark_cpu_temp, 1, metrics->cpu_temp_c, 0);
    }

    const int16_t ram_usage = clamp_percent(metrics->ram_usage_percent);
    if (ui->Monitor_dark_ram_slider) {
        lv_slider_set_value(ui->Monitor_dark_ram_slider, ram_usage, LV_ANIM_OFF);
    }
    if (ui->Monitor_dark_ram_data) {
        spangroup_set(ui->Monitor_dark_ram_data, 1, ram_usage, 0);
    }

    const int16_t gpu_usage = clamp_percent(metrics->gpu_usage_percent);
    if (ui->Monitor_dark_arc_2) {
        lv_arc_set_value(ui->Monitor_dark_arc_2, gpu_usage);
    }
    if (ui->Monitor_dark_gpu_percent) {
        spangroup_set(ui->Monitor_dark_gpu_percent, 0, gpu_usage, 0);
    }

    if (ui->Monitor_dark_gpu_freq) {
        spangroup_set(ui->Monitor_dark_gpu_freq, 1, metrics->gpu_freq_mhz, 0);
    }
    if (ui->Monitor_dark_gpu_temp) {
        spangroup_set(ui->Monitor_dark_gpu_temp, 1, metrics->gpu_temp_c, 0);
    }

    const int16_t gram_usage = clamp_percent(metrics->gram_usage_percent);
    if (ui->Monitor_dark_gram_slider) {
        lv_slider_set_value(ui->Monitor_dark_gram_slider, gram_usage, LV_ANIM_OFF);
    }
    
    if (ui->Monitor_dark_gram_data) {
        spangroup_set(ui->Monitor_dark_gram_data, 1, gram_usage, 0);
    }

    if (metrics->has_date && ui->Monitor_dark_datetext_date) {
        lv_label_set_text_fmt(ui->Monitor_dark_datetext_date, "%04u/%02u/%02u",
                            (unsigned)metrics->year,
                            (unsigned)metrics->month,
                            (unsigned)metrics->day);
    }
    
    if (metrics->has_day_of_week && ui->Monitor_dark_weekday) {
        static const char *const day_names[] = {
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        };
        if (metrics->day_of_week >= 0 && metrics->day_of_week <= 6) {
            lv_label_set_text(ui->Monitor_dark_weekday, day_names[metrics->day_of_week]);
        }
    }

    if (metrics->has_time && ui->Monitor_dark_digital_clock_time) {
        const bool is_pm = metrics->hour >= 12;
        uint8_t hour12 = metrics->hour % 12;
        if(metrics->hour && hour12 == 0) {
            hour12 = 12;
        }
        
        const char *suffix = is_pm ? "PM" : "AM";
        lv_dclock_set_text_fmt(ui->Monitor_dark_digital_clock_time, "%u:%02u:%02u %s",
                            (unsigned)hour12,
                            (unsigned)metrics->minute,
                            (unsigned)metrics->second,
                            suffix);

        Monitor_dark_digital_clock_time_hour_value = hour12;
        Monitor_dark_digital_clock_time_min_value = metrics->minute;
        Monitor_dark_digital_clock_time_sec_value = metrics->second;
        Monitor_dark_digital_clock_time_meridiem[0] = suffix[0];
        Monitor_dark_digital_clock_time_meridiem[1] = suffix[1];
        Monitor_dark_digital_clock_time_meridiem[2] = '\0';
    }
}

static void ha_panel_update(lv_ui *ui, const system_metrics_t *metrics)
{
    if (ui->HA_dark_date && lv_obj_is_valid(ui->HA_dark_date)) {
        lv_span_t *day_span = lv_spangroup_get_child(ui->HA_dark_date, 0);
        lv_span_t *date_span = lv_spangroup_get_child(ui->HA_dark_date, 2);

        if (metrics->has_day_of_week && day_span && metrics->day_of_week >= 0 && metrics->day_of_week <= 6) {
            static const char *const day_names[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
            lv_span_set_text(day_span, day_names[metrics->day_of_week]);
        }

        if (metrics->has_date && date_span) {
            char date_text[16];
            snprintf(date_text, sizeof(date_text), "%04u/%02u/%u",
                        (unsigned)metrics->year,
                        (unsigned)metrics->month,
                        (unsigned)metrics->day);
            lv_span_set_text(date_span, date_text);
        }

        // lv_spangroup_refr_mode(ui->HA_dark_date);
    }

    if (metrics->has_time && ui->HA_dark_digital_clock_time && lv_obj_is_valid(ui->HA_dark_digital_clock_time)) {
        lv_dclock_set_text_fmt(ui->HA_dark_digital_clock_time, "%02u:%02u:%02u",
                                (unsigned)metrics->hour,
                                (unsigned)metrics->minute,
                                (unsigned)metrics->second);

        HA_dark_digital_clock_time_hour_value = metrics->hour;
        HA_dark_digital_clock_time_min_value = metrics->minute;
        HA_dark_digital_clock_time_sec_value = metrics->second;
    }
}

void custom_update_metrics(lv_ui *ui, const system_metrics_t *metrics)
{
    if (!ui || !metrics) {
        return;
    }

    // If at Monitor panel then update the metrics and time
    if (screen_is_active(ui->Monitor_dark)) {
        monitor_panel_update(ui, metrics);
    }
    // If at HA panel then update the homeassistant entry data and time
    else if (screen_is_active(ui->HA_dark)) {
        ha_panel_update(ui, metrics);
    }

}

static void update_ac_mode(lv_ui *ui, ha_climate_mode_t mode)
{
    if (!ui) {
        return;
    }

    if (ui->HA_dark_ac_off && lv_obj_is_valid(ui->HA_dark_ac_off)) {
        lv_obj_clear_state(ui->HA_dark_ac_off, LV_STATE_CHECKED);
    }
    if (ui->HA_dark_ac_cool && lv_obj_is_valid(ui->HA_dark_ac_cool)) {
        lv_obj_clear_state(ui->HA_dark_ac_cool, LV_STATE_CHECKED);
    }
    if (ui->HA_dark_ac_heat && lv_obj_is_valid(ui->HA_dark_ac_heat)) {
        lv_obj_clear_state(ui->HA_dark_ac_heat, LV_STATE_CHECKED);
    }

    lv_color_t indicator_color = lv_color_hex(0x686868);
    switch (mode) {
    case HA_CLIMATE_MODE_COOL:
        if (ui->HA_dark_ac_cool) {
            lv_obj_add_state(ui->HA_dark_ac_cool, LV_STATE_CHECKED);
        }
        indicator_color = lv_color_hex(0x2195f6);
        break;
    case HA_CLIMATE_MODE_HEAT:
        if (ui->HA_dark_ac_heat) {
            lv_obj_add_state(ui->HA_dark_ac_heat, LV_STATE_CHECKED);
        }
        indicator_color = lv_color_hex(0xea7b32);
        break;
    case HA_CLIMATE_MODE_OFF:
    default:
        if (ui->HA_dark_ac_off) {
            lv_obj_add_state(ui->HA_dark_ac_off, LV_STATE_CHECKED);
        }
        indicator_color = lv_color_hex(0x686868);
        break;
    }

    if (ui->HA_dark_temp_slider && lv_obj_is_valid(ui->HA_dark_temp_slider)) {
        lv_obj_set_style_bg_color(ui->HA_dark_temp_slider, indicator_color, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
}

static int16_t clamp_slider_value(const lv_obj_t *slider, int16_t value)
{
    if (!slider) {
        return value;
    }
    const int32_t min = lv_slider_get_min_value(slider);
    const int32_t max = lv_slider_get_max_value(slider);
    if (value < min) {
        return (int16_t)min;
    }
    if (value > max) {
        return (int16_t)max;
    }
    return value;
}

void custom_update_ha_state(lv_ui *ui, const ha_state_t *state)
{
    if (!ui || !state) {
        return;
    }

    if (!ui->HA_dark || !lv_obj_is_valid(ui->HA_dark)) {
        return;
    }

    if (state->has_temperature && ui->HA_dark_temp_info) {
        char temp_text[16];
        snprintf(temp_text, sizeof(temp_text), "%.1f°C", state->temperature_c);
        spangroup_set_text_idx(ui->HA_dark_temp_info, 0, temp_text);
    }

    if (state->has_humidity && ui->HA_dark_hum_info) {
        char hum_text[16];
        snprintf(hum_text, sizeof(hum_text), "%.1f%%", state->humidity_percent);
        spangroup_set_text_idx(ui->HA_dark_hum_info, 0, hum_text);
    }

    if (state->has_switch1) {
        if (ui->HA_dark_sw_1) {
            if (state->switch1_on) {
                lv_obj_add_state(ui->HA_dark_sw_1, LV_STATE_CHECKED);
            } else {
                lv_obj_clear_state(ui->HA_dark_sw_1, LV_STATE_CHECKED);
            }
        }
        if (ui->HA_dark_sw_info_1) {
            spangroup_set_text_idx(ui->HA_dark_sw_info_1, 0, state->switch1_on ? "On" : "Off");
        }
    }

    if (state->has_switch2) {
        if (ui->HA_dark_sw_2) {
            if (state->switch2_on) {
                lv_obj_add_state(ui->HA_dark_sw_2, LV_STATE_CHECKED);
            } else {
                lv_obj_clear_state(ui->HA_dark_sw_2, LV_STATE_CHECKED);
            }
        }
        if (ui->HA_dark_sw_info_2) {
            spangroup_set_text_idx(ui->HA_dark_sw_info_2, 0, state->switch2_on ? "On" : "Off");
        }
    }

    if (state->has_printer_progress && ui->HA_dark_printer_slider) {
        lv_slider_set_range(ui->HA_dark_printer_slider, 0, 100);
        const int16_t progress = clamp_slider_value(ui->HA_dark_printer_slider, (int16_t)(state->printer_progress + 0.5f));
        lv_slider_set_value(ui->HA_dark_printer_slider, progress, LV_ANIM_OFF);
        if (ui->HA_dark_printer_info) {
            char progress_text[12];
            snprintf(progress_text, sizeof(progress_text), "%d%%", (int)progress);
            spangroup_set_text_idx(ui->HA_dark_printer_info, 2, progress_text);
        }
    }

    if (state->has_target_temp && ui->HA_dark_temp_slider) {
        const int16_t temp_value = clamp_slider_value(ui->HA_dark_temp_slider, (int16_t)(state->target_temp_c + 0.5f));
        lv_slider_set_value(ui->HA_dark_temp_slider, temp_value, LV_ANIM_OFF);
        if (ui->HA_dark_ac_temp) {
            lv_label_set_text_fmt(ui->HA_dark_ac_temp, "%d", (int)temp_value);
        }
    }

    if (state->has_climate_mode) {
        update_ac_mode(ui, state->climate_mode);
    }
}

void custom_handle_switch(uint8_t index, bool on)
{
    esp_err_t err = ha_sync_publish_switch(index, on);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to publish switch%u -> %d (%s)", (unsigned)index, on, esp_err_to_name(err));
    }
}

void custom_handle_ac_mode(ha_climate_mode_t mode)
{
    update_ac_mode(&guider_ui, mode);
    esp_err_t err = ha_sync_publish_climate_mode(mode);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to publish climate mode (%s)", esp_err_to_name(err));
    }
}

void custom_handle_ac_target_temp(int32_t temp_c)
{
    if (temp_c < 0) {
        temp_c = 0;
    }
    if (temp_c > 50) {
        temp_c = 50;
    }
    if (guider_ui.HA_dark_temp_slider && lv_obj_is_valid(guider_ui.HA_dark_temp_slider)) {
        lv_slider_set_value(guider_ui.HA_dark_temp_slider, temp_c, LV_ANIM_OFF);
    }
    if (guider_ui.HA_dark_ac_temp && lv_obj_is_valid(guider_ui.HA_dark_ac_temp)) {
        lv_label_set_text_fmt(guider_ui.HA_dark_ac_temp, "%d", (int)temp_c);
    }

    esp_err_t err = ha_sync_publish_climate_temp((float)temp_c);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to publish climate temp (%s)", esp_err_to_name(err));
    }
}

void custom_handle_printer_progress(int32_t progress)
{
    if (progress < 0) {
        progress = 0;
    }
    if (progress > 100) {
        progress = 100;
    }

    if (guider_ui.HA_dark_printer_slider && lv_obj_is_valid(guider_ui.HA_dark_printer_slider)) {
        lv_slider_set_value(guider_ui.HA_dark_printer_slider, progress, LV_ANIM_OFF);
    }

    esp_err_t err = ha_sync_publish_printer_progress((float)progress);
    if (err != ESP_OK) {
        ESP_LOGW(TAG, "Failed to publish printer progress (%s)", esp_err_to_name(err));
    }
}

void scrollable_disable(lv_obj_t *obj){
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}
