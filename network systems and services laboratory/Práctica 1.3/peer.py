import socket
import select
import sys
import os
import errno
import signal
from datetime import datetime

CHUNK_SIZE = 1024

def enviar_fichero(socket_conn, filepath):
    if not os.path.isfile(filepath):
        print("El fichero no existe.")
        return
    filesize = os.path.getsize(filepath)
    filename = os.path.basename(filepath)
    header = f"/file {filename} {filesize}\n"
    socket_conn.send(header.encode())
    with open(filepath, "rb") as f:
        while True:
            chunk = f.read(CHUNK_SIZE)
            if not chunk:
                break
            socket_conn.send(chunk)
    print("Envío de fichero completado.")

def recibir_fichero(socket_conn, header):
    try:
        _, filename, filesize_str = header.split()
        filesize = int(filesize_str)
    except Exception as e:
        print("Error al analizar el header:", e)
        return
    print(f"Recibiendo fichero: {filename} ({filesize} bytes)")
    bytes_recibidos = 0
    filepath_recibido = "recibido_" + filename
    with open(filepath_recibido, "wb") as f:
        while bytes_recibidos < filesize:
            chunk = socket_conn.recv(CHUNK_SIZE)
            if not chunk:
                break
            f.write(chunk)
            bytes_recibidos += len(chunk)
            try:
                texto = chunk.decode('utf-8', errors='replace')
                print(f"Mensaje Recibido: {texto}", end="")
            except Exception as e:
                pass
    if bytes_recibidos >= filesize:
        print(f"\nFichero {filename} recibido correctamente.")
    else:
        print("La recepción del fichero se interrumpió.")

