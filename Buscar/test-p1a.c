#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "p1.h"

int cmp_nombres(void *a, int k, void *x) {
  char **nombres= a, *nom= x;
  return strcmp(nombres[k], nom);
}

int buscar_nombre(char **nombres, int n, char *nom) {
  return buscar(nombres, n, nom, cmp_nombres);
}

char *nombres[]={ "alberto", "ana", "diego", "juan",
                  "maria", "pedro", "silvia", "ximena" };

int main(int argc, char **argv) {
  if (argc!=2) {
    fprintf(stderr, "uso: %s <nombre>\n", argv[0]);
    fprintf(stderr, "nombres que si estan: alberto juan ximena\n");
    fprintf(stderr, "nombres que no estan: arturo sonia zoila\n");
    exit(1);
  }
  printf("%d\n", buscar_nombre(nombres, 8, argv[1]));
  return 0;
}
