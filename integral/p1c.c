#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "integral.h"

/* Programe aca la funcion integral_g_dx_dy_par */

typedef struct {
	double xi, xf;
	double yi, yf;
	double n, m;
	double result;
	pthread_t pid;
} Args;

void *integral_g_dx_dy_thread(void *ptr) {
	Args *args = (Args*)ptr;
	args->result = integral_g_dx_dy(args->xi, args->xf, args->n, 
		args->yi, args->yf, args->m);
	//printf("%f\n", args->result);
	return NULL;
}

double integral_g_dx_dy_par(double xi, double xf, int n,
                            double yi, double yf, int m) {
	double total = 0.0;
	Args *args_a = (Args*)malloc(8*sizeof(Args));
	int i = 0;
	double h = (yf - yi) / 8.0;
	double c = 0.0;
	while (i != 8) {
		Args *args = &args_a[i];
		args->xi = xi;
		args->xf = xf;
		args->n = n;
		args->yi = yi + c;
		c += h;
		args->yf = yi + c;
		args->m = m;
		pthread_create(&args->pid, NULL, integral_g_dx_dy_thread, args);
		i++;
		
	}

	i = 0;
	for (; i < 8; ++i) {
		Args *args = &args_a[i];
		pthread_join(args->pid, NULL);
		total += args->result;
	}

	return total;
}

