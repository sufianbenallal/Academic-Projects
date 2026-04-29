#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "picalc_pipes.h"

int main(int argc, char *argv[]) {

    long nworkers;

    char workfifopath[] = "work";
    char resultfifopath[] = "result";

    char dispatcherpath[] = "picalc_dispatcher";
    char gathererpath[] = "picalc_gatherer";
    char workerpath[] = "picalc_worker";

    if (argc < 4) {
        printf("Incorrect arguments. Usage:\n");
        printf("%s <integral divisions> <number of work packages> <number of worker processes>\n", argv[0]);
        printf("\nTerminating.\n");
        return (-1);
    }

    nworkers = atol(argv[3]);

    /* Create work and results FIFOs */
    mkfifo(workfifopath, 0666);
    mkfifo(resultfifopath, 0666);

    /* Create process to launch gatherer */
    if (fork() == 0) {
        char *myargv[] = {gathererpath, resultfifopath, NULL};
        char *myenvp[] = {NULL};
        execve(gathererpath, myargv, myenvp);
        perror("execve");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nworkers; i++) {
        /* Create process to launch worker */
        if (fork() == 0) {
            char *myargv[] = {workerpath, workfifopath, resultfifopath, NULL};
            char *myenvp[] = {NULL};
            execve(workerpath, myargv, myenvp);
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }

    /* Create process to launch dispatcher */
    if (fork() == 0) {
        char *myargv[] = {dispatcherpath, argv[1], argv[2], workfifopath, NULL};
        char *myenvp[] = {NULL};
        execve(dispatcherpath, myargv, myenvp);
        perror("execve");
        exit(EXIT_FAILURE);
    }

    /* Wait for all processes to finish */
    for (int i = 0; i < nworkers + 2; i++) {
        wait(NULL);
    }

    /* Cleanup FIFOs */
    unlink(workfifopath);
    unlink(resultfifopath);

    return (0);
}

