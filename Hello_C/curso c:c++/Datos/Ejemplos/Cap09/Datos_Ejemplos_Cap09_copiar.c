/********** Copiar el contenido de un archivo en otro **********/
/* copiar.c
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *des = NULL, *org = NULL;
  int conta = 0, car = 0;

  // Comprobar el n�mero de argumentos pasados
  // en la l�nea de �rdenes
  if (argc != 3)
  {
    printf("Sintaxis: copiar origen destino\n");
    exit(1);
  }

  // Abrir el archivo indicado por argv[1] para leer
  // y el indicado por argv[2] para escribir
  if ( (org = fopen(argv[1], "rb")) == NULL ||
       (des = fopen(argv[2], "wb")) == NULL )
  {
    printf("No se puede realizar la copia\n");
    exit(2);
  }

  // Copiar
  while (!ferror(org) && !ferror(des))
  {
    car = fgetc(org);
    if (feof(org)) break;
    conta++;   // contar caracteres
    fputc(car, des);
  }

  // Verificar si la copia se hizo con �xito
  if (ferror(org) || ferror(des))
    perror("Error durante la copia");
  else
    printf("Se han copiado %d caracteres\n", conta-1);

  fclose(org);
  fclose(des);
}
