#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "impr.h"

struct doc {
  char *s;
  int time;
  int pri;
};

void doPrint(Doc *doc) {
  printf("starting %s, pri= %d\n", doc->s, doc->pri);
  sleep(doc->time);
  printf("finishing %s\n", doc->s);
}

static void *task(void *ptr) {
  Doc *doc= ptr;
  printf("requesting %s\n", doc->s);
  imprimir(doc, doc->pri);
  return NULL;
}

int main() {
  Doc a= {"a", 2, 0};
  Doc b= {"b", 1, 0};
  Doc c= {"c", 1, 9};
  Doc d= {"d", 1, 5};
  pthread_t ta, tb, tc, td;
  pthread_create(&ta, NULL, task, &a);
  sleep(1);
  pthread_create(&tb, NULL, task, &b);
  pthread_create(&tc, NULL, task, &c);
  pthread_create(&td, NULL, task, &d);
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);
  pthread_join(tc, NULL);
  pthread_join(td, NULL);
  return 0;
}
