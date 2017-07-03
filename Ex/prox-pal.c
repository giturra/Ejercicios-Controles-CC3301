#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prox-pal.h"

char *prox_pal(char **pfrase) {
  char *p1 = *pfrase;
  char *p3 = NULL;
  while (*p1 != '\0') {
    if (*p1 == ' ') {
      p1++;
    } else {
        p3 = p1;
        while (*p1 != '\0') {
          if (*p1 != ' '){
            p1++;
          } else {
            break;
          }
        }
        *pfrase = p1;
        **pfrase = '\0';
        (*pfrase)++;
        break;
    }
  }
  return p3;
}



