/* puts.c
 */
#include <stdio.h>

int main(void)
{
  char *c = NULL; // para almacenar el valor retornado por fgets
  char texto[80];

  printf("Introducir una línea de texto:\n");
  c = fgets(texto, sizeof(texto), stdin);
  printf("\nEl texto introducido es:\n");
  puts(texto);    // equivalente a: printf("%s\n", texto);
  puts("\nSe escribe por segunda vez:");
  puts(c);
}
