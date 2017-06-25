#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>

#include "reparar.h"

static Nodo *abb(char x, Nodo *izq, Nodo *der) {
  Nodo *a= malloc(sizeof(*a));
  a->x= x;
  a->izq= izq;
  a->der= der;
  return a;
}

static Nodo *hoja(char x) {
  return abb(x, NULL, NULL);
}

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

#define INVALID ((Nodo*)(intptr_t)1)

int main() {
  printf("1er. test\n");
  Nodo *b= INVALID;
  reparar(&b);
  mostrar(b, 0);

  printf("\n2do. test\n");
  Nodo *t= hoja('t');
  Nodo *r= hoja('r');
  Nodo *u= abb('u', t, NULL);
  Nodo *s= abb('s', r, u);
  r->izq= t-> izq= u->der= INVALID;

  reparar(&s);
  mostrar(s, 0);

  return 0;
}
