#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include <limits>
#include <string>
#include <conio.h>
#include <cctype>
#include "utils.h"
#include "CHora.h"

using namespace std;

bool utils::CUtils::LeerDato(int& dato) {
	int error;
	cin.exceptions(ios::failbit | ios::badbit); //Habilito estas excepciones

	try {
		cin >> dato;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eliminar '\n'
		return true;
	}
	catch (exception& e)
	{
		cout << e.what() << ": dato no valido\n";
		cout << "Introduzca un dato valido \n\n";
		cin.clear();//Todas las operaciones de lectura (incluida la de ignorar) fallarán automáticamente si se establece un indicador de error. Es por eso que debe borrar los indicadores de error antes de usar ignorar
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//Establece el nºmax de caracteres a ignorar

		LeerDato(dato);
	}
	if (cin.eof()) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eliminar '\n'
		return false;
	}
}


bool utils::CUtils::LeerDato(float& dato) {
	int error;
	cin.exceptions(ios::failbit | ios::badbit); //Habilito estas excepciones

	try {
		cin >> dato;
	}
	catch (exception& e)
	{
		cout << e.what() << ": dato no valido\n";
		cout << "Introduzca un dato valido \n\n";
		cin.clear();//Todas las operaciones de lectura (incluida la de ignorar) fallarán automáticamente si se establece un indicador de error. Es por eso que debe borrar los indicadores de error antes de usar ignorar
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//Establece el nºmax de caracteres a ignorar

		LeerDato(dato);
	}
	if (cin.eof()) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eliminar '\n'
		return false;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eliminar '\n'
	return true;

}

bool utils::CUtils::LeerDato(double& dato) {
	int error;
	cin.exceptions(ios::failbit | ios::badbit); //Habilito estas excepciones

	try {
		cin >> dato;
	}
	catch (exception& e)
	{
		cout << e.what() << ": dato no valido\n";
		cout << "Introduzca un dato valido \n\n";
		cin.clear();//Todas las operaciones de lectura (incluida la de ignorar) fallarán automáticamente si se establece un indicador de error. Es por eso que debe borrar los indicadores de error antes de usar ignorar
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//Establece el nºmax de caracteres a ignorar

		LeerDato(dato);
	}
	if (cin.eof()) {
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eliminar '\n'
		return false;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // eliminar '\n'
	return true;

}

int utils::CUtils::CrearMenu(char* opciones_menu[], int num_opciones)
{
	int n;

	for (int i = 0; i < num_opciones; i++)
	{
		cout << "\t" << opciones_menu[i] << "\n";

	}

	LeerDato(n);

	return n;
}

bool utils::CUtils::LeerDato(string& dato) {
	bool fallo = false;

	do {
		try {
			getline(cin, dato);
			utils::CUtils::ConverMayus(dato); // Convierto en mayúscula
			//CHora::EsHoraCorrecta();
			if (cin.eof()) {
				cout << "Pulsaste Control + Z\n\n";
				return false;
			}

			fallo = cin.fail();

			if (fallo) {
				throw std::runtime_error("error: dato no válido");
			}
		}
		catch (const std::exception& e) {
			cout << e.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (fallo);

	return true;
}


bool utils::CUtils::LeerDato(char* c, int n) {
	bool fallo = false;

	do {
		try {
			cin.getline(c, n, '\n');
			utils::CUtils::ConverMayus(c);//Convierto en mayuscula
			//CHora::EsHoraCorrecta();
			if (cin.eof()) {
				cout << "Pulsaste Control + Z\n\n";//Pendiente no funciona
				return false;
			}

			fallo = cin.fail();

			if (fallo) {
				throw std::runtime_error("error: dato no válido");
			}
		}
		catch (const std::exception& e) {
			cout << e.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (fallo);

	return true;
}

char* utils::CUtils::ConverMayus(char* str) {
	//int e = 0;

	if (str == NULL)
		return 0;

	_strupr(str);
	return str;
}


string& utils::CUtils::ConverMayus(string& str)
{
	for (int i = 0; i < str.length(); i++)
		str.at(i) = toupper(str.at(i));
	return str;
}