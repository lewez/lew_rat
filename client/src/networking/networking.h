#ifndef NETWORKING_H
#define NETWORKING_H

#include <winsock2.h>
#include "constants.h"
#include "util/util.h"

#include "payload/client_payload_callback.h"
#include "payload/payloads/system.h"

#pragma comment(lib, "ws2_32.lib")

extern int init_networking();
extern int init_socket(SOCKET* socket_out);
extern int init_listen_socket(SOCKET* socket_out);
extern int on_connected_listen_socket(SOCKET* p_socket_server);
extern void listen_on_socket();

#endif
