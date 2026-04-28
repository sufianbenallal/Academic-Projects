#include "funciones.h"
using namespace std;

vector<vector<float>> ConstruirMatriz(int nFilas, int nColumnas)
{
	vector<vector<float>> array(nFilas);
	for (int i = 0; i < nFilas; i++) {
		array[i] = vector<float>(nColumnas);
	}
	for (int i = 0; i < nFilas; i++) {
		for (int j = 0; j < nColumnas; j++) {
			array[i][j] = 0;
		}
	}
	return array;
}

void IntroducirDatos(vector<vector<float>>& array)
{
	if (array.size() == 0) {
		cout << "No existe matriz. Pulsa la opcion 1 para crear una." << endl;
		system("pause");
	}
	else {
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[i].size(); j++) {
				cout << "Intoduce el valor de fila " << i + 1 << " y columna " << j + 1 << endl;
				cin >> array[i][j];
			}
		}
	}
}


void Mostrar(vector<vector<float>>& array)
{

	if (array.size() == 0)
	{
		cout << "No existe matriz. Pulsa opcion 1 para crear una." << endl;
	}
	else {
		for (int i = 0; i < array.size(); i++)
		{
			for (int j = 0; j < array[i].size(); j++) {
				cout << array[i][j] << "        ";
			}
			cout << endl;
		}
	}
}