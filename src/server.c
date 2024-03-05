//
// Server.c
//
// Created by Alex Gushulak 3/5/2024
//

#include "server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, in_addr_t interface, int port, int backlog, void(*launch)(struct Server *server)) {

    struct Server server;

    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interface = interface;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interface);

    server.socket = socket(domain, service, protocol);
    if (server.socket == 0) {
        perror("Failed to connect to socket");
        exit(1);
    } 

    if((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0) {
        perror("Failed to bind to socket");
        exit(1);
    }

    if((listen(server.socket, server.backlog)) < 0) {
        perror("Failed to listen to socket");
        exit(1);
    }

    server.launch = launch;

    return server;
}