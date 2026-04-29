#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integrate.h"

//funcion mia
 double my_f(double x) {
     return 1.0 / sqrt(1.0 + x*x);
 }


int main( int argc, char* argv[]){

  long ndiv;
  double x1, x2, result;

  if( argc < 4)
  {
    printf("Invalid arguments. Usage:\n");
    printf("%s <x start> <x end> <number of integral steps>\n", argv[0]);
    exit( -1);
  }

  x1 = atof(argv[1]);
  x2 = atof(argv[2]);
  ndiv = atol(argv[3]);

  /* TO-DO: integrate using the tr_integrate() function */
  tr_integrate(&result, x1, x2, ndiv, my_f);
  
  printf("Calculated value: %.14lf\n", result);

  return(0);
}
