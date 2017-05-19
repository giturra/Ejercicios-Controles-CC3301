#include <stdio.h>
#include "integral.h"

/* Programe aca la funcion integral */
double integral(Funcion f, void *p, double xi, double xf, int n) {
	double nd = (double) n;
	double h = (xf - xi)/nd;
	double t = (f(p, xi) + f(p,xf))/2.0;
	double sum = 0.0;
	int k = 1;
	for (; k < n; ++k) {
		sum += f(p, xi + k*h);
	}
	double result = h*(t + sum);
	return result;
}