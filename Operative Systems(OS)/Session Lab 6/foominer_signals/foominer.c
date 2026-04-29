#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include "foominerlib.h"
#include <signal.h>
#include <time.h>

int sigint_count = 0;
time_t ultimo_sigint = 0;

void mysigaction(int signum, siginfo_t *info, void *context);


int main( int argc, char* argv[]){

  int difficulty;
  uint32_t nonce_start, nonce_end, nonce_sol;
  struct fooblock b;
  char * blockfile;

  struct sigaction a;
  a.sa_sigaction = mysigaction;
  sigemptyset(&a.sa_mask);
  a.sa_flags = SA_SIGINFO;

  struct sigaction c;
  c.sa_sigaction = mysigaction;
  sigemptyset( &c.sa_mask);
  c.sa_flags = SA_SIGINFO;

  struct sigaction d;
  d.sa_sigaction = mysigaction;
  sigemptyset(&d.sa_mask);
  d.sa_flags = SA_SIGINFO;

  sigaction(SIGUSR1, &a, NULL);
  sigaction( SIGINT, &c, NULL);
  sigaction(SIGALRM, &d, NULL);

  if( argc < 5){ 
    printf("Too few arguments.\nUsage:\n");
    printf("%s <block file> <difficulty> <nonce start> <nonce end>\n", argv[0]);
    return -1; 
  }

  blockfile = argv[1];
  difficulty = atoi( argv[2]);
  nonce_start = (uint32_t) atol( argv[3]);
  nonce_end = (uint32_t) atol( argv[4]);

  if( fooblock_load( blockfile, &b) == -1)
    return -1;
    
  if( fooblock_mine( &b, difficulty, nonce_start, nonce_end, &nonce_sol) == 0){
    printf("(%d) found nonce %u is valid.\n", getpid(), nonce_sol);
    fooblock_save_solved( blockfile, &b, nonce_sol);
    return 0;
  }
  printf("(%d) Nonce not found.\n", getpid());
  return 1;
}

void mysigaction(int signum, siginfo_t *info, void *context) {
    if (signum == SIGUSR1) {
        printf("Miner (%d) working, %u hashes checked.\n", getpid(), hashes);

    } else if (signum == SIGINT) {
	time_t current;
	time(&current);
	int dif = current - ultimo_sigint;

        if (sigint_count == 0) {
            printf("\nRequesting miner status.\n");
	    raise(SIGUSR1);
     	    printf("Press Ctrl+C again within 2 seconds to terminate.\n");
	    sigint_count = 1;
 	    ultimo_sigint = current;
	    alarm(2);

         } else if (dif < 2) {
            printf("\nTermination requested.\n");
            exit(1);
        }

     } else if (signum == SIGALRM) {
            if (sigint_count == 1) {
                printf("Termination cancelled.\n");
                sigint_count = 0;
        }
    }
}
