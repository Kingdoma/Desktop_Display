#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <stdbool.h>

void web_server_start(void);
void web_server_stop(void);
bool web_server_is_running(void);

#endif /* WEB_SERVER_H */
