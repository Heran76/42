// matriz.c
#include <stdio.h>

int main(void)
{
  // 1, 3, 5, 7,... --> a(i) = a(i-1) + 2 para i = 1, 2,..., 9
  // a(0) = 1
  // a(1) = a(0) + 2
  // a(2) = a(1) + 2
  // ...

  int i = 0, a[100] = {0};
  // Mostrar los 10 primeros números de la serie
  a[0] = 1;
  for (i = 1; i <= 9; i++)
  {
    a[i] = a[i-1] + 2;
  }

  for (i = 0; i <= 9; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\n");
}
