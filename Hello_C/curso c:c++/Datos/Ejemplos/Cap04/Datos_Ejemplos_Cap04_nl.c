/* nl.c - Carácter \n
 */
#include <stdio.h>

int main(void)
{
  float precio = 0;
  char car = 0;

  printf("Precio: ");
  scanf("%g", &precio);
  while (getchar() != '\n');

  printf("Pulse <Entrar> para continuar ");
  // scanf("%*c%c", &car);
  scanf("%c", &car);

  printf("Precio = %g\n", precio);
}
