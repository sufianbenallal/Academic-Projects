//
// Created by sufia on 16/12/2022.
//
#define CRT_SECURE_NO_WARNINGS

#include "Estadistica.h"

void MostrarAlumno(tficha Ficha) // muestra los datos del alumno que anteriormente hemos introducido
{
    int i = 0;
    printf("El nombre del alumno %d es:\t%s.\n", i + 1, Ficha.nombre);
    printf("El dni del alumno %d es:\t%s.\n", i + 1, Ficha.dni);
    printf("La nota del alumno %d es:\t%lf.\n", i + 1, Ficha.nota);
    printf("La segunda nota del alumno %d es:\t%lf.\n", i + 1, Ficha.nota2);
}
void MostrarAlumnos(tficha Fichas[], int num) // Análogo al anterior pero mostraria el de todos
{
    int i;
    printf("NOMBRE         DNI                 NOTA\n");
    printf("======        ======               ======\n");

    for (i = 0; i < num; i++)
        MostrarAlumno(Fichas[i]);
}

int ImprimeEstadistica(int cont[], int num, double suma) // Saca en pantalla los resultados de la estadistica hecha con otro comando llamado ImprimeEstadística
{

    if (cont[0] != 0)
        printf("El porcentaje de suspensos es de: %lf.\n", ((double)cont[4] / num) * 100);
    if (cont[1] != 0)
        printf("El porcentaje de suspensos es de: %.lf.\n", ((double)cont[3] / num) * 100);
    if (cont[2] != 0)
        printf("El porcentaje de suspensos es de: %.lf.\n", ((double)cont[2] / num) * 100);
    if (cont[3] != 0)
        printf("El porcentaje de suspensos es de: %.lf.\n", ((double)cont[1] / num) * 100);
    if (cont[4] != 0)
        printf("El porcentaje de suspensos es de:%.lf.\n", ((double)cont[0] / num) * 100);
    if (cont[5] != 0)
        printf("La media entre las dos notas es de:%lf.\n", ((double)cont[5]/ num) * 100);
    else
        suma = suma / num;
    printf("La media de las notas es:%.2f.\t", suma);
}
char Calificaciones[NUM_NOTAS][20] =
        {
                "Matricula", "Sobresaliente","Notable","Aprobado","Suspenso"
        };
