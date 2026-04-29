#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char* argv[]){

  int fd, data;

  fd = open( "myfile.bin", O_RDONLY);
  if( fd == -1){
    perror("Error opening file");
    exit( -1);
  }

  while( read( fd, &data, sizeof( int)) != 0)
    printf("%d\n", data);

  close( fd);

  return 0;
}
