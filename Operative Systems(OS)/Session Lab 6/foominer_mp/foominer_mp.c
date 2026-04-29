#include <stdio.h> 
#include <stdlib.h> 
#include <stdint.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <errno.h> 
#include "foominer_mp.h"


int main( int argc, char* argv[])
{
  int difficulty, nminers, status;
  char * blockfile;
  uint32_t nonce_start = FOOMINER_NONCE_START, nonce_end=FOOMINER_NONCE_END;
  pid_t pid;

  if( argc < 4){
    printf("Too few arguments.\nUsage:\n");
    printf("%s <block file> <difficulty> <num miners>\n", argv[0]);
    return -1;
  }

  blockfile = argv[1];
  difficulty = atoi( argv[2]);
  nminers = atoi( argv[3]);

  struct foominer_data miner[nminers];

  foominer_distribute_workload( nonce_start, nonce_end, miner, nminers);

  for( int i = 0; i < nminers; i++) {
    /* 1: Create miner processes and use foominer_exec() */
    pid = fork();

  if (pid == 0) {
      foominer_exec(blockfile, difficulty, &miner[i]);
      exit(-1);
  } else if (pid > 0) {
      miner[i].pid = pid;
  } else {
      perror("fork");
      return -1;
  }
}

  int minersrunning = nminers;

  while( minersrunning > 0){

    /* 2: Wait for a miner process to end */
   pid = wait(&status);
    minersrunning--;
    int miner_index = foominer_miner_ended( pid, miner, nminers);

    if( WIFEXITED( status)){
      switch(WEXITSTATUS(status)){
        case -1:
          printf("Miner %d (PID=%d) reports error status. Terminating others and exiting.\n", miner_index, pid);
          foominer_miner_kill_remaining( miner, nminers);
          return -1;
        case 0:
          printf("Miner %d (PID=%d) reports nonce found. Terminating other miners.\n", miner_index, pid);
          foominer_miner_kill_remaining( miner, nminers);
          return 1;
        case 1:
          printf("Miner %d (%d) reports no solution found.\n", miner_index, pid);
          break;
      }
    } 
    else {
      printf("Miner %d (%d) crashed. Terminating others and exiting.\n", miner_index, pid);
      foominer_miner_kill_remaining( miner, nminers);
      return -1;
    }
  }
  printf("All miners ended and no solution found.\n");
  return 0;
}

int foominer_exec( char * blockfile, int difficulty, struct foominer_data * miner){

    /* 4: execute miner using execve(). Return -1 in case of error */
  char difficulty_str[12];
  char nonce_start_str[20];
  char nonce_end_str[20];
  
  sprintf(difficulty_str, "%d", difficulty);
  sprintf(nonce_start_str, "%u", miner->nonce_start);
  sprintf(nonce_end_str, "%u", miner->nonce_end);

  execlp(FOOMINER_MINER_PROG, FOOMINER_MINER_PROG, blockfile, difficulty_str, nonce_start_str, nonce_end_str, NULL);
  return -1;
}


void foominer_distribute_workload( uint32_t nonce_start, uint32_t nonce_end, struct foominer_data * miner, int nminers){

  uint32_t workload;

  for( int i = 0; i < nminers; i++){
    miner[i].nonce_start = nonce_start;
    workload = (nonce_end-nonce_start)/(nminers-i);
    miner[i].nonce_end = nonce_start + workload;
    nonce_start+=workload;
  }
} 

int foominer_miner_ended( int pid, struct foominer_data * miner, int nminers){
  for( int i = 0; i < nminers; i++)
    if( miner[i].pid == pid){
      miner[i].pid = 0;
      return i;
    }
}

void foominer_miner_kill_remaining( struct foominer_data * miner, int nminers){
        /* 3: Terminate all remaining active miner processes */
	for (int i = 0; i < nminers; i++) {
            if (miner[i].pid != 0) {
                kill(miner[i].pid, SIGTERM);
            }
        }
}


