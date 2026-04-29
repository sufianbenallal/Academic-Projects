#Servidor WEB en Python
import socket
import select
import os
import time
import sys
import mimetypes
import ssl
import base64

from datetime import datetime

HOST = '127.0.0.1'
PORT = 8080
TIEMPO_INACTIVO = 10
modo_persistente = '--persistente' in sys.argv
contador_post = 1  # Contador para archivos POST
modo_https = '--https' in sys.argv
registro_peticiones = []


servidor = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
servidor.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

#Cargar el certificado de SSL
if modo_https:
    contexto_ssl = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    contexto_ssl.load_cert_chain(certfile="ncert.pem", keyfile="ncert.pem")
    servidor = contexto_ssl.wrap_socket(servidor, server_side=True)

servidor.bind((HOST, PORT))
servidor.listen(5)
servidor.setblocking(False)

sockets_list = [servidor]
clientes = {}

protocolo = "https" if modo_https else "http"
print(f"Servidor web escuchando en {protocolo}://{HOST}:{PORT}/")
print("Modo:", "PERSISTENTE" if modo_persistente else "NO PERSISTENTE")
ultimo_uso = time.time()

def servir_archivo(path, accept_language=None):
    if path == "/":
        # HTML dinámico con logs
        cuerpo_html = "<!DOCTYPE html><html lang='es'><head><meta charset='UTF-8'>"
        cuerpo_html += "<title>Servidor Web</title>"
        cuerpo_html += "<link rel='stylesheet' href='style.css'>"
        cuerpo_html += "</head><body><div class='contenido'>"
        cuerpo_html += "<h1>Bienvenido al servidor web en Python!</h1>"
        cuerpo_html += "<p>Este página muestra las peticiones que se hacen al servidor (GET,POST.DELETE,..).</p>"
        cuerpo_html += "<img src='imagen.jpg' alt='Imagen local' width='300'>"
        cuerpo_html += "<br><br><button onclick='location.reload()'>Refrescar</button>"


        # Mostrar registros
        cuerpo_html += "<h2>Últimas peticiones al servidor:</h2><div class='registro'>"
        # Contenedor principal para dividir en 2 columnas
        cuerpo_html += "<div class='contenido-principal'>"

        # Sección izquierda (logs)
        cuerpo_html += "<div class='logs'>"
        cuerpo_html += "<h2>Últimas peticiones al servidor:</h2><div class='registro'>"



        if registro_peticiones:
            for linea in reversed(registro_peticiones[-10:]):
                cuerpo_html += f"<p>{linea}</p>"
        else:
            cuerpo_html += "<p>No se han hecho peticiones todavía.</p>"
        cuerpo_html += "</div></div>"
         # Sección derecha (vídeo)
        cuerpo_html += """
        <div class="video-box">
            <h2>Vídeo demostrativo</h2>
            <video width="360" controls autoplay loop muted>
                <source src="video.mp4" type="video/mp4">
                Tu navegador no soporta vídeo HTML5.
            </video>
        </div>
        </div> <!-- Fin de contenido-principal -->
        </div> <!-- Fin de contenido -->
        <script>
            function saludar() {
                alert("¡Hola desde JavaScript!");
            }
        </script>
        </body></html>
        """

        headers = (
            "HTTP/1.0 200 OK\r\n"
            "Content-Type: text/html\r\n"
            f"Content-Length: {len(cuerpo_html.encode())}\r\n"
            "Connection: close\r\n\r\n"
        )

        return headers.encode() + cuerpo_html.encode()

        # Script incluido al final
        cuerpo_html += """
        </body></html>
        """

        headers = (
            "HTTP/1.0 200 OK\r\n"
            "Content-Type: text/html\r\n"
            f"Content-Length: {len(cuerpo_html.encode())}\r\n"
            "Connection: close\r\n\r\n"
        )

        return headers.encode() + cuerpo_html.encode()

    # ↓ Resto de archivos normales
    archivo = "." + path
    if not os.path.exists(archivo):
        return b"HTTP/1.0 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>"

    if not os.access(archivo, os.R_OK):
        return b"HTTP/1.0 403 Forbidden\r\nContent-Type: text/html\r\n\r\n<h1>403 Forbidden</h1>"

    try:
        with open(archivo, "rb") as f:
            contenido = f.read()
        tipo_mime, _ = mimetypes.guess_type(archivo)
        headers = (
            "HTTP/1.0 200 OK\r\n"
            f"Content-Type: {tipo_mime or 'application/octet-stream'}\r\n"
            f"Content-Length: {len(contenido)}\r\n"
            "Connection: close\r\n\r\n"
        ).encode()
        return headers + contenido
    except Exception as e:
        print(f"Error interno al servir {archivo}: {e}")
        return b"HTTP/1.0 500 Internal Server Error\r\nContent-Type: text/html\r\n\r\n<h1>500 Internal Server Error</h1>"


