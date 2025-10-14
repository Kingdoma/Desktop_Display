/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "gui_guider.h"

void custom_init(lv_ui *ui);
void home_timer_cb(lv_timer_t * t);
void chart_line_timer_cb(lv_timer_t * t);
void firefighting_timer_cb(lv_timer_t * t);
void electricity_timer_cb(lv_timer_t * t);

/* Compatibility helpers for GUI Guider generated code */
lv_obj_t * lv_dclock_create(lv_obj_t * parent, const char * init_text);
void lv_dclock_set_text_fmt(lv_obj_t * obj, const char * fmt, ...);
void clock_count_24(int * hour, int * minute, int * second);
void guider_anim_pause(void * var, lv_anim_exec_xcb_t exec_cb);
void guider_anim_resume(void * var, lv_anim_exec_xcb_t exec_cb);
void guider_anim_exec_set_angle(void * var, int32_t value);
void guider_anim_exec_set_y(void * var, int32_t value);


#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
