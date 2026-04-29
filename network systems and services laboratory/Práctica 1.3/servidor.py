import socket
import select
import sys

def main():
    if len(sys.argv) != 2:
        print("Uso: servidor.py <puerto>")
        sys.exit(1)

    puerto = int(sys.argv[1])
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind(('', puerto))
    server_socket.listen()
    server_socket.setblocking(False)  # Configuración no bloqueante

    sockets = [server_socket]
    print(f"Servidor escuchando en puerto {puerto}")

    while True:
        # Monitorizamos los sockets que están listos para lectura.
        read_sockets, _, exception_sockets = select.select(sockets, [], sockets)
        for s in read_sockets:
            if s is server_socket:
                # Aceptar nuevos clientes
                client_socket, addr = server_socket.accept()
                client_socket.setblocking(False)
                sockets.append(client_socket)
                print(f"Nuevo cliente conectado: {addr}")
            else:
                try:
                    data = s.recv(1024)
                    if data:
                        # Enviar el mensaje a todos los demás clientes
                        for client in sockets:
                            if client is not server_socket and client != s:
                                client.send(data)
                    else:
                        # Si no se recibe datos, es que el cliente se ha desconectado
                        print("Cliente desconectado")
                        sockets.remove(s)
                        s.close()
                except ConnectionResetError:
                    print("Cliente desconectado abruptamente")
                    sockets.remove(s)
                    s.close()

        # Manejo de excepciones en los sockets
        for s in exception_sockets:
            sockets.remove(s)
            s.close()

if __name__ == "__main__":
    main()