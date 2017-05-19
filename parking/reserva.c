#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#include "reserva.h"

/* Implemente aca las funciones reservar y liberar */

pthread_mutex_t m;
pthread_cond_t c;

int es[5] = {0, 0, 0, 0, 0};

int ubicar(int k);

int ubicar(int k) {
	if (k == 1) {
		int i = 0;
		for (; i < 5; ++i) {
			if (es[i] == 0) {
				return i;
			}
		} 
	}
	else if (k == 2) {
		int i = 0;
		for(; i < 5; ++i) {
			if (i == 4) {
				return -1;
			}
			if (es[i] == 0 && es[i+1] == 0){
				return i;
			}
		}
	}
	else if (k == 3) {
		int i = 0;
		for(; i < 5; ++i) {
			if (i == 3) {
				return -1;
			}
			if (es[i] == 0 && es[i+1] == 0 && es[i+2] == 0){
				return i;
			}
		}	
	}
	return -1;
}

int reservar(char *nom, int k) {
	int len = strlen(nom);
	char *nombre = malloc(sizeof(char)*len+1);
	nombre[len+1] = 0;
	int i = 0;
	for (; i < len; ++i) {
		nombre[i] = nom[i];
	}
	pthread_mutex_lock(&m);
	int val = ubicar(k);
	while (val == -1) {
		pthread_cond_wait(&c, &m);
	}
	if (k == 1) {
		es[val] = 1;
	} 
	else if (k == 2) {
		es[val] = es[val+1] = 1;
	}
	else if (k == 3) {
		es[val] = es[val + 1] = es[val+2] = 1;
	}
	pthread_mutex_unlock(&m);
	return val;
}
void liberar(char *nom) {
	pthread_mutex_lock(&m);
	free(nom);
}

