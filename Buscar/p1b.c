#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p1.h"

#define MAX 80

void read_line(FILE *file, char *line, int i, int len);
int cmp_lines(void *a, int k, void *x);

void read_line(FILE *file, char *line, int i, int len) {
  if (fseek(file, i*MAX, SEEK_SET)!=0) {
    perror("compare_file_lines");
    exit(1);
  }
  if (fread(line, 1, len, file)!=len) {
    perror("compare_file_lines");
    exit(1);
  }
}

int cmp_lines(void *a, int k, void *x){
	FILE *f = a;
	char *s = x;
	int len = strlen(s);
	char pa[len];
	read_line(f, pa, k, len);
	int val = strcmp(pa, s);
	return val;
}

int consultar(char *nom_dic, char *pal, int n_lin) {
	FILE *f = fopen(nom_dic, "r");
	return buscar(f, n_lin, pal, cmp_lines);
}