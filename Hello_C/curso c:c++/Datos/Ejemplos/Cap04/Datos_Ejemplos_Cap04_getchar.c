/* getchar.c
 */  
#include <stdio.h>
#include <stdlib.h> // para EXIT_FAILURE (1) y EXIT_SUCCESS (0)

int main(void)
{
  int car;
  // Leer/escribir caracteres desde stdin
  while ((car = getchar()) != EOF)
    printf("%c", car);

  // Verificar si devolvió EOF
  if (feof(stdin))
     printf("El programa finalizó correctamente\n");
  // Si no EOF, ocurrió un error
  else if (ferror(stdin))
  {
    printf("Ocurrió un error\n");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
