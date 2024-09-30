// punteros3.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void visualizar(double **, int, int);
void asignarMemoriaMatriz2D(void ***, int, int, size_t);
void liberarMemoriaMatriz2D(void **, int);

int main(void)
{
  double **m = NULL; // dirección del bloque de memoria a reservar
  int filas = 2, cols = 3; // número filas y columnas de la matriz
  // Crear una matriz bidimensional dinámicamente
  asignarMemoriaMatriz2D(&m, filas, cols, sizeof(double));
  if (m == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }
  // ...

  // Visualizar la matriz
  visualizar(m, filas, cols);

  // Liberar la memoria asignada a la matriz
  liberarMemoriaMatriz2D(m, filas);
  return 0;
}

void visualizar(double **x, int filas, int cols)
{
  int f = 0, c = 0;
  for (f = 0; f < filas; f++)
  {
    for (c = 0; c < cols; c++)
      printf("%5g", x[f][c]);
    printf("\n");
  }
}

void asignarMemoriaMatriz2D(void ***x, int nFilas, int nCols, size_t tamElemento)
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
  *x = p; // guardar la dirección de la matriz en el parámetro
          // pasado por referencia a esta función.
          // El tipo de *x es void **, igual que el de p.
}

void liberarMemoriaMatriz2D(void **pm, int nFilas)
{
  // Liberar la memoria asignada a cada una de las filas
  for (int f = 0; f < nFilas; f++)
    free(pm[f]);
  // Liberar la memoria asignada a la matriz de punteros
  free(pm);
}
