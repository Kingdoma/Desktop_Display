#ifndef HA_SETTINGS_H
#define HA_SETTINGS_H

#include <stdbool.h>
#include <stdint.h>

#define HA_SETTINGS_MAX_URL 128
#define HA_SETTINGS_MAX_TOKEN 256
#define HA_SETTINGS_MAX_SNTP_SERVER 64
#define HA_SETTINGS_MAX_TIME_ZONE 64
#define HA_SETTINGS_MAX_ENTITY_ID 64
#define HA_SETTINGS_EXTRA_COUNT 5

typedef struct {
    char base_url[HA_SETTINGS_MAX_URL];
    char auth_token[HA_SETTINGS_MAX_TOKEN];
    uint32_t poll_interval_ms;
    char sntp_server[HA_SETTINGS_MAX_SNTP_SERVER];
    char time_zone[HA_SETTINGS_MAX_TIME_ZONE];
    char entity_switch_1[HA_SETTINGS_MAX_ENTITY_ID];
    char entity_switch_2[HA_SETTINGS_MAX_ENTITY_ID];
    char entity_ac[HA_SETTINGS_MAX_ENTITY_ID];
    char entity_weather[HA_SETTINGS_MAX_ENTITY_ID];
    char entity_extra[HA_SETTINGS_EXTRA_COUNT][HA_SETTINGS_MAX_ENTITY_ID];
} ha_settings_t;

void ha_settings_init(void);
const ha_settings_t *ha_settings_get(void);
bool ha_settings_save(const ha_settings_t *settings);

#endif /* HA_SETTINGS_H */
