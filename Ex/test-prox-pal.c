#include <stdio.h>
#include <stdlib.h>

#include "prox-pal.h"

int main() {
  char txt[]= " hola   que tal";
  char *frase= txt;
  char *pal;
  for (;;) {
    pal= prox_pal(&frase);
    if (pal==NULL)
      break;
    printf("\"%s\"\n", pal);
  }

  return 0;
}
