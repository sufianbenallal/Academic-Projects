import socket

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

def udp_server(host, port):
    server_socket = create_socket(host)
    if not server_socket:
        return
    try:
        server_socket.bind((host, port))
        print(f"Servidor UDP escuchando en {host}:{port}")
        while True:
            try:
                data, addr = server_socket.recvfrom(1024)
                print(f"Mensaje recibido de {addr}: {data.decode()}")
                server_socket.sendto(data, addr)  # Eco de respuesta
            except socket.timeout:
                print("Tiempo de espera agotado esperando datos.")
            except Exception as e:
                print(f"Error al recibir datos: {e}")
    except Exception as e:
        print(f"Error en el servidor: {e}")
    finally:
        server_socket.close()

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 3:
        print("Uso: python udp_server.py <IP> <Puerto>")
    else:
        ip, port = sys.argv[1], int(sys.argv[2])
        udp_server(ip, port)
