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
#include "lvgl.h"
#include "custom.h"
#include "gui_guider_support.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

extern int Home_digital_clock_time_hour_value;
extern int Home_digital_clock_time_min_value;
extern int Home_digital_clock_time_sec_value;
extern char Home_digital_clock_time_meridiem[];

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

void custom_update_metrics(lv_ui *ui, const system_metrics_t *metrics)
{
    if (!ui || !metrics) {
        return;
    }

    const int16_t cpu_usage = clamp_percent(metrics->cpu_usage_percent);
    if (ui->Home_arc_1) {
        lv_arc_set_value(ui->Home_arc_1, cpu_usage);
    }
    if (ui->Home_cpu_percent) {
        lv_label_set_text_fmt(ui->Home_cpu_percent, "%d", cpu_usage);
    }

    if (ui->Home_cpu_fequency_data) {
        lv_label_set_text_fmt(ui->Home_cpu_fequency_data, "%.2f", metrics->cpu_freq_ghz);
    }
    if (ui->Home_cpu_temp_data) {
        lv_label_set_text_fmt(ui->Home_cpu_temp_data, "%.0f", metrics->cpu_temp_c);
    }

    const int16_t ram_usage = clamp_percent(metrics->ram_usage_percent);
    if (ui->Home_ram_slider) {
        lv_slider_set_value(ui->Home_ram_slider, ram_usage, LV_ANIM_OFF);
    }
    if (ui->Home_ram_data) {
        lv_label_set_text_fmt(ui->Home_ram_data, "%d", ram_usage);
    }

    const int16_t gpu_usage = clamp_percent(metrics->gpu_usage_percent);
    if (ui->Home_arc_2) {
        lv_arc_set_value(ui->Home_arc_2, gpu_usage);
    }
    if (ui->Home_gpu_percent) {
        lv_label_set_text_fmt(ui->Home_gpu_percent, "%d", gpu_usage);
    }

    if (ui->Home_gpu_frequency_data) {
        lv_label_set_text_fmt(ui->Home_gpu_frequency_data, "%.0f", metrics->gpu_freq_mhz);
    }
    if (ui->Home_gpu_temp_data) {
        lv_label_set_text_fmt(ui->Home_gpu_temp_data, "%.0f", metrics->gpu_temp_c);
    }

    const int16_t gram_usage = clamp_percent(metrics->gram_usage_percent);
    if (ui->Home_gram_slider) {
        lv_slider_set_value(ui->Home_gram_slider, gram_usage, LV_ANIM_OFF);
    }
    if (ui->Home_gram_data) {
        lv_label_set_text_fmt(ui->Home_gram_data, "%d", gram_usage);
    }

    if (metrics->has_date && ui->Home_datetext_date) {
        lv_label_set_text_fmt(ui->Home_datetext_date, "%04u/%02u/%02u",
                              (unsigned)metrics->year,
                              (unsigned)metrics->month,
                              (unsigned)metrics->day);
    }

    if (metrics->has_day_of_week && ui->Home_weekday) {
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
            lv_label_set_text(ui->Home_weekday, day_names[metrics->day_of_week]);
        }
    }

    if (metrics->has_time && ui->Home_digital_clock_time) {
        const bool is_pm = metrics->hour >= 12;
        uint8_t hour12 = metrics->hour % 12;
        if(metrics->hour && hour12 == 0) {
            hour12 = 12;
        }
        
        const char *suffix = is_pm ? "PM" : "AM";
        lv_dclock_set_text_fmt(ui->Home_digital_clock_time, "%u:%02u:%02u %s",
                               (unsigned)hour12,
                               (unsigned)metrics->minute,
                               (unsigned)metrics->second,
                               suffix);

        Home_digital_clock_time_hour_value = hour12;
        Home_digital_clock_time_min_value = metrics->minute;
        Home_digital_clock_time_sec_value = metrics->second;
        Home_digital_clock_time_meridiem[0] = suffix[0];
        Home_digital_clock_time_meridiem[1] = suffix[1];
        Home_digital_clock_time_meridiem[2] = '\0';
    }
}

void scrollable_disable(lv_obj_t *obj){
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}
