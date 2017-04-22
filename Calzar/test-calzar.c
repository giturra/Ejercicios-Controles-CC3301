#include <stdio.h>
#include <stdlib.h>

#include "calzar.h"

Nodo *abb(int x, Nodo *izq, Nodo *der) {
  Nodo *a= malloc(sizeof(*a));
  a->x= x;
  a->izq= izq;
  a->der= der;
  return a;
}

Nodo *hoja(int x) {
  return abb(x, NULL, NULL);
}

void mostrar(Nodo *a, int lvl) {
  int i;
  for (i= 0; i<lvl; i++)
    putchar(' ');

  if (a==NULL) {
    printf("NULL\n");
  }
  else {
    printf("%d\n", a->x);
    mostrar(a->izq, lvl+2);
    mostrar(a->der, lvl+2);
  }
}

int main() {
  { // Ejemplo 1
    Nodo *a= hoja(1);
    Nodo *b= NULL;
    int res= calzar(a, &b);
    if (!res || b!=a) {
      fprintf(stderr, "Ejemplo 1 falla\n");
      exit(1);
    }
  }

  { // Ejemplo 2
    Nodo *a= NULL;
    Nodo *b= hoja(1);
    int res= calzar(a, &b);
    if (res) {
      fprintf(stderr, "Ejemplo 2 falla\n");
      exit(1);
    }
  }

  { // Ejemplo 3
    Nodo *a= hoja(1);
    Nodo *b= hoja(2);
    int res= calzar(a, &b);
    if (res) {
      fprintf(stderr, "Ejemplo 3 falla\n");
      exit(1);
    }
  }

  { // Ejemplo 4
    Nodo *a= abb(4, abb(2, hoja(1), hoja(3)), hoja(5));
    Nodo *b= abb(4, hoja(2), NULL);
    int res= calzar(a, &b);
    if (!res) {
      fprintf(stderr, "Ejemplo 4 falla\n");
      exit(1);
    }
    if (b->izq->izq!=a->izq->izq || b->izq->der!=a->izq->der ||
        b->der!=a->der) {
      printf("%s\n", "holi");
      fprintf(stderr, "Ejemplo 4 falla\n");
      exit(1);
    }
  }

  { // Ejemplo 5
    Nodo *a= abb(4, abb(2, hoja(1), hoja(3)), NULL);
    Nodo *b= abb(4, NULL, hoja(5));
    int res= calzar(a, &b);
    if (res) {
      fprintf(stderr, "Ejemplo 5 falla\n");
      exit(1);
    }
    if (b->izq!=a->izq) {
      fprintf(stderr, "Ejemplo 5 falla\n");
      exit(1);
    }
  }

  printf("Felicitaciones, todos los tests funcionan correctamente\n");
  return 0;
}
