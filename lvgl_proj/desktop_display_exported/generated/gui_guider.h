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
	lv_obj_t *Home_cont_time;
	lv_obj_t *Home_digital_clock_time;
	lv_obj_t *Home_datetext_date;
	lv_obj_t *Home_time_title;
	lv_obj_t *Home_weekday;
	lv_obj_t *Home_cont_net;
	lv_obj_t *Home_speed_info;
	lv_obj_t *Home_download_icon;
	lv_obj_t *Home_upload_icon;
	lv_obj_t *Home_speed_label;
	lv_obj_t *Home_upload_data;
	lv_obj_t *Home_download_data;
	lv_obj_t *Home_label_8;
	lv_obj_t *Home_ip_data;
	lv_obj_t *Home_ip_label;
	lv_obj_t *Home_ping_data;
	lv_obj_t *Home_Ping_label;
	lv_obj_t *Home_net_monitor_tit;
	lv_obj_t *Home_ping_unit;
	lv_obj_t *Home_cont_cpu_monitor;
	lv_obj_t *Home_cpu_usage;
	lv_obj_t *Home_arc_1;
	lv_obj_t *Home_cpu_percent_label;
	lv_obj_t *Home_cpu_percent;
	lv_obj_t *Home_cpu_monitor_title;
	lv_obj_t *Home_cpu_fequency_label;
	lv_obj_t *Home_ram_label;
	lv_obj_t *Home_ram_slider;
	lv_obj_t *Home_cpu_temp_label;
	lv_obj_t *Home_cpu_fequency_data;
	lv_obj_t *Home_cpu_fequency_unit;
	lv_obj_t *Home_cpu_temp_unit;
	lv_obj_t *Home_cpu_temp_data;
	lv_obj_t *Home_ram_unit;
	lv_obj_t *Home_ram_data;
	lv_obj_t *Home_cont_gpu_monitor;
	lv_obj_t *Home_cont_2;
	lv_obj_t *Home_arc_2;
	lv_obj_t *Home_label_20;
	lv_obj_t *Home_label_19;
	lv_obj_t *Home_label_18;
	lv_obj_t *Home_label_17;
	lv_obj_t *Home_label_16;
	lv_obj_t *Home_slider_1;
	lv_obj_t *Home_label_15;
	lv_obj_t *Home_label_14;
	lv_obj_t *Home_label_13;
	lv_obj_t *Home_label_12;
	lv_obj_t *Home_label_11;
	lv_obj_t *Home_label_10;
	lv_obj_t *Home_label_9;
	lv_obj_t *Home_label_home_title;
	lv_obj_t *Home_btn_menu;
	lv_obj_t *Home_btn_menu_label;
	lv_obj_t *Home_cont_menu;
	lv_obj_t *Home_img_tick;
	lv_obj_t *Home_btn_phone;
	lv_obj_t *Home_btn_phone_label;
	lv_obj_t *Home_btn_warning;
	lv_obj_t *Home_btn_warning_label;
	lv_obj_t *Home_btn_power;
	lv_obj_t *Home_btn_power_label;
	lv_obj_t *Home_btn_temp;
	lv_obj_t *Home_btn_temp_label;
	lv_obj_t *Home_btn_link;
	lv_obj_t *Home_btn_link_label;
	lv_obj_t *Home_btn_safe;
	lv_obj_t *Home_btn_safe_label;
	lv_obj_t *Home_btn_light;
	lv_obj_t *Home_btn_light_label;
	lv_obj_t *Home_label_monitor;
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
LV_IMG_DECLARE(_download_alpha_13x13);
LV_IMG_DECLARE(_upload_alpha_13x13);

LV_IMG_DECLARE(_home_bak_27x56);

LV_IMG_DECLARE(_menu_bak_480x320);
LV_IMG_DECLARE(_menu_bal_alpha_192x192);

LV_IMG_DECLARE(_menu_air_54x54);

LV_IMG_DECLARE(_menu_anfang_54x54);

LV_IMG_DECLARE(_menu_elevator_54x54);

LV_IMG_DECLARE(_menu_tem_54x54);

LV_IMG_DECLARE(_menu_xiaofang_54x54);

LV_IMG_DECLARE(_menu_electricity_54x54);

LV_IMG_DECLARE(_menu_light_54x54);

LV_FONT_DECLARE(lv_font_montserratMedium_17)
LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_montserratMedium_13)
LV_FONT_DECLARE(lv_font_montserratMedium_14)
LV_FONT_DECLARE(lv_font_montserratMedium_35)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_10)


#ifdef __cplusplus
}
#endif
#endif
