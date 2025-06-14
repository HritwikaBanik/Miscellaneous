// comm.c
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

    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);
    read(new_socket, buffer, 1024);
    printf("Client says: %s\n", buffer);
    send(new_socket, response, strlen(response), 0);
    close(new_socket);
    close(server_fd);
}

void run_client() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from client";
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(sock, message, strlen(message), 0);
    read(sock, buffer, 1024);
    printf("Server says: %s\n", buffer);
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [server|client]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "server") == 0) {
        run_server();
    } else if (strcmp(argv[1], "client") == 0) {
        run_client();
    } else {
        printf("Invalid option. Use 'server' or 'client'.\n");
        return 1;
    }

    return 0;
}