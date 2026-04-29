#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include "ejemplo5.h"

int consume_item( unsigned int data);
void dump_system_status( struct txfer_data * d);

int main( int argc, char* argv[]){
  
  int fd;
  struct txfer_data * d;
  size_t memsize = sizeof( struct txfer_data);

  fd = shm_open( SHM_NAME, O_RDWR, 0);
  if( fd == -1){
    perror( "Error opening shared memory object");
    exit( -1);
  }

  d = (struct txfer_data *) mmap( NULL, memsize, PROT_READ | PROT_WRITE, 
                                  MAP_SHARED, fd, 0);
  if( d == MAP_FAILED){
    perror( "Error mapping shared memory object");
    exit( -1);
  } 
    
  unsigned int thedata;
  int retval;
  
  do{ 
    while( d->count == 0);
    thedata = d->buffer[d->out];
    retval = consume_item( thedata);
    if( retval == -1){
      dump_system_status( d);
      exit( -1);
    }
    d->out = (d->out + 1) % BUFFER_SIZE;
    d->count--;
  } while( 1);
  
  return 0;
}

int consume_item( unsigned int data){

  static unsigned int refdata = 1; /* First expected integer is 1 */

  if( data == refdata){
    if( data % 10000 == 0) /* Prints something every 10000 items received */
      printf("Got expected data: %u\n", data);
  }
  else{
    printf("Corrupt data!! Expected %u, got %u!\n", refdata, data);
    return( -1);
  }
  refdata++;

  if( CONS_DELAY_US) usleep( CONS_DELAY_US);

  return 0;
}

void dump_system_status( struct txfer_data * d){

  printf("System status: count = %u, in = %u, out = %u.\n", 
          d->count, d->in, d->out);
  printf("Buffer contents:\n");
  for( int i = 0; i < BUFFER_SIZE; i++)
    printf("buffer[%d] = %d\n", i, d->buffer[i]);
}