def main():
    if len(sys.argv) != 3:
        print("Uso: peer.py <IP-servidor> <puerto>")
        sys.exit(1)
        
    # Solicitar autenticación
    username = input("Ingrese su nombre de usuario: ")
    password = input("Ingrese su contraseña: ")
    
    # Configurar el handler para CTRL+C
    def signal_handler(sig, frame):
        print(f"\nEl usuario {username} ha cerrado la conexión.")
        sys.exit(0)
    signal.signal(signal.SIGINT, signal_handler)
    
    server_ip = sys.argv[1]
    server_port = int(sys.argv[2])
    
    # Paso 1: Iniciar un socket servidor propio para recibir conexiones.
    peer_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    peer_server.bind(('', 0))  # Se asigna un puerto disponible automáticamente
    peer_server.listen()
    my_ip = socket.gethostbyname(socket.gethostname())
    my_port = peer_server.getsockname()[1]
    print(f"Mi peer está escuchando en {my_ip}:{my_port}")
    
    # Paso 2: Registrar mi dirección de escucha en el servidor de usuarios con autenticación.
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        s.connect((server_ip, server_port))
        # Enviar el registro con el formato "username password IP:puerto"
        mensaje_registro = f"{username} {password} {my_ip}:{my_port}"
        s.send(mensaje_registro.encode())
        # Leer la lista de peers
        data = s.recv(1024)
    except Exception as e:
        print(f"Error conectándose al servidor de usuarios: {e}")
        sys.exit(1)
    s.close()
    
    # Convertir la información recibida en una lista de peers con formato: username IP
    peers = data.decode().splitlines()
    print("Lista de peers obtenida:")
    for p in peers:
        print(p)
        
    # Inicializamos las listas y el diccionario para conexiones y nombres.
    peer_connections = []
    connected_peers = []  # Conexiones salientes
    peer_usernames = {}   # Diccionario que guardará: {socket: username}
    
    # Paso 3: Conectar a los peers obtenidos.
    for peer in peers:
        try:
            partes = peer.split()
            if len(partes) == 2:
                user_registrado, ipport = partes
                ip, port_str = ipport.split(':')
                port = int(port_str)
            else:
                ip, port_str = peer.split(':')
                port = int(port_str)
                user_registrado = ""
            if ip == my_ip and port == my_port:
                continue
            p_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            p_socket.connect((ip, port))
            connected_peers.append(p_socket)
            peer_connections.append(p_socket)
            peer_usernames[p_socket] = user_registrado
            print(f"Conectado a peer {ip}:{port} (usuario {user_registrado})")
        except Exception as e:
            print(f"No se pudo conectar a {peer}: {e}")

    # Lista de sockets a monitorizar: socket de escucha, STDIN y todas las conexiones.
    inputs = [peer_server, sys.stdin] + connected_peers

    while True:
        read_sockets, _, _ = select.select(inputs, [], [])
        for s in read_sockets:
            if s == peer_server:
                # Aceptar nuevas conexiones entrantes de otros peers.
                conn, addr = peer_server.accept()
                conn.setblocking(False)
                inputs.append(conn)
                peer_connections.append(conn)
                print(f"Conexión entrante desde {addr}")
                try:
                    registro = conn.recv(1024).decode().strip()
                    # Se espera el formato "username IP:puerto" para el peer entrante
                    partes = registro.split()
                    if len(partes) == 2:
                        user_registrado, _ = partes
                    else:
                        user_registrado = "Desconocido"
                    peer_usernames[conn] = user_registrado
                    print(f"Conexión entrante registrada: {addr} (usuario {user_registrado})")
                except Exception as e:
                    print(f"Error al registrar peer entrante: {e}")
            elif s == sys.stdin:
                mensaje = sys.stdin.readline()
                if mensaje:
                    # Si se detecta un comando para mensaje privado.
                    if mensaje.startswith("/w "):
                        parts = mensaje.split(maxsplit=2)
                        if len(parts) < 3:
                            print("Uso: /w <destinatario> <mensaje>")
                        else:
                            destinatario = parts[1]
                            private_message = parts[2]
                            timestamp = datetime.now().strftime("%H:%M:%S")
                            mensaje_con_usuario = f"{username} [{timestamp}] (Privado a {destinatario}): {private_message}"
                            enviado = False
                            for sock, user in peer_usernames.items():
                                if user == destinatario:
                                    try:
                                        sock.send(mensaje_con_usuario.encode())
                                        enviado = True
                                        print(f"Mensaje privado enviado a {destinatario}.")
                                    except Exception as e:
                                        print(f"Error enviando mensaje a {destinatario}: {e}")
                            if not enviado:
                                print(f"El usuario {destinatario} no está disponible.")
                    elif mensaje.startswith("/file "):
                        parts = mensaje.split(maxsplit=1)
                        if len(parts) == 2:
                            filepath = parts[1].strip()
                            for peer_socket in peer_connections:
                                try:
                                    enviar_fichero(peer_socket, filepath)
                                except Exception as e:
                                    print(f"Error enviando fichero a un peer: {e}")
                        else:
                            print("Uso: /file <ruta_del_fichero>")
                    else:
                        timestamp = datetime.now().strftime("%H:%M:%S")
                        mensaje_con_usuario = f"{username} [{timestamp}]: {mensaje}"
                        for peer_socket in peer_connections:
                            try:
                                peer_socket.send(mensaje_con_usuario.encode())
                            except Exception as e:
                                print(f"Error enviando mensaje a un peer: {e}")
            else:
                # Recibe mensaje de alguno de los peers (entrante o saliente)
                try:
                    data = s.recv(1024)
                    if data:
                        texto = data.decode(errors='ignore')
                        if texto.startswith("/file "):
                            header = texto.split("\n")[0]
                            recibir_fichero(s, header)
                        else:
                            print("Mensaje recibido:", texto)
                    else:
                        # Si no se recibe nada, significa que ese peer se ha desconectado.
                        nombre_peer = peer_usernames.get(s, "Un peer")
                        print(f"El usuario {nombre_peer} se ha desconectado.")
                        if s in inputs:
                            inputs.remove(s)
                        s.close()
                except OSError as e:
                    if e.errno == errno.EAGAIN or e.errno == errno.EWOULDBLOCK:
                        pass
                    else:
                        print("Error OSError al recibir datos:", e)
                except Exception as e:
                    print("Error al recibir datos:", e)

if __name__ == "__main__":
    main()