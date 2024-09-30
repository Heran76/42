// binario-t.c
#include <stdio.h>

int main()
{
  int n = 0;
  char *s = "¡Hola mundo!\n";
  FILE *pf; // flujo
  // Abrir el archivo
  pf = fopen("miarchivo-t.bin", "wt");  // t = archivo de texto
  // Escribir en el archivo
  fwrite(s, strlen(s), 1, pf);
  n = 9;        fwrite(&n, sizeof(int), 1, pf);
  n = 256;      fwrite(&n, sizeof(int), 1, pf);
  n = 17435911; fwrite(&n, sizeof(int), 1, pf);
  // Cerrar el archivo
  fclose(pf);

  return 0;
}
