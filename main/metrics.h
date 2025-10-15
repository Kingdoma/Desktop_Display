#ifndef METRICS_H
#define METRICS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define METRICS_PACKET_MAGIC   (0xA5U)
#define METRICS_PACKET_VERSION (0x01U)

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
} pc_metrics_packet_t;

typedef struct {
    float cpu_usage_percent;
    float cpu_temp_c;
    float cpu_freq_mhz;
    float gpu_usage_percent;
    float gpu_temp_c;
    float gpu_freq_mhz;
    float gram_usage_percent;
    float ram_usage_percent;
} system_metrics_t;

void metrics_queue_init(void);
bool metrics_decode_packet(const uint8_t *data, size_t len, system_metrics_t *out);
bool metrics_queue_push(const system_metrics_t *metrics);
bool metrics_queue_pop(system_metrics_t *out);

#ifdef __cplusplus
}
#endif

#endif /* METRICS_H */
