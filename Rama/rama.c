#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int v;
  struct nodo *izq, *der;
} Nodo;

Nodo **_rama(Nodo *a, int v, int depth, int *p) {
  Nodo **r;
  (*p)++;
  if (a == NULL) {
    return NULL;
  }
  if (a->v == v) {
    r = malloc((depth+1)*sizeof(Nodo*));
  }
  else if (a->v < v) {
    r = _rama(a->der, v, depth+1, p);
  }
  else {
    r = _rama(a->izq, v, depth+1, p);
  }
  if (r != NULL) {
    r[depth] = a;
  }
  return r;
}

Nodo **rama(Nodo *a, int v, int *p) {
  int depth = *p;
  return _rama(a, v, depth, p);
}


Nodo nodos[]= {
  { 0, NULL, NULL}, /* no se usa */
  { 10, NULL, NULL},
  { 20, &nodos[1], NULL},
  { 30, &nodos[1], &nodos[6]},
  { 40, NULL, NULL},
  { 50, &nodos[4], NULL},
  { 60, &nodos[5], &nodos[7]},
  { 70, NULL, NULL} };

int main() {
  Nodo *a= &nodos[3];
  int n;
  Nodo **r= rama(a, 50, &n);
  if (n!=3)
    printf("n debio ser 3, no %d\n", n);
  if (r[0]->v!=30)
    printf("el primer nodo debio ser 30, no %d\n", r[0]->v);
  else if (r[1]->v!=60)
    printf("el segundo nodo debio ser 60, no %d\n", r[1]->v);
  else if (r[2]->v!=50)
    printf("el tercer nodo debio ser 50, no %d\n", r[2]->v);

  if (rama(a, 55, &n)!=NULL)
    printf("55 no debe estar en el arbol\n");
  return 0;
}