/* Cambia a minúsculas.
 * Cap6\ejercicio4.c
 */

#include <stdio.h>
#include <string.h>

char *mayusculasMinusculas(char *);
char *leerCadena(char *, int);

int main(void)
{
  char cadena[100]; // se reserva espacio para 100 caracteres
  printf ("Introduzca una cadena de caracteres:\n");
  leerCadena(cadena, sizeof(cadena));
  printf("La cadena en minúsculas es:\n%s\n", mayusculasMinusculas(cadena));
    // No se podría poner tilde a las mayúsculas
}

char *mayusculasMinusculas(char *str)
{
  int i = 0, desp = 'a' - 'A';

  for (i = 0; str[i] != 0; i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
      str[i] += desp;
  return str;
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
