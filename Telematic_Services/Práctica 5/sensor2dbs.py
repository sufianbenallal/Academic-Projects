#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import time
import json
import urllib3
import mysql.connector
import requests

db = mysql.connector.connect(host="localhost", user="adroom", passwd="adminroom", db="iroom")

type_sensor = ['temperature', 'humidity', 'light', 'sound', 'motion']
last_value = [0, 0, 0, 0, 0, 0, 0, 0]

# PONER LA IP DE LA MÁQUINA VIRTUAL EN LA QUE ESTÉ CORRIENDO EL EMULADOR
server = 'http://192.168.56.1:8000/'
http = urllib3.PoolManager()


def updateSensor(code):
    value = 0
    medidas = ['temperature', 'humidity', 'light', 'sound', 'motion']
    try:
        response = requests.get(f'http://192.168.56.1:8000/{medidas[code]}')
        response.raise_for_status()
        if response.status_code == 200:
            data = response.json()
            value = data[medidas[code]]
            last_value[code] = value
        else:
            print("La petición no se ha efectuado de forma correcta")

    except ValueError:
        print('Error de leer dato de sensor')
    if value != last_value[code]:
        try:
            cursor.execute("""INSERT INTO sensors(nombre, valor) VALUES (%s, %s)""", (type_sensor[code], value))
            db.commit()
            last_value[code] = value

        except ValueError:
            print('Error al insertar en base de datos')


def controlLightColor():
    try:
        cursor.execute("""SELECT valor FROM sensors WHERE nombre='red' ORDER BY time DESC""")
        red = int(cursor.fetchone()[0])
        if red != last_value[5]:
            last_value[5] = red
            print("red:" + str(red))
            response = http.request('PUT', server + 'red/' + str(red))

        cursor.execute("""SELECT valor FROM sensors WHERE nombre='green' ORDER BY time DESC""")
        green = int(cursor.fetchone()[0])
        if green != last_value[6]:
            last_value[6] = green
            print("green" + str(green))
            response = http.request('PUT', server + 'green/' + str(green))

        cursor.execute("""SELECT valor FROM sensors WHERE nombre='blue' ORDER BY time DESC""")
        blue = int(cursor.fetchone()[0])
        if blue != last_value[7]:
            last_value[7] = blue
            print("blue" + str(blue))
            response = http.request('PUT', server + 'blue/' + str(blue))

    except ValueError:
        print('Error al consultar de base de datos o conectar con iroom')


if __name__ == "__main__":
    cursor = db.cursor(buffered=True)
    cursor.execute("""DROP table sensors""")
    cursor.execute("""create table if not exists sensors( time TIMESTAMP DEFAULT CURRENT_TIMESTAMP, nombre VARCHAR(15), valor INTEGER)""")
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('temperature', 20))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('humidity', 40))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('light', 30))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('sound', 10))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('motion', 0))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('red', 20))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('blue', 20))
    cursor.execute("""INSERT INTO sensors(nombre, valor) values(%s, %s)""", ('green', 20))
    db.commit()
    print('Base de datos creada, comienza la consulta de sensores')
    while True:
        for code in range(0, 5):
            updateSensor(code)
            time.sleep(1)
        controlLightColor()
