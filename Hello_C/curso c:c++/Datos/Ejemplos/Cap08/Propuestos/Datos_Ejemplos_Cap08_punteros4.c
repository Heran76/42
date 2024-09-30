// punteros4.c
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

void AsignarMem2D(tmatriz2D *);
void LiberarMem2D(tmatriz2D);
void Visualizar(tmatriz2D);
void AsignarDatos(tmatriz2D);

int main(void)
{
  tmatriz2D m = { NULL, 2, 3 }; // estructura m

  // Crear una matriz bidimensional dinámicamente
  AsignarMem2D(&m);
  if (m.p == NULL)
  {
    printf("Insuficiente memoria\n");
    return -1;
  }

  // Asignar datos desde el teclado a la matriz
  AsignarDatos(m);

  // Visualizar la matriz
  Visualizar(m);

  // Liberar la memoria asignada a la matriz
  LiberarMem2D(m);
  return 0;
}

void AsignarMem2D(tmatriz2D *x)
{
  x->p = (double **)asignarMemoriaMatriz2D(x->filas, x->cols, sizeof(double));
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
