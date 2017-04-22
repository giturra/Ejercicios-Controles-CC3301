#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int espacio(char *s, char *p, char *r) {
 char *p1 = s;
 char *p2 = p;

 int len1 = strlen(s);
 int len2 = strlen(p);
 int len3 = strlen(r);
 int count = 0;
 int countp = 0;

 int val = 0;
 while (count < len1) {
  if (*p1 == *p2) {
    while (*p1 == *p2) {
      p1++;
      p2++;
      countp++;
      count++;
    }
    p2 = p;
    if (len2 == countp) {
      val++;
    }
  }
  p1++;
  count++;
 }
 int space = len1 + 1;
 if (val > 0) {
    space = (((len1 + 1) - (len2+1)*val) + (len3+1)*val);
 }
 return space;
}

char *substituir(char *s, char *p, char *r) {
  int space = espacio(s, p, r);
  char *newS = malloc(space);
  char *pn = newS + space - 1;
  *pn = '\0';
  pn = newS;
  int contador = 0;


  char *ps = s;
  char *pp = p;
  char *pr = r;
  int count = 0;
  while (1) {
    if (*ps == *pp) {
      char *bps = ps;
      while (*pp == *ps) {
        pp++;
        ps++;
        count++;
      }
      if (count != strlen(p)) {
        ps = bps;
        count = 0;
      }
      pp = p;
    }

    if (count == strlen(p)) {
      count = 0;
      int lenR = strlen(r);
      while (lenR) {
        *pn = *pr;
        pn++;
        pr++;
        lenR--;
      }
      pr = r;
    }
    *pn = *ps;
    pn++;
    ps++;
    contador++;

    if (contador == strlen(s)) {
      break;
    }
  }
  return newS;
}

int main() {
  if (espacio("hola mundo", "hello", "bonjour")!=11)
    printf("falla test 1\n");
  else if (espacio("hola mundo", "ola", "ello")!=12)
    printf("falla test 2\n");
  else if (espacio("elgatotemelperro", "el", "un")!=17)
    printf("falla test 3\n");
  else if (strcmp(substituir("hola mundo", "hello", "bonjour"),
             "hola mundo") != 0)
    printf("falla test 4\n");
  else if (strcmp(substituir("hola mundo", "ola", "ello"),
                  "hello mundo") != 0)
    printf("falla test 5\n");
  else if (strcmp(substituir("elgatotemelperro", "el", "un"),
                  "ungatotemunperro") != 0)
    printf("falla test 6\n");
  else
    printf("Todos los tests funcionan correctamente\n");
  return 0;
}

