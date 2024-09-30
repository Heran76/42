/* Utilización de la sentencia goto
 * goto.c
 */
#include <stdio.h>
#define K 8

int main(void)
{
  int f, c, n;
  
  printf("Valor de n: ");
  scanf("%d", &n);
  
  for (f = 0; f < K; f++)
  {
    for (c = 0; c < K; c++)
    {
      if (f*c > n) goto salir;
    }
  }
  salir:
  if (f < K && c < K)
    printf("(%d, %d)\n", f, c);
}
