typedef struct nodo {
  char x;
  struct nodo *izq, *der;
} Nodo;

Nodo *abb(Nodo *a, int i, int j);
