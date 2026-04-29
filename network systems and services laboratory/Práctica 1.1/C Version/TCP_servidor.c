#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define BACKLOG 5

int create_socket(const char *ip) {
    int sock;
    if (strchr(ip, ':')) {
        sock = socket(AF_INET6, SOCK_STREAM, 0);
    } else {
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }
    if (sock < 0) {
        perror("Error al crear el socket");
        return -1;
    }
    return sock;
}

void tcp_server(const char *ip, int port) {
    int server_sock = create_socket(ip);
    if (server_sock < 0) return;
    
    struct sockaddr_in6 server_addr6;
    struct sockaddr_in server_addr;
    struct sockaddr *server_ptr;
    socklen_t addr_len;
    
    if (strchr(ip, ':')) {
        memset(&server_addr6, 0, sizeof(server_addr6));
        server_addr6.sin6_family = AF_INET6;
        server_addr6.sin6_port = htons(port);
        server_addr6.sin6_addr = in6addr_any;
        server_ptr = (struct sockaddr *)&server_addr6;
        addr_len = sizeof(server_addr6);
    } else {
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_ptr = (struct sockaddr *)&server_addr;
        addr_len = sizeof(server_addr);
    }
    
    if (bind(server_sock, server_ptr, addr_len) < 0) {
        perror("Error en bind");
        close(server_sock);
        return;
    }
    
    if (listen(server_sock, BACKLOG) < 0) {
        perror("Error en listen");
        close(server_sock);
        return;
    }
    
    printf("Servidor TCP escuchando en %s:%d\n", ip, port);
    while (1) {
        struct sockaddr_in6 client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Error en accept");
            continue;
        }
        
        char buffer[BUFFER_SIZE];
        ssize_t recv_len = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (recv_len > 0) {
            buffer[recv_len] = '\0';
            printf("Mensaje recibido: %s\n", buffer);
            send(client_sock, buffer, recv_len, 0);
        }
        close(client_sock);
    }
    close(server_sock);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <IP> <Puerto>\n", argv[0]);
        return 1;
    }
    tcp_server(argv[1], atoi(argv[2]));
    return 0;
}
