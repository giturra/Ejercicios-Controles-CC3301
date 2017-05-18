#include <stdio.h>
#include <math.h>
#include "integral.h"

double g(double x, double y) {
  return sin(x+y);
}

/* integral_g_dx(y, xi, xf, n) ~=
 *                    integral sin(x+y) dx en [xi,xf]
 *                  = integral sin(x) dx en [xi+y, xf+y]
 *                  = (-cos(xf+y)) - (-cos(xi+y))
 *
 * integral integral_g_dx(y) dy en [yi, yf]=
 *                    integral -cos(xf+y) - (-cos(xi+y)) dy en [yi, yf]
 *                  = - integral cos(xf+y) dy en [yi, yf] +
 *                      integral cos(xi+y) dy en [yi, yf]
 *                  = - integral cos(y) dy en [xf+yi, xf+yf] +
 *                      integral cos(y) dy en [xi+yi, xi+yf]
 *                  = - ( sin(xf+yf) - sin(xf+yi) ) +
 *                      ( sin(xi+yf) - sin(xi+yi) )
 */

int main() {
  double xi= 0.0, xf= 0.5;
  double yi= 0.0, yf= 1.0;
  double numerico= integral_g_dx_dy(xi, xf, 100, yi, yf, 200);

  double algebraico= - ( sin(xf+yf) - sin(xf+yi) ) +
                       ( sin(xi+yf) - sin(xi+yi) );

  printf("Numerico= %f, Algebraico= %f, error= %f\n",
        numerico, algebraico, numerico-algebraico);
  printf("A mi me dio un error de -0.000001\n");
  return 0;
}
