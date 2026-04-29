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
        sock = socket(AF_INET6, SOCK_DGRAM, 0);
    } else {
        sock = socket(AF_INET, SOCK_DGRAM, 0);
    }
    if (sock < 0) {
        perror("Error al crear el socket");
        return -1;
    }
    struct timeval timeout = {TIMEOUT, 0};
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    return sock;
}

void udp_client(const char *server_ip, int port, int num_requests) {
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
    
    char buffer[BUFFER_SIZE];
    double rtts[num_requests];
    int received = 0;
    
    for (int i = 0; i < num_requests; i++) {
        snprintf(buffer, BUFFER_SIZE, "Ping %d", i+1);
        double start_time = get_time_ms();
        sendto(sock, buffer, strlen(buffer), 0, server_ptr, addr_len);
        ssize_t recv_len = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        double end_time = get_time_ms();
        
        if (recv_len < 0) {
            printf("Tiempo de espera agotado. Paquete perdido.\n");
        } else {
            buffer[recv_len] = '\0';
            double rtt = end_time - start_time;
            rtts[received++] = rtt;
            printf("Respuesta recibida: %s - RTT: %.2f ms\n", buffer, rtt);
        }
    }
    
    if (received > 0) {
        double min = rtts[0], max = rtts[0], sum = 0;
        for (int i = 0; i < received; i++) {
            if (rtts[i] < min) min = rtts[i];
            if (rtts[i] > max) max = rtts[i];
            sum += rtts[i];
        }
        printf("RTT Min: %.2f ms, Max: %.2f ms, Promedio: %.2f ms\n", min, max, sum / received);
    } else {
        printf("No se recibieron respuestas.\n");
    }
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Uso: %s <IP> <Puerto> <N_Paquetes>\n", argv[0]);
        return 1;
    }
    udp_client(argv[1], atoi(argv[2]), atoi(argv[3]));
    return 0;
}
