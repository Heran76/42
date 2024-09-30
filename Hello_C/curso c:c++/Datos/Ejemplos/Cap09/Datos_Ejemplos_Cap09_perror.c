// perror.c
//
#include <stdio.h>
#include <stdlib.h>
 
main() 
{ 
  FILE *pf; 
  char *cadena = "Esta cadena nunca será escrita";
 
  if ((pf = fopen("datos", "r")) == NULL)
  {
    perror("datos");
    return EXIT_FAILURE;
  } 
  fprintf(pf, "%s\n", cadena); 
  if (ferror(pf)) 
  { 
    perror("Error al escribir en el archivo"); 
    clearerr(pf); 
  } 
  fclose(pf);
}
