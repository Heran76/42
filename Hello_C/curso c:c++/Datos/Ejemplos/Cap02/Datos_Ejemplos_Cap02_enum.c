/* enum.c
 */
#include <stdio.h>

enum colores
{
  azul, amarillo, rojo, verde, blanco, negro
};

int main(void)
{
  enum colores color;
  
  /* Leer un color introducido desde el teclado */
  printf("Color: ");
  scanf("%d", &color);
  /* Visualizar un color */
  printf("%d\n", color);
  /* Si el color es verde... */
  if (color == verde) printf("esperanza\n");
}
