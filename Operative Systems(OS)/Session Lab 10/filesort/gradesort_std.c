#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "filesort.h"

int gradesort( int fd)
{
  int i, j, nswaps = 0, nelem, swap;
  struct evaluation e1, e2;
  struct stat s;
	fstat(fd,&s);
  int tam= s.st_size;
/* TO-DO: Obtain file size */
  nelem= tam/ sizeof(struct evaluation);
/* TO-DO: Calculate the number of items in the file */

  for( i=0; i < nelem-1; i++)
  {
    swap = 0;
    lseek(fd,0,SEEK_SET);
/* TO-DO: Set file offset at beginning of file for each pass */
    for( j=0; j<nelem-i-1; j++)
    {
      read(fd,&e1,sizeof(struct evaluation));
			read(fd,&e2,sizeof(struct evaluation));
/* TO-DO: Read the next two items from file */
      if(e1.avgrade < e2.avgrade)
      {
        lseek(fd,-2*sizeof(struct evaluation),SEEK_CUR);
				write(fd,&e2,sizeof(struct evaluation));
				write(fd,&e1,sizeof(struct evaluation));
/* TO-DO: Save the two items in the file swapping their positions */
        swap=1;
        nswaps++;
      }
      lseek(fd,-sizeof(struct evaluation),SEEK_CUR);
  /* TO-DO: Set file offset at the correct position for next read */
    }
    if( swap == 0)
      break;
  }

  return nswaps;
}

