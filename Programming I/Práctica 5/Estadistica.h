//
// Created by sufia on 16/12/2022.
//

#ifndef UNTITLED_ESTADISTICA_H
#define UNTITLED_ESTADISTICA_H
#define CRT_SECURE_NO_WARNINGS
#define MAX_ALUM 100
#define MAX_CAD 20
#define NUM_NOTAS 5

#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char nombre[MAX_CAD];
    char dni[MAX_CAD];
    double nota;
    double nota2;
}tficha;

int main();
tficha LeeAlumno();
int LeeCadena(char cadena[], int max);
int PedirDatos(tficha[]);
void MostrarAlumno(tficha Ficha);
void MostrarAlumnos(tficha Fichas[], int num);
int ImprimeEstadistica(int cont[], int num, double suma);
int CalcularEstadistica(tficha Fichas[], int cont[], int num);



#endif //UNTITLED_ESTADISTICA_H

