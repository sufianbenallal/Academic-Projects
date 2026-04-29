#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int fd;
    struct stat fileStat;

    fd = open("myfile.bin", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        exit(-1);
    }

    if (fstat(fd, &fileStat) == -1) {
        perror("Error getting file information");
        exit(-1);
    }
    off_t fileSize = fileStat.st_size;

    int* dataBuffer = (int*)malloc(fileSize);
    if (dataBuffer == NULL) {
        perror("Memory allocation failed");
        exit(-1);
    }

    ssize_t bytesRead = read(fd, dataBuffer, fileSize);
    if (bytesRead == -1) {
        perror("Error reading file");
        exit(-1);
    }

    close(fd);

    printf("Data read from file:\n");
    int numElements = bytesRead / sizeof(int);
    for (int i = 0; i < numElements; i++) {
        printf("%d\n", dataBuffer[i]);
    }

    free(dataBuffer);

    return 0;
}

