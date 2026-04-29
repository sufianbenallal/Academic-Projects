#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        int estado_hijo;

        if (fork() != 0) {
                printf("Padre: esperando a que finalice el proceso hijo...\n");
                int pid_hijo = wait(&estado_hijo);
                printf("Padre: hijo (PID=%d) finalizado con estado %d.\n", pid_hijo, WEXITSTATUS(estado_hijo));
        } else {
                printf("Hijo: durmiendo unos segundos...\n");
                sleep(1);
                printf("Hijo: finalizando.\n");
                exit(1);
        }
        return 0;
}
