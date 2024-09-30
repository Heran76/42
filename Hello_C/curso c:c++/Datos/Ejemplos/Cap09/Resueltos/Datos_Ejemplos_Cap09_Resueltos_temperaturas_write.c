/* Construir el archivo de temperaturas */
/* temperaturas_write.c
 */
#include <stdio.h>
#include <stdlib.h>

struct cabecera
{
  struct posicion
  {
    int grados, minutos;
    float segundos;
  } latitud, longitud; // Posici�n geogr�fica del punto
  
  int total_muestras;
};

int main(int argc, char *argv [])
{
  FILE *pf;
  struct cabecera cab;
  float temperatura = 0.0F;

  if (argc != 2)
  {
    fprintf(stderr, "Sintaxis: %s nombre_archivo.\n", argv[0]);
    exit(-1);
  }
  if ((pf = fopen(argv[1], "wb")) == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }
  // Escribir el registro de cabecera
  cab.total_muestras = 0;
  fwrite(&cab, 1, sizeof(cab), pf);
  // Escribir las temperaturas
  printf("Muestras. Terminar con eof.\n");
  while (scanf("%f", &temperatura) != EOF)
  {
    fwrite(&temperatura, 1, sizeof(float), pf);
    ++cab.total_muestras;
  }
  // Actualizar el registro de cabecera
  rewind(pf);
  fwrite(&cab, 1, sizeof(cab), pf);
  fclose(pf);
}
