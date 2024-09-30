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

  // Verificar si devolvi� EOF
  if (feof(stdin))
     printf("El programa finaliz� correctamente\n");
  // Si no EOF, ocurri� un error
  else if (ferror(stdin))
  {
    printf("Ocurri� un error\n");
    exit(EXIT_FAILURE);
  }
  return EXIT_SUCCESS;
}
