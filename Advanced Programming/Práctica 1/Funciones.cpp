#define _CRT_SECURE_NO_DEPRECATE
#include "funciones.h"
#include "MemoryManager.h"

using namespace std;

float** ConstruirMatriz(int nFilas, int nColumnas)
{
	int i, j, k;
	float** matrix;
	matrix = (float**)malloc(nFilas * sizeof(float*));
	if (matrix == NULL)
	{
		cout << "El puntero sigue sin tener memoria.\n";
		return NULL;
	}
	else
	{
		for (i = 0; i < nFilas; i++)
		{
			matrix[i] = (float*)malloc(nColumnas * sizeof(float));
			if (matrix[i] == NULL)
			{
				cout << "El puntero sigue teniendo espacio de memoria insuficiente.\n";
				for (j = 0; j < i; j++)
				{
					free(matrix[j]);
				}
				free(matrix);
				return NULL;
			}
			else
			{
				for (k = 0; k < nColumnas; k++)
				{
					matrix[i][k] = 0;
				}
			}
		}
		return matrix;
	}
}

void IntroducirDatos(MatFloat* pDestino)
{
	int i;
	int j;
	int x;
	float c;

	if (pDestino->ppMatrizF == NULL)
	{
		cout << "La matriz no ha sido creada todavía.\n";
		return;
	}

	else
	{
		cout << "Introducir los datos de la matriz.\n";
		for (i = 0; i < pDestino->nFilas; i++)
		{
			for (j = 0; j < pDestino->nColumnas; j++)
			{
				cin >> pDestino->ppMatrizF[i][j];
				while (cin.fail())
				{
					cout << "Introduzca un dato valido";
					cin.clear();									//borramos el bit de error
					cin.ignore(numeric_limits<int>::max(), '\n');
					cin >> pDestino->ppMatrizF[i][j];
				}
			}
		}
	}
}

void Mostrar(MatFloat mOrigen)
{
	int i, j;
	if (mOrigen.ppMatrizF == NULL)
	{
		cout << "La matriz no ha sido creada todavia.\n";
		return;
	}
	else
	{
		for (i = 0; i < mOrigen.nFilas; i++)
		{
			for (j = 0; j < mOrigen.nColumnas; j++)
			{
				cout << mOrigen.ppMatrizF[i][j] << "        ";
			}
			cout << endl;
		}
	}
}

void Destruir(MatFloat* pMatFloat)
{
	int i;
	if (pMatFloat->ppMatrizF == NULL)
	{
		cout << "La matriz no ha sido creada todavia.\n\n";
		return;
	}
	else
	{
		for (i = 0; i < pMatFloat->nFilas; i++)
		{
			free(pMatFloat->ppMatrizF[i]);
		}
		free(pMatFloat->ppMatrizF); //liberamos el espacio de la matriz que queda 
		pMatFloat->ppMatrizF = NULL; //ponemos ppmatrizf a null
		pMatFloat->nFilas = 0; //ponemos a 0 el puntero que apunta al nº de filas y, luego a las columnas 
		pMatFloat->nColumnas = 0;
		cout << " Matriz liberada y borrada.\n \n";
	}

}