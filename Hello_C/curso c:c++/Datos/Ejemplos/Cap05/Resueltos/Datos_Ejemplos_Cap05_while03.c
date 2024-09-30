/* Código ASCII de cada uno de los caracteres de un texto
 * while03.c
 */
#include <stdio.h>
 
int main(void)
{ 
  char car = 0; // car = carácter nulo (\0)

  printf("Introduzca una cadena de texto: "); 
  while (true) // es lo mismo que while (1)
  {
    car = getchar();
    if (car != '\n')
      printf("El código ASCII de %c es %d\n", car, car);
    else
      printf("Introduzca una cadena de texto: ");
  }
} 
