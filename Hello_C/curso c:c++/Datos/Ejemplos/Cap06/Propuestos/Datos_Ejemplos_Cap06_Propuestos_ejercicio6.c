/* Cuenta caracteres
 *
 * Cap6\ejercicio6.c
 *
 * Utilizando las funciones de la bibliotca de C la solución sería:
 *
 * leerCadena(cadena, sizeof(cadena));
 * printf("\nLa línea leída es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
 *   cadena, strlen(cadena));
 *
 * Nosotros utilizaremos una función "longitud" propia.
 */
#include <stdio.h>
#include <string.h>
#include <locale.h>

int longitud(char []);
char *leerCadena(char *, int);

int main(void)
{
  setlocale(0, ""); // configuración regional predeterminada
  char cadena[200]; // se reserva espacio para 100 caracteres
  printf("Introduzca una cadena de caracteres:\n");
  leerCadena(cadena, sizeof(cadena));
  printf("\nLa línea leída es:\n\"%s\"\n\n... y tiene %d caracteres.\n",
    cadena, longitud(cadena));
}

int longitud(char str[])
{
  int i = 0;

  while (str[i++]);

  return --i; // para no contar el carácter '\0'
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
