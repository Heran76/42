/****** Escribir datos en un archivo carácter a carácter *******/
/* fputc.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  FILE *pf;
  char buffer[81];
  int i = 0;

  // Abrir el archivo "texto" para escribir
  if ((pf = fopen("texto", "w")) == NULL)
  {
    perror("El archivo no se puede abrir");
    exit(EXIT_FAILURE);
  }
  strcpy(buffer, "Este es un texto escrito por fputc!!\n");

  while (!ferror(pf) && buffer[i])
    fputc(buffer[i++], pf);

  if (ferror(pf))
    perror("Error durante la escritura");

  fclose(pf);
}
