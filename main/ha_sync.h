// Home Assistant sync helper (WebSocket + REST).
#pragma once

#include "esp_err.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ha_state_cb_t)(const char *state, void *user_ctx);

typedef struct {
    const char *entity_id;       // e.g. "switch.office_light"
    ha_state_cb_t on_remote_state;
    void *user_ctx;
} ha_entity_config_t;

typedef struct {
    const char *base_url;        // e.g. "http://ha.local:8123"
    const char *auth_token;      // Long-lived token (without "Bearer " prefix)
    uint32_t poll_interval_ms;   // How often to fetch remote state for all entities
    const ha_entity_config_t *entities;
    size_t entity_count;
} ha_sync_config_t;

// Start the HA sync task. Safe to call once; returns ESP_ERR_INVALID_STATE if already running.
esp_err_t ha_sync_start(const ha_sync_config_t *config);

// Enqueue a local state change to push to HA for the specified entity.
esp_err_t ha_sync_set_local_state(const char *entity_id, const char *state);

#ifdef __cplusplus
}
#endif
