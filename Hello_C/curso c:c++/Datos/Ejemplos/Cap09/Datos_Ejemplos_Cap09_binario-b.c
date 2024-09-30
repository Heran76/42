// binario-b.c
#include <stdio.h>

int main()
{
  int n = 0;
  char *s = "¡Hola mundo!\n";
  FILE *pf; // flujo
  // Abrir el archivo
  pf = fopen("miarchivo-b.bin", "wb");  // b = archivo binario
  // Escribir en el archivo
  fwrite(s, strlen(s), 1, pf);
  n = 9;        fwrite(&n, sizeof(int), 1, pf);
  n = 256;      fwrite(&n, sizeof(int), 1, pf);
  n = 17432583; fwrite(&n, sizeof(int), 1, pf);
  // Cerrar el archivo
  fclose(pf);

  return 0;
}
