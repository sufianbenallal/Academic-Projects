#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main( char argc, char* argv[]){

  char * myargv[] = { "/bin/programa_que_no_existe", "-l", NULL};
  char * myenv[] = { NULL};

  if( execve( myargv[0], myargv, myenv) == -1){
    perror( "Error lanzando el programa de ejemplo.");
    exit( -1);
  }

  printf("Boo!!\n");

  return 0;
}
