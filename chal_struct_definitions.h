#ifndef _CHAL_STRUCT_DEFINITIONS_H
#define _CHAL_STRUCT_DEFINITIONS_H

#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef struct {
    int socket_fd;
    struct sockaddr_in server_address;
} os_udp_server_t;

#endif