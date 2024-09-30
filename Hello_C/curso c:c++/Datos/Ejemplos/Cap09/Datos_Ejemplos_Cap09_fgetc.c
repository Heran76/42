/****** Leer datos de un archivo carácter a carácter *******/
/* fgetc.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *pf = NULL;
  char buffer[81];
  int i = 0;

  // Abrir el archivo "texto" para leer
  if ((pf = fopen("texto", "r")) == NULL)
  {
    perror("El archivo no se puede abrir");
    exit(EXIT_FAILURE);
  }

  while (!ferror(pf) && !feof(pf))
    buffer[i++] = fgetc(pf);
  buffer[--i] = '\0';

  if (ferror(pf))
    perror("Error durante la lectura");

  fclose(pf);
  
  printf("%s", buffer);
}
