#include "server.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void launch(struct Server *server) {
    char buffer[30000];
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>This is a Server, Truth Be Told</h1></body></html>";
    while (1) 
    {
        printf("====== WAITING FOR CONNECTIONS ======\n");
        int address_length = sizeof(server->address);
        int new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t*)&address_length);
        read(new_socket, buffer, 30000);
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}

int main() {
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
}