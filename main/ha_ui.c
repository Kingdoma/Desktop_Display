#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "esp_log.h"
#include "lvgl.h"
#include "ha_ui.h"

#define HA_UI_TAG "ha_ui"

/* Backing storage for HA sync data that the LVGL task can read. */
static ha_ui_sw_t g_sw_1;
static ha_ui_sw_t g_sw_2;
static ha_ui_weather_t g_weather;
static ha_ui_climate_t g_ac;
static ha_ui_sensor_t g_hum;
static ha_ui_sensor_t g_temp;
static ha_ui_printer_t g_printer;
static ha_ui_element_t g_elements;

ha_ui_element_t *sync_data = NULL;

void ha_ui_sync_data_init(void)
{
    memset(&g_sw_1, 0, sizeof(g_sw_1));
    memset(&g_sw_2, 0, sizeof(g_sw_2));
    memset(&g_weather, 0, sizeof(g_weather));
    memset(&g_ac, 0, sizeof(g_ac));
    memset(&g_hum, 0, sizeof(g_hum));
    memset(&g_temp, 0, sizeof(g_temp));
    memset(&g_printer, 0, sizeof(g_printer));
    memset(&g_elements, 0, sizeof(g_elements));

    g_elements.sw_1 = &g_sw_1;
    g_elements.sw_2 = &g_sw_2;
    g_elements.weahter_card = &g_weather;
    g_elements.ac_card = &g_ac;
    g_elements.hum_card = &g_hum;
    g_elements.temp_card = &g_temp;
    g_elements.printer_card = &g_printer;

    sync_data = &g_elements;
}

void ha_ui_set_ui(lv_ui *ui)
{
    /* LVGL updates now live in custom.c; keep hook for compatibility. */
    (void)ui;
}

void ha_ui_update_switch(uint8_t lvgl_id, const char *state, const char *last_changed)
{
    if (!state || !sync_data) {
        return;
    }

    const bool is_on = (state[0] == 'o' || state[0] == 'O') && (state[1] == 'n' || state[1] == 'N');
    ha_ui_sw_t *target = NULL;
    switch (lvgl_id) {
    case 1:
        target = sync_data->sw_1;
        break;
    case 2:
        target = sync_data->sw_2;
        break;
    default:
        ESP_LOGW(HA_UI_TAG, "entry is not defined in sync_data");
        return;
    }

    if (!target) {
        return;
    }

    target->switch_on = is_on;
    if (last_changed && last_changed[0]) {
        strlcpy(target->last_changed, last_changed, sizeof(target->last_changed));
    } else {
        target->last_changed[0] = '\0';
    }
}

void ha_ui_update_climate(uint8_t lvgl_id, const float temperature, const char *state, const char *last_changed)
{
    (void)lvgl_id;
    if (!state || !sync_data || !sync_data->ac_card) {
        return;
    }

    sync_data->ac_card->temperature = temperature;
    strlcpy(sync_data->ac_card->mode, state, sizeof(sync_data->ac_card->mode));
    if (last_changed && last_changed[0]) {
        strlcpy(sync_data->ac_card->last_changed, last_changed, sizeof(sync_data->ac_card->last_changed));
    } else {
        sync_data->ac_card->last_changed[0] = '\0';
    }
}

void ha_ui_update_printer(uint8_t lvgl_id, const char *state, const char *last_changed)
{
    (void)lvgl_id;
    if (!state || !sync_data || !sync_data->printer_card) {
        return;
    }

    strlcpy(sync_data->printer_card->mode, state, sizeof(sync_data->printer_card->mode));
    if (last_changed && last_changed[0]) {
        strlcpy(sync_data->printer_card->last_changed, last_changed, sizeof(sync_data->printer_card->last_changed));
    } else {
        sync_data->printer_card->last_changed[0] = '\0';
    }
}

void ha_ui_update_weather(const float temperature, const char *state, const char *last_changed)
{
    if (!state || !sync_data || !sync_data->weahter_card) {
        return;
    }

    sync_data->weahter_card->temperature = temperature;
    strlcpy(sync_data->weahter_card->weather, state, sizeof(sync_data->weahter_card->weather));
    if (last_changed && last_changed[0]) {
        strlcpy(sync_data->weahter_card->last_changed, last_changed, sizeof(sync_data->weahter_card->last_changed));
    } else {
        sync_data->weahter_card->last_changed[0] = '\0';
    }
}

void ha_ui_update_sensor(const char *state, const char *last_changed, int8_t type)
{
    if (!state || !sync_data) {
        return;
    }

    ha_ui_sensor_t *target = NULL;
    switch (type) {
    case 1:
        target = sync_data->hum_card;
        break;
    case 2:
        target = sync_data->temp_card;
        break;
    default:
        ESP_LOGW(HA_UI_TAG, "entry is not defined in sync_data");
        return;
    }

    if (!target) {
        return;
    }

    strlcpy(target->data, state, sizeof(target->data));
    if (last_changed && last_changed[0]) {
        strlcpy(target->last_changed, last_changed, sizeof(target->last_changed));
    } else {
        target->last_changed[0] = '\0';
    }
}
