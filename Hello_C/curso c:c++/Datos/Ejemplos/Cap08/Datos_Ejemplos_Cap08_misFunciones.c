/* misFunciones.c */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "misFunciones.h"

void visualizar(double **x, int filas, int cols)
{
  for (int f = 0; f < filas; f++)
  {
    for (int c = 0; c < cols; c++)
      printf("%5g", x[f][c]);
    printf("\n");
  }
}

void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento)
{
  void **p = 0;
  // Asignar memoria para la matriz de punteros
  p = (void **)malloc(nFilas * sizeof(void *));
  if (p == NULL)  return NULL;
  // Asignar memoria para cada una de las filas
  for (int i = 0; i < nFilas; i++)
  {
    p[i] = malloc(nCols * tamElemento);
    if (p[i] == NULL)
    {
      // Liberar la memoria asignada hasta este instante
      liberarMemoriaMatriz2D(p, i);
      return NULL;
    }
    // Iniciar la fila con ceros
    memset(p[i], 0, nCols * tamElemento);
  }
  return p;
}

void liberarMemoriaMatriz2D(void **pm, int nFilas)
{
  // Liberar la memoria asignada a cada una de las filas
  for (int f = 0; f < nFilas; f++)
    free(pm[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(pm);
}
