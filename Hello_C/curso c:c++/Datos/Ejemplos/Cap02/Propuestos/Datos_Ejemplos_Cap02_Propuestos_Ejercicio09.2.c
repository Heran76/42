#include <stdio.h>
#define N 10

int main(void)
{
  // Serie de Fibonacci
  // f(0) = 0, f(1) = 1, f(2) = f(0) + f(1), ... , f(i) = f(i-2) + f(i-1)

  int f[N] = {0}, i;
  
  // Mostrar los N primeros números de la serie
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i < N; i++)
  {
    f[i] = f[i-2] + f[i-1];
  }

  for (i = 0; i < N; i++)
  {
    printf("%d ", f[i]);
  }
  
  printf("\n");
}
