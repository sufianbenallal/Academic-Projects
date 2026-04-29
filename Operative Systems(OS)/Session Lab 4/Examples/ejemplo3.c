#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*int main( int argc, char* argv[]){

    pid_t pid1, pid2;
    
    if( (pid1=fork()) != 0){ 
      if( (pid2=fork()) != 0){ 
        printf("Padre: esperando a que acabe el Hijo 1...\n");
        printf("Padre: Hijo 1 finalizado. Esperando a que acabe el Hijo 2...\n");
        printf("Padre: Hijo 2 finalizado. THE END.\n");
      } else {
        printf("Hijo 2: durmiendo unos segundos...\n");
        sleep( 2); 
        printf("Hijo 2: despertado y finalizando.\n");
      }   
    } else {
        printf("Hijo 1: durmiendo unos segundos...\n");
        sleep( 3); 
        printf("Hijo 1: despertado y finalizando.\n");
    }   

    return 0;
}
*/

int main( int argc, char* argv[]){

    pid_t pid1, pid2;
    
    if( (pid1=fork()) != 0){ 
      if( (pid2=fork()) != 0){ 
        printf("Padre: esperando a que acabe el Hijo 1...\n");
	waitpid(pid1, NULL, 0);
        printf("Padre: Hijo 1 finalizado. Esperando a que acabe el Hijo 2...\n");
	waitpid(pid2, NULL, 0);
        printf("Padre: Hijo 2 finalizado. THE END.\n");
      } else {
        printf("Hijo 2: durmiendo unos segundos...\n");
        sleep( 2); 
        printf("Hijo 2: despertado y finalizando.\n");
      }   
    } else {
        printf("Hijo 1: durmiendo unos segundos...\n");
        sleep( 3); 
        printf("Hijo 1: despertado y finalizando.\n");
    }   

    return 0;
}
