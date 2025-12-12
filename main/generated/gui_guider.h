/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Monitor_dark;
	bool Monitor_dark_del;
	lv_obj_t *Monitor_dark_cont_time;
	lv_obj_t *Monitor_dark_digital_clock_time;
	lv_obj_t *Monitor_dark_datetext_date;
	lv_obj_t *Monitor_dark_time_title;
	lv_obj_t *Monitor_dark_weekday;
	lv_obj_t *Monitor_dark_cont_net;
	lv_obj_t *Monitor_dark_speed_info;
	lv_obj_t *Monitor_dark_download_icon;
	lv_obj_t *Monitor_dark_download;
	lv_span_t *Monitor_dark_download_span;
	lv_obj_t *Monitor_dark_upload_icon;
	lv_obj_t *Monitor_dark_upload;
	lv_span_t *Monitor_dark_upload_span;
	lv_obj_t *Monitor_dark_iploc;
	lv_span_t *Monitor_dark_iploc_span;
	lv_obj_t *Monitor_dark_ping;
	lv_span_t *Monitor_dark_ping_span;
	lv_obj_t *Monitor_dark_net_monitor_tit;
	lv_obj_t *Monitor_dark_cont_cpu_monitor;
	lv_obj_t *Monitor_dark_cpu_usage;
	lv_obj_t *Monitor_dark_arc_1;
	lv_obj_t *Monitor_dark_cpu_percent;
	lv_span_t *Monitor_dark_cpu_percent_span;
	lv_obj_t *Monitor_dark_ram_slider;
	lv_obj_t *Monitor_dark_ram_data;
	lv_span_t *Monitor_dark_ram_data_span;
	lv_obj_t *Monitor_dark_cpu_temp;
	lv_span_t *Monitor_dark_cpu_temp_span;
	lv_obj_t *Monitor_dark_cpu_freq;
	lv_span_t *Monitor_dark_cpu_freq_span;
	lv_obj_t *Monitor_dark_cpu_monitor_title;
	lv_obj_t *Monitor_dark_cont_gpu_monitor;
	lv_obj_t *Monitor_dark_gpu_usage;
	lv_obj_t *Monitor_dark_arc_2;
	lv_obj_t *Monitor_dark_gpu_percent;
	lv_span_t *Monitor_dark_gpu_percent_span;
	lv_obj_t *Monitor_dark_gram_slider;
	lv_obj_t *Monitor_dark_gram_data;
	lv_span_t *Monitor_dark_gram_data_span;
	lv_obj_t *Monitor_dark_gpu_temp;
	lv_span_t *Monitor_dark_gpu_temp_span;
	lv_obj_t *Monitor_dark_gpu_freq;
	lv_span_t *Monitor_dark_gpu_freq_span;
	lv_obj_t *Monitor_dark_gpu_monitor_title;
	lv_obj_t *Monitor_dark_label_home_title;
	lv_obj_t *Monitor_dark_menu;
	lv_obj_t *HA_dark;
	bool HA_dark_del;
	lv_obj_t *HA_dark_printer_card;
	lv_obj_t *HA_dark_printer_slider;
	lv_obj_t *HA_dark_printer_info;
	lv_span_t *HA_dark_printer_info_span;
	lv_obj_t *HA_dark_printer_title;
	lv_obj_t *HA_dark_temperature_card;
	lv_obj_t *HA_dark_temp_title;
	lv_obj_t *HA_dark_temp_info;
	lv_span_t *HA_dark_temp_info_span;
	lv_obj_t *HA_dark_temp_icon;
	lv_obj_t *HA_dark_humidity_card;
	lv_obj_t *HA_dark_hum_info;
	lv_span_t *HA_dark_hum_info_span;
	lv_obj_t *HA_dark_hum_title;
	lv_obj_t *HA_dark_hum_icon;
	lv_obj_t *HA_dark_hum_icon_f;
	lv_obj_t *HA_dark_switch_card_2;
	lv_obj_t *HA_dark_sw_info_2;
	lv_span_t *HA_dark_sw_info_2_span;
	lv_obj_t *HA_dark_sw_title_2;
	lv_obj_t *HA_dark_sw_2;
	lv_obj_t *HA_dark_switch_card_1;
	lv_obj_t *HA_dark_sw_info_1;
	lv_span_t *HA_dark_sw_info_1_span;
	lv_obj_t *HA_dark_sw_title_1;
	lv_obj_t *HA_dark_sw_1;
	lv_obj_t *HA_dark_ac_card;
	lv_obj_t *HA_dark_temp_slider;
	lv_obj_t *HA_dark_ac_temp_label;
	lv_obj_t *HA_dark_ac_temp;
	lv_obj_t *HA_dark_ac_off;
	lv_obj_t *HA_dark_ac_off_label;
	lv_obj_t *HA_dark_ac_cool;
	lv_obj_t *HA_dark_ac_cool_label;
	lv_obj_t *HA_dark_ac_heat;
	lv_obj_t *HA_dark_ac_heat_label;
	lv_obj_t *HA_dark_ac_info;
	lv_span_t *HA_dark_ac_info_span;
	lv_obj_t *HA_dark_ac_title;
	lv_obj_t *HA_dark_time_card;
	lv_obj_t *HA_dark_date;
	lv_span_t *HA_dark_date_span;
	lv_obj_t *HA_dark_digital_clock_time;
	lv_obj_t *HA_dark_temp;
	lv_span_t *HA_dark_temp_span;
	lv_obj_t *HA_dark_weather;
	lv_obj_t *HA_dark_menu;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_Monitor_dark(lv_ui *ui);
void setup_scr_HA_dark(lv_ui *ui);
LV_IMG_DECLARE(_download_alpha_13x13);
LV_IMG_DECLARE(_upload_alpha_13x13);

LV_IMG_DECLARE(_temperature_35x35);
LV_IMG_DECLARE(_humidity_alpha_28x28);
LV_IMG_DECLARE(_sun_alpha_60x60);
LV_IMG_DECLARE(_cloudy_alpha_60x60);
LV_IMG_DECLARE(_foog_alpha_60x60);
LV_IMG_DECLARE(_rainy_alpha_60x60);
LV_IMG_DECLARE(_windy_alpha_60x60);
LV_IMG_DECLARE(_storm_alpha_60x60);
LV_IMG_DECLARE(_snowy_alpha_60x60);

LV_FONT_DECLARE(lv_font_montserratMedium_17)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_35)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_22)


#ifdef __cplusplus
}
#endif
#endif
