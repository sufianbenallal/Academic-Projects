from flask import Flask, render_template, Response, request, flash, redirect, abort, jsonify, session, url_for
import json
import time
import os
import urllib3
import secrets
import mysql.connector

def generate_unique_code():
    # Genera un código único aleatorio
    return secrets.token_urlsafe(8)
server = 'http://192.168.56.1:8000/'
http = urllib3.PoolManager()
db = mysql.connector.connect(host="localhost", user="adroom", passwd="adminroom", db="iroom")
os.environ['IROOM_SETTINGS'] = '/home/sufianbenallal/iroom/config/iroom.cfg'

app = Flask(__name__)
app.config.from_object(__name__)
app.config.from_envvar('IROOM_SETTINGS', silent=True)
last_value = {sensor: 0 for sensor in ['temperature', 'light', 'sound', 'motion', 'humidity']}

def event_sensor():
    print("SSE Connection Established")
    while True:
        cursor = db.cursor()

        for sensor in ['temperature', 'light', 'sound', 'motion', 'humidity']:
            cursor.execute(f"SELECT valor FROM sensors WHERE nombre = %s ORDER BY time DESC LIMIT 1", (sensor,))
            result = cursor.fetchone()

            if result:
                valor = int(result[0])
                sensor_data = {"tipo": sensor, "valor": valor}
                data_json = json.dumps(sensor_data)
                print(sensor_data)
                yield 'data: %s\n\n' % str(data_json)

        cursor.close()
        time.sleep(1)

@app.route('/update_sensor')
def sse_request():
    return Response(event_sensor(), mimetype='text/event-stream')

@app.route('/shorten_url', methods=['POST'])
def shorten_url():
    if not session.get('logged_in'):
        abort(401)  # No autorizado

    data = request.json  # Cambiado a request.json para obtener datos JSON
    original_url = data.get('original_url')

    if not original_url:
        abort(400)  # Solicitud incorrecta
    code = generate_unique_code()

    # Guarda en la base de datos
    cursor = db.cursor()
    cursor.execute("INSERT INTO url_mapping (code, original_url) VALUES (%s, %s)", (code, original_url))
    db.commit()
    cursor.close()

    # Devuelve el código generado
    return jsonify({"code": code})

@app.route('/URL/<string:code>')
def redirect_to_original_url(code):
    # Busca el código en la base de datos
    cursor = db.cursor()
    cursor.execute("SELECT original_url FROM url_mapping WHERE code = %s", (code,))
    result = cursor.fetchone()
    cursor.close()

    if result:
        original_url = result[0]
        return redirect(original_url, code=307)  # Redirección permanente
    else:
        return redirect(url_for('main'))  # Redirección a la página de inicio si el código no está en la base de datos

@app.route('/')
def main():
    return render_template('index.html')

@app.route('/sensors')
def sensors():
    return render_template('sensors.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    error = None
    if request.method == 'POST':
        if request.form['username'] != app.config['USERNAME']:
            error = 'Invalid username'
        elif request.form['password'] != app.config['PASSWORD']:
            error = 'Invalid password'
        else:
            session['logged_in'] = True
            flash('Has entrado en la sesion')
            return redirect(url_for('sensors'))
    return render_template('login.html', error=error)

@app.route('/logout')
def logout():
    session.pop('logged_in', None)
    flash('Has salido de la sesion')
    return redirect(url_for('main'))

@app.route('/iluminacion')
def iluminacion():
    return render_template('iluminacion.html')

@app.route('/setcolor', methods=['GET'])
def setcolor():
    # Extraer los valores de red, green, blue del color
    red = request.args.get('red')
    green = request.args.get('green')
    blue = request.args.get('blue')

    cursor = db.cursor()
    cursor.execute("INSERT INTO sensors (nombre, valor) VALUES (%s, %s)", ('iluminacion', red))
    db.commit()
    cursor.close()

    return jsonify({"status": "success", "message": "Color guardado correctamente"})

if __name__ == '__main__':
    with app.test_request_context():
        app.debug = True
        app.run(host='0.0.0.0')