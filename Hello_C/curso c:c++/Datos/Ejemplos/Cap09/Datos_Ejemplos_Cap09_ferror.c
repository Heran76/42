// ferror.c
//
#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{ 
  FILE *pf; 
  char *cadena = "Esta cadena nunca será escrita";

  if ((pf = fopen("datos", "r")) == NULL)
  {
    printf("Error: no se puede abrir el archivo\n");
    return EXIT_FAILURE;
  } 
  fprintf(pf, "%s\n", cadena); 
  if (ferror(pf)) 
  { 
    printf("Error al escribir en el archivo\n"); 
    clearerr(pf); 
  } 
  fclose(pf);
}
