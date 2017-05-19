# Programe su solucion el archivo reserva.c.
# El test de prueba esta en test-reserva.c.  No modifique este archivo.
# Compile con:
#     make
# Verifique que su solucion ejecutando:
#     ./test-reserva
# Lo felicitara si funciona de acuerdo con el ejemplo del enunciado.

CFLAGS= -g -std=c99 -Wall -pedantic
LDFLAGS= -g

all: test-reserva

reserva.o: reserva.h

test-reserva.o: reserva.h

test-reserva: reserva.o test-reserva.o -lpthread

clean:
	rm -f *.o
	rm -f test-reserva

