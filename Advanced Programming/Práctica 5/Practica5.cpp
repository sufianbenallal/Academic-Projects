#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <limits>
#include "utils.h"
#include "CHora.h"
#include "CFicha.h"
#include "MemoryManager.h"

void VisualizarFicha(const CFicha& ficha);

using namespace std;

int main() {

	int n = 0, edad = 0, hora = 0, minuto = 0, segundo = 0;
	string nombre, formato;
	const int num_opciones = 3;
	CFicha* punt_CFicha = nullptr;
	bool b = false;

	char* c[] = {
	(char*)"1. Crear una ficha dinamicamente.",
	(char*)"2. Visualizar ficha.",
	(char*)"3. Terminar.",
	};

	while (n != 3) {// Mientras no se pulse 3
		n = utils::CUtils::CrearMenu(c, num_opciones);
		switch (n) {

		case 1:
			if (punt_CFicha != nullptr)
				delete punt_CFicha;

			punt_CFicha = new CFicha();

			cout << "Se ha creado un objeto dinamicamente \n\n";

			cout << "Introduce tu nombre\n\n";
			utils::CUtils::LeerDato(nombre);
			punt_CFicha->AsignarNombre(nombre);

			do {
				cout << "Introduce tu edad\n\n";
				utils::CUtils::LeerDato(edad);
				punt_CFicha->AsignarEdad(edad);
			} while (edad < 0 || edad > 130);

			do {
				cout << "Introduce la hora \n\n";
				utils::CUtils::LeerDato(hora);

			} while (hora < 0 || hora > 23);

			do {
				cout << "Introduce el minuto \n\n";
				utils::CUtils::LeerDato(minuto);

			} while (minuto < 0 || minuto > 59);

			do {
				cout << "Introduce el segundo \n\n";
				utils::CUtils::LeerDato(segundo);

			} while (segundo < 0 || segundo > 59);

			cout << "Introduce el formato 'AM' 'FM' o '24 horas'\n\n";
			utils::CUtils::LeerDato(formato);

			b = punt_CFicha->AsignarNacio(hora, minuto, segundo, formato);


			break;//Break case 1 menu principal

		case 2:

			if (punt_CFicha != nullptr)
				if (b)
					VisualizarFicha(*punt_CFicha);

				else {
					cout << "Debes crear primero una ficha valida \n\n";
				}

			break;

		case 3:
			delete punt_CFicha;
			break;
		}//Fin del switch
	}//Fin del while

	MemoryManager::dumpMemoryLeaks();
	system("pause");
	return 0;
}


void VisualizarFicha(const CFicha& ficha) {
	string nombre, formato;
	int edad = 0, hora = 0, minuto = 0, segundo = 0;
	CHora obj;

	nombre = ficha.ObtenerNombre();
	edad = ficha.ObtenerEdad();
	obj = ficha.ObtenerNacio();//Retorna objeto de clase CHora relleno

	obj.ObtenerHora(hora, minuto, segundo, formato);//Como no puedo acceder a miembros privados llamo a funcion para obtener valor atributos

	cout << " " << nombre << "\tEdad: " << edad << "\tNacio a las " << hora << "Horas " << minuto << "Minutos " << segundo << "Segundos " << formato << endl;

}