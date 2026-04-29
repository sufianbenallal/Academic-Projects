#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define ARRAY_SIZE 10

int main(int argc, char *argv[]) {

  int myarray[ARRAY_SIZE];
  int fd, last_num;
  off_t file_size;

  fd = open("myfile.bin", O_RDWR | O_CREAT, 0600);
  if (fd == -1) {
    perror("Error opening file");
    exit(-1);
  }

  file_size = lseek(fd, 0, SEEK_END);
  last_num = file_size / sizeof(int);

  for (int i = 0; i < ARRAY_SIZE; i++)
    myarray[i] = last_num + i + 1;

  write(fd, myarray, ARRAY_SIZE * sizeof(int));

  close(fd);

  return 0;
}
