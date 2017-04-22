typedef struct nodo {
  int x;
  struct nodo *izq, *der;
} Nodo;

int calzar(Nodo *a, Nodo **ppat);
