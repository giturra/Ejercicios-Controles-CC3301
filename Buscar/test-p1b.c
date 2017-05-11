#include <stdio.h>
#include <stdlib.h>

#include "p1.h"

int main(int argc, char **argv) {
  if (argc!=2) {
    fprintf(stderr, "uso: %s <nombre>\n", argv[0]);
    fprintf(stderr, "nombres que si estan: embarcacion lluvia\n");
    fprintf(stderr, "nombres que no estan: nube bote\n");
    exit(1);
  }
  printf("%d\n", consultar("dicc.txt", argv[1], 4));
  return 0;
}
