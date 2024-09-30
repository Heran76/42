/* Rotación de caracteres
 *
 * Cap6\ejercicio3.c
 */

#include <stdio.h>
#include <string.h>

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

int main(void)
{
  int n_car = 0, n_caracteres = 0; // número de caracteres
  char car, frase[50], stemp[50];  // 50 caracteres como máximo
  printf("Introduzca una frase:\n");
  leerCadena(frase, sizeof(frase));
  strcpy(stemp, frase);
  n_caracteres = strlen(frase);
  printf("%s", frase);
  do
  { // Repite el bucle mientras la cadena no vuelva a ser la original
    car = frase[n_caracteres - 1];
    for (n_car = n_caracteres - 2; n_car >= 0; n_car--)
    {
      frase[n_car + 1] = frase[n_car];
    }
    frase[0] = car;
    printf("-%s", frase);
  }
  while( strcmp(frase, stemp) );
  printf("\n");
}
