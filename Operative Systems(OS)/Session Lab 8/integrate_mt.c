 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include "integrate_mt.h"
#include "integrate.h"

void * tr_integrate_thread(void * arg);

int tr_integrate_mt( double * result, double x1, double x2, long nstep, int nthreads, double(*f)(double)){

  int i;

  struct th_work w[nthreads];
  pthread_t th[nthreads];
	pthread_mutex_t exmut= PTHREAD_MUTEX_INITIALIZER;
	double myresult=0;/* TO-DO: Declare additional variables, if needed                   */
  /* TO-DO: Declare thread-related resources and variables            */

  th_distribute_work( w, nthreads, x1, x2, nstep);

  for( i=0; i<nthreads; i++){
    w[i].f=f;
		w[i].presult=&myresult;
		w[i].pmutex = &exmut;
		pthread_create(&th[i],NULL,tr_integrate_thread,&w[i]);
		/* TO-DO: Complete the struct th_work data for the thread         */
    /* TO-DO: Create thread.                                          */
  }

  for(i=0; i<nthreads; i++)
    pthread_join(th[i],NULL);/* TO-DO: Wait for each thread to finish                          */
     *result=myresult; 
  /* TO-DO: Perform final tasks, if needed                            */    
  return(0);
}

void * tr_integrate_thread(void * arg)
{
  double result;
	struct th_work *w = (struct th_work *) arg;
	tr_integrate(&result, w->x_start, w->x_end, w->n_steps, w->f);
	pthread_mutex_lock(w->pmutex);
	*(w->presult) +=result;
	pthread_mutex_unlock(w->pmutex);
	/* TO-DO: Declare  variables to handle the arg and perform the      */
  /*        necessary type conversion                                 */
    
  /* TO-DO: Use tr_integrate() to integrate the part assigned to the  */
  /*        thread and store it in the local result variable          */
    
  /* TO-DO: Update the main result variable in mutual exclusion       */

  pthread_exit( NULL);
}

void th_distribute_work( struct th_work * w, int n_th, double x_start, double x_end, unsigned long total_steps){

  int i;
  double stepsize = (x_end - x_start)/total_steps;

  for( i=0; i<n_th; i++)
  {
    w[i].x_start = x_start;
    w[i].n_steps = total_steps / ( n_th - i);
    w[i].x_end = x_start + w[i].n_steps * stepsize;
    total_steps -= w[i].n_steps;
    x_start = w[i].x_end;
  }
}
