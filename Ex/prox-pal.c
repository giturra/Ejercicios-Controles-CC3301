#include <stdio.h>
#include <stdlib.h>

#include "prox-pal.h"

char *prox_pal(char **pfrase) {
  char *frase = *pfrase;
  char *frase2 = NULL;
  char *pal = NULL;
  while (*frase != '\0') {
  	frase2 = frase;
  	++frase;
  	if (*frase2 == ' ' && *frase != ' ') {
  		pal = frase;
  	}
  	else if (*frase2 != ' ' && *frase == ' ') {
  		frase[0] = '\0'; //Esto me da segmetation fault
  		break;
  	}
  }

  return pal;
}

int main() {
	char *str = "        hello world!";

	printf("%s\n", prox_pal(&str));
}
