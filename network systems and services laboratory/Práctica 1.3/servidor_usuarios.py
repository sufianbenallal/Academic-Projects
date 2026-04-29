import socket
import select
import sys
import os

CHUNK_SIZE = 1024

USUARIOS_PERMITIDOS = {
    "Sufian": "contraseña123",
    "Paco": "clave5552",
    "Manuel": "20502050"
}
def main():
    if len(sys.argv) != 2:
        print("Uso: servidor_usuarios.py <puerto>")
        sys.exit(1)

    puerto = int(sys.argv[1])
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('', puerto))
    server_socket.listen()

    peers = [] # Lista de peers registrados

    print(f"Servidor de usuarios escuchando en el puerto {puerto}")

    while True:
        # Monitorizamos el socket del servidor de usuarios
        read_sockets, _, _ = select.select([server_socket], [], [])
        for s in read_sockets:
            client_socket, addr = server_socket.accept()
            print(f"Conexión entrante desde {addr}")
            
            # Se espera que el mensaje de registro tenga el siguiente formato:  username IP:puerto 
            registro = client_socket.recv(1024).decode().strip()
            if registro:
                try:
                    # Separamos el nombre del usuario y la dirección IP
                except Exception as e:
                    print("Error en el formato de registro:", e)
                    client_socket.send("Formato de registro incorrecto".encode())
                    client_socket.close()
                if username not in USUARIOS_PERMITIDOS or USUARIOS_PERMITIDOS[username] != password:
                    print(f"Autenticación fallida para {username}")
                    client_socket.send("Autenticación fallida".encode())
                    client_socket.close()
                    continue
                    
                peer_info = f"{username} {direccion}"
                print(f"Peer registrado: {peer_info}")
                peers.append(peer_info)
                

                lista_peers = "\n".join(peers)                 # Construir la lista actual de peers
                client_socket.send(lista_peers.encode()) # Enviar la lista al peer que se acaba de registrar
            else:
                print("No se recibió información de registro.")
            client_socket.close()

def enviar_fichero(socket_conn, filepath):
    if not os.path.isfile(filepath):
        print("El fichero no existe.")
        return
    filesize = os.path.getsize(filepath)
    filename = os.path.basename(filepath)
    

    header = f"/file {filename} {filesize}\n"     # Enviar header
    socket_conn.send(header.encode())

    with open(filepath, "rb") as f:     # Lee y envia el fichero en bloques
        while True:
            chunk = f.read(CHUNK_SIZE)
            if not chunk:
                break
            socket_conn.send(chunk)
    print("Envío de fichero completado.")

def recibir_fichero(socket_conn, header):
    # El header tiene el siguiente formato: /file nombre_fichero tamaño_fichero 
    try:
        _, filename, filesize_str = header.split()
        filesize = int(filesize_str)
    except Exception as e:
        print("Error al analizar el header:", e)
        return
    print(f"Recibiendo fichero: {filename} ({filesize} bytes)")
    bytes_recibidos = 0
    with open("recibido_" + filename, "wb") as f:
        while bytes_recibidos < filesize:
            chunk = socket_conn.recv(CHUNK_SIZE)
            if not chunk:
                break
            f.write(chunk)
            bytes_recibidos += len(chunk)
    if bytes_recibidos >= filesize:
        print(f"Fichero {filename} recibido correctamente.")
    else:
        print("La recepción del fichero se interrumpió.")

if __name__ == "__main__":
    main()