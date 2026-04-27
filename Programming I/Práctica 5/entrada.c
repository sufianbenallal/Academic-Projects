//
// Created by sufia on 16/12/2022.
//
#define _CRT_SECURE_NO_WARNINGS

#include "Estadistica.h"

int PedirDatos(tficha Fichas[]) // Recoge el nº de alumnos de la clase
{
    int num = 0, i;
    printf("Introduzca el numero de alumnos de la clase:\n\n");
    scanf_s("%d", & num);

    while (getchar() != '\n');

    for (i = 0; i < num; i++)
        Fichas[i] = LeeAlumno();

    return i;
}

tficha  LeeAlumno() // Recoge el nombre,DNI y nota del alumno
{
    int i = 0;
    tficha Ficha;
    printf("Introduzca el nombre del alumno numero %d.\n", i + 1);
    LeeCadena(Ficha.nombre, MAX_CAD);

    printf("Introduzca el DNI del alumno numero %d.\n", i + 1);
    scanf("%s", &Ficha.dni);
    while (getchar() != '\n');

    printf("Introduzca la nota del alumno numero %d.\n", i + 1);
    scanf_s("%lf", &Ficha.nota);
    while (getchar() != '\n');

    printf("Introduzca la segunda nota del alumno numero %d.\n", i + 1);
    scanf_s("%lf", &Ficha.nota2);
    while (getchar() != '\n');

    return Ficha;
}


int LeeCadena(char cadena[], int max) //lee la cadena de caracteres que introducimos a traves del teclado
{
    char* p;
    int n;
    p = fgets(cadena, max, stdin);
    if (p != NULL);
    {
        n = strlen(cadena);
        if (n > 0 && cadena[n - 1] == '\n')
            cadena[n - 1] = '\0';
    }
    return n ;
}
