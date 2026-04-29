#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define SHM_NAME "/my_shm"
#define SHM_STRBUF_SIZE 80

int main( int argc, char* argv[]){

  int fd; 
  char * strbuf;

  fd = shm_open( SHM_NAME, O_CREAT | O_RDWR, 0600);
  if( fd == -1){
    perror( "Error creating shared memory object");
    exit( -1);
  }

  ftruncate( fd, SHM_STRBUF_SIZE);

  strbuf = (char *) mmap( NULL, SHM_STRBUF_SIZE, PROT_READ | PROT_WRITE, 
                          MAP_SHARED, fd, 0); 
  if( strbuf == MAP_FAILED){
    perror( "Error mapping shared memory object");
    exit( -1);
  }

  strcpy( strbuf, "Hello, world!!");

  munmap(strbuf, SHM_STRBUF_SIZE);
  close(fd);
  return 0;
}
