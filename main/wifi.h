#ifndef WIFI_H
#define WIFI_H

#include <string.h>
#include <stdlib.h>
#include "app_main.h"

#define ADVANCED_WIFI_SETTING

#ifdef ADVANCED_WIFI_SETTING
// Override these for your network when enabling static IP.
#ifndef ADVANCED_WIFI_IP
#define ADVANCED_WIFI_IP "192.168.110.191"
#endif
#ifndef ADVANCED_WIFI_GATEWAY
#define ADVANCED_WIFI_GATEWAY "192.168.110.2"
#endif
#ifndef ADVANCED_WIFI_NETMASK
#define ADVANCED_WIFI_NETMASK "255.255.255.0"
#endif
#endif

void wifi_connect(void);

void wifi_setting_clear();

void wifi_diconnect();

void wifi_reconnect();

const char *wifi_get_ip(void);

#endif /* WIFI_H */
