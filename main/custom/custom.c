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
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "esp_log.h"
#include "lvgl.h"
#include "custom.h"
#include "ha_ui.h"
#include "app_main.h"
#include "wifi.h"

/*********************
 *      DEFINES
 *********************/
#define HA_UI_TAG "ha_ui"

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

bool screen_is_active(const lv_obj_t *screen)
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
        snprintf(data_text, sizeof(data_text), "%d" , (uint16_t)data);
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

static void spangroup_set_status(const lv_obj_t* obj, app_status_t status)
{   
    lv_span_t* span;
    span = lv_spangroup_get_child(obj, 1);

    switch (status)
    {
    case CONNECT:
        lv_span_set_text(span, "Connect");
        lv_style_set_text_color(&span->style, lv_color_hex(0x64e09e));
        break;

    case DISCONNECT:
        lv_span_set_text(span, "Disconnect");
        lv_style_set_text_color(&span->style, lv_color_hex(0xffe460));
        break;

    case WAITING:
        lv_span_set_text(span, "Waiting");
        lv_style_set_text_color(&span->style, lv_color_hex(0xffe460));
        break;

    case READY:
        lv_span_set_text(span, "Ready");
        lv_style_set_text_color(&span->style, lv_color_hex(0x64e09e));
        break;

    case ERROR:
        lv_span_set_text(span, "Error");
        lv_style_set_text_color(&span->style, lv_color_hex(0xff0027));
        break;
    
    default:
        ESP_LOGW(HA_UI_TAG,"Unknow Status %d",status);
        break;
    }
}

static time_t timegm_compat(struct tm *tm)
{
    time_t local = mktime(tm);
    if (local == (time_t)-1) {
        return (time_t)-1;
    }
    struct tm gtm = {0};
    if (!gmtime_r(&local, &gtm)) {
        return (time_t)-1;
    }
    time_t local_as_utc = mktime(&gtm);
    if (local_as_utc == (time_t)-1) {
        return (time_t)-1;
    }
    return local + (local - local_as_utc);
}

static bool parse_iso8601_utc(const char *ts, time_t *out_epoch)
{
    if (!ts || !out_epoch) {
        return false;
    }

    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    if (sscanf(ts, "%4d-%2d-%2dT%2d:%2d:%2d", &year, &month, &day, &hour, &minute, &second) != 6) {
        return false;
    }

    const char *search_start = strchr(ts, 'T');
    if (search_start) {
        search_start++;
    } else {
        search_start = ts;
    }
    const char *tz = NULL;
    const char *cursor = search_start;
    while (cursor && *cursor) {
        const char *found = strpbrk(cursor, "+-");
        if (!found) {
            break;
        }
        tz = found;
        cursor = found + 1;
    }

    int tz_sign = 1;
    int tz_hour = 0;
    int tz_min = 0;
    if (tz && strlen(tz) >= 6) {
        tz_sign = (*tz == '-') ? -1 : 1;
        (void)sscanf(tz + 1, "%2d:%2d", &tz_hour, &tz_min);
    }

    struct tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    tm.tm_isdst = -1;

    time_t epoch_utc = timegm_compat(&tm);
    if (epoch_utc == (time_t)-1) {
        return false;
    }
    epoch_utc -= tz_sign * (tz_hour * 3600 + tz_min * 60);
    *out_epoch = epoch_utc;
    return true;
}

static void format_elapsed_since(const char *last_changed, char *out, size_t out_len)
{
    if (!out || out_len == 0) {
        return;
    }
    out[0] = '\0';

    time_t changed = 0;
    if (!last_changed || !parse_iso8601_utc(last_changed, &changed)) {
        strlcpy(out, "--", out_len);
        return;
    }

    time_t now = time(NULL);
    if (now < changed) {
        now = changed;
    }
    uint32_t diff = (uint32_t)difftime(now, changed);
    uint32_t days = diff / 86400;
    uint32_t hours = (diff % 86400) / 3600;
    uint32_t mins = (diff % 3600) / 60;
    uint32_t secs = diff % 60;

    if (days > 0) {
        snprintf(out, out_len, "%lu day%s", (unsigned long)days, days == 1 ? "" : "s");
    } else if (hours > 0) {
        snprintf(out, out_len, "%lu hour%s", (unsigned long)hours, hours == 1 ? "" : "s");
    } else if (mins > 0) {
        snprintf(out, out_len, "%lu min", (unsigned long)mins);
    } else {
        snprintf(out, out_len, "%lu s", (unsigned long)secs);
    }
}

