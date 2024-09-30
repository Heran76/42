/*************** Matrices de números complejos ***************/
/* matrices-de-complejos.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"

#define MAX 10 // máximo número de filas y columnas

typedef struct
{
  int filas;    // filas que actualmente tiene la matriz
  int columnas; // columnas que actualmente tiene la matriz
  tcomplejo c[MAX][MAX]; // matriz de complejos
} tmatriz;

tmatriz LeerMatriz()
{
  tmatriz m;
  int r = 0;

  do
  {
    printf("\nNúmero de filas: ");
    r = scanf("%d", &m.filas);
    fflushstdin();
  } while (r != 1 || m.filas > MAX);

  do
  {
    printf("Número de columnas: ");
    r = scanf("%d", &m.columnas);
    fflushstdin();
  } while (r != 1 || m.columnas > MAX);

  // Leer los datos para la matriz
  for (int f = 0; f < m.filas; f++)
  {
    for (int c = 0; c < m.columnas; c++)
    {
      m.c[f][c] = leerComplejo();
    }
  }
  return m;
}

void VisualizarMatriz(tmatriz m)
{
  printf("\n");
  for (int f = 0; f < m.filas; f++)
  {
    for (int c = 0; c < m.columnas; c++)
      mostrarComplejo(m.c[f][c]);
    printf("\n");
  }
}

tmatriz Multiplicar(tmatriz a, tmatriz b)
{
  tmatriz m;

  if (a.columnas != b.filas)
  {
    printf("No se pueden multiplicar las matrices.\n");
    exit(-1);
  }

  m.filas = a.filas;
  m.columnas = b.columnas;

  // Multiplicar las matrices
  for (int f = 0; f < m.filas; f++)
  {
    for (int c = 0; c < m.columnas; c++)
    {
      m.c[f][c].r = 0;
      m.c[f][c].i = 0;
      for (int k = 0; k < a.columnas; k++)
        m.c[f][c] = sumarComplejos(m.c[f][c], multiplicarComplejos(a.c[f][k], b.c[k][c]));
    }
  }
  return m;
}

int main(void)
{
  static tmatriz a, b, c;

  printf("Matriz [a]:\n");  a = LeerMatriz();
  VisualizarMatriz(a);
  printf("\nMatriz [b]:\n");  b = LeerMatriz();
  VisualizarMatriz(b);
  c = Multiplicar(a, b);
  printf("\nMatriz [c]=[a]x[b]:\n");  VisualizarMatriz(c);
}
