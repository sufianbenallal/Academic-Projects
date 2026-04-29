#define _CRT_SECURE_NO_WARNINGS
#include "CHora.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <limits>
#include "utils.h"
#include "MemoryManager.h"

void VisualizarHora(const CHora& hora);

using namespace std;

int main() {

	int n = 0, m = 0, horas = 0, minutos = 0, segundos = 0;
	const int num_opciones = 5, num_subopciones = 6;
	CHora* punt_CHora = nullptr;
	CHora Obj;
	string formato;//
	bool b = false;

	char* c[] = {
	(char*)"1. Crear un objeto local.",
	(char*)"2. Crear un objeto dinámicamente.",
	(char*)"3. Constructor copia.",
	(char*)"4. Operador de asignación.",
	(char*)"5. Terminar."
	};

	char* d[] = {
	(char*)"1. Con una hora predeterminada.",
	(char*)"2. Introduciendo la hora.",
	(char*)"3. Introduciendo la hora y los minutos.",
	(char*)"4. Introduciendo la hora, los minutos y los segundos.",
	(char*)"5. Introduciendo la hora, los minutos, los segundos y el formato.",
	(char*)"6. Volver al menu principal"
	};


	while (n != 5) {// Mientras no se pulse 5
		m = 0;
		n = utils::CUtils::CrearMenu(c, num_opciones);
		switch (n) {

		case 1:
			while (m != 6) {//Mientras no se pulse 6

				m = utils::CUtils::CrearMenu(d, num_subopciones);
				switch (m) {

				case 1:
				{
					CHora pred;
					VisualizarHora(pred);
					break;
				}

				case 2:
				{
					do {
						cout << "Introduzca las horas \n";
						utils::CUtils::LeerDato(horas);
					} while (horas < 0 || horas > 24);

					CHora obj1(horas);
					VisualizarHora(obj1);
					break;
				}
				case 3:
				{
					do {
						cout << "Introduzca las horas \n";
						utils::CUtils::LeerDato(horas);
					} while (horas < 0 || horas > 24);

					do {
						cout << "Introduzca los minutos \n";
						utils::CUtils::LeerDato(minutos);
					} while (minutos < 0 || minutos > 60);

					CHora obj1(horas, minutos);
					VisualizarHora(obj1);
					break;
				}

				case 4:
				{
					do {
						cout << "Introduzca las horas \n";
						utils::CUtils::LeerDato(horas);
					} while (horas < 0 || horas > 24);

					do {
						cout << "Introduzca los minutos \n";
						utils::CUtils::LeerDato(minutos);
					} while (minutos < 0 || minutos > 60);

					do {
						cout << "Introduzca los segundos \n";
						utils::CUtils::LeerDato(segundos);
					} while (segundos < 0 || segundos > 60);

					CHora obj1(horas, minutos, segundos);
					VisualizarHora(obj1);
					break;
				}

				case 5:
				{
					do {
						cout << "Introduzca las horas \n";
						utils::CUtils::LeerDato(horas);
					} while (horas < 0 || horas > 24);

					do {
						cout << "Introduzca los minutos \n";
						utils::CUtils::LeerDato(minutos);
					} while (minutos < 0 || minutos > 60);

					do {
						cout << "Introduzca los segundos \n";
						utils::CUtils::LeerDato(segundos);
					} while (segundos < 0 || segundos > 60);

					cout << "Introduce el formato 'AM' o 'PM' o '24 HORAS' \n";
					utils::CUtils::LeerDato(formato);

					CHora obj1(horas, minutos, segundos, formato);
					b = obj1.EsHoraCorrecta();
					if (b) //Si es verdadedo = Si es distinto de 0
						VisualizarHora(obj1);
					break;
				}//Fin case 5
				break;
				}//Fin switch

			}//Fin while submenu

			break;//Break case 1 menu principal

		case 2:
			if (punt_CHora != nullptr)
				delete punt_CHora;

			cout << "Se ha creado un objeto dinamicamente \n\n";
			do {
				cout << "Introduzca las horas \n";
				utils::CUtils::LeerDato(horas);
			} while (horas < 0 || horas > 24);

			do {
				cout << "Introduzca los minutos \n";
				utils::CUtils::LeerDato(minutos);
			} while (minutos < 0 || minutos > 60);

			do {
				cout << "Introduzca los segundos \n";
				utils::CUtils::LeerDato(segundos);
			} while (segundos < 0 || segundos > 60);

			cout << "Introduce el formato 'AM' o 'PM' o '24 HORAS' \n";
			utils::CUtils::LeerDato(formato);

			punt_CHora = new CHora(horas, minutos, segundos, formato);
			b = punt_CHora->EsHoraCorrecta();
			if (b) //Si es verdadedo = Si es distinto de 0
				VisualizarHora(*punt_CHora);

			break;

		case 3:
			if (punt_CHora != nullptr) {
				CHora copia(*punt_CHora);// Utilizo el constructor de copia para crear un nuevo objeto
				cout << "\n\n";
				VisualizarHora(copia);
			}
			else {
				cout << "Debes crear primero un objeto dinamico \n\n";
			}
			break;

		case 4:
			if (punt_CHora != nullptr) {
				CHora obj_asign = *punt_CHora;//Utilizo operador de asignación para copiar objeto dinamico
				VisualizarHora(obj_asign);
			}
			else {
				cout << "Debes crear primero un objeto dinamico \n\n";
			}
			break;

		case 5:
			delete punt_CHora;
			break;
		}//Fin del switch
	}//Fin del while

	MemoryManager::dumpMemoryLeaks();
	std::system("pause");
	return 0;
}


void VisualizarHora(const CHora& hora) { //
	int horas = 0, minutos = 0, segundos = 0;
	string cadena;

	hora.ObtenerHora(horas, minutos, segundos, cadena);

	/*if (cadena == NULL) {
		cout << "\nNo exite ninguna hora aun\n";
			exit(0);
	}*/

	cout << "La hora introducida es:  "<< "\n\n" << horas << ":" << minutos << ":" << segundos << "\n" << "Formato: " << cadena << "\n\n";
	//Imprimir por pantalla

}