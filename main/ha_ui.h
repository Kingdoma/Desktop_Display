#ifndef HA_UI_H
#define HA_UI_H

#include <stdint.h>
#include "generated/gui_guider.h"

/* Provide LVGL UI pointer for HA updates. */
void ha_ui_set_ui(lv_ui *ui);

/* Update HA switch UI for the configured entity.
 * lvgl_id selects which switch card to update (1 or 2). */
void ha_ui_update_switch(uint8_t lvgl_id, const char *state, const char *last_changed);

void ha_ui_update_climate(const char *state, const char *last_changed, uint8_t lvgl_id);

void ha_ui_update_printer(const char *state, const char *last_changed, uint8_t lvgl_id);

void ha_ui_update_weather(const float temperature, const char *state, const char *last_changed);

#endif /* HA_UI_H */
