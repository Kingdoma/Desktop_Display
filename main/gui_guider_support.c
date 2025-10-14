#include "gui_guider_support.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

lv_obj_t * lv_dclock_create(lv_obj_t * parent, const char * init_text)
{
    lv_obj_t * label = lv_label_create(parent);
    if(label == NULL) {
        return NULL;
    }
    if(init_text != NULL) {
        lv_label_set_text(label, init_text);
    }
    return label;
}

void lv_dclock_set_text_fmt(lv_obj_t * obj, const char * fmt, ...)
{
    if(obj == NULL || fmt == NULL) {
        return;
    }

    char buffer[32];
    va_list args;
    va_start(args, fmt);
    int written = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    if(written < 0) {
        return;
    }
    buffer[sizeof(buffer) - 1] = '\0';
    lv_label_set_text(obj, buffer);
}

void clock_count_24(int * hour, int * minute, int * second)
{
    if(hour == NULL || minute == NULL || second == NULL) {
        return;
    }

    (*second)++;
    if(*second >= 60) {
        *second = 0;
        (*minute)++;
    }
    if(*minute >= 60) {
        *minute = 0;
        (*hour)++;
    }
    if(*hour >= 24) {
        *hour = 0;
    }
}

void clock_count_12(int * hour, int * minute, int * second, char meridiem[3])
{
    if(hour == NULL || minute == NULL || second == NULL || meridiem == NULL) {
        return;
    }

    (*second)++;
    if(*second >= 60) {
        *second = 0;
        (*minute)++;
    }
    if(*minute >= 60) {
        *minute = 0;
        (*hour)++;
    }

    if(*hour > 12) {
        *hour -= 12;
    }

    if(*hour == 12 && *minute == 0 && *second == 0) {
        if(strncmp(meridiem, "AM", 2) == 0) {
            meridiem[0] = 'P';
            meridiem[1] = 'M';
        } else {
            meridiem[0] = 'A';
            meridiem[1] = 'M';
        }
    }

    if(*hour == 0) {
        *hour = 12;
        meridiem[0] = 'A';
        meridiem[1] = 'M';
    }

    meridiem[2] = '\0';
}

void guider_anim_pause(void * var, lv_anim_exec_xcb_t exec_cb)
{
    if(var == NULL) {
        return;
    }
    lv_anim_del(var, exec_cb);
}

void guider_anim_resume(void * var, lv_anim_exec_xcb_t exec_cb)
{
    LV_UNUSED(var);
    LV_UNUSED(exec_cb);
    /* Animations are re-created explicitly by GUI Guider callbacks. */
}

void guider_anim_exec_set_angle(void * var, int32_t value)
{
    if(var == NULL) {
        return;
    }
    lv_img_set_angle((lv_obj_t *)var, (int16_t)value);
}

void guider_anim_exec_set_y(void * var, int32_t value)
{
    if(var == NULL) {
        return;
    }
    lv_obj_set_y((lv_obj_t *)var, (lv_coord_t)value);
}
