#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "picalc_pipes.h"

int main(int argc, char* argv[]) {
    int workfd;
    int resulfd;
    int perm = 0;

    if (argc < 3) { 
        printf("Incorrect arguments. Usage:\n");
        printf("%s <work FIFO> <results FIFO> [<permanent>]\n", argv[0]);
        printf("\nTerminating.\n");
        return -1;
    }

    if (argc == 4)
        if (strcmp(argv[3], "permanent") == 0)
            perm = 1;

    do {
        if ((workfd = open(argv[1], O_RDONLY)) == -1) {
            perror("Error opening work pipe.");
            exit(-1);
        }

        if ((resulfd = open(argv[2], O_WRONLY)) == -1) {
            perror("Error opening results pipe.");
            exit(-1);
        }

        /* Invoke function that models process behaviour */
        worker(workfd, resulfd);

        /* When done, close the pipe descriptors */
        close(workfd);
        close(resulfd);
    } while (perm == 1);

    return 0;
}

