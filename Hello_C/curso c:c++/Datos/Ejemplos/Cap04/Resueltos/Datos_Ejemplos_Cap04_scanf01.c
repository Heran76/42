/* scanf01.c */
#include <stdio.h>

int main(void)
{
  char nombre[80] = { 0 }; // cadena de caracteres 'nombre' vacía
  printf("Nombre: ");
  scanf("%s", nombre);
  printf("%s\n", nombre);
}
