/************* Cálculo del factorial de un número *************/
/* factorial.c
 */
#include <stdio.h>

unsigned long long factorial(int n);

int main(void)
{
  int numero;
  unsigned long long fac;

  do
  {
    printf("¿Número (0 a 20)?  ");
    scanf("%d", &numero);
  }
  while (numero < 0 || numero > 20);
  fac = factorial(numero);
  printf("\nEl factorial de %d es %lld\n", numero, fac);
}

unsigned long long factorial(int n)
{
  if (n == 0)
    return 1;
  else
    return n*factorial(n-1);
}
