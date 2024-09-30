/* Puntero a puntero.
* puntero_a_puntero.c
*/
#include <stdio.h>

void leerMatriz(int **q, int f, int c)
{
  for (int i = 0; i < f; i++)
  {
    for (int j = 0; j < c; j++)
    {
      printf("Elemento [%d][%d]: ", i, j);
      scanf("%d", &q[i][j]);
    }
  }
}

void visualizarMatriz(int **q, int f, int c)
{
  for (int i = 0; i < f; i++)
  {
    for (int j = 0; j < c; j++)
      printf("%7d", q[i][j]);
    printf("\n");
  }
}

int main(void)
{
  int a[5][5]; // matriz de dos dimensiones
  int *p[5];   // matriz de punteros

  for (int i = 0; i < 5; i++)
    p[i] = a[i]; // asignar a p las filas de a

  leerMatriz(p, 5, 5);
  visualizarMatriz(p, 5, 5);
}
