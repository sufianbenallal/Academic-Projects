import socket
import select
import sys
from datetime import datetime
import os

CHUNK_SIZE = 1024

def enviar_fichero(sock, filepath):
    if not os.path.isfile(filepath):
        print("El fichero no existe.")
        return
    filesize = os.path.getsize(filepath)
    filename = os.path.basename(filepath)
    # Enviamos header
    header = f"/file {filename} {filesize}\n"
    sock.send(header.encode())
    # Enviar el contenido del fichero en bloques de tamaño 1024 bytes
    with open(filepath, "rb") as f:
        while True:
            chunk = f.read(CHUNK_SIZE)
            if not chunk:
                break
            sock.send(chunk)
    print("Envío de fichero completado.")

def main():
    if len(sys.argv) != 3:
        print("Uso: cliente.py <IP-servidor> <puerto>")
        sys.exit(1)

    username = input("Ingrese su nombre de usuario: ")

    server_ip = sys.argv[1]
    puerto = int(sys.argv[2])
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect((server_ip, puerto))
    except Exception as e:
        print(f"Error conectando al servidor: {e}")
        sys.exit(1)
    client_socket.setblocking(False)

    print(f"Conectado a {server_ip}:{puerto}")
    print("Escribe tus mensajes y presiona Enter para enviar.")
    print("Para enviar un fichero, escribe: /file <ruta_del_fichero>")

    # Buffer para acumular datos recibidos
    recv_buffer = b""
    # Estado de recepción de fichero cuando no se está recibiendo(none)
    file_state = None
    try:
        while True:
            sockets_list = [sys.stdin, client_socket]
            read_sockets, _, _ = select.select(sockets_list, [], [])
            for s in read_sockets:
                if s == client_socket:
                    try:
                        data = s.recv(CHUNK_SIZE)
                    except Exception as e:
                        continue
                    if not data:
                        print("Desconexión del servidor.")
                        sys.exit(0)
                    recv_buffer += data
                    # Si estamos recibiendo un fichero, procesamos todo lo del buffer
                    if file_state is not None:
                        # Escribimos todo lo que tenemos en el fichero
                        file_state["file"].write(recv_buffer)
                        file_state["received"] += len(recv_buffer)
                        recv_buffer = b""
                        # Si ya se recibió todo, cerramos
                        if file_state["received"] >= file_state["filesize"]:
                            file_state["file"].close()
                            print(f"\nFichero {file_state['filename']} recibido correctamente.")
                            file_state = None
                    else:
                        # Si no estamos en estado de recepción de fichero, Buscamos si hay un header
                        if b"\n" in recv_buffer:
                            header_line, rest = recv_buffer.split(b"\n", 1)
                            text_header = header_line.decode(errors='ignore')
                            if text_header.startswith("/file "):
                                try:
                                    parts = text_header.split()
                                    # Se espera un header completo
                                    filename = parts[1]
                                    filesize = int(parts[2])
                                    file_state = {
                                        "filename": filename,
                                        "filesize": filesize,
                                        "received": 0,
                                        "file": open("recibido_" + filename, "wb")
                                    }
                                    print(f"Inicio de recepción de fichero: {filename} ({filesize} bytes)")
                                except Exception as e:
                                    print("Error procesando header de fichero:", e)
                                recv_buffer = rest  # Lo que sobra del buffer se conserva
                                if file_state is not None and recv_buffer:
                                    file_state["file"].write(recv_buffer)
                                    file_state["received"] += len(recv_buffer)
                                    recv_buffer = b""
                                    if file_state["received"] >= file_state["filesize"]:
                                        file_state["file"].close()
                                        print(f"\nFichero {file_state['filename']} recibido correctamente.")
                                        file_state = None
                            else:
                                # Si el header no es de fichero, tratamos recv_buffer como mensaje
                                print(recv_buffer.decode(errors='ignore'))
                                recv_buffer = b""
                else:
                    input_message = sys.stdin.readline()
                    if input_message:
                        if input_message.startswith("/file "):
                            parts = input_message.split(maxsplit=1)
                            if len(parts) == 2:
                                filepath = parts[1].strip()
                                enviar_fichero(client_socket, filepath)
                            else:
                                print("Uso: /file <ruta_del_fichero>")
                        else:
                            timestamp = datetime.now().strftime("%H:%M:%S")
                            msg_con_info = f"{username} [{timestamp}]: {input_message}"
                            try:
                                client_socket.send(msg_con_info.encode())
                            except Exception as e:
                                print(f"Error enviando mensaje: {e}")
    except KeyboardInterrupt:
        print(f"\nEl usuario {username} ha cerrado la conexión.")
        sys.exit(0)

if __name__ == "__main__":
    main()