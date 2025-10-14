#ifndef GUI_GUIDER_SUPPORT_H
#define GUI_GUIDER_SUPPORT_H

#include <stdint.h>
#include "lvgl.h"

lv_obj_t * lv_dclock_create(lv_obj_t * parent, const char * init_text);
void lv_dclock_set_text_fmt(lv_obj_t * obj, const char * fmt, ...);
void clock_count_24(int * hour, int * minute, int * second);
void clock_count_12(int * hour, int * minute, int * second, char meridiem[3]);
void guider_anim_pause(void * var, lv_anim_exec_xcb_t exec_cb);
void guider_anim_resume(void * var, lv_anim_exec_xcb_t exec_cb);
void guider_anim_exec_set_angle(void * var, int32_t value);
void guider_anim_exec_set_y(void * var, int32_t value);

#endif /* GUI_GUIDER_SUPPORT_H */
