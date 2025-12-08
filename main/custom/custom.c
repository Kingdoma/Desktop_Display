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
    if (ui->Monitor_dark_arc_1) {
        lv_arc_set_value(ui->Monitor_dark_arc_1, cpu_usage);
    }
    if (ui->Monitor_dark_cpu_percent) {
        lv_label_set_text_fmt(ui->Monitor_dark_cpu_percent, "%d", cpu_usage);
    }

    if (ui->Monitor_dark_cpu_frequency_data) {
        lv_label_set_text_fmt(ui->Monitor_dark_cpu_frequency_data, "%.2f", metrics->cpu_freq_ghz);
    }
    if (ui->Monitor_dark_cpu_temp_data) {
        lv_label_set_text_fmt(ui->Monitor_dark_cpu_temp_data, "%.1f", metrics->cpu_temp_c);
    }

    const int16_t ram_usage = clamp_percent(metrics->ram_usage_percent);
    if (ui->Monitor_dark_ram_slider) {
        lv_slider_set_value(ui->Monitor_dark_ram_slider, ram_usage, LV_ANIM_OFF);
    }
    if (ui->Monitor_dark_ram_data) {
        lv_label_set_text_fmt(ui->Monitor_dark_ram_data, "%d", ram_usage);
    }

    const int16_t gpu_usage = clamp_percent(metrics->gpu_usage_percent);
    if (ui->Monitor_dark_arc_2) {
        lv_arc_set_value(ui->Monitor_dark_arc_2, gpu_usage);
    }
    if (ui->Monitor_dark_gpu_percent) {
        lv_label_set_text_fmt(ui->Monitor_dark_gpu_percent, "%d", gpu_usage);
    }

    if (ui->Monitor_dark_gpu_frequency_data) {
        lv_label_set_text_fmt(ui->Monitor_dark_gpu_frequency_data, "%d", (int)metrics->gpu_freq_mhz);
    }
    if (ui->Monitor_dark_gpu_temp_data) {
        lv_label_set_text_fmt(ui->Monitor_dark_gpu_temp_data, "%.1f", metrics->gpu_temp_c);
    }

    const int16_t gram_usage = clamp_percent(metrics->gram_usage_percent);
    if (ui->Monitor_dark_gram_slider) {
        lv_slider_set_value(ui->Monitor_dark_gram_slider, gram_usage, LV_ANIM_OFF);
    }
    if (ui->Monitor_dark_gram_data) {
        lv_label_set_text_fmt(ui->Monitor_dark_gram_data, "%d", gram_usage);
    }
}

void scrollable_disable(lv_obj_t *obj){
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
}
