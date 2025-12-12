#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include "esp_log.h"
#include "lvgl.h"
// #include "lv_async.h"
#include "ha_ui.h"

#define HA_UI_TAG "ha_ui"

typedef struct {
    bool switch_on;
    float temperature;
    char state[16];
    char elapsed[24];
    uint8_t lvgl_id;
    lv_obj_t *lv_obj;
} ha_ui_msg_t;

static lv_ui *s_ui = NULL;

void ha_ui_set_ui(lv_ui *ui)
{
    s_ui = ui;
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
    int tz_sign = 1, tz_hour = 0, tz_min = 0;

    // Basic YYYY-MM-DDTHH:MM:SS parsing; ignore fractional seconds.
    if (sscanf(ts, "%4d-%2d-%2dT%2d:%2d:%2d", &year, &month, &day, &hour, &minute, &second) != 6) {
        return false;
    }

    const char *tz = strpbrk(ts, "+-");
    if (tz && (tz[0] == '+' || tz[0] == '-') && strlen(tz) >= 6) {
        tz_sign = (tz[0] == '-') ? -1 : 1;
        sscanf(tz + 1, "%2d:%2d", &tz_hour, &tz_min);
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

static void ha_switch_ui_apply(void *arg)
{
    ha_ui_msg_t *msg = (ha_ui_msg_t *)arg;
    if (!msg || !s_ui) {
        free(msg);
        return;
    }

    lv_obj_t *sw = NULL;
    lv_obj_t *info = NULL;
    if (msg->lvgl_id == 2) {
        sw = s_ui->HA_dark_sw_2;
        info = s_ui->HA_dark_sw_info_2;
    } else {
        sw = s_ui->HA_dark_sw_1;
        info = s_ui->HA_dark_sw_info_1;
    }

    if (sw && lv_obj_is_valid(sw)) {
        if (msg->switch_on) {
            lv_obj_add_state(sw, LV_STATE_CHECKED);
        } else {
            lv_obj_clear_state(sw, LV_STATE_CHECKED);
        }
    }

    if (info && lv_obj_is_valid(info)) {
        lv_span_t *span_state = lv_spangroup_get_child(info, 0);
        lv_span_t *span_time = lv_spangroup_get_child(info, 2);
        if (span_state) {
            lv_span_set_text(span_state, msg->switch_on ? "On" : "Off");
        }
        if (span_time) {
            lv_span_set_text(span_time, msg->elapsed);
        }
        lv_spangroup_refr_mode(info);
    }

    free(msg);
}

static void ha_weather_ui_apply(void *arg)
{
    ha_ui_msg_t *msg = (ha_ui_msg_t *)arg;
    if (!msg || !s_ui) {
        free(msg);
        return;
    }

    lv_obj_t *info = s_ui->HA_dark_temp;
    char out[4];

    snprintf(out, sizeof(out), "%.1f", msg->temperature);

    if (info && lv_obj_is_valid(info)) {
        lv_span_t *span_state = lv_spangroup_get_child(info, 0);
        if (span_state) {
            lv_span_set_text(span_state, out);
        }
        lv_spangroup_refr_mode(info);
    }

    if(strcmp(msg->state, "sunny") == 0){
        lv_img_set_src(s_ui->HA_dark_weather, &_sun_alpha_60x60);
    }
    else if (strcmp(msg->state, "cloudy") == 0 || strcmp(msg->state, "partlycloudy") == 0)
    {
        lv_img_set_src(s_ui->HA_dark_weather, &_cloudy_alpha_60x60);
    }
    else if (strcmp(msg->state, "foogy") == 0)
    {
        lv_img_set_src(s_ui->HA_dark_weather, &_foog_alpha_60x60);
    }
    else if (strcmp(msg->state, "windy") == 0)
    {
        lv_img_set_src(s_ui->HA_dark_weather, &_windy_alpha_60x60);
    }
    else if (strcmp(msg->state, "rainy") == 0)
    {
        lv_img_set_src(s_ui->HA_dark_weather, &_rainy_alpha_60x60);
    }
    else if (strcmp(msg->state, "storm") == 0)
    {
        lv_img_set_src(s_ui->HA_dark_weather, &_storm_alpha_60x60);
    }
    else if (strcmp(msg->state, "snowy") == 0)
    {
        lv_img_set_src(s_ui->HA_dark_weather, &_snowy_alpha_60x60);
    }else{
        ESP_LOGW(HA_UI_TAG,"Weather state not listed: %s", msg->state);
    }

    free(msg);
}

static void ha_sensor_ui_apply(void *arg)
{
    ha_ui_msg_t *msg = (ha_ui_msg_t *)arg;
    if (!msg || !s_ui) {
        free(msg);
        return;
    }

    lv_obj_t *info = msg->lv_obj;

    if (info && lv_obj_is_valid(info)) {
        lv_span_t *span_state = lv_spangroup_get_child(info, 0);
        lv_span_t *span_time = lv_spangroup_get_child(info, 3);
        if (span_state) {
            lv_span_set_text(span_state, msg->state);
        }
        if (span_time) {
            lv_span_set_text(span_time, msg->elapsed);
        }
        lv_spangroup_refr_mode(info);
    }

    free(msg);
}

void ha_ui_update_switch(uint8_t lvgl_id, const char *state, const char *last_changed)
{
    if (!state) {
        return;
    }
    char elapsed[24];
    format_elapsed_since(last_changed, elapsed, sizeof(elapsed));

    const bool is_on = (state[0] == 'o' || state[0] == 'O') && (state[1] == 'n' || state[1] == 'N');
    ha_ui_msg_t *msg = malloc(sizeof(*msg));
    if (!msg) {
        ESP_LOGW(HA_UI_TAG, "Failed to alloc HA UI msg");
        return;
    }
    msg->switch_on = is_on;
    strlcpy(msg->elapsed, elapsed, sizeof(msg->elapsed));
    msg->lvgl_id = lvgl_id ? lvgl_id : 1;

    // Run LVGL updates in the LVGL context.
    if (lv_async_call(ha_switch_ui_apply, msg) != LV_RES_OK) {
        free(msg);
        ESP_LOGW(HA_UI_TAG, "Failed to enqueue LVGL async update");
    }
}

void ha_ui_update_climate(const char *state, const char *last_changed, uint8_t lvgl_id)
{
    // if (!state) {
    //     return;
    // }
    // char elapsed[24];
    // format_elapsed_since(last_changed, elapsed, sizeof(elapsed));

    // ha_switch_ui_update_async(is_on, elapsed, lvgl_id ? lvgl_id : 1);
}

void ha_ui_update_printer(const char *state, const char *last_changed, uint8_t lvgl_id)
{
    ;
}

void ha_ui_update_weather(const float temperature, const char *state, const char *last_changed)
{ 
    if (!state) {
        return;
    }
    char elapsed[24];
    format_elapsed_since(last_changed, elapsed, sizeof(elapsed));

    ha_ui_msg_t *msg = malloc(sizeof(*msg));
    if (!msg) {
        ESP_LOGW(HA_UI_TAG, "Failed to alloc HA UI msg");
        return;
    }

    msg->temperature = temperature;
    strlcpy(msg->state, state, sizeof(msg->state));
    strlcpy(msg->elapsed, elapsed, sizeof(msg->elapsed));

    // Run LVGL updates in the LVGL context.
    if (lv_async_call(ha_weather_ui_apply, msg) != LV_RES_OK) {
        free(msg);
        ESP_LOGW(HA_UI_TAG, "Failed to enqueue LVGL async update");
    }
}

void ha_ui_update_temp_sensor(const char *state, const char *last_changed)
{
    if (!state) {
        return;
    }
    char elapsed[24];
    format_elapsed_since(last_changed, elapsed, sizeof(elapsed));

    ha_ui_msg_t *msg = malloc(sizeof(*msg));
    if (!msg) {
        ESP_LOGW(HA_UI_TAG, "Failed to alloc HA UI msg");
        return;
    }

    msg->lv_obj = s_ui->HA_dark_temp_info;
    strlcpy(msg->state, state, sizeof(msg->state));
    strlcpy(msg->elapsed, elapsed, sizeof(msg->elapsed));

    // Run LVGL updates in the LVGL context.
    if (lv_async_call(ha_sensor_ui_apply, msg) != LV_RES_OK) {
        free(msg);
        ESP_LOGW(HA_UI_TAG, "Failed to enqueue LVGL async update");
    }
}

void ha_ui_update_hum_sensor(const char *state, const char *last_changed)
{
        if (!state) {
        return;
    }
    char elapsed[24];
    format_elapsed_since(last_changed, elapsed, sizeof(elapsed));

    ha_ui_msg_t *msg = malloc(sizeof(*msg));
    if (!msg) {
        ESP_LOGW(HA_UI_TAG, "Failed to alloc HA UI msg");
        return;
    }

    msg->lv_obj = s_ui->HA_dark_hum_info;
    strlcpy(msg->state, state, sizeof(msg->state));
    strlcpy(msg->elapsed, elapsed, sizeof(msg->elapsed));

    // Run LVGL updates in the LVGL context.
    if (lv_async_call(ha_sensor_ui_apply, msg) != LV_RES_OK) {
        free(msg);
        ESP_LOGW(HA_UI_TAG, "Failed to enqueue LVGL async update");
    }
}