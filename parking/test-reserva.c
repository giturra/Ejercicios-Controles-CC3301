#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "reserva.h"

typedef struct {
  char *nom;
  int k;
  int lugar;
} Args;

void *carro(void *ptr) {
  Args *args= ptr;
  args->lugar= reservar(args->nom, args->k);
  return NULL;
}

int main() {
  int lugar_juan= reservar("juan", 1);
  printf("juan reservo el lugar %d\n", lugar_juan);
  if (lugar_juan!=0) {
    fprintf(stderr, "juan debio haber estacionado en 0, no en %d\n",
            lugar_juan);
    exit(1);
  }

  int lugar_eva= reservar("eva", 2);
  printf("eva reservo el lugar %d\n", lugar_eva);
  if (lugar_eva!=1) {
    fprintf(stderr, "eva debio haber estacionado en 1, no en %d\n",
            lugar_eva);
    exit(2);
  }

  pthread_t hebra_pato;
  Args args_pato= { "pato", 3, -1 };
  pthread_create(&hebra_pato, NULL, carro, &args_pato);
  printf("Verificando que pato espera por obtener su lugar\n");
  sleep(1);
  if (args_pato.lugar!=-1) {
    fprintf(stderr, "pato debio haber esperado, pero recibio\n");
    fprintf(stderr, "incorrectamente el lugar %d\n",
            args_pato.lugar);
    exit(3);
  }

  int lugar_ana= reservar("ana", 1);
  printf("ana reservo el lugar %d\n", lugar_ana);
  if (lugar_ana!=3) {
    fprintf(stderr, "ana debio haber estacionado en 3, no en %d\n",
            lugar_ana);
    exit(4);
  }

  pthread_t hebra_pedro;
  Args args_pedro= { "pedro", 5, -1 };
  pthread_create(&hebra_pedro, NULL, carro, &args_pedro);
  printf("Verificando que pedro espera por obtener su lugar\n");
  sleep(1);
  if (args_pedro.lugar!=-1) {
    fprintf(stderr, "pedro debio haber esperado, pero recibio\n");
    fprintf(stderr, "incorrectamente el lugar %d\n",
            args_pedro.lugar);
    exit(5);
  }

  liberar("eva");
  printf("eva libera su lugar\n");
  if (args_pato.lugar!=-1) {
    fprintf(stderr, "pato debio haber esperado, pero recibio\n");
    fprintf(stderr, "incorrectamente el lugar %d\n",
            args_pato.lugar);
    exit(6);
  }

  liberar("juan");
  printf("eva libera su lugar\n");
  pthread_join(hebra_pato, NULL);
  printf("pato reservo el lugar %d\n", args_pato.lugar);
  if (args_pato.lugar!=0) {
    fprintf(stderr, "pato debio haber estacionado en 0, no en %d\n",
            args_pato.lugar);
    exit(7);
  }

  liberar("pato");
  printf("pato libera su lugar\n");
  if (args_pedro.lugar!=-1) {
    fprintf(stderr, "pedro debio haber esperado, pero recibio\n");
    fprintf(stderr, "incorrectamente el lugar %d\n",
            args_pedro.lugar);
    exit(8);
  }

  /* Al liberar ana usamos una copia del string "ana".  En el enunciado
   * se pide que se haga una copia del string y por lo tanto en la
   * comparacion se debe usar strcmp y no la igualdad de punteros.
   */
  char copia_ana[4];
  strcpy(copia_ana, "ana");
  liberar(copia_ana);
  printf("ana libera su lugar\n");
  pthread_join(hebra_pedro, NULL);
  printf("pedro reservo el lugar %d\n", args_pedro.lugar);
  if (args_pedro.lugar!=0) {
    fprintf(stderr, "pedro debio haber estacionado en 0, no en %d\n",
            args_pedro.lugar);
    exit(9);
  }

  liberar("pedro");
  printf("pedro libera su lugar\n");

  printf("\nFelicitaciones: su solucion funciona de acuerdo al enunciado.\n");

  return 0;
}
