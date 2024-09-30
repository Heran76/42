/* entrada-salida.c */
#include <stdio.h>
#include "entrada-salida.h"

int leerInt(int *pdato)
{
  int r = 0;
  while (r == 0)
  {
    r = scanf("%d", pdato);
    if (r == 0)
    {
      printf("Dato incorrecto. Introduzca otro: ");
    }
    fflushstdin();
  }
  return r;
}

int leerDouble(double *pdato)
{
  int r = 0;
  while (r == 0)
  {
    r = scanf("%lf", pdato);
    if (r == 0)
    {
      printf("Dato incorrecto. Introduzca otro: ");
    }
    fflushstdin();
  }
  return r;
}

int leerDato(char *formato, void *pdato)
{
  int r = 0;
  while (r == 0)
  {
    r = scanf(formato, pdato);
    if (r == 0)
    {
      printf("Dato incorrecto. Introduzca otro: ");
    }
    fflushstdin();
  }
  return r;
}

void fflushstdin(void)
{
  if (!feof(stdin) && !ferror(stdin))
    while ((getchar()) != '\n');
}
