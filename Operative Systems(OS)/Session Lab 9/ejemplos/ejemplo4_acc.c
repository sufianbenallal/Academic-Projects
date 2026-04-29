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

  fd = shm_open( SHM_NAME, O_RDWR, 0);
  if( fd == -1){
    perror( "Error opening shared memory object");
    exit( -1);
  }

  p = (struct shared_data *) mmap( NULL, shm_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if( p == MAP_FAILED){
    perror( "Error mapping shared memory object");
    exit( -1);
  } 

  long aux = 0;
  for( long i = 0; i < 100000000; i++){
    aux++;
  }

  sem_wait( &p->sem);
  p->x += aux;
  sem_post( &p->sem); 

  printf("Final x value: %ld\n", p->x);

  return 0;
}
