/*********** Conversión de minúsculas a mayúsculas ***********/
/* strupr.c
 */
#include <stdio.h>

#define LONG_MAX 81	    // longitud máxima de la cadena
void minusculasMayusculas(char str[]);

int main(void) // función principal
{
  char cadena[LONG_MAX];

  printf ("Introducir una cadena: ");
  fgets(cadena, sizeof(cadena), stdin);
  minusculasMayusculas(cadena); // llamada a la función
  printf ("%s\n", cadena);
}

/**************************************************************
                 Función minusculasMayusculas
**************************************************************/
// Convierte minúsculas a mayúsculas

void minusculasMayusculas(char str[])
{
  int i = 0, desp = 'a' - 'A';

  for (i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - desp;
}
