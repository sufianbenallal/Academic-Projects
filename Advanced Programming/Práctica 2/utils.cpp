#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include <iostream>
#include <string>
#include <new>

using namespace std;

int LeerInt()
{
	int error, num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit; //comprobacion de error
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		if (error != 0 || num < 0)
		{
			cout << "Error, introduce un numero." << endl;
		}
	} while (error != 0 || num < 0);
	return num;
}


float LeerFloat()
{
	int error;
	float num;
	do
	{
		cin >> num;
		error = cin.rdstate() & ios::failbit;
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		if (error != 0)
			cout << "Error, introduce un numero." << endl;

	} while (error != 0);
	return num;
}

int CrearMenu(const char* opciones_menu[], int num_opciones)
{
	int i, op;

	for (i = 1; i <= num_opciones; i++)
	{
		cout << i << "." << opciones_menu[i - 1] << endl;
	}

	do
	{
		cout << "Escoja una opcion del menu: ";
		op = LeerInt();
	} while (op < 1 || op > 7);

	return op;
}