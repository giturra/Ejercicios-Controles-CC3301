# Para compilar los probramas escriba en el shell de comandos:
# make
#
# Este comando compilara binarios para los siguientes programas:
# test-extraer: test y solucion para la funcion extract de los apuntes.
# test-extraer: test y 2da. solucion para extract.
# test-repBits: test sin solucion para la pregunta 1 parte b del control 1
#   del semestre Otono 2013.  Este ejercicio aparece propuesto en los apuntes.
#   Modifique la funcion repBits en el archivo test-repBits.c para que funcione
#   de acuerdo al enunciado.

CFLAGS= -g -Wall -pedantic -std=c99 -I$(LIBJSOCKET)
LDFLAGS= -g

all: test-extraer test-extraer2 test-repBits

clean:
	rm -f *.o test-extraer test-extraer2 test-repBits
