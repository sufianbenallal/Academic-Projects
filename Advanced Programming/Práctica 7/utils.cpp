#define _CRT_SECURE_NO_WARNINGS
#include "utils.h"
#include <iostream>
#include <string>
#include <new>

using namespace std;
using namespace utils;

bool CUtils::LeerInt(int& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{
		cin >> dato; //vamos a eliminar caracteres sobrantes
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin.exceptions(ios::goodbit);
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			cin.exceptions(ios::goodbit);
			return false;
		}
		else
		{
			cout << e.what() << ": Dato no valido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			return LeerInt(dato);
		}
	}
}

bool CUtils::LeerFloat(float& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin.exceptions(ios::goodbit);
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			cin.exceptions(ios::goodbit);
			return false;
		}
		else
		{
			cout << e.what() << ": Dato no valido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			return LeerFloat(dato);
		}
	}
}

bool CUtils::LeerDouble(double& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{
		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin.exceptions(ios::goodbit);
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			cin.exceptions(ios::goodbit);
			return false;
		}
		else
		{
			cout << e.what() << ": Dato no valido\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			return LeerDouble(dato);
		}
	}
}

bool CUtils::LeerDato(string& dato)
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{
		getline(cin, dato); //leer variable de tipo string
		cin.exceptions(ios::goodbit);
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof()) //si pulsamos ctrl+z
		{
			cin.clear();
			cin.exceptions(ios::goodbit);
			return false;
		}
		else
		{
			cout << e.what() << ": El dato no es valido.";
			cin.clear();
			return LeerDato(dato);
		}
	}
}

bool utils::CUtils::LeerDato(char* dato)
{
	int error;
	char cadena[10];
	strcpy(cadena, dato);
	int n = strlen(cadena);
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{
		cin.getline(dato, 10);
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		cin.exceptions(ios::goodbit);
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			cin.exceptions(ios::goodbit);
			return false;
		}
		else
		{
			cout << e.what() << ": el dato no es valido." << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			return LeerDato(dato);
		}
	}
}

char* CUtils::ConverMayus(char* str)
{
	int i;
	char cad[10];
	strcpy(cad, str);
	for (i = 0; i < strlen(cad); i++)
	{
		cad[i] = toupper(cad[i]);
	}
	return cad;
}

string& CUtils::ConverMayus(string& str)
{
	int i;
	for (i = 0; i < str.size(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

int CUtils::CrearMenu(const char* opciones_menu[], int num_opciones)
{
	int i, op;
	for (i = 1; i <= num_opciones; i++)
	{
		cout << i << "." << opciones_menu[i - 1] << endl;
	}
	do
	{
		cout << "Escoge una opcion del menu: ";
		CUtils::LeerInt(op);
	} while (op < 1 || op > num_opciones);
	return op;
}