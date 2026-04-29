#include<iostream>
#include<stdlib.h>
#include <limits>
#include <string.h>
using namespace std;

int LeerInt()
{
	int error;
	int num;
	do
	{
		cin >> num;
		error = cin.rdstate() & cin.failbit; // Corregir esta línea

		if (error)
		{
			cout << "\nEl dato introducido no es correcto\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (error);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return num;
}

float LeerFloat()
{
	int error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & cin.failbit; // Corregir esta línea

		if (error)
		{
			cout << "\nEl dato introducido no es correcto\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Corregir esta línea
		}
	} while (error);

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return num;
}

int CrearMenu(char* opciones_menu[], int num_opciones)
{
	int n;

	for (int i = 0; i < num_opciones; i++)
	{
		cout << "\t" << opciones_menu[i] << "\n";
	}
	n = LeerInt();
	return n;
}

void LeerCadena(char* c, int n) {

	if (c != nullptr) {
		cin.getline(c, n, '\n');

		if (cin.fail()) {//Verifica si se ha excedido el tamaño permitido
			cin.clear();//Elimina cualq flag de cin activado
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//Descarta el exceso de caracteres
		}

	}

}

char* ConverMayus(char* str) {

	if (str != nullptr) {
		int longitud;
		longitud = strlen(str);

		for (int i = 0; i < longitud; i++)
			str[i] = toupper(str[i]);//Pone en mayusculas el caracter
	}

	return str;
}

string& ConverMayus(string& str) {

	for (int i = 0; i < str.length(); i++) {
		str.at(i) = toupper(str.at(i));
	}

	return str;
}