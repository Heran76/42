/* Escribir el contenido de una matriz de cadenas de caracteres.
 * Versión con punteros.
 * punteros_a_cadenas.c
 */
#include <stdio.h>
#include <string.h>
#define CADS 5
#define TCAD 81
char *leerCadena(char *, int);

void LeerCadenas(char **q, int f)
{
  for (int i = 0; i < f; i++)
  {
    printf("Cadena [%d]: ", i);
    leerCadena(q[i], TCAD);
  }
}

void MostrarCadenas(char **q, int f)
{
  for (int i = 0; i < f; i++)
    printf("%s\n", q[i]);
}

int main(void)
{
  char cad[CADS][TCAD]; // matriz de cadenas de caracteres
  char *p[CADS];        // matriz de punteros

  for (int i = 0; i < CADS; i++)
    p[i] = cad[i];

  LeerCadenas(p, CADS);
  MostrarCadenas(p, CADS);
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
