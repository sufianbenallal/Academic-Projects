#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/*int main( int argc, char* argv[]){
    
    fork();
    printf("La verdad; no sé quién soy.\n");
    sleep(1);
    
    return 0;
}
*/
/*
int main( int argc, char* argv[]){
	int pid;
	pid = fork();
	if(pid==0)
		printf("Soy (%d), mi padre es (%d).\n", getpid(), getppid());
	else
    		printf("Soy (%d), mi hijo es (%d).\n", getpid(), pid);
	return 0;
}
*/
int main( int argc, char* argv[]){
        int pid;
        pid = fork();
        if(pid==0)
                printf("Soy (%d), mi padre es (%d).\n", getpid(), getppid());
        else {
                printf("Soy (%d), mi hijo es (%d).\n", getpid(), pid);
		wait(NULL);
	}
        return 0;
}
