/* test.c */
#include <stdio.h>
#include <stdbool.h>
#include "entrada-salida.h"

int main(void)
{
  double dato;
  int m[100] = { 0 }, i = 0, r = 0, n = 0;

  printf("Dato: "); leerDato("%lf", &dato);

  while (true)
  {
    printf("m[%d]: ", i); r = leerDato("%d", &m[i]);
    if (r == EOF) break;
    i++;
  }
  n = i;
  printf("%g ", dato);
  for (i = 0; i < n; ++i)
    printf("%d ", m[i]);
  printf("\n");
}
