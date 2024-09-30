/*************** Argumentos en l�nea de �rdenes ***************/
/* args.c
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  // C�digo com�n a todos los casos
  printf("Argumentos:\n");
  if (argc == 1)
  {
    // Escriba aqu� el c�digo que solo se debe ejecutar cuando
    // no se pasan argumentos
    printf("    ninguno\n");
  }
  else
  {
    bool argumento_k = false, argumento_l = false,
        argumento_n = false;
  
    // �Qu� argumentos se han pasado?
    for (int i = 1; i < argc; i++)
    {
      if (strcmp(argv[i], "-k") == 0) argumento_k = true;
      if (strcmp(argv[i], "-l") == 0) argumento_l = true;
      if (strcmp(argv[i], "-n") == 0) argumento_n = true;
    }

    if (argumento_k) // si se pas� el argumento -k:
    {
      // Escriba aqu� el c�digo que solo se debe ejecutar cuando
      // se pasa el argumento -k
      printf("    -k\n");
    }

    if (argumento_l) // si se pas� el argumento -l:
    {
      // Escriba aqu� el c�digo que solo se debe ejecutar cuando
      // se pasa el argumento -l
      printf("    -l\n");
    }

    if (argumento_n) // si se pas� el argumento -n:
    {
      // Escriba aqu� el c�digo que solo se debe ejecutar cuando
      // se pasa el argumento -n
      printf("    -n\n");
    }
  }
  // C�digo com�n a todos los casos
  return 0;
}
