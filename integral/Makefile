# Resuelva la pregunta 1 parte a.- en el archivo p1a.c.
# Compile con:
#     make test-p1a
# Pruebe con:
#     ./test-p1a
#
# Resuelva parte b.- en el archivo p1b.c.
# Compile con:
#     make test-p1b
# Pruebe con:
#     ./test-p1b
#
# Resuelva parte c.- en el archivo p1c.c.
# Compile con:
#     make test-p1c
# Pruebe con:
#     ./test-p1c
#

CFLAGS= -g -std=c99 -Wall -pedantic
LDFLAGS= -g

all: test-p1a test-p1b test-p1c

test-p1a.o p1a.o: integral.h

test-p1a: test-p1a.o p1a.o -lm

test-p1b.o p1b.o: integral.h

test-p1b: test-p1b.o p1b.o p1a.o -lm

test-p1c.o p1c.o: integral.h

test-p1c: test-p1c.o p1c.o p1b.o p1a.o -lm -lpthread

clean:
	rm -f *.o
	rm -f test-p1a test-p1b test-p1c

