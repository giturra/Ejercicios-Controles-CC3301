#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

Nodo *abb(Nodo *a, int i, int j) {
  int floor = ((j+i+1)/2);
  if (i > j) {
    return NULL;
  }
  a[floor].izq = abb(a, i, floor-1);
  a[floor].der = abb(a, floor+1, j);
  return &a[floor];

}

//[0,1,2,3,4,5,6,7]