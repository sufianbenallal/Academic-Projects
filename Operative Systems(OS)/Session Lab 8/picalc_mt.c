#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "integrate_mt.h"
#include "f.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <número de hilos> <número de divisiones>\n", argv[0]);
        return 1;
    }

    int n_threads = atoi(argv[1]);
    long n_divisions = atol(argv[2]);

    if (n_threads <= 0 || n_divisions <= 0) {
        printf("Ambos argumentos deben ser enteros positivos.\n");
        return 1;
    }

    double result;
    int error = tr_integrate_mt(&result, 0.0, 1.0, n_divisions, n_threads, f);

    if (error != 0) {
        printf("Error al calcular la integral.\n");
        return 1;
    }

    result *= 4;

    printf("Valor calculado: %.14lf\n", result);
    return 0;
}
