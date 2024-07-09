/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _DNSSERVER_H_
#define _DNSSERVER_H_

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>

#include <lwip/udp.h>
#include "lwip/ip_addr.h"

typedef struct dns_server_t_ {
    struct udp_pcb *udp;
     ip_addr_t ip;
} dns_server_t;

void dns_server_init(dns_server_t *d, ip_addr_t *ip);
void dns_server_deinit(dns_server_t *d);
static int dns_socket_new_dgram(struct udp_pcb **udp, void *cb_data, udp_recv_fn cb_udp_recv);
static int dns_socket_bind(struct udp_pcb **udp, uint32_t ip, uint16_t port);
static int dns_socket_sendto(struct udp_pcb **udp, const void *buf, size_t len, const ip_addr_t *dest, uint16_t port);
static void dns_server_process(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *src_addr, u16_t src_port);


#endif
