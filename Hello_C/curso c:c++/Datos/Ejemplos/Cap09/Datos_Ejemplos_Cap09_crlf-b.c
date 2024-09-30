// crlf-b.c
#include <stdio.h>

int main()
{
  FILE *pf; // flujo
  // Abrir el archivo
  pf = fopen("miarchivo-b.txt", "wb");  // b = archivo binario
  // Escribir en el archivo
  fprintf(pf, "¡Hola mundo!\n");
  fprintf(pf, "%d * %d = %d\n", 9, 256, 9*256);
  // Cerrar el archivo
  fclose(pf);

  return 0;
}
