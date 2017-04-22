#include <stdio.h>
#include <stdlib.h>

#include "calzar.h"

/*int calzar(Nodo *a, Nodo **ppat) {
  if (a != NULL && *ppat == NULL) {
  	*ppat = a;
  	return 1;
  }
  if (a == NULL && *ppat != NULL) {
  	return 0;
  }
  if (a->x == (*ppat)->x) {
  	if (a->izq->x == (*ppat)->izq->x) {
  		printf("%s\n", "Wenas");
  		return calzar(a->izq, &(*ppat)->izq);
  	}
  	if (a->der->x == (*ppat)->der->x) {
  		return calzar(a->der, &(*ppat)->der);
  	}

  }
  return 0;
}*/

int calzar(Nodo *a, Nodo **ppat) {
  if (a == NULL) {
    return 0;
  }
  if (a != NULL && *ppat == NULL) {
    *ppat = a;
    return 1;
  }
  if (calzar(a->izq, &((*ppat)->izq))) {
    if (calzar(a->der, &((*ppat)->der))) {
      return 1;
    }
  }
  return 0;

}
