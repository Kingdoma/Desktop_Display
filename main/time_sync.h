#ifndef TIME_SYNC_H
#define TIME_SYNC_H

#include <stdbool.h>
#include "metrics.h"

#ifdef __cplusplus
extern "C" {
#endif

// sntp task
void sntp_task(void *arg);

// Update date/time fields in metrics using the current system clock
bool update_wall_clock(system_metrics_t *metrics);

#ifdef __cplusplus
}
#endif

#endif /* TIME_SYNC_H */
