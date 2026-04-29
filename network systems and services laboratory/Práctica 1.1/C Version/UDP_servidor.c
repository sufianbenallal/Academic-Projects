#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

typedef struct sockaddr_in6 sockaddr_in6;
typedef struct sockaddr_in sockaddr_in;

typedef struct sockaddr sockaddr;

int create_socket(const char *ip) {
    int sock;
    if (strchr(ip, ':')) { // IPv6
        sock = socket(AF_INET6, SOCK_DGRAM, 0);
    } else { // IPv4
        sock = socket(AF_INET, SOCK_DGRAM, 0);
    }
    if (sock < 0) {
        perror("Error al crear el socket");
        return -1;
    }
    return sock;
}

void udp_server(const char *ip, int port) {
    int sock = create_socket(ip);
    if (sock < 0) return;
    
    sockaddr_in6 server_addr6;
    sockaddr_in server_addr;
    sockaddr *server_ptr;
    socklen_t addr_len;
    
    if (strchr(ip, ':')) { // IPv6
        memset(&server_addr6, 0, sizeof(server_addr6));
        server_addr6.sin6_family = AF_INET6;
        server_addr6.sin6_port = htons(port);
        server_addr6.sin6_addr = in6addr_any;
        server_ptr = (sockaddr *)&server_addr6;
        addr_len = sizeof(server_addr6);
    } else { // IPv4
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_ptr = (sockaddr *)&server_addr;
        addr_len = sizeof(server_addr);
    }
    
    if (bind(sock, server_ptr, addr_len) < 0) {
        perror("Error en bind");
        close(sock);
        return;
    }
    
    printf("Servidor UDP escuchando en %s:%d\n", ip, port);
    char buffer[BUFFER_SIZE];
    sockaddr_in6 client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    while (1) {
        ssize_t recv_len = recvfrom(sock, buffer, BUFFER_SIZE, 0, (sockaddr *)&client_addr, &client_len);
        if (recv_len < 0) {
            perror("Error al recibir datos");
            continue;
        }
        buffer[recv_len] = '\0';
        printf("Mensaje recibido: %s\n", buffer);
        sendto(sock, buffer, recv_len, 0, (sockaddr *)&client_addr, client_len);
    }
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <IP> <Puerto>\n", argv[0]);
        return 1;
    }
    udp_server(argv[1], atoi(argv[2]));
    return 0;
}
