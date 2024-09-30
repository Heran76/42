// serie.c
#include <stdio.h>
#define N 10

int main(void)
{
  // 1, 3, 5, 7,... --> a(i) = a(i-1) + 2 para i = 1, 2,..., 9
  // a(0) = 1
  // a(1) = a(0) + 2
  // a(2) = a(1) + 2
  // ...

  int i = 0, a = 0;
  // Mostrar los 10 primeros números de la serie
  a = 1;                    // a(0)
  printf("%d ", a);
  for (i = 1; i <= 9; i++)
  {
    a = a + 2;              // a(1), a(2),...
    printf("%d ", a);
  }
  printf("\n");
}
