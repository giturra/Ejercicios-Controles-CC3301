Pregunta 1.a

+ Programe la función prox_pal en el archivo prox-pal.c
+ Compile con: $ make test-prox-pal
+ Ejecute con: $ ./test-prox-pal

La salida debe ser exactamente:

"hola"
"que"
"tal"

Pregunta 1.b

+ Programe la función abb en el archivo abb.c
+ Compile con: $ make test-abb
+ Ejecute con: $ ./test-abb

La salida debe ser exactamente:

e
  c
    b
      a
        NULL
        NULL
      NULL
    d
      NULL
      NULL
  g
    f
      NULL
      NULL
    h
      NULL
      NULL

Pregunta 2

+ Programe la función imprimir y otras funciones que necesite en el archivo
  impr.c
+ Compile con: $ make test-impr
+ Ejecute con: $ ./test-impr

La salida debe ser exactamente:

requesting a
starting a, pri= 0
requesting b
requesting c
requesting d
finishing a
starting c, pri= 9
finishing c
starting d, pri= 5
finishing d
starting b, pri= 0
finishing b

Observe que se debe imprimir primero c, luego d y finalmente b.
Otro orden sería incorrecto.

Pregunta 3

+ Programe la funcón reparar y otras funciones que necesite en el archivo
  reparar.c
+ Compile con: $ make test-reparar
+ Ejecute con: $ ./test-reparar

La salida debe ser exactamente:

1er. test
NULL

2do. test
s
  r
    NULL
    NULL
  u
    t
      NULL
      NULL
    NULL

