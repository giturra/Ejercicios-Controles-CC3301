#define _POSIX_C_SOURCE 1
#include <stdio.h>
#include <setjmp.h>
#include <stdint.h>
#include <signal.h>
#include <stdlib.h>

#include "reparar.h"
 
// Declare aca las variables globales que necesite
jmp_buf ring;


// Declare aca otras funciones que necesite
void cap(int sig) {
	siglongjmp(ring, 1);
}

void reparar(Nodo **pa) {
	Nodo *a = *pa;
	void (*hdlr)();
  hdlr = signal(SIGSEGV, cap);

  if (sigsetjmp(ring,1) != 0) {
  	signal(SIGSEGV, hdlr);
  	*pa = NULL;
  	return;
  	
  }

  if (a== NULL) {
  	return;
  }
  
  reparar(&(a->izq));
  reparar(&(a->der));

  signal(SIGSEGV, hdlr);
}
