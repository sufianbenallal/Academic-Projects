#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "MemoryManager.h"

struct MatFloat
{
	int nFilas; // Número de filas
	int nColumnas; // Número de columnas
	float** ppMatrizF; // Datos de la matriz
};

float** ConstruirMatriz(int nFilas, int nColumnas);
void IntroducirDatos(MatFloat* pDestino);
void Mostrar(MatFloat mOrigen);
void Destruir(MatFloat* pMatFloat);