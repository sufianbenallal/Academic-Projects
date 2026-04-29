#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "picalc_pipes.h"

int main(int argc, char* argv[]) {
    int resulfd;
    int perm = 0;

    if (argc < 2) {
        printf("Incorrect arguments. Usage:\n");
        printf("%s <results FIFO> [<permanent>]\n", argv[0]);
        printf("\nTerminating.\n");
        return -1;
    }

    if (argc == 3)
        if (strcmp(argv[2], "permanent") == 0)
            perm = 1;

    do {
        if ((resulfd = open(argv[1], O_RDONLY)) == -1) {
            perror("Error opening results pipe.");
            exit(-1);
        }

        /* Invoke function that models process behaviour */
        gatherer(resulfd);

        /* When done, close the pipe descriptor */
        close(resulfd);
    } while (perm == 1);

    return 0;
}

