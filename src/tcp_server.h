//
// Created by me on 22.06.24.
//

#ifndef FALLOUT_LAMP_TCP_SERVER_H
#define FALLOUT_LAMP_TCP_SERVER_H


#include <pico/cyw43_arch.h>
#include "lwip/pbuf.h"
#include "lwip/tcp.h"

#define HTTP_PORT 80

#include <string.h>

#include "pico/cyw43_arch.h"
#include "pico/stdlib.h"

#include "lwip/pbuf.h"
#include "lwip/tcp.h"

#include "dhcpd/dhcpserver.h"
#include "dnsd/dnsserver.h"

#define TCP_PORT 80
#define DEBUG_printf printf
#define POLL_TIME_S 5
#define HTTP_GET "GET"
#define HTTP_RESPONSE_HEADERS "HTTP/1.1 %d OK\nContent-Length: %d\nContent-Type: text/html; charset=utf-8\nConnection: close\n\n"
#define LED_TEST_BODY "<html><body><h1>Hello from Fallout Lamp</h1><br /><h2>Lamp is %s</p><p><a href=\"?led=%d\">Turn led %s</h2></body></html>"
#define LED_PARAM "led=%d"
#define LED_TEST "/ledtest"
#define LED_GPIO 0
#define HTTP_RESPONSE_REDIRECT "HTTP/1.1 302 Redirect\nLocation: http://%s" LED_TEST "\n\n"

typedef struct TCP_SERVER_T_ {
    struct tcp_pcb *server_pcb;
    bool complete;
    ip_addr_t gw;
    async_context_t *context;
} TCP_SERVER_T;

typedef struct TCP_CONNECT_STATE_T_ {
    struct tcp_pcb *pcb;
    int sent_len;
    char headers[128];
    char result[256];
    int header_len;
    int result_len;
    ip_addr_t *gw;
} TCP_CONNECT_STATE_T;

int run_server();

static err_t tcp_server_poll(void *arg, struct tcp_pcb *pcb);

err_t tcp_server_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);

void key_pressed_func(void *param);

static void tcp_server_err(void *arg, err_t err);

static err_t tcp_server_accept(void *arg, struct tcp_pcb *client_pcb, err_t err);

static bool tcp_server_open(void *arg, const char *ap_name);

void key_pressed_worker_func(async_context_t *context, async_when_pending_worker_t *worker);

static int test_server_content(const char *request, const char *params, char *result, size_t max_result_len);

static err_t tcp_server_sent(void *arg, struct tcp_pcb *pcb, u16_t len);

static void tcp_server_close(TCP_SERVER_T *state);

static err_t tcp_close_client_connection(TCP_CONNECT_STATE_T *con_state, struct tcp_pcb *client_pcb, err_t close_err);

#endif //FALLOUT_LAMP_TCP_SERVER_H
