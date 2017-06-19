Este es el test de prueba para la pregunta 1 parte b del control 3 del semestre
primavera 2014.

Programe en el archivo mult.c la funcion pedida: mult.  Agregue otras
funciones si lo necesita.  Use la funcion leer en util.c para recibir
por los pipes los resultados de los hijos.

Compile mult.c con el comando make y luego ejecute el binario mult.
El programa le dira si el resultado es correcto.

Pero cuidado: que sea correcto no significa que sea eficiente.
El objetivo de la pregunta es que la multiplicacion de la matriz se
haga en paralelo.  No tiene sentido crear 8 procesos para hacer la
multiplicacion secuencialmente.  Piense bien si esta haciendolo en
paralelo.  Un indicador de que esta haciendo la multiplicacion de manera
secuencial es si en ningun momento necesito un arreglo para almacenar
los pipes.
