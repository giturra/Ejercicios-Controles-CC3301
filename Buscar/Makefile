# Programe la funcion buscar de la parte a en el archivo p1a.c y
# pruebe su solucion con el programa de prueba en test-p1a.c.
#
# Programe la funcion consultar de la parte b en el archivo p1b.c y
# pruebe su solucion con el programa de prueba en test-p1b.c

CFLAGS= -g -Wall -pedantic -std=c99
LDFLAGS= -g

all: test-p1a test-p1b

test-p1a: p1a.o test-p1a.o

test-p1b: p1a.o p1b.o test-p1b.o

p1a.o test-p1a.o p1b.o test-p1b.o: p1.h

clean:
	rm -f *.o test-p1a test-p1b
