/* LeerCadena.c */
#include <stdio.h>
#define LF 10

int main(void)
{
  char nombre[80] = { 0 }; // cadena de caracteres 'nombre' vac�a
  int i = 0;
  printf("Nombre: ");
  nombre[i] = getchar(); // primer car�cter
  while (nombre[i] != LF) // tecla [Entrar] implica LF
  {
    i++;
    nombre[i] = getchar(); // siguientes caracteres
  }
  nombre[i] = '\0'; // car�cter de terminaci�n de una cadena
  printf("%s\n", nombre);
}