static void update_switch_card(lv_ui *ui, uint8_t id, const ha_ui_sw_t *data)
{
    if (!ui || !data) {
        return;
    }

    lv_obj_t *sw = (id == 2) ? ui->HA_dark_sw_2 : ui->HA_dark_sw_1;
    lv_obj_t *info = (id == 2) ? ui->HA_dark_sw_info_2 : ui->HA_dark_sw_info_1;

    if (sw && lv_obj_is_valid(sw)) {
        if (data->switch_on) {
            lv_obj_add_state(sw, LV_STATE_CHECKED);
        } else {
            lv_obj_clear_state(sw, LV_STATE_CHECKED);
        }
    }

    if (info && lv_obj_is_valid(info)) {
        char elapsed[32];
        format_elapsed_since(data->last_changed, elapsed, sizeof(elapsed));
        lv_span_t *span_state = lv_spangroup_get_child(info, 0);
        lv_span_t *span_time = lv_spangroup_get_child(info, 2);
        if (span_state) {
            lv_span_set_text(span_state, data->switch_on ? "On" : "Off");
        }
        if (span_time) {
            lv_span_set_text(span_time, elapsed);
        }
        lv_spangroup_refr_mode(info);
    }
}

static void update_weather_card(lv_ui *ui, const ha_ui_weather_t *data)
{
    if (!ui || !data) {
        return;
    }

    if (ui->HA_dark_temp && lv_obj_is_valid(ui->HA_dark_temp)) {
        char out[8];
        snprintf(out, sizeof(out), "%.1f", data->temperature);
        lv_span_t *span_state = lv_spangroup_get_child(ui->HA_dark_temp, 0);
        if (span_state) {
            lv_span_set_text(span_state, out);
        }
        lv_spangroup_refr_mode(ui->HA_dark_temp);
    }

    if (!ui->HA_dark_weather || !lv_obj_is_valid(ui->HA_dark_weather) || data->weather[0] == '\0') {
        return;
    }

    if(strcmp(data->weather, "sunny") == 0 || strcmp(data->weather, "clear-night") == 0){
        lv_img_set_src(ui->HA_dark_weather, &_sun_alpha_60x60);
    }
    else if (strcmp(data->weather, "cloudy") == 0 || strcmp(data->weather, "partlycloudy") == 0)
    {
        lv_img_set_src(ui->HA_dark_weather, &_cloudy_alpha_60x60);
    }
    else if (strcmp(data->weather, "foogy") == 0)
    {
        lv_img_set_src(ui->HA_dark_weather, &_foog_alpha_60x60);
    }
    else if (strcmp(data->weather, "windy") == 0)
    {
        lv_img_set_src(ui->HA_dark_weather, &_windy_alpha_60x60);
    }
    else if (strcmp(data->weather, "rainy") == 0)
    {
        lv_img_set_src(ui->HA_dark_weather, &_rainy_alpha_60x60);
    }
    else if (strcmp(data->weather, "storm") == 0)
    {
        lv_img_set_src(ui->HA_dark_weather, &_storm_alpha_60x60);
    }
    else if (strcmp(data->weather, "snowy") == 0)
    {
        lv_img_set_src(ui->HA_dark_weather, &_snowy_alpha_60x60);
    }else{
        ESP_LOGW(HA_UI_TAG,"Weather state not listed: %s", data->weather);
    }
}

