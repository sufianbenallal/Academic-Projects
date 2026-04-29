#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 2

double get_time_ms() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

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
    struct timeval timeout = {TIMEOUT, 0};
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    return sock;
}

void tcp_client(const char *server_ip, int port) {
    int sock = create_socket(server_ip);
    if (sock < 0) return;
    
    struct sockaddr_in6 server_addr6;
    struct sockaddr_in server_addr;
    struct sockaddr *server_ptr;
    socklen_t addr_len;
    
    if (strchr(server_ip, ':')) {
        memset(&server_addr6, 0, sizeof(server_addr6));
        server_addr6.sin6_family = AF_INET6;
        server_addr6.sin6_port = htons(port);
        inet_pton(AF_INET6, server_ip, &server_addr6.sin6_addr);
        server_ptr = (struct sockaddr *)&server_addr6;
        addr_len = sizeof(server_addr6);
    } else {
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, server_ip, &server_addr.sin_addr);
        server_ptr = (struct sockaddr *)&server_addr;
        addr_len = sizeof(server_addr);
    }
    
    if (connect(sock, server_ptr, addr_len) < 0) {
        perror("Error en connect");
        close(sock);
        return;
    }
    
    char buffer[BUFFER_SIZE] = "Hola, servidor";
    double start_time = get_time_ms();
    send(sock, buffer, strlen(buffer), 0);
    ssize_t recv_len = recv(sock, buffer, BUFFER_SIZE, 0);
    double end_time = get_time_ms();
    
    if (recv_len < 0) {
        printf("Tiempo de espera agotado. No se recibió respuesta.\n");
    } else {
        buffer[recv_len] = '\0';
        printf("Respuesta recibida: %s - RTT: %.2f ms\n", buffer, end_time - start_time);
    }
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <IP> <Puerto>\n", argv[0]);
        return 1;
    }
    tcp_client(argv[1], atoi(argv[2]));
    return 0;
}
