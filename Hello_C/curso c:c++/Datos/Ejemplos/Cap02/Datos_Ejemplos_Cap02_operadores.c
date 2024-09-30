/* operadores.c
 */
#include <stdio.h>

int main(void)
{
  float x = 0, a = 15, b = 5, c = 11, d = 4;
  
  --c; // o bien c--
  x = (a - b) * (c - d) / 2;
  b++;
  printf("x = %g, b = %g, c = %g\n", x, b, c);
}