static void update_climate_card(lv_ui *ui, const ha_ui_climate_t *data)
{
    if (!ui || !data) {
        return;
    }

    if (ui->HA_dark_ac_temp && lv_obj_is_valid(ui->HA_dark_ac_temp)) {
        char out[8];
        snprintf(out, sizeof(out), "%.0f", data->temperature);
        lv_label_set_text(ui->HA_dark_ac_temp, out);
    }

    if (ui->HA_dark_temp_slider && lv_obj_is_valid(ui->HA_dark_temp_slider)) {
        lv_slider_set_value(ui->HA_dark_temp_slider, (int32_t)data->temperature, LV_ANIM_OFF);
    }

    if (ui->HA_dark_ac_info && lv_obj_is_valid(ui->HA_dark_ac_info)) {
        char elapsed[32];
        format_elapsed_since(data->last_changed, elapsed, sizeof(elapsed));
        lv_span_t *span_state = lv_spangroup_get_child(ui->HA_dark_ac_info, 0);
        lv_span_t *span_time = lv_spangroup_get_child(ui->HA_dark_ac_info, 2);
        if (span_state) {
            lv_span_set_text(span_state, data->mode);
        }
        if (span_time) {
            lv_span_set_text(span_time, elapsed);
        }
        lv_spangroup_refr_mode(ui->HA_dark_ac_info);

        lv_obj_t *btn_cool = ui->HA_dark_ac_cool;
        lv_obj_t *btn_heat = ui->HA_dark_ac_heat;
        lv_obj_t *btn_off = ui->HA_dark_ac_off;

        if (strcmp(data->mode, "cool") == 0 && btn_cool && lv_obj_is_valid(btn_cool)) {
            lv_event_send(btn_cool, LV_EVENT_CLICKED, NULL);
        } else if (strcmp(data->mode, "heat") == 0 && btn_heat && lv_obj_is_valid(btn_heat)) {
            lv_event_send(btn_heat, LV_EVENT_CLICKED, NULL);
        } else if (strcmp(data->mode, "off") == 0 && btn_off && lv_obj_is_valid(btn_off)) {
            lv_event_send(btn_off, LV_EVENT_CLICKED, NULL);
        }
    }
}

static void update_sensor_card(lv_obj_t *info, const ha_ui_sensor_t *data)
{
    if (!info || !data || !lv_obj_is_valid(info)) {
        return;
    }

    char elapsed[32];
    format_elapsed_since(data->last_changed, elapsed, sizeof(elapsed));
    lv_span_t *span_state = lv_spangroup_get_child(info, 0);
    lv_span_t *span_time = lv_spangroup_get_child(info, 2);
    if (span_state) {
        lv_span_set_text(span_state, data->data[0] ? data->data : "--");
    }
    if (span_time) {
        lv_span_set_text(span_time, elapsed);
    }
    lv_spangroup_refr_mode(info);
}

void monitor_panel_update(lv_ui *ui, const system_metrics_t *metrics)
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

void ha_panel_update(lv_ui *ui, const system_metrics_t *metrics)
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
        lv_dclock_set_text_fmt(ui->HA_dark_digital_clock_time, "%u:%02u:%02u",
                                (unsigned)metrics->hour,
                                (unsigned)metrics->minute,
                                (unsigned)metrics->second);

        HA_dark_digital_clock_time_hour_value = metrics->hour;
        HA_dark_digital_clock_time_min_value = metrics->minute;
        HA_dark_digital_clock_time_sec_value = metrics->second;
    }

    if (!sync_data) {
        return;
    }

    update_weather_card(ui, sync_data->weahter_card);
    update_switch_card(ui, 1, sync_data->sw_1);
    update_switch_card(ui, 2, sync_data->sw_2);
    update_climate_card(ui, sync_data->ac_card);
    update_sensor_card(ui->HA_dark_hum_info, sync_data->hum_card);
    update_sensor_card(ui->HA_dark_temp_info, sync_data->temp_card);
}

void setting_panel_update(lv_ui *ui){
    spangroup_set_status(ui->Setting_dark_wifi_info, g_module_status.wifi_staus);
    spangroup_set_status(ui->Setting_dark_usb_info, g_module_status.cdc_status);
    spangroup_set_status(ui->Setting_dark_sntp_info, g_module_status.sntp_status);
    spangroup_set_status(ui->Setting_dark_ha_info, g_module_status.ha_status);
    spangroup_set_status(ui->Setting_dark_web_info, g_module_status.web_status);

    if (ui && ui->Setting_dark_wifi_ip && lv_obj_is_valid(ui->Setting_dark_wifi_ip)) {
        lv_span_t *span = lv_spangroup_get_child(ui->Setting_dark_wifi_ip, 1);
        if (span) {
            const char *ip = "--";
            if (g_module_status.wifi_staus == CONNECT) {
                const char *current = wifi_get_ip();
                if (current && current[0] != '\0') {
                    ip = current;
                }
            }
            lv_span_set_text(span, ip);
            lv_spangroup_refr_mode(ui->Setting_dark_wifi_ip);
        }
    }
}

void scrollable_disable(lv_obj_t *obj){
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}
