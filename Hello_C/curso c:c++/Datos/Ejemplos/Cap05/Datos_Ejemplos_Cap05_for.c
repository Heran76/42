/********************* Tablero de ajedrez *********************/
/* for.c
 */
#include <stdio.h>

int main(void)
{
  int falfil, calfil;  // posici�n del alfil
  // Posici�n actual: fila, columna

  printf("Posici�n del alfil (fila, columna): ");
  scanf("%d %d", &falfil, &calfil);
  printf("\n");  // dejar una l�nea en blanco

  // Pintar el tablero de ajedrez
  for (int fila = 1; fila <= 8; fila++)
  {
    for (int columna = 1; columna <= 8; columna++)
    {
      if ((fila + columna == falfil + calfil) ||
	       (fila - columna == falfil - calfil))
	      printf("* ");
      else if ((fila + columna) % 2 == 0)
	      printf("B ");
      else
	      printf("N ");
    }
    printf("\n");  // cambiar de fila
  }
}
