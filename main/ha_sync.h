#ifndef HA_SYNC_H
#define HA_SYNC_H

#include <stdbool.h>
#include <stdint.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HA_CLIMATE_MODE_OFF = 0,
    HA_CLIMATE_MODE_COOL,
    HA_CLIMATE_MODE_HEAT,
} ha_climate_mode_t;

typedef struct {
    bool mqtt_connected;
    bool has_temperature;
    float temperature_c;
    bool has_humidity;
    float humidity_percent;
    bool has_switch1;
    bool switch1_on;
    bool has_switch2;
    bool switch2_on;
    bool has_printer_progress;
    float printer_progress;
    bool has_climate_mode;
    ha_climate_mode_t climate_mode;
    bool has_target_temp;
    float target_temp_c;
} ha_state_t;

/**
 * @brief Start MQTT client and subscriptions for Home Assistant entity syncing.
 */
void ha_sync_start(void);

/**
 * @brief Create the HA sync task (safe to call multiple times).
 */
void ha_sync_task_start(void);

/**
 * @brief Pop the latest HA state update (if any).
 *
 * @param[out] out Filled with the most recent state on success.
 * @return true if a state was returned, false if the queue was empty.
 */
bool ha_sync_state_pop(ha_state_t *out);

/**
 * @brief Publish a switch command.
 *
 * @param index Switch index (1 or 2).
 * @param on Desired state.
 */
esp_err_t ha_sync_publish_switch(uint8_t index, bool on);

/**
 * @brief Publish a climate mode command.
 */
esp_err_t ha_sync_publish_climate_mode(ha_climate_mode_t mode);

/**
 * @brief Publish a climate target temperature command (in Celsius).
 */
esp_err_t ha_sync_publish_climate_temp(float temp_c);

/**
 * @brief Publish a printer progress/target value (0-100).
 */
esp_err_t ha_sync_publish_printer_progress(float progress);

#ifdef __cplusplus
}
#endif

#endif /* HA_SYNC_H */
