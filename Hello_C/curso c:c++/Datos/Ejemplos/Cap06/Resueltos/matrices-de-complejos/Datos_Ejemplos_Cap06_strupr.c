/*********** Conversi�n de min�sculas a may�sculas ***********/
/* strupr.c
 */
#include <stdio.h>

#define LONG_MAX 81	    // longitud m�xima de la cadena
void minusculasMayusculas(char str[]);

int main(void) // funci�n principal
{
  char cadena[LONG_MAX];

  printf ("Introducir una cadena: ");
  fgets(cadena, sizeof(cadena), stdin);
  minusculasMayusculas(cadena); // llamada a la funci�n
  printf ("%s\n", cadena);
}

/**************************************************************
                 Funci�n minusculasMayusculas
**************************************************************/
// Convierte min�sculas a may�sculas

void minusculasMayusculas(char str[])
{
  int i = 0, desp = 'a' - 'A';

  for (i = 0; str[i] != '\0'; ++i)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - desp;
}
