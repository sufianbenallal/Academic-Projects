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
    struct sigaction c;

    a.sa_sigaction = mysigaction;
    sigemptyset( &a.sa_mask);
    a.sa_flags = SA_SIGINFO;


    b.sa_sigaction = mysigaction;
    sigemptyset( &b.sa_mask);
    b.sa_flags = SA_SIGINFO;
    
    c.sa_sigaction = mysigaction;
    sigemptyset( &c.sa_mask);
    c.sa_flags = SA_SIGINFO;


    sigaction( SIGINT, &a, NULL);

    sigaction( SIGUSR1, &b, NULL);
    
    sigaction( SIGALRM, &c, NULL);
    alarm(10);
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
    printf("PID= %d \n", info->si_pid);
    signal( SIGINT, SIG_DFL);
   }
   else if(n==SIGUSR1){
    printf("Recibido USR1.\n");
    printf("PID= %d \n", info->si_pid);
    signal( SIGUSR1, SIG_DFL);
   }
   else if(n==SIGALRM){
    printf("Recibido ALRM.\n");
    printf("PID= %d \n", info->si_pid);
    //signal( SIGALRM, SIG_DFL);
    exit(1); 
   }

}
