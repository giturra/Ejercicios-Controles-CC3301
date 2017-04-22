CFLAGS= -g -Wall -pedantic -std=c99
LDFLAGS= -g

all: test-calzar

test-calzar.o calzar.o: calzar.h

test-calzar: calzar.o test-calzar.o

clean:
	rm -f *.o
	rm -f test-calzar
