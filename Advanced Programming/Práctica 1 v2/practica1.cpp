#include "funciones.h"
#include "MemoryManager.h"

using namespace std;

void menu();
void clearScreen();

int main()
{
	int opcion;
	vector<vector<float>> matriz;
	do {
		clearScreen();
		menu();
		cout << "Selecciona una opcion del menu:" << endl;
		cin >> opcion;

		clearScreen();
		switch (opcion)
		{
		case 1:
			cout << "1. Construir matriz" << endl;
			int filas, columnas;
			cout << "Introduzca el numero de filas:" << endl;
			cin >> filas;
			cout << "Introduzca el numero de columnas:" << endl;
			cin >> columnas;
			do
			{
				cout << "El numero de filas o columnas debe ser mayor que 0 " << endl;
				cout << "Introduzca el numero de filas:" << endl;
				cin >> filas;
				cout << "Introduzca el numero de columnas:" << endl;
				cin >> columnas;
			} while (filas < 1 || columnas < 1);
			matriz = ConstruirMatriz(filas, columnas);
			break;
		case 2:
			cout << "2. Introducir matriz" << endl;
			IntroducirDatos(matriz);
			break;
		case 3:
			cout << "3. Volcar matriz" << endl;
			Mostrar(matriz);
			system("pause");
			break;
			/*case 4:
				cout<<"4. Destruir matriz"<<endl;
				Destruir(&matriz);
				system("pause");
				break;*/
		case 4:
			cout << "5. Terminar" << endl;
			clearScreen();
			break;
		default:
			cout << "Introduce un numero del 1 al 5:" << endl;
			system("pause");
			break;
		}

	} while (opcion != 4);
	return 0;
	MemoryManager::dumpMemoryLeaks();
}


void menu()
{
	cout << "1. Construir matriz" << endl;
	cout << "2. Introducir matriz" << endl;
	cout << "3. Volcar matriz" << endl;
	cout << "4. Terminar" << endl;
}

void clearScreen()
{
	if (system("CLS"))
		system("clear");
}