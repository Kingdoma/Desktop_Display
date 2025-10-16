#include "metrics.h"

#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

#define METRICS_QUEUE_LENGTH 1

static QueueHandle_t s_metrics_queue;

void metrics_queue_init(void)
{
    if (!s_metrics_queue) {
        s_metrics_queue = xQueueCreate(METRICS_QUEUE_LENGTH, sizeof(system_metrics_t));
    }
}

static inline float tenths_to_float(int16_t value)
{
    return (float)value / 10.0f;
}

bool metrics_decode_packet(const uint8_t *data, size_t len, system_metrics_t *out)
{
    if (!data || !out) {
        return false;
    }

    if (len != sizeof(pc_metrics_packet_t)) {
        return false;
    }

    const pc_metrics_packet_t *packet = (const pc_metrics_packet_t *)data;

    if (packet->magic != METRICS_PACKET_MAGIC || packet->version != METRICS_PACKET_VERSION) {
        return false;
    }

    memset(out, 0, sizeof(*out));

    out->cpu_usage_percent = (float)packet->cpu_usage_tenths / 10.0f;
    out->cpu_temp_c = tenths_to_float(packet->cpu_temp_tenths);
    out->cpu_freq_ghz = (float)packet->cpu_freq_mhz / 1000.0f;
    out->gpu_usage_percent = (float)packet->gpu_usage_tenths / 10.0f;
    out->gpu_temp_c = tenths_to_float(packet->gpu_temp_tenths);
    out->gpu_freq_mhz = (float)packet->gpu_freq_mhz;
    out->gram_usage_percent = (float)packet->gram_usage_tenths / 10.0f;
    out->ram_usage_percent = (float)packet->ram_usage_tenths / 10.0f;

    return true;
}

bool metrics_queue_push(const system_metrics_t *metrics)
{
    if (!metrics) {
        return false;
    }

    metrics_queue_init();
    if (!s_metrics_queue) {
        return false;
    }

    if (xQueueSend(s_metrics_queue, metrics, 0) == pdPASS) {
        return true;
    }

    system_metrics_t dropped;
    (void)xQueueReceive(s_metrics_queue, &dropped, 0);
    return xQueueSend(s_metrics_queue, metrics, 0) == pdPASS;
}

bool metrics_queue_pop(system_metrics_t *out)
{
    if (!out) {
        return false;
    }

    metrics_queue_init();
    if (!s_metrics_queue) {
        return false;
    }

    return xQueueReceive(s_metrics_queue, out, 0) == pdPASS;
}
