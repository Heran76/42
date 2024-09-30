/* Cuenta caracteres
 *
 * Cap6\ejercicio6.c
 *
 * Utilizando las funciones de la bibliotca de C la soluci�n ser�a:
 *
 * leerCadena(cadena, sizeof(cadena));
 * printf("\nLa l�nea le�da es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
 *   cadena, strlen(cadena));
 *
 * Nosotros utilizaremos una funci�n "longitud" propia.
 */
#include <stdio.h>
#include <string.h>
#include <locale.h>

int longitud(char []);
char *leerCadena(char *, int);

int main(void)
{
  setlocale(0, ""); // configuraci�n regional predeterminada
  char cadena[200]; // se reserva espacio para 100 caracteres
  printf("Introduzca una cadena de caracteres:\n");
  leerCadena(cadena, sizeof(cadena));
  printf("\nLa l�nea le�da es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
    cadena, longitud(cadena));
}

int longitud(char str[])
{
  int i = 0;

  while (str[i++]);

  return --i; // para no contar el car�cter '\0'
}

char *leerCadena(char *str, int n)
{
  char *fin, *c = 0;
  fin = fgets(str, n, stdin);
  if (c = strchr(str, '\n'))
    *c = 0; // reemplazar '\n'
  else if (!feof(stdin))
    while (getchar() != '\n'); // limpiar buffer stdin
  return fin;
}
