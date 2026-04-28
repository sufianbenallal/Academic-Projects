#include <iostream>
#include "utils.h"
#include "CMatFloat.h"
#include <new>
#include "MemoryManager.h"

using namespace std;

int main()
{
	{
	int op = 0;
	int nFilas = 0, nColumnas = 0, numelem = 0;
	CMatFloat Matriz; //utilizamos la clase para crear un objeto 
	//si quisieramos añadir un 2º objeto por ejemplo, matriz2 tendriamos que añadir sus sentencias en cada case y funcinonaria igual

	Matriz.Iniciar(); //inicializamos la matriz, poniendo todo a 0

	do
	{
		const char* opciones_menu[] =
		{
			"Construir matriz 1D",
			"Construir matriz 2D",
			"Introducir matriz",
			"Mostrar matriz",
			"Destruir matriz",
			"Terminar"
		};

		int num_opciones;
		num_opciones = (sizeof(opciones_menu) / sizeof(const char*));

		switch (op = CrearMenu(opciones_menu, num_opciones))
		{
		case 1:
		{
			cout << "\n Introduce el numero de elementos: ";
			cin >> numelem;
			while (cin.fail())
			{
				cout << " Introduce un nº valido: ";
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				cin >> numelem;
			}
			Matriz.CrearMatriz1D(numelem);
			cout << "La matriz ha sido creada :D \n";
			break;
		}

		case 2:
		{
			cout << "Introduce el n de filas: ";
			cin >> nFilas;
			while (cin.fail())
			{
				cout << " Introduce un nº valido: ";
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				cin >> nFilas;
			}
			cout << endl;

			cout << " Introduce el n de columnas: ";
			cin >> nColumnas;
			while (cin.fail())
			{
				cout << " Introduce un nº valido: ";
				cin.clear();
				cin.ignore(numeric_limits<int>::max(), '\n');
				cin >> nColumnas;
			}
			cout << endl;

			Matriz.CrearMatriz2D(nFilas, nColumnas);
			cout << endl << "La matriz ha sido creada :D\n";
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			//Introducir matriz.
			Matriz.Introducir();
			break;
		}

		case 4:
		{
			Matriz.Mostrar();
			break;
		}

		case 5:
		{
			//Destruir matriz.
			Matriz.Destruir();
			cout << "\nLa matriz ha sido destruida. " << endl;
			break;
		}

		case 6:
		{
			//Terminar			
			system("pause");
		}
		}

	} while (op != 7);
	return 0;
}
	MemoryManager::dumpMemoryLeaks();
	return 0;
}