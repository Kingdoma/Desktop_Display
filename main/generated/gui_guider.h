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
  
	lv_obj_t *Home;
	bool Home_del;
	lv_obj_t *Home_tileview_1;
	lv_obj_t *Home_tileview_1_preformance_monitor;
	lv_obj_t *Home_tileview_1_ha_table;
	lv_obj_t *Home_time_monitor;
	lv_obj_t *Home_time_monitor_label;
	lv_obj_t *Home_digital_clock_time;
	lv_obj_t *Home_weekday;
	lv_obj_t *Home_date;
	lv_obj_t *Home_net_monitor;
	lv_obj_t *Home_net_speed;
	lv_obj_t *Home_download_data;
	lv_span_t *Home_download_data_span;
	lv_obj_t *Home_download_icon;
	lv_obj_t *Home_upload_data;
	lv_span_t *Home_upload_data_span;
	lv_obj_t *Home_upload_icon;
	lv_obj_t *Home_net_monitor_label;
	lv_obj_t *Home_ip_data;
	lv_obj_t *Home_ip_label;
	lv_obj_t *Home_net_ping;
	lv_span_t *Home_net_ping_span;
	lv_obj_t *Home_net_ping_label;
	lv_obj_t *Home_cpu_monitor;
	lv_obj_t *Home_cpu_usage;
	lv_obj_t *Home_arc_2;
	lv_obj_t *Home_cpu_percent;
	lv_span_t *Home_cpu_percent_span;
	lv_obj_t *Home_cpu_monitor_label;
	lv_obj_t *Home_ram_slider;
	lv_obj_t *Home_ram_usage;
	lv_span_t *Home_ram_usage_span;
	lv_obj_t *Home_ram_label;
	lv_obj_t *Home_cpu_temp;
	lv_span_t *Home_cpu_temp_span;
	lv_obj_t *Home_cpu_temp_label;
	lv_obj_t *Home_cpu_frequency;
	lv_span_t *Home_cpu_frequency_span;
	lv_obj_t *Home_cpu_freq_label;
	lv_obj_t *Home_gpu_monitor;
	lv_obj_t *Home_gpu_usage;
	lv_obj_t *Home_arc_1;
	lv_obj_t *Home_gpu_percent;
	lv_span_t *Home_gpu_percent_span;
	lv_obj_t *Home_gpu_monitor_label;
	lv_obj_t *Home_gram_slider;
	lv_obj_t *Home_gram_usage;
	lv_span_t *Home_gram_usage_span;
	lv_obj_t *Home_gram_label;
	lv_obj_t *Home_gpu_temp;
	lv_span_t *Home_gpu_temp_span;
	lv_obj_t *Home_gpu_temp_label;
	lv_obj_t *Home_gpu_frequency;
	lv_span_t *Home_gpu_frequency_span;
	lv_obj_t *Home_gpu_freq_label;
	lv_obj_t *Home_perform_title;
	lv_obj_t *Home_cont_14;
	lv_obj_t *Home_bar_1;
	lv_obj_t *Home_label_47;
	lv_obj_t *Home_spangroup_8;
	lv_span_t *Home_spangroup_8_span;
	lv_obj_t *Home_cont_13;
	lv_obj_t *Home_label_46;
	lv_obj_t *Home_spangroup_7;
	lv_span_t *Home_spangroup_7_span;
	lv_obj_t *Home_label_45;
	lv_obj_t *Home_cont_12;
	lv_obj_t *Home_label_44;
	lv_obj_t *Home_spangroup_6;
	lv_span_t *Home_spangroup_6_span;
	lv_obj_t *Home_label_43;
	lv_obj_t *Home_cont_11;
	lv_obj_t *Home_sw_2;
	lv_obj_t *Home_label_42;
	lv_obj_t *Home_spangroup_5;
	lv_span_t *Home_spangroup_5_span;
	lv_obj_t *Home_cont_10;
	lv_obj_t *Home_sw_1;
	lv_obj_t *Home_label_41;
	lv_obj_t *Home_spangroup_4;
	lv_span_t *Home_spangroup_4_span;
	lv_obj_t *Home_cont_9;
	lv_obj_t *Home_label_40;
	lv_obj_t *Home_spangroup_3;
	lv_span_t *Home_spangroup_3_span;
	lv_obj_t *Home_slider_3;
	lv_obj_t *Home_label_39;
	lv_obj_t *Home_label_38;
	lv_obj_t *Home_btn_3;
	lv_obj_t *Home_btn_3_label;
	lv_obj_t *Home_btn_2;
	lv_obj_t *Home_btn_2_label;
	lv_obj_t *Home_btn_1;
	lv_obj_t *Home_btn_1_label;
	lv_obj_t *Home_cont_8;
	lv_obj_t *Home_spangroup_2;
	lv_span_t *Home_spangroup_2_span;
	lv_obj_t *Home_digital_clock_2;
	lv_obj_t *Home_spangroup_1;
	lv_span_t *Home_spangroup_1_span;
	lv_obj_t *Home_img_3;
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
	lv_obj_t *Monitor_dark_upload_icon;
	lv_obj_t *Monitor_dark_upload_label;
	lv_obj_t *Monitor_dark_upload_data;
	lv_obj_t *Monitor_dark_download_data;
	lv_obj_t *Monitor_dark_download_label;
	lv_obj_t *Monitor_dark_ip_data;
	lv_obj_t *Monitor_dark_ip_label;
	lv_obj_t *Monitor_dark_ping_data;
	lv_obj_t *Monitor_dark_ping_label;
	lv_obj_t *Monitor_dark_net_monitor_tit;
	lv_obj_t *Monitor_dark_ping_unit;
	lv_obj_t *Monitor_dark_cont_cpu_monitor;
	lv_obj_t *Monitor_dark_cpu_usage;
	lv_obj_t *Monitor_dark_arc_1;
	lv_obj_t *Monitor_dark_cpu_percent_label;
	lv_obj_t *Monitor_dark_cpu_percent;
	lv_obj_t *Monitor_dark_cpu_monitor_title;
	lv_obj_t *Monitor_dark_cpu_frequency_label;
	lv_obj_t *Monitor_dark_ram_label;
	lv_obj_t *Monitor_dark_ram_slider;
	lv_obj_t *Monitor_dark_cpu_temp_label;
	lv_obj_t *Monitor_dark_cpu_frequency_data;
	lv_obj_t *Monitor_dark_cpu_frequency_unit;
	lv_obj_t *Monitor_dark_cpu_temp_unit;
	lv_obj_t *Monitor_dark_cpu_temp_data;
	lv_obj_t *Monitor_dark_ram_unit;
	lv_obj_t *Monitor_dark_ram_data;
	lv_obj_t *Monitor_dark_cont_gpu_monitor;
	lv_obj_t *Monitor_dark_gpu_usage;
	lv_obj_t *Monitor_dark_arc_2;
	lv_obj_t *Monitor_dark_gpu_percent_label;
	lv_obj_t *Monitor_dark_gpu_percent;
	lv_obj_t *Monitor_dark_gpu_monitor_title;
	lv_obj_t *Monitor_dark_gpu_frequency_label;
	lv_obj_t *Monitor_dark_gram_label;
	lv_obj_t *Monitor_dark_gram_slider;
	lv_obj_t *Monitor_dark_gpu_temp_label;
	lv_obj_t *Monitor_dark_gpu_frequency_data;
	lv_obj_t *Monitor_dark_gpu_frequency_unit;
	lv_obj_t *Monitor_dark_gpu_temp_unit;
	lv_obj_t *Monitor_dark_gpu_temp_data;
	lv_obj_t *Monitor_dark_gram_unit;
	lv_obj_t *Monitor_dark_gram_data;
	lv_obj_t *Monitor_dark_label_home_title;
	lv_obj_t *Monitor_dark_menu;
	lv_obj_t *HA_dark;
	bool HA_dark_del;
	lv_obj_t *HA_dark_printer_card;
	lv_obj_t *HA_dark_bar_1;
	lv_obj_t *HA_dark_label_10;
	lv_obj_t *HA_dark_spangroup_8;
	lv_span_t *HA_dark_spangroup_8_span;
	lv_obj_t *HA_dark_temperature_card;
	lv_obj_t *HA_dark_label_9;
	lv_obj_t *HA_dark_spangroup_7;
	lv_span_t *HA_dark_spangroup_7_span;
	lv_obj_t *HA_dark_label_8;
	lv_obj_t *HA_dark_humidity_card;
	lv_obj_t *HA_dark_label_7;
	lv_obj_t *HA_dark_spangroup_6;
	lv_span_t *HA_dark_spangroup_6_span;
	lv_obj_t *HA_dark_label_6;
	lv_obj_t *HA_dark_switch_card_2;
	lv_obj_t *HA_dark_sw_4;
	lv_obj_t *HA_dark_label_5;
	lv_obj_t *HA_dark_spangroup_5;
	lv_span_t *HA_dark_spangroup_5_span;
	lv_obj_t *HA_dark_switch_card_1;
	lv_obj_t *HA_dark_sw_3;
	lv_obj_t *HA_dark_label_4;
	lv_obj_t *HA_dark_spangroup_4;
	lv_span_t *HA_dark_spangroup_4_span;
	lv_obj_t *HA_dark_ac_card;
	lv_obj_t *HA_dark_label_3;
	lv_obj_t *HA_dark_spangroup_3;
	lv_span_t *HA_dark_spangroup_3_span;
	lv_obj_t *HA_dark_slider_1;
	lv_obj_t *HA_dark_label_2;
	lv_obj_t *HA_dark_label_1;
	lv_obj_t *HA_dark_btn_3;
	lv_obj_t *HA_dark_btn_3_label;
	lv_obj_t *HA_dark_btn_2;
	lv_obj_t *HA_dark_btn_2_label;
	lv_obj_t *HA_dark_btn_1;
	lv_obj_t *HA_dark_btn_1_label;
	lv_obj_t *HA_dark_time_card;
	lv_obj_t *HA_dark_spangroup_2;
	lv_span_t *HA_dark_spangroup_2_span;
	lv_obj_t *HA_dark_digital_clock_1;
	lv_obj_t *HA_dark_spangroup_1;
	lv_span_t *HA_dark_spangroup_1_span;
	lv_obj_t *HA_dark_img_1;
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


void setup_scr_Home(lv_ui *ui);
void setup_scr_Monitor_dark(lv_ui *ui);
void setup_scr_HA_dark(lv_ui *ui);
LV_IMG_DECLARE(_download_alpha_13x13);
LV_IMG_DECLARE(_upload_alpha_13x13);

LV_IMG_DECLARE(_temperature_35x35);

LV_IMG_DECLARE(_humidity_35x35);
LV_IMG_DECLARE(_cloudy_alpha_60x60);
LV_IMG_DECLARE(_download_alpha_13x13);
LV_IMG_DECLARE(_upload_alpha_13x13);

LV_IMG_DECLARE(_temperature_35x35);

LV_IMG_DECLARE(_humidity_35x35);
LV_IMG_DECLARE(_cloudy_alpha_60x60);

LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_montserratMedium_17)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_35)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_montserratMedium_30)
LV_FONT_DECLARE(lv_font_montserratMedium_22)


#ifdef __cplusplus
}
#endif
#endif
