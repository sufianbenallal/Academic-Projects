//
// Created by sufia on 22/11/2022.
//
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Diccionario.h"


int main()
{
    char identificador_de_la_cadena[MAX_CAD];
    tPalabra Diccionario[MAX_PAL];
    int num_pal = 0;
    int opcion;

    printf("PROGRAMA DICCIONARIO\n");
    printf("===============\n");

    while ((opcion = menu()) != 4)

    {
        switch (opcion)
        {
            case 1:
            {
                num_pal = anyadir_palabra(Diccionario, num_pal);
                printf("[%d]palabras existentes\n", num_pal);
                system("pause");
                break;
            }
            case 2:
            {
                traducir_palabra(Diccionario, num_pal);
                system("pause");
                break;
            }
            case 3:
            {
                mostrar_diccionario(Diccionario, num_pal);
                system("pause");
                break;
            }
        }
    }
}
