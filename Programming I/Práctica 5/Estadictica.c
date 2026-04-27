//
// Created by sufia on 16/12/2022.
//
#define CRT_SECURE_NO_WARNINGS

#include "Estadistica.h"

int CalcularEstadística(tficha Fichas[],int cont[],int num) // hace calculo estadístico a raíz de los datos que hemos metido por teclado
{
    int i = 0;
    for (i = 0; i < num; i++)
    {
        if ((Fichas[i].nota >= 0) && (Fichas[i].nota < 5)) cont[4]++;
        else if ((Fichas[i].nota >= 5) && (Fichas[i].nota < 7)) cont[3]++;
        else if ((Fichas[i].nota >= 7) && (Fichas[i].nota > 9)) cont[2]++;
        else if ((Fichas[i].nota >= 9) && (Fichas[i].nota > 10)) cont[1]++;
        else if (Fichas[i].nota == 10) cont[0]++;
        else if ((Fichas[i].nota /0.6)&&(Fichas[i].nota2 /0.4))cont[5]++;
    }
    return i;
}
