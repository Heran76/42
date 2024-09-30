/* Teorema de Pitágoras.
 * pitagoras.c
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
  unsigned int x = 1, y = 1, z = 0;
  printf("%10s %10s %10s\n", "Z", "X", "Y");
  printf("      ___________________________\n");

  while (x <= 50)
  {
    while (y <= 50)
    {
      /* Calcular z. Como z es un entero, almacena
      la parte entera de la raíz cuadrada */
      z = (int)sqrt(x * x + y * y);
      if (z > 50) break; // salir del bucle while (y <= 50)
      /* Si la raíz cuadrada anterior fue exacta,
      escribir z, x e y */
      if (z * z == x * x + y * y)
        printf("%10d %10d %10d\n", z, x, y);
      y = y + 1;
    }
    x = x + 1; y = x;
  }
}
