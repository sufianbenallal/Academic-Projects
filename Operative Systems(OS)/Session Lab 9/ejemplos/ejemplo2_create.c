#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define SHM_NAME "/my_shm"

int main( int argc, char* argv[]){

  int fd; 
  long * p_x;

  fd = shm_open( SHM_NAME, O_CREAT | O_RDWR, 0600);
  if( fd == -1){
    perror( "Error creating shared memory object");
    exit( -1);
  }

  ftruncate( fd, sizeof( long));

  p_x = (long *) mmap( NULL, sizeof( long), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); 
  if( p_x == MAP_FAILED){
    perror( "Error mapping shared memory object");
    exit( -1);
  }

  *p_x = 0;

  return 0;
}
