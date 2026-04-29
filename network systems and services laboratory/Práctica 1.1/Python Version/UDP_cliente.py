import socket
import time
import statistics

def create_socket(ip_version):
    """Crea un socket compatible con IPv4 o IPv6 según la dirección IP."""
    try:
        if ':' in ip_version:
            return socket.socket(socket.AF_INET6, socket.SOCK_DGRAM)
        else:
            return socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    except socket.error as e:
        print(f"Error al crear el socket: {e}")
        return None

def udp_client(server_ip, port, num_requests=5):
    client_socket = create_socket(server_ip)
    if not client_socket:
        return
    client_socket.settimeout(2)
    rtts = []
    
    try:
        for i in range(num_requests):
            message = f"Ping {i+1}"
            start_time = time.time()
            try:
                client_socket.sendto(message.encode(), (server_ip, port))
                data, _ = client_socket.recvfrom(1024)
                end_time = time.time()
                rtt = (end_time - start_time) * 1000
                rtts.append(rtt)
                print(f"Respuesta recibida: {data.decode()} - RTT: {rtt:.2f} ms")
            except socket.timeout:
                print("Tiempo de espera agotado. Paquete perdido.")
            except Exception as e:
                print(f"Error en la comunicación: {e}")
        
        if rtts:
            print(f"RTT Min: {min(rtts):.2f} ms, Max: {max(rtts):.2f} ms, Promedio: {statistics.mean(rtts):.2f} ms")
        else:
            print("No se recibieron respuestas.")
    except Exception as e:
        print(f"Error en el cliente: {e}")
    finally:
        client_socket.close()

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 3:
        print("Uso: python udp_client.py <IP> <Puerto>")
    else:
        ip, port = sys.argv[1], int(sys.argv[2])
        udp_client(ip, port)
