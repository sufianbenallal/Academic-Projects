#include<iostream>
#include"utils.h"
#include"CHora.h"
#include<string>
#include<cstdlib>
#include "MemoryManager.h"

using namespace std;
using namespace utils;



char* CUtils::ConverMayus(char* str)//convertir cadena a mayusculas
{
	if (str == 0)
		return 0;
	int longitud = strlen(str);
	for (int i = 0; i < longitud; i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

string& CUtils::ConverMayus(string& str)
{
	int longitud = str.size();
	for (int i = 0; i < longitud; i++)
	{
		str.at(i) = toupper(str.at(i));
	}
	return str;
}

bool CUtils::LeerDato(int& dato) //pag 428
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{

		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			return false; //se pulso Ctrl+Z
		}
		else
		{
			cout << e.what() << ": dato no valido \n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Vuelva a introducir el dato: ";
			return LeerDato(dato);
		}
	}
}

bool CUtils::LeerDato(float& dato) //pag 428
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{

		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			return false; //se pulso Ctrl+Z
		}
		else
		{
			cout << e.what() << ": dato no valido \n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Vuelva a introducir el dato: ";
			return LeerDato(dato);
		}
	}
}

bool CUtils::LeerDato(double& dato) //pag 428
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{

		cin >> dato;
		cin.ignore(numeric_limits<int>::max(), '\n');
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			return false; //se pulso Ctrl+Z
		}
		else
		{
			cout << e.what() << ": dato no valido \n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Vuelva a introducir el dato: ";
			return LeerDato(dato);
		}
	}
}

bool CUtils::LeerDato(string& dato) //pag 428
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{
		getline(cin, dato);
		cin.ignore(numeric_limits<int>::max(), '\n');
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			return false; //se pulso Ctrl+Z
		}
		else
		{
			cout << e.what() << ": dato no valido \n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Vuelva a introducir el dato: ";
			return false;
		}
	}
}

bool CUtils::LeerDato(char* dato, int n) //pag 428
{
	cin.exceptions(ios::failbit | ios::badbit);
	try
	{

		cin.getline(dato, n);
		cin.ignore(numeric_limits<int>::max(), '\n');
		return true;
	}
	catch (ios_base::failure& e)
	{
		if (cin.eof())
		{
			cin.clear();
			return false; //se pulso Ctrl+Z
		}
		else
		{
			cout << e.what() << ": dato no valido \n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cout << "Vuelva a introducir el dato: ";
			return false;
		}
	}
}

int CUtils::menu(char* opciones[], int numOpciones)
{
	int i;
	int opcion = 0;
	cout << "\n\n___________________________________________________\n\n" << endl;
	for (i = 1; i <= numOpciones; ++i)
		cout << "     " << opciones[i - 1] << endl;
	cout << "___________________________________________________\n";
	do
	{
		cout << "\nOpcion (1 - " << numOpciones << "): ";
		LeerDato(opcion);
	} while (opcion<1 || opcion>numOpciones);

	return opcion;
}

void VisualizarHora(const CHora& horaVisu)
{
	int hh, mm, ss;
	string ff;
	horaVisu.ObtenerHora(hh, mm, ss, ff);
	cout << "Formato: " << "Hora: " << "Minutos: " << "Segundos: " << endl;
	cout << ff << ": " << hh << ": " << mm << ": " << ss << endl;
	system("pause");
}

void VisualizarFicha(CFicha& ficha)
{
	std::string nombre = ficha.ObtenerNombre();
	int edad = ficha.ObtenerEdad();
	CHora hora = ficha.ObtenerNacio();
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
	VisualizarHora(hora);
	system("Pause");
}

