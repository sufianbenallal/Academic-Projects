#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "picalc_pipes.h"

int main( int argc, char* argv[]){

  long nstep, nwp, nworkers;
  int workfd[2], resultfd[2];

  if( argc < 4){ 
    printf("Incorrect arguments. Usage:\n");
    printf("%s <integral divisions> <number of work packages> <number of worker processes>\n", argv[0]);
    printf("\nTerminating.\n");
    return( -1);
  }

  nstep = atol(argv[1]);
  nwp = atol(argv[2]);
  nworkers = atol(argv[3]);

  if( pipe(workfd) ){
    perror("Error creating work pipe.");
    exit( -1);
  }
  if( pipe(resultfd) ){
    perror("Error creating results pipe.");
    exit( -1);
  }

  /* TO-DO: Create process to model gatherer                */
  if (fork() == 0) {
    /* TO-DO: In the new process,                             */
    /* TO-DO: - Close unused pipe descriptors                 */
    close(workfd[0]);
    close(workfd[1]);
    close(resultfd[1]);
    /* TO-DO: - Invoke function that models process behaviour */
    gatherer(resultfd[0]);
    /* TO-DO: - When done, close remaining pipe descriptors   */
    close(resultfd[0]);
    /* TO-DO: - And terminate process                         */
    exit(0);
  }

  for( int i = 0 ; i < nworkers; i++){
    /* TO-DO: Create processes to model workers               */
    if (fork() == 0) {
      /* TO-DO: In each of the new processes,                   */
      /* TO-DO: - Close unused pipe descriptors                 */
      close(workfd[1]);
      close(resultfd[0]);
      /* TO-DO: - Invoke function that models process behaviour */
      worker(workfd[0], resultfd[1]);
      /* TO-DO: - When done, close remaining pipe descriptors   */
      close(workfd[0]);
      close(resultfd[1]);
      /* TO-DO: - And terminate process                         */
      exit(0);
    }
  }

  /* TO-DO: Create process to model dispatcher              */
  if (fork() == 0) {
    /* TO-DO: In the new process,                             */
    /* TO-DO: - Close unused pipe descriptors                 */
    close(workfd[0]);
    close(resultfd[0]);
    close(resultfd[1]);
    /* TO-DO: - Invoke function that models process behaviour */
    dispatcher(workfd[1], nwp, nstep);
    /* TO-DO: - When done, close remaining pipe descriptors   */
    close(workfd[1]);
    /* TO-DO: - And terminate process                         */
    exit(0);
  }

  /* TO-DO: Close all pipe descriptors. (Why?)              */
  close(workfd[0]);
  close(workfd[1]);
  close(resultfd[0]);
  close(resultfd[1]);

  /* TO-DO: Wait for all processes to finish                */
  for (int i = 0; i < nworkers + 2; i++)
    wait(NULL);

  return(0);
}
