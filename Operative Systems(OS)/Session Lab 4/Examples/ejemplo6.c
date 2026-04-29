#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(char argc, char* argv[]) {
    char *myargv[] = { "./ejemplo6b", "Uno", "Dos", "Tres", "Catorce!", NULL };
    char *myenv[] = { NULL };

    printf("Me. (PID: %d)\n", getpid());

    int estado_hijo;
    pid_t pid_hijo = fork();

    if (pid_hijo < 0) {
        perror("Error al crear el proceso hijo");
        exit(-1);
    }

    if (pid_hijo == 0) {
        if (execve(myargv[0], myargv, myenv) == -1) {
            perror("Error lanzando el programa de ejemplo.");
            exit(-1);
        }
    } else {
        wait(&estado_hijo);

        if (WIFEXITED(estado_hijo)) {
            printf("Hijo finalizado con valor de salida %d.\n", WEXITSTATUS(estado_hijo));
        } else {
            printf("Hijo finalizado de manera anormal.\n");
        }
    }

    return 0;
}
