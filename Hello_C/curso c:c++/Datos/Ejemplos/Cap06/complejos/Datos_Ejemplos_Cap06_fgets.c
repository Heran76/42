/* fgets.c
 */
#include <stdio.h>
#include <string.h>

int main(void)
{
  char texto[40];
  char *c = NULL;

  printf("Introducir líneas de texto.\n");
  printf("Para finalizar introducir la marca EOF\n\n");
  do
  {
    // Leer una línea de texto
    fgets(texto, sizeof(texto), stdin);
    if (feof(stdin) || ferror(stdin)) break;
    if (c = strchr(texto, '\n')) *c = 0;
    // Operaciones con la línea de texto leída
    // ...
  }
  while (!feof(stdin) && !ferror(stdin));
}
