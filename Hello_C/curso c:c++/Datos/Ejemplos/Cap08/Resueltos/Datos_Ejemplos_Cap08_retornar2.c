// retornar2.c
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "misFunciones.h"

typedef struct
{
  double **p; // dirección de comienzo de la matriz
  int filas;  // número de filas
  int cols;   // número de columnas
} tmatriz2D;  // tipo

tmatriz2D *AsignarMem2D(int, int);
void LiberarMem2D(tmatriz2D);
void Visualizar(tmatriz2D);
void AsignarDatos(tmatriz2D);

int main(void)
{
  int filas = 2, cols = 3;
  tmatriz2D *m = NULL; // puntero a una estructura tmatriz2D

  // Crear una matriz bidimensional dinámicamente
  m = AsignarMem2D(filas, cols);
  if (m == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }

  // Asignar datos desde el teclado a la matriz
  AsignarDatos(*m);

  // Visualizar la matriz
  Visualizar(*m);

  // Liberar la memoria asignada a la matriz
  LiberarMem2D(*m);
  // Liberar la memoria asignada a la estructura
  free(m);
  return 0;
}

tmatriz2D *AsignarMem2D(int filas, int cols)
{
  tmatriz2D *x = (tmatriz2D *)malloc(sizeof(tmatriz2D));
  if (x == NULL) return NULL;
  x->p = NULL; x->filas = filas; x->cols = cols;
  // Crear una matriz bidimensional dinámicamente
  x->p = (double **)asignarMemoriaMatriz2D(filas, cols, sizeof(double));
  return x;
}

void LiberarMem2D(tmatriz2D x)
{
  liberarMemoriaMatriz2D(x.p, x.filas);
}

void AsignarDatos(tmatriz2D x)
{
  for (int f = 0; f < x.filas; f++)
  {
    for (int c = 0; c < x.cols; c++)
    {
      printf("elemento[%d][%d] = ", f, c);
      scanf("%lf", &x.p[f][c]);
    }
    printf("\n");
  }
}

void Visualizar(tmatriz2D x)
{
  visualizar(x.p, x.filas, x.cols);
}
