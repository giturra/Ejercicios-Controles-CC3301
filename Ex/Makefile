CFLAGS= -g -Wall -pedantic -std=c99
LDFLAGS= -g
LDLIBS= -lpthread

all: test-prox-pal test-abb test-impr test-reparar

test-prox-pal: test-prox-pal.o prox-pal.o
test-prox-pal.o prox-pal.o: prox-pal.h

test-abb: test-abb.o abb.o
test-abb.o abb.o: abb.h

test-impr: test-impr.o impr.o
test-impr.o impr.o: impr.h

test-reparar: test-reparar.o reparar.o
test-reparar.o reparar.o: reparar.h

clean:
	rm -f *.o
	rm -f test-prox-pal test-abb test-impr test-reparar
