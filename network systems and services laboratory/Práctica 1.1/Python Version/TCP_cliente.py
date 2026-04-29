import socket
import time
import sys

def tcp_client(host, port, count=5):
    try:
        rtt_list = []
        with socket.socket(socket.AF_INET6 if ':' in host else socket.AF_INET, socket.SOCK_STREAM) as s:
            s.settimeout(2)
            s.connect((host, port))
            
            for i in range(count):
                start_time = time.time()
                s.sendall(b'ping')
                try:
                    data = s.recv(1024)
                    end_time = time.time()
                    rtt = (end_time - start_time) * 1000
                    rtt_list.append(rtt)
                    print(f"Respuesta TCP: {data.decode()} - RTT: {rtt:.2f} ms")
                except socket.timeout:
                    print("Error: Tiempo de espera agotado")
        
        if rtt_list:
            print(f"Estadísticas: Mínimo RTT: {min(rtt_list):.2f} ms, Máximo RTT: {max(rtt_list):.2f} ms, Promedio RTT: {sum(rtt_list)/len(rtt_list):.2f} ms")
    except Exception as e:
        print(f"Error en cliente TCP: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Uso: python tcp_client.py <host> <port>")
        sys.exit(1)
    
    try:
        host = sys.argv[1]
        port = int(sys.argv[2])
        tcp_client(host, port)
    except ValueError:
        print("Error: El puerto debe ser un número entero válido")
        sys.exit(1)
