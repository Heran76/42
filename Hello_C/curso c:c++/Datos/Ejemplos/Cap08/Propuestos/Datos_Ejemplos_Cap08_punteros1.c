// punteros1.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void visualizar(double *, int);

int main(void)
{
  int elems = 6; // n�mero de elementos de la matriz
  // Crear una matriz unidimensional din�micamente
  double *m = (double *)malloc(elems * sizeof(double));
  if ( m == NULL )
  {
    printf("Insuficiente memoria\n");
    return -1;
  }
  // Iniciar la matriz con ceros
  memset(m, 0, elems * sizeof(double));

  // ...

  // Visualizar la matriz
  visualizar(m, elems);

  free(m);
  return 0;
}

void visualizar(double *x, int elems)
{
  for (int i = 0; i < elems; i++)
    printf("%5g", x[i]);
  printf("\n");
}
