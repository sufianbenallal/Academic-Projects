#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void mysigaction( int n, siginfo_t * info, void * context);
long niter, i;
double piq;

int main( int argc, char *argv[])
{
  double xdelta, ydelta;
  long in, out;
  int temp;

  if( argc != 3)
  {
    printf("Invalid number of arguments. Usage:\n");
    printf("%s <iterations>\n", argv[0]);
    exit( -1);
  }

  niter = atol(argv[1]);
  temp = atoi(argv[2]);

  alarm(temp);

  in = out = 0;
  srand48( time( NULL));
  
  struct sigaction c;
  c.sa_sigaction = mysigaction;
  sigemptyset( &c.sa_mask);
  c.sa_flags = SA_SIGINFO;
  sigaction( SIGALRM, &c, NULL);
  
  printf("Proceso lanado (PID=%d).\n", getpid());

  for( i = 0; i < niter; i++)
  {
    xdelta = drand48()-0.5;
    ydelta = drand48()-0.5;

    if( xdelta*xdelta + ydelta*ydelta <= 0.25)
      in++;
    else
      out++;
     piq=(double)in/(double)(in + out);
  }

  printf("Finalizado después de %ld iteraciones.\n", niter);
  printf("Valor calculado: %lf\n", 4*piq);

  return 0;
}

void mysigaction( int n, siginfo_t * info, void * context){

    if(n==SIGALRM){
    	  printf("Finalizado por timeout tras %ld iteraciones.\n", i);
  	  printf("Valor calculado: %lf\n", 4*piq);
    	exit(1);
    }
}
