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
#include "metrics.h"
#include "ha_sync.h"

extern int Monitor_dark_digital_clock_time_hour_value;
extern int Monitor_dark_digital_clock_time_min_value;
extern int Monitor_dark_digital_clock_time_sec_value;
extern char Monitor_dark_digital_clock_time_meridiem[3];
extern int HA_dark_digital_clock_time_min_value;
extern int HA_dark_digital_clock_time_hour_value;
extern int HA_dark_digital_clock_time_sec_value;

void custom_init(lv_ui *ui);
void custom_update_metrics(lv_ui *ui, const system_metrics_t *metrics);
void custom_update_ha_state(lv_ui *ui, const ha_state_t *state);
void custom_handle_switch(uint8_t index, bool on);
void custom_handle_ac_mode(ha_climate_mode_t mode);
void custom_handle_ac_target_temp(int32_t temp_c);
void custom_handle_printer_progress(int32_t progress);
void scrollable_disable(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
