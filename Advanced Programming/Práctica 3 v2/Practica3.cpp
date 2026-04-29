#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>
#include "CHora.h"
#include "utils.h"
#include "MemoryManager.h"

using namespace std;

void VisualizarHora(const CHora& hora);

int main() {

	int n = 0, horas = 0, minutos = 0, segundos = 0;
	CHora Obj;
	string formato;
	bool b = false;

	Obj.Iniciar();
	const int num_opciones = 3;

	char* c[] = {
	(char*)"1. Introducir hora",
	(char*)"2. Visualizar hora",
	(char*)"3. Terminar"
	};


	while (n != 3) {

		n = CrearMenu(c, num_opciones);


		switch (n) {

		case 1:
			cout << "Elegiste 1. Introducir hora\n\n";

			do {
				cout << "Introduce la hora\n";
				horas = LeerInt();
			} while (0 > horas || horas > 23);

			do {
				cout << "Introduce los minutos\n";
				minutos = LeerInt();
			} while (0 > minutos || minutos > 59);

			do {
				cout << "Introduce los segundos\n";
				segundos = LeerInt();

			} while (0 > segundos || segundos > 59);

			cout << "Introduce el formato \n";
			getline(cin, formato);

			b = Obj.AsignarHora(horas, minutos, segundos, formato);

			break;


		case 2:
			cout << "Elegiste 2. Visualizar hora\n\n";
			if (b == false) {
				cout << "\nLa ultima hora introducida no es valida\n\n";
				break;
			}
			VisualizarHora(Obj);

			break;

		case 3:
			cout << "Elegiste 3. Terminar\n\n";
			break;


		default: cout << " Aprende a elegir\n";
			break;

		}//Fin del switch

	}//Fin del While

	MemoryManager::dumpMemoryLeaks();

	return 0;
}

void VisualizarHora(const CHora& hora) {
	int nHoras = 0, nMinutos = 0, nSegundos = 0;
	string cadena;

	hora.ObtenerHora(nHoras, nMinutos, nSegundos, cadena);

	cout << "\n\n" << nHoras << ":" << nMinutos << ":" << nSegundos << "\n" << "Formato: " << cadena << "\n\n";
}