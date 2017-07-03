#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

static Nodo u[]= {
  {'a', NULL, NULL},
  {'b', NULL, NULL},
  {'c', NULL, NULL},
  {'d', NULL, NULL},
  {'e', NULL, NULL},
  {'f', NULL, NULL},
  {'g', NULL, NULL},
  {'h', NULL, NULL}};

Nodo *abb(Nodo *a, int i, int j) {
	Nodo *node = a+1;
	printf("%c\n", node->x);
	return NULL;  
}

int main() {
	abb(u,0,7);
	return 0;
}