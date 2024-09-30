/******************* Copiar matrices *******************/
/* copiar_matrices.c
 */
#include <stdio.h>

#define FILAS 3
#define COLS 3

void copiarArray( float destino[][COLS], float origen[][COLS] );

int main(void)
{
  static float a[FILAS][COLS], c[FILAS][COLS];

  // Leer datos para la matriz a
  for (int fila = 0; fila < FILAS; fila++)
  {
    for (int col = 0; col < COLS; col++)
    {
      printf("a[%d][%d] = ", fila, col);
      scanf("%f", &a[fila][col]);
    }
  }

  // Copiar la matriz a en c
  copiarArray(c, a);

  // Escribir los datos de la matriz c
  for (int fila = 0; fila < FILAS; fila++)
  {
    // Escribir una fila
    for (int col = 0; col < COLS; col++)
      printf("%10g", c[fila][col]);
    printf("\n"); // fila siguiente
  }
}

void copiarArray( float destino[][COLS], float origen[][COLS] )
{
  for (int fila = 0; fila < FILAS; fila++)
  {
    for (int col = 0; col < COLS; col++)
      destino[fila][col] = origen[fila][col];
  }
}
