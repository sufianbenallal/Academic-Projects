#define CRT_SECURE_NO_WARNINGS


#include"Estadistica.h"

int main()
{
    tficha Fichas[MAX_ALUM];
    char identificador_de_la_cadena[MAX_CAD];
    int num;
    int cont[5] = {0};
    printf("PROGRAMA ESTADISTICA.\n\n");
    printf("=========================");
    printf("\n");
    printf("Numero de alumnos (MAX: 100)\n");
    printf("\n\n");
    num = PedirDatos(Fichas);
    if (num > 0)
    {
        //MostrarAlumno(Ficha);
        MostrarAlumnos(Fichas,num);
        CalcularEstadistica(Fichas, cont, num);
    }
}
