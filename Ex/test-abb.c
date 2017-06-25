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

static void mostrar(Nodo *a, int lvl) {
  int i;
  for (i= 0; i<lvl; i++)
    putchar(' ');

  if (a==NULL) {
    printf("NULL\n");
  }
  else {
    printf("%c\n", a->x);
    mostrar(a->izq, lvl+2);
    mostrar(a->der, lvl+2);
  }
}

int main() {
  Nodo *t= abb(u, 0, 7);
  mostrar(t, 0);
  return 0;
}
