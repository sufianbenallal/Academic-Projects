#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "funciones.h"
#include "MemoryManager.h"

using namespace std;
void clearScreen();
void menu();

int main()
{
	{
		int op;
		int dato = 0;
		MatFloat matriz;
		matriz.ppMatrizF = NULL;
		matriz.nFilas = 0;
		matriz.nColumnas = 0;
		do
		{
			clearScreen();
			menu();
			cout << " Elige la opcion deseada: ";
			cin >> op;
			clearScreen();

			if (op < 1 || op > 5)
			{
				cout << " La opcion deseada no existe, pulse un nuevo numero: \n";
				//op = 0;
				//return -1;
			}
			else
			{
				switch (op)
				{
				case 1:

					dato = 0;
					if (matriz.ppMatrizF != NULL)
					{
						cout << " Hay una matriz existente. Debe borrarla antes de continuar.\n";
						system("pause");
						break;
					}
					else
					{
						cout << " Opcion 1: Construir matriz de datos.\n";
						cout << "\n";
						cout << "Introducir las dimensiones de la matriz : \n";
						do
						{
							cout << " Nº de filas. ";
							dato = scanf("%d", &matriz.nFilas);
							while (getchar() != '\n')
								continue;
						} while (!dato || matriz.nFilas < 1);

						do
						{
							cout << " Nº de columnas. ";
							dato = scanf("%d", &matriz.nColumnas);
							while (getchar() != '\n')
								continue;
						} while (!dato || matriz.nColumnas < 1);
					}
					matriz.ppMatrizF = ConstruirMatriz(matriz.nFilas, matriz.nColumnas);
					cout << " Matriz creada \n\n";
					system("pause");
					break;

				case 2:
					cout << " Opcion 2: Introducir matriz.\n";
					cout << "\n";
					IntroducirDatos(&matriz);
					system("pause");
					break;
				case 3:
					cout << " Opcion 3: Volcar matriz.\n";
					cout << "\n";
					Mostrar(matriz);
					system("pause");
					break;
				case 4:
					cout << " Opcion 4: Destruir matriz.\n";
					Destruir(&matriz);
					system("pause");
					break;
				case 5:
					cout << " Opcion 5: Terminar.\n";
					Destruir(&matriz);
					system("pause");
					return 0;
				}
			}
		} while (op > 1 || op < 5);
	}
	MemoryManager::dumpMemoryLeaks();
}

void clearScreen()
{
	if (system("CLS"))
		system("clear");
}

void menu()
{
	cout << "1. Construir matriz" << endl;
	cout << "2. Introducir matriz" << endl;
	cout << "3. Volcar matriz" << endl;
	cout << "4. Destruir matriz" << endl;
	cout << "5. Terminar" << endl;
}