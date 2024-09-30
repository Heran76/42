/* Este programa utiliza strcpy_s y strcat_s
 * strcpy_s.c
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
  char cadena[81];
  int r = 0;
  r = strcpy_s(cadena, sizeof(cadena), "Hola, ");
  r = strcat_s(cadena, sizeof(cadena), "strcpy ");
  r = strcat_s(cadena, sizeof(cadena), "y ");
  r = strcat_s(cadena, sizeof(cadena), "strcat te saludan!");
  printf("cadena = %s\n", cadena);
}
