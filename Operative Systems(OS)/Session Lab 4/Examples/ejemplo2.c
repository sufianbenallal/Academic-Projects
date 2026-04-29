#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/*int main( int argc, char* argv[]){

    if( fork() != 0){ 
        printf("Padre: esperando a que finalice el proceso hijo...\n");
        printf("Padre: hijo finalizado.\n");
    } else {
        printf("Hijo: durmiendo unos segundos...\n");
        sleep( 1); 
        printf("Hijo: finalizando.\n");
    }   

    return 0;
}
*/

int main(int argc, char* argv[]) {

	if (fork() != 0) {
		printf("Padre: esperando a que finalice el proceso hijo...\n");
        	int pid_hijo = wait(NULL);
        	printf("Padre: hijo (%d) finalizado.\n", pid_hijo);
	} else {
        	printf("Hijo: durmiendo unos segundos...\n");
        	sleep(1);
       		printf("Hijo: finalizando.\n");
	}
	return 0;
}
