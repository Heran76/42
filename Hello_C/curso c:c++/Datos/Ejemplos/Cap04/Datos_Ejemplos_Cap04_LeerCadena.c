/* LeerCadena.c */
#include <stdio.h>
#define LF 10

int main(void)
{
  char nombre[80] = { 0 }; // cadena de caracteres 'nombre' vacía
  int i = 0;
  printf("Nombre: ");
  nombre[i] = getchar(); // primer carácter
  while (nombre[i] != LF) // tecla [Entrar] implica LF
  {
    i++;
    nombre[i] = getchar(); // siguientes caracteres
  }
  nombre[i] = '\0'; // carácter de terminación de una cadena
  printf("%s\n", nombre);
}
