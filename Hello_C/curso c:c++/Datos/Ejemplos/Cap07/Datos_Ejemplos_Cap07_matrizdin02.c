/************** Matriz dinámica de dos dimensiones **************/
/* matrizdin02.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h> // necesaria para memset
void **asignarMemoriaMatriz2D(int nFilas, int nCols, size_t tamElemento);
void liberarMemoriaMatriz2D(void **pm, int nFilas);
void mostrarMatriz(int **pm, int nFilas, int nCols);

int main(void)
{
  int **m = NULL;
  int nFilas = 0, nCols = 0;
  int correcto = 0;

  do
  {
    printf("Número de filas de la matriz:    ");
    correcto = scanf("%d", &nFilas);
    while (getchar() != '\n'); // limpiar buffer
  }
  while (!correcto || nFilas < 1);

  do
  {
    printf("Número de columnas de la matriz: ");
    correcto = scanf("%d", &nCols);
    while (getchar() != '\n'); // limpiar buffer
  }
  while (!correcto || nCols < 1);

  // Asignar memoria para la matriz 2D
  m = (int **)asignarMemoriaMatriz2D(nFilas, nCols, sizeof(double));
  if (m == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  // Operaciones
  // ...

  // Visualizar la matriz 2D
  mostrarMatriz(m, nFilas, nCols);

  // Liberar la memoria asignada
  liberarMemoriaMatriz2D(m, nFilas);

  return 0;
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

void mostrarMatriz(int **pm, int nFilas, int nCols)
{
  for (int f = 0; f < nFilas; f++)
  {
    for (int c = 0; c < nCols; c++)
      printf("%d  ", pm[f][c]);
    printf("\n");
  }
}
