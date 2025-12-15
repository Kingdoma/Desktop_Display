#ifndef HA_UI_H
#define HA_UI_H

#include <stdint.h>
#include <stdbool.h>
#include "generated/gui_guider.h"

#define HA_LAST_CHANGED_LEN 48

typedef struct {
    bool switch_on;
    // char state[16];
    char last_changed[HA_LAST_CHANGED_LEN];
} ha_ui_sw_t;

typedef struct {
    char weather[16];
    float temperature;
    char last_changed[HA_LAST_CHANGED_LEN];
} ha_ui_weather_t;

typedef struct {
    char mode[16];
    float temperature;
    char last_changed[HA_LAST_CHANGED_LEN];
} ha_ui_climate_t;

typedef struct {
    char data[16];
    char last_changed[HA_LAST_CHANGED_LEN];
} ha_ui_sensor_t;

typedef struct {
    char mode[16];
    char last_changed[HA_LAST_CHANGED_LEN];
} ha_ui_printer_t;

typedef struct {
    ha_ui_sw_t *sw_1;
    ha_ui_sw_t *sw_2;
    ha_ui_weather_t *weahter_card;
    ha_ui_climate_t *ac_card;
    ha_ui_sensor_t *hum_card;
    ha_ui_sensor_t *temp_card;
    ha_ui_printer_t *printer_card;
} ha_ui_element_t;

/* Shared HA state that can be read from the LVGL task. */
extern ha_ui_element_t *sync_data;

/* Allocate/reset sync_data so HA updates have a target buffer. */
void ha_ui_sync_data_init(void);

/* Provide LVGL UI pointer for HA updates. */
void ha_ui_set_ui(lv_ui *ui);

/* Update HA switch UI for the configured entity.
 * lvgl_id selects which switch card to update (1 or 2). */
void ha_ui_update_switch(uint8_t lvgl_id, const char *state, const char *last_changed);

void ha_ui_update_climate(uint8_t lvgl_id, const float temperature, const char *state, const char *last_changed);

void ha_ui_update_printer(uint8_t lvgl_id, const char *state, const char *last_changed);

void ha_ui_update_weather(const float temperature, const char *state, const char *last_changed);

void ha_ui_update_sensor(const char *state, const char *last_changed, int8_t type);

#endif /* HA_UI_H */
