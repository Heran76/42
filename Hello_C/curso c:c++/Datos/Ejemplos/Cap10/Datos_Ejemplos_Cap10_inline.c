// inline.c - Una macro comparada con una función en línea
#include <stdio.h>

#define MENOR( X, Y ) ((X) < (Y) ? (X) : (Y))

inline extern int menor( int x, int y )
{
  return x < y ? x : y;
}

int main()
{
  int m, a = 10, b = 20;

  // Utilizando la macro
  m = MENOR( a--, b-- ); // efecto colateral
                         // el valor menor se decrementa dos veces
  printf("menor = %d, a = %d, b = %d\n", m, a, b);

  // Llamando a la función
  a = 10; b = 20;
  m = menor( a--, b-- );
  printf("menor = %d, a = %d, b = %d\n", m, a, b);
}
