/* Función para copiar una cadena en otra.
 * copicad1.c
 */
#include <stdio.h>
#define LONGCAD 81
void copicad(char *, char *);

int main(void)
{
  char cadena1[LONGCAD], cadena2[LONGCAD];

  printf("Introducir una cadena: ");
  fgets(cadena1, LONGCAD, stdin);
  copicad(cadena2, cadena1);    // copia la cadena1 en la cadena2
  printf("La cadena copiada es: %s\n", cadena2);
}

void copicad(char *p, char *q)  // copia la cadena q en p
{ 
  while ((*p = *q) != '\0') 
  {
    p++;
    q++;
  }
}
