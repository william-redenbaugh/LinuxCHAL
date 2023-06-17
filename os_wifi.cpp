#include "global_includes.h"
#include<stdio.h>	//printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <unistd.h>

#define DEBUG_WIFI

#ifdef DEBUG_WIFI
#define wifi_println(e)       println(e)
#define wifi_print(e)         print(e)
#define wifi_printf(e, ...)   printf(e)
#endif

int os_wifi_connect_sta(char *ssid, char *password) {
  return OS_RET_OK;
}

int os_wifi_disconnect_sta() {
  return OS_RET_OK;
}

os_udp_server_t *os_wifi_setup_udp_server(int port) {

  os_udp_server_t *udp = (os_udp_server_t*)malloc(sizeof(os_udp_server_t));
  if (udp == NULL) {
      return NULL;  // Failed to allocate memory
  }

  // Create socket
  udp->socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp->socket_fd < 0) {
      free(udp);
      return NULL;  // Failed to create socket
  }

  // Set up server address
  memset(&udp->server_address, 0, sizeof(struct sockaddr_in));
  udp->server_address.sin_family = AF_INET;
  udp->server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  udp->server_address.sin_port = htons(port);

  // Bind socket to server address
  if (bind(udp->socket_fd, (struct sockaddr *)&udp->server_address, sizeof(struct sockaddr_in)) < 0) {
      close(udp->socket_fd);
      free(udp);
      return NULL;  // Failed to bind socket
  }

  return udp;
}

int os_wifi_deconstruct_udp_server(os_udp_server_t *udp){
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  close(udp->socket_fd);
  free(udp);

  return OS_RET_OK;
}

int os_wifi_start_udp_transmission(os_udp_server_t *udp, char *ip, uint16_t port) {

  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  if(ip == NULL){
    return OS_RET_INVALID_PARAM;
  }

  struct sockaddr_in dest_addr;
  memset(&dest_addr, 0, sizeof(struct sockaddr_in));
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, ip, &(dest_addr.sin_addr)) <= 0) {
    return OS_RET_INVALID_PARAM;
  }

  if (connect(udp->socket_fd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr_in)) < 0) {
    return OS_RET_TIMEOUT;
  }

  return OS_RET_OK;
}

int os_wifi_stop_udp_transmission(os_udp_server_t *udp) {
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  // Disconnect the socket
  if (connect(udp->socket_fd, NULL, 0) < 0) {
    return OS_RET_INT_ERR;
  }

  return OS_RET_OK;
}

int os_wifi_transmit_udp_packet(os_udp_server_t *udp, uint16_t packet_size, uint8_t *arr) {
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }
  ssize_t bytes_sent = send(udp->socket_fd, arr, packet_size, 0);
  if (bytes_sent < 0) {
      return OS_RET_INT_ERR;
  }

  return OS_RET_OK;
}

int os_wifi_receive_packet(os_udp_server_t *udp, uint16_t *packet_size, uint8_t *arr, uint32_t timeout_ms) {
  if(udp == NULL || packet_size == NULL || arr == NULL){
    return OS_RET_NULL_PTR;
  }

  struct timeval timeout;
  timeout.tv_sec = timeout_ms / 1000;
  timeout.tv_usec = (timeout_ms % 1000) * 1000;

  setsockopt(udp->socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));

  ssize_t bytes_received = recv(udp->socket_fd, arr, *packet_size, 0);
  if (bytes_received < 0) {
    return OS_RET_INT_ERR;  // Receiving failed
  }

  *packet_size = bytes_received;
  return OS_RET_NO_AVAILABLE_DATA;
}

int os_wifi_receive_packet_indefinite(os_udp_server_t *udp, uint16_t *packet_size, uint8_t *arr){
  if(udp == NULL){
    return OS_RET_NULL_PTR;
  }

  struct timeval timeout;
  timeout.tv_sec = 0;
  timeout.tv_usec = 0;

  setsockopt(udp->socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));

  ssize_t bytes_received = recv(udp->socket_fd, arr, *packet_size, 0);
  if (bytes_received < 0) {
    return OS_RET_INT_ERR;  // Receiving failed
  }

  *packet_size = bytes_received;
  return OS_RET_NO_AVAILABLE_DATA;
}