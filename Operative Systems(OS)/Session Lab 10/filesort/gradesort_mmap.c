#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
#include "filesort.h"

int gradesort( int fd)
{
  int i, j, nswaps = 0, nelem, swap;
  struct evaluation *pe, temp;
  struct stat s;

	fstat(fd,&s);
	int tam= s.st_size;
  /* TO-DO: Obtain file size */

  pe =  (struct evaluation*) mmap(NULL,tam,PROT_READ| PROT_WRITE,MAP_SHARED,fd,0);
/* TO-DO: Map the file */
  if( pe == MAP_FAILED)
  {
    perror("Error mapping file)");
    exit( -1);
  }

 nelem=tam/sizeof(struct evaluation);
 /* TO-DO: Calculate the number of items in the file */

  for( i=0; i < nelem ; i++){
    swap = 0;
    for( j=0 ; j<nelem-i-1; j++)
      if(pe[j].avgrade < pe[j+1].avgrade)
 /* TO-DO: Check if the items are in correct order */
      {
        temp=pe[j];
			pe[j]=pe[j+1];
			pe[j+1]=temp;
/* TO-DO: Swap the items */
        swap = 1;
        nswaps++;
      }
    if( swap == 0)
      break;
  }
  munmap(pe,s.st_size);
  /* TO-DO: Unmap the file */
  return nswaps;
}

