#include <stdio.h>

int main(void)
{
  // Serie de Fibonacci
  // f(0) = 0, f(1) = 1, f(2) = f(0) + f(1), ... , f(i) = f(i-2) + f(i-1)

  int ant = 0, ult = 1, sig, i;

  // Mostrar los 10 primeros números de la serie
  printf("%d %d ", ant, ult);
  for (i = 2; i <= 9; i++)
  {
    sig = ant + ult;
    ant = ult;
    ult = sig;
    printf("%d ", sig);
  }
  printf("\n");
}
