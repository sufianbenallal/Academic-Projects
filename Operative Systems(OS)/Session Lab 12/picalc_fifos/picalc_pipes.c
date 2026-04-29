#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "picalc_pipes.h"

void dispatcher(int workfd, long nwp, long nstep) {
    long package_size = nstep / nwp;
    long remainder = nstep % nwp;

    for (long i = 0; i < nwp; i++) {
        long start = i * package_size;
        long end = (i + 1) * package_size;
        if (i == nwp - 1) {
            end += remainder;
        }
        write(workfd, &start, sizeof(long));
        write(workfd, &end, sizeof(long));
    }
}

void worker(int workfd, int resultfd) {
    long start, end;
    while (read(workfd, &start, sizeof(long)) > 0 && read(workfd, &end, sizeof(long)) > 0) {
        double sum = 0.0;
        for (long i = start; i < end; i++) {
            double x = (i + 0.5) / (double) end;
            sum += 4.0 / (1.0 + x * x);
        }
        write(resultfd, &sum, sizeof(double));
    }
}

void gatherer(int resultfd) {
    double sum = 0.0;
    double partial_sum;
    while (read(resultfd, &partial_sum, sizeof(double)) > 0) {
        sum += partial_sum;
    }
    printf("Calculated value: %lf\n", sum);
}

