typedef struct nodo {
  char x;
  struct nodo *izq, *der;
} Nodo;
  
void reparar(Nodo **pa);
