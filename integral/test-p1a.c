#include <stdio.h>
#include <math.h>
#include "integral.h"

double sin_fun(void *p, double x) {
  return sin(x);
}

int main() {
  double numerico= integral(sin_fun, NULL, 0.0, 1.0, 100);
  /* integral sin(x) dx = -cos(x) */
  double algebraico= (-cos(1.0)) - (-cos(0.0));
  printf("Numerico= %f, Algebraico= %f, error= %f\n",
        numerico, algebraico, numerico-algebraico);
  printf("A mi me dio un error de -0.000004\n");
  return 0;
}
