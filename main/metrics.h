#ifndef METRICS_H
#define METRICS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define METRICS_PACKET_MAGIC   (0xA5U)
#define METRICS_PACKET_VERSION (0x02U)

typedef struct __attribute__((packed)) {
    uint8_t magic;
    uint8_t version;
    uint16_t cpu_usage_tenths;
    int16_t cpu_temp_tenths;
    uint16_t cpu_freq_mhz;
    uint16_t gpu_usage_tenths;
    int16_t gpu_temp_tenths;
    uint16_t gpu_freq_mhz;
    uint16_t gram_usage_tenths;
    uint16_t ram_usage_tenths;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t day_of_week;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} pc_metrics_packet_t;

typedef struct {
    float cpu_usage_percent;
    float cpu_temp_c;
    float cpu_freq_ghz;
    float gpu_usage_percent;
    float gpu_temp_c;
    float gpu_freq_mhz;
    float gram_usage_percent;
    float ram_usage_percent;
    uint16_t year;
    uint8_t month;
    uint8_t day;
    int8_t day_of_week;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    bool has_date;
    bool has_time;
    bool has_day_of_week;
} system_metrics_t;

void metrics_queue_init(void);
bool metrics_decode_packet(const uint8_t *data, size_t len, system_metrics_t *out);
bool metrics_queue_push(const system_metrics_t *metrics);
bool metrics_queue_pop(system_metrics_t *out);

#ifdef __cplusplus
}
#endif

#endif /* METRICS_H */
