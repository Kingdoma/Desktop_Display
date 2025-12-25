#ifndef WIFI_H
#define WIFI_H

#include <string.h>
#include <stdlib.h>
#include "app_main.h"

void wifi_connect(void);

void wifi_setting_clear();

void wifi_diconnect();

void wifi_reconnect();

const char *wifi_get_ip(void);

#endif /* WIFI_H */
