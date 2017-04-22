#include <stdio.h>
#include <stdlib.h>

unsigned mascara(unsigned k) {
  return k==32 ? -1 : (1<<k)-1;
}

unsigned int extract(unsigned int x, int i, int k) {
  return (  x & mascara(32-i)  ) >> (32-i-k);
}

int main() {
  /* Test 1 */
  unsigned int t1= extract(0x048b6048, 0, 4);
  if (t1!=0) {
    fprintf(stderr, "fallo el test 1\n");
    exit(1);
  }

  /* Test 1b */
  unsigned int t1b= extract(0x648b6048, 0, 4);
  if (t1b!=6) {
    fprintf(stderr, "fallo el test 1b\n");
    exit(1);
  }

  /* Test 2 */
  unsigned int t2= extract(0x048b6048, 8, 12);
  if (t2!=0x8b6) {
    fprintf(stderr, "fallo el test 4\n");
    exit(1);
  }

  /* Test 3 */
  unsigned int t3= extract(0x048b6048, 28, 4);
  if (t3!=0x8) {
    fprintf(stderr, "fallo el test 3\n");
    exit(1);
  }

  printf("Todos los tests pasaron exitosamente\n");

  return 0;
}

