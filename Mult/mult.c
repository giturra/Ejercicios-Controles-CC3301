
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "util.h"

#define BUFF_SIZE 8192

void mult(double **a, double **b, double **c) {
  //int i, j, k;
  pid_t children[8];
  int fds[8];

  for(int i = 0; i < 8; ++i) {
    int fd[2];
    double row[8];
    if (pipe(fd) != 0) {
      perror("Can't open pipe");
      exit(1);
    }
    fds[i] = fd[0];
    if ((children[i] = fork()) == 0) {
      close(fd[0]);
      for(int j = 0; j < 8; ++j) {
        double s = 0.0;
        for(int k = 0; k < 8; ++k) {
          s += a[i][k]*b[k][j];
        }
        row[j] = s;
      }
      write(fd[1], row, 8*sizeof(double));
      exit(0);
    } else {
      close(fd[1]);
    }

  }

  for(int i = 0; i < 8; i++){
    read(fds[i], c[i], 8*sizeof(double));
    close(fds[i]);
  }

  for (int i = 0; i < 8; i++) {
      waitpid(children[i], NULL, 0);
  }



}

/* Ahora viene el test de prueba */

void sec_mult(double **a, double **b, double **c) {
  int i, j, k;
  for (i=0; i<8; i++) {
    for (j=0; j<8; j++) {
      double s= 0.0;
      for (k=0; k<8; k++)
        s += a[i][k] * b[k][j];
      c[i][j]= s;
} } }

double **nueva_matriz(int n, int m) {
  double **a= malloc(n*sizeof(double*));
  int i;
  for (i= 0; i<n; i++)
    a[i]= malloc(m*sizeof(double));
  return a;
}

void matriz_aleatoria(double **a) {
  int i, j;
  for (i=0; i<8; i++) {
    for (j=0; j<8; j++) {
      a[i][j]= (double)rand() / RAND_MAX;
} } }

int main() {
  double **a= nueva_matriz(8, 8);
  double **b= nueva_matriz(8, 8);
  double **c= nueva_matriz(8, 8);
  double **d= nueva_matriz(8, 8);
  matriz_aleatoria(a);
  matriz_aleatoria(b);
  mult(a, b, c);
  sec_mult(a, b, d);
  int i, j;
  for (i=0; i<8; i++) {
    for (j=0; j<8; j++) {
      if (c[i][j]!=d[i][j]) {
        fprintf(stderr, "las matrices difieren en %d, %d: %f != %f\n", i, j,
               c[i][j], d[i][j]);
        return 1;
      }
    }
  } 
  printf("Correcto: ambas funciones entregan la misma matriz\n");
  return 0;
}
