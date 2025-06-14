#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

void run_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *response = "Hello from server";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Server listening...\n");

    new_socket = accept(server_fd, (struct sockaddr )&address, (socklen_t)&addrlen);
    read(new_socket, buffer, 1024);
    printf("Client says: %s\n", buffer);
    send(new_socket, response, strlen(response), 0);
    close(new_socket);
    close(server_fd);
}