try:
    while True:
        tiempo_espera = max(0, TIEMPO_INACTIVO - (time.time() - ultimo_uso))
        ready_read, _, _ = select.select(sockets_list, [], [], tiempo_espera)

        if not ready_read:
            print("Servidor web inactivo")
            ultimo_uso = time.time()
            continue

        for sock in ready_read:
            if sock == servidor:
                cliente, addr = servidor.accept()
                cliente.setblocking(False)
                sockets_list.append(cliente)
                clientes[cliente] = b""
            else:
                try:
                    datos = sock.recv(4096)
                    if datos:
                        clientes[sock] += datos
                        if b"\r\n\r\n" in clientes[sock]:
                            peticion = clientes[sock].decode(errors='ignore')
                            lineas = peticion.split("\r\n")
                            if len(lineas) == 0 or len(lineas[0].split()) < 2:
                                respuesta = b"HTTP/1.0 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<h1>400 Bad Request</h1>"
                                sock.sendall(respuesta)
                                  # Cierre limpio según el modo
                                if not modo_persistente:
                                    sock.close()
                                    sockets_list.remove(sock)
                                    del clientes[sock]
                                else:
                                    clientes[sock] = b""
                                
                                continue #salta al siguiente socket 

                            primera_linea = lineas[0]
                            partes = primera_linea.split()
                            metodo = partes[0]
                            recurso = partes[1]
                            
                            # Protección para la ruta /admin
                            if recurso.startswith("/admin"):
                                autorizado = False
                                usuario_esperado = "admin"
                                password_esperado = "1234"

                                for linea in lineas:
                                    if linea.lower().startswith("authorization: basic "):
                                        token = linea.split(" ")[-1]
                                        try:
                                            decoded = base64.b64decode(token).decode()
                                            usuario, password = decoded.split(":")
                                            if usuario == usuario_esperado and password == password_esperado:
                                                autorizado = True
                                        except:
                                            pass

                                if not autorizado:
                                    respuesta = (
                                        "HTTP/1.0 401 Unauthorized\r\n"
                                        "WWW-Authenticate: Basic realm=\"Zona protegida\"\r\n"
                                        "Content-Type: text/html\r\n\r\n"
                                        "<h1>401 Unauthorized</h1><p>Se requiere autenticación.</p>"
                                    ).encode()

                                    sock.sendall(respuesta)

                                    if not modo_persistente:
                                        sock.close()
                                        sockets_list.remove(sock)
                                        del clientes[sock]
                                    else:
                                        clientes[sock] = b""
                                    
                                    continue
                                    
                                if recurso == "/admin":
                                    recurso = "/admin.html"


                            ahora = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
                            ip = sock.getpeername()[0]
                            log_line = f"{ahora} {metodo} {recurso} desde {ip}"

                            # Mostrar por consola
                            print(log_line)

                            # Guardar en registro interno (para mostrar en la web)
                            registro_peticiones.append(log_line)

                            # Guardar también en log.txt (modo append)
                            with open("historico_peticiones.txt", "a") as f:
                                f.write(log_line + "\n")    


                            if metodo == 'GET':
                                respuesta = servir_archivo(recurso)
                                if recurso == "/logs":
                                    try:
                                        with open("historico_peticiones.txt", "r") as f:
                                            contenido = f.read()
                                        respuesta = (
                                            "HTTP/1.0 200 OK\r\n"
                                            "Content-Type: text/plain\r\n"
                                            f"Content-Length: {len(contenido)}\r\n"
                                            "Connection: close\r\n\r\n"
                                            f"{contenido}"
                                        ).encode()
                                    except:
                                        respuesta = (
                                            "HTTP/1.0 500 Internal Server Error\r\n"
                                            "Content-Type: text/html\r\n\r\n"
                                            "<h1>Error cargando logs</h1>"
                                        ).encode()
                                    sock.sendall(respuesta)

                                    if not modo_persistente:
                                        sock.close()
                                        sockets_list.remove(sock)
                                        del clientes[sock]
                                    else:
                                        clientes[sock] = b""
                                    continue


                            elif metodo == 'HEAD':
                                path = recurso if recurso != "/" else "/index.html"
                                archivo = "." + path
                                if os.path.exists(archivo):
                                    if os.access(archivo, os.R_OK):
                                        tipo_mime, _ = mimetypes.guess_type(archivo)
                                        headers = (
                                            "HTTP/1.0 200 OK\r\n"
                                            f"Content-Type: {tipo_mime or 'application/octet-stream'}\r\n"
                                            f"Content-Length: {os.path.getsize(archivo)}\r\n"
                                            "Connection: close\r\n\r\n"
                                        )
                                        respuesta = headers.encode()
                                    else:
                                        respuesta = b"HTTP/1.0 403 Forbidden\r\nContent-Type: text/html\r\n\r\n<h1>403 Forbidden</h1>"
                                else:
                                    respuesta = b"HTTP/1.0 404 Not Found\r\nContent-Type: text/html\r\n\r\n<h1>404 Not Found</h1>"

                            elif metodo == 'POST':
                                _, _, body = clientes[sock].partition(b"\r\n\r\n")
                                print("Cuerpo recibido:", body.decode(errors='ignore'))

                                while True:
                                    nombre_archivo = f"post_data_{contador_post}.txt"
                                    if not os.path.exists(nombre_archivo):
                                        try:
                                            with open(nombre_archivo, "wb") as f:
                                                f.write(body)
                                            mensaje = f"POST guardado en {nombre_archivo}"
                                            respuesta = (
                                                "HTTP/1.0 200 OK\r\n"
                                                "Content-Type: text/html\r\n\r\n"
                                                f"{mensaje}"
                                            ).encode()
                                            break
                                        except Exception as e:
                                            print(f"Error al guardar POST: {e}")
                                            respuesta = b"HTTP/1.0 500 Internal Server Error\r\nContent-Type: text/html\r\n\r\n<h1>500 Internal Server Error</h1>"
                                            break
                                    else:
                                        contador_post += 1
                                contador_post += 1

                            elif metodo == 'DELETE':
                                archivo = "." + recurso
                                if os.path.exists(archivo):
                                    if os.access(archivo, os.W_OK):
                                        os.remove(archivo)
                                        respuesta = (
                                            "HTTP/1.0 200 OK\r\n"
                                            "Content-Type: text/html\r\n\r\n"
                                            f"Archivo {recurso} eliminado."
                                        ).encode()
                                    else:
                                        respuesta = (
                                            "HTTP/1.0 403 Forbidden\r\n"
                                            "Content-Type: text/html\r\n\r\n"
                                            f"No tienes permisos para eliminar {recurso}"
                                        ).encode()
                                else:
                                    respuesta = (
                                        "HTTP/1.0 404 Not Found\r\n"
                                        "Content-Type: text/html\r\n\r\n"
                                        f"No se encontró el archivo {recurso}"
                                    ).encode()

                            else:
                                respuesta = (
                                    "HTTP/1.0 405 Method Not Allowed\r\n"
                                    "Content-Type: text/html\r\n\r\n"
                                    "<h1>405 Method Not Allowed</h1>"
                                ).encode()

                            sock.sendall(respuesta)

                            if not modo_persistente:
                                sock.close()
                                sockets_list.remove(sock)
                                del clientes[sock]
                            else:
                                clientes[sock] = b""
                    else:
                        sock.close()
                        sockets_list.remove(sock)
                        del clientes[sock]
                except Exception as e:
                    print(f"Error con cliente: {e}")
                    sock.close()
                    if sock in sockets_list:
                        sockets_list.remove(sock)
                    if sock in clientes:
                        del clientes[sock]

        ultimo_uso = time.time()

except KeyboardInterrupt:
    print("\nCerrando servidor correctamente...")
    for sock in sockets_list:
        sock.close()
    sys.exit(0)