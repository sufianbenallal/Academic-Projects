#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define START_VAL 100000000

void mysigaction( int n, siginfo_t * info, void * context);

int main( int argc, char* argv[]){

    long i, j;

    struct sigaction a;
    struct sigaction b;

    a.sa_sigaction = mysigaction;
    sigemptyset( &a.sa_mask);
    a.sa_flags = SA_SIGINFO;
    
    b.sa_sigaction = mysigaction;
    sigemptyset( &b.sa_mask);
    b.sa_flags = SA_SIGINFO;

    sigaction( SIGINT, &a, NULL);
    sigaction( SIGUSR1, &b, NULL);

    for( i = START_VAL; ; i++){
      for( j = 2 ; j < i; j++)
        if ((i % j) == 0)
          break;
      if( j == i)
        printf("%ld\n", i); 
    }   

    return 0;
}

void mysigaction( int n, siginfo_t * info, void * context){

    if(n==SIGINT){
    	printf("It is a good day to die... but the day is not yet over.\n");
    	printf("PID = %d\n",info->si_pid);
    	signal( SIGINT, SIG_DFL);
    }
    if(n==SIGUSR1){
    	printf("¡He recibido una señal de usuario!\n");
    	printf("PID = %d\n",info->si_pid);
 
   	signal( SIGUSR1, SIG_DFL);
    }
    
    
}
