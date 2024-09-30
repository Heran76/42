#include <stdio.h>
#define FILAS 10
#define COLS 10

void CopiarMatriz(float (*destino)[COLS], float (*origen)[COLS])
{
  for (int fila = 0; fila < FILAS; fila++)
  {
    for (int col = 0; col < COLS; col++)
      destino[fila][col] = origen[fila][col];
  }
}

int main(void)
{
  static float m1[FILAS][COLS];
  static float m2[FILAS][COLS];
  m1[0][0] = 33;
  CopiarMatriz(m2, m1);
  for (int fila = 0; fila < FILAS; fila++)
  {
    for (int col = 0; col < COLS; col++)
      printf("%g ", m2[fila][col]);
    printf("\n");
  }
}
