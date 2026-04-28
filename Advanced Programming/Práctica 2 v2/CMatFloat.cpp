#include <vector>
#include <iostream>
#include "CMatFloat.h"
using namespace std;

void CMatFloat::Iniciar() //inicilizamos igual que en la parte 1 todo a 0 
{
	m_nFilas = 0;
	m_nColumnas = 0;
}

void CMatFloat::CrearMatriz2D(int nFilas, int nColumnas)
{
	m_nFilas = nFilas; //asignamos los valores adecuados como nos piden para filas y columnas
	m_nColumnas = nColumnas;

	if (m_nFilas == 1) //si tenemos una sola dimension -> crearmatriz1D
	{
		CrearMatriz1D(nColumnas);
		return;
	}
	else //matriz de 2D
	{
		vector<vector<float>> v(nFilas, vector<float>(nColumnas, 0)); //sentencia igual que en la practica anterior para crear el vector
		m_ppDatosF = v; //los datos se guardaran en V
	}
}

void CMatFloat::CrearMatriz1D(int nElementos)
{
	m_nColumnas = nElementos; //en vez de ncol y nfilas tenemos nelem porque solo tenemos 1 fila y sus elementos
	vector<vector<float>> v(1, vector<float>(nElementos, 0)); //igual que arriba pero en 1D
	m_ppDatosF = v;
}

void CMatFloat::Introducir()
{
	if (m_ppDatosF.size() == 0) {
		cout << "No existe matriz. Pulsa la opcion 1 'o' 2 para crear una." << endl;
		system("pause");
	}
	else {
		for (int i = 0; i < m_ppDatosF.size(); i++)
		{
			for (int j = 0; j < m_ppDatosF[i].size(); j++) {
				cout << "Intoduce el valor de fila " << i + 1 << " y columna " << j + 1 << endl;
				cin >> m_ppDatosF[i][j];
			}
		}
	}
}

void CMatFloat::Mostrar()
{
	if (m_ppDatosF.size() == 0)
	{
		cout << "No existe matriz. Pulsa opcion 1 'o' 2 para crear una." << endl;
	}
	else {
		for (int i = 0; i < m_ppDatosF.size(); i++)
		{
			for (int j = 0; j < m_ppDatosF[i].size(); j++) {
				cout << m_ppDatosF[i][j] << "        ";
			}
			cout << endl;
		}
	}
}