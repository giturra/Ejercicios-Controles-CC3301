#include <stdio.h>
#include "p1.h"

int buscar(void *a, int n, void *x, Comparador cmp) {
	int inicio = 0;
	int final = n - 1;
	int centro = 0;
	while (inicio <= final) {
		centro = ((final - inicio)/2) + inicio;
		int valor = cmp(a, centro, x);
		//printf("%d\n", valor);
		if (valor == 0) {
			return centro;
		} 
		else if (valor > 0) {
			final = centro - 1;
		} else {
			inicio = centro + 1;
		}
	}
	return -1;
}