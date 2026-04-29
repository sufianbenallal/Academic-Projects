import socket
import sys

def tcp_server(port):
    try:
        with socket.socket(socket.AF_INET6, socket.SOCK_STREAM) as s:
            s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # Mejora 1: Permitir reutilización del puerto
            s.bind(("::", port))
            s.listen()
            print(f"Servidor TCP escuchando en el puerto {port}...")
            
            while True:
                conn, addr = s.accept()
                with conn:
                    print(f"Conexión desde {addr}")
                    data = conn.recv(1024)
                    if data:
                        conn.sendall(b'pong')
    except Exception as e:
        print(f"Error en el servidor TCP: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Uso: python tcp_server.py <port>")
        sys.exit(1)
    
    try:
        port = int(sys.argv[1])
        if port < 1 or port > 65535:
            raise ValueError("El puerto debe estar entre 1 y 65535")  # Mejora 2: Validar rango de puertos
        tcp_server(port)
    except ValueError as e:
        print(f"Error: {e}")
        sys.exit(1)
