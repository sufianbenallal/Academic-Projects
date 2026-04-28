#include <iostream>
#include "CMatFloat.h"
#include <new>
#include "MemoryManager.h"

using namespace std;

void CMatFloat::Iniciar()
{
	m_ppDatosF = NULL;
	m_nFilas = 0;
	m_nColumnas = 0;
}

//con CrearMatriz2D y pasarle numFilas = 1, te sobra la funcion crearMatriz1D
void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	int i;
	int j;
	m_nFilas = nFilas;
	m_nColumnas = nColumnas;

	if (m_nFilas == 1)
	{
		CrearMatriz1D(nColumnas); //lo comentado arriba, con este if ya haces la funcion 1D
		return;
	}

	else
	{ // f = new float *[10];
		m_ppDatosF = (float**)new float* [nFilas];
		if (m_ppDatosF == NULL)
		{
			cout << "La memoria es insuficiente.";
			delete[] m_ppDatosF; //como la memoria es insuficiente porque hay datos, los borramos/liberamos
			return;
		}
		else
		{
			for (i = 0; i < nFilas; i++)
			{
				m_ppDatosF[i] = (float*)new float[nColumnas];
				if (m_ppDatosF == NULL)
				{
					for (j = 0; j < i; j++)
					{
						delete[] m_ppDatosF[j];
					}
					delete[] m_ppDatosF; //esta sentencia es como el free
				}
				for (j = 0; j < i; j++)
				{
					m_ppDatosF[i][j] = 0; // ponemos a 0 todas las celdas posibles(filas y columnas)
				}
			}
		}
	}
}


void CMatFloat::CrearMatriz1D(int nElementos)
{
	int i;
	m_nColumnas = nElementos;
	m_nFilas = 1;
	m_ppDatosF = (float**)new float* [1]; //solo necesitamos una dimension de filas
	if (m_ppDatosF == NULL)
	{
		cout << "La memoria es insuficiente.";
		delete[] m_ppDatosF;
		return;
	}
	else
	{
		m_ppDatosF[0] = (float*)new float[nElementos]; // solo nos interesa rellenar la 1ª fila
		if (m_ppDatosF[0] == NULL)
		{
			delete[] m_ppDatosF[0]; // liberamos memoria
			delete[] m_ppDatosF;
		}
		else
		{
			for (i = 0; i < nElementos; i++)
			{
				m_ppDatosF[0][i] = 0; //ponemos todas las celdas de la fila a 0
			}
		}
	}
}


void CMatFloat::Introducir()
{
	int i, j;
	if (m_ppDatosF == NULL) //siempre comprobar!!
	{
		cout << " La matriz no ha sido creada. \n" << endl;
		return;
	}

	else
	{
		for (i = 0; i < m_nFilas; i++)
		{
			for (j = 0; j < m_nColumnas; j++)
			{
				cout << "\nIntroduce dato: [" << i << ", " << j << "] ";
				cin >> m_ppDatosF[i][j];
				while (cin.fail())
				{
					cout << " Introduce un nº valido: ";
					cin.clear();
					cin.ignore(numeric_limits<int>::max(), '\n');
					cin >> m_ppDatosF[i][j];
				}
			}
		}
	}
}

void CMatFloat::Mostrar()
{
	int i, j;
	if (m_ppDatosF == NULL)
	{
		cout << " La matriz no ha sido creada. \n" << endl;
		return;
	}
	else
	{
		for (i = 0; i < m_nFilas; i++)
		{
			for (j = 0; j < m_nColumnas; j++)
			{
				cout << m_ppDatosF[i][j] << "   "; //muestra por pantalla los datos introducidos
			}
			cout << endl;
		}
	}
}

void CMatFloat::Destruir()
{
	int i;
	if (m_ppDatosF == NULL)
	{
		cout << "\nLa matriz no ha sido creada.\n" << endl;
		return;
	}

	else
	{
		for (i = 0; i < m_nFilas; i++)
		{
			delete[] m_ppDatosF[i]; //hace lo mismo que un free, borramos los datos de la matriz
		}
		delete[] m_ppDatosF; //borramos los datos de la matriz 
		Iniciar();
	}
}


bool CMatFloat::Existe()
{
	if (m_ppDatosF != NULL)
		return true;
}