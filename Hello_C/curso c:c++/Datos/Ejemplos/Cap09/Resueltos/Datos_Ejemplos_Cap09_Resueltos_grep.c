/********** Buscar cadenas de caracteres en archivos **********/
/* grep.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int BuscarCadena(char *cadena1, char *cadena2)
{
    // ¿cadena2 está contenida en cadena1?
    return strstr(cadena1, cadena2) != 0;
}

void BuscarEnFich(char *nombrefich, char *cadena)
{
  FILE *pf;
  char linea[256];
  int nrolinea = 0;
  
  // Abrir el archivo nombrefich
  if ((pf = fopen(nombrefich, "r")) == NULL)
  {
    perror(nombrefich);
    return;
  }
  
  // Buscar cadena en el archivo asociado con pf
  while (fgets(linea, sizeof(linea), pf) != NULL)
  {
    nrolinea++;
    if (BuscarCadena(linea, cadena))
      printf("%s[%d]: %s", nombrefich, nrolinea, linea);
  }
  fclose(pf);
}

int main(int argc, char *argv[])
{
  // Verificar el número de argumentos
  if (argc < 3)
  {
    printf("Sintaxis: %s palabra f1 f2 ... fn\n", argv[0]);
    exit(-1);
  }
  
  // Llamar a la función BuscarEnFich por cada archivo
  for (int i = 2; i < argc; i++)
    BuscarEnFich(argv[i], argv[1]);
}
