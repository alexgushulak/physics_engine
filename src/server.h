//
// Server.h
//
// Created by Alex Gushulak 3/5/2024
//

#ifndef Server_h
#define Server_h

#include <sys/socket.h>
#include <netinet/in.h>

struct Server
{
    int domain;
    int service;
    int protocol;
    in_addr_t interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    int socket;

    void (*launch)(struct Server *server);

};

struct Server server_constructor(int domain, int service, int protocol, in_addr_t interface, int port, int backlog, void (*launch)(struct Server *server));

#endif