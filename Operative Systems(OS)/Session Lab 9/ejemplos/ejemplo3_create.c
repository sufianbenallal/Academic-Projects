#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>
#include "ejemplo3.h"

int main( int argc, char* argv[]){

  int fd; 
  struct shared_data * p;
  size_t shm_size = sizeof( struct shared_data);

  fd = shm_open( SHM_NAME, O_CREAT | O_RDWR, 0600);
  if( fd == -1){
    perror( "Error creating shared memory object");
    exit( -1);
  }

  ftruncate( fd, shm_size);

  p = (struct shared_data *) mmap( NULL, shm_size, PROT_READ | PROT_WRITE, 
                                   MAP_SHARED, fd, 0); 
  if( p == MAP_FAILED){
    perror( "Error mapping shared memory object");
    exit( -1);
  }

  p->x = 0;
  sem_init( &p->sem, 1, 1); 

  return 0;
}
