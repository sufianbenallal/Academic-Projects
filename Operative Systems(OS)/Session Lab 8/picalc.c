#include <stdio.h>
#include <stdlib.h>
#include "integrate.h"
#include "f.h"

int main(int argc, char* argv[]){
  long ndiv;
  double x1, x2, result;

  if(argc != 2) {
    printf("Usage: %s <number of integral steps>\n", argv[0]);
    exit(-1);
  }

  x1 = 0.0;
  x2 = 1.0;
  ndiv = atol(argv[1]);

  tr_integrate(&result, x1, x2, ndiv, f);
  printf("Valor calculado: %.14lf\n", 4 * result);

  return 0;
}

