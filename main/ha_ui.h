#ifndef HA_UI_H
#define HA_UI_H

#include "generated/gui_guider.h"

/* Provide LVGL UI pointer for HA updates. */
void ha_ui_set_ui(lv_ui *ui);

/* Update HA switch UI for the configured entity. */
void ha_ui_update_switch(const char *state, const char *last_changed);

#endif /* HA_UI_H */
