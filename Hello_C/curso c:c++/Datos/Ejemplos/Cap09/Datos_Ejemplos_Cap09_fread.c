/*** Leer datos de un archivo registro a registro ***/
/* fread.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
} registro;      // tipo registro

bool existe(char *nombreArchivo);
void mostrarArchivo(char *nombreArchivo);

int main(void)
{
  char nombreArchivo[30]; // nombre del archivo

  // Solicitar el nombre del archivo
  printf("Nombre del archivo: ");
  scanf("%s", nombreArchivo);
  while (getchar() != '\n'); // limpiar buffer stdin

  // Verificar si el archivo existe
  if (existe(nombreArchivo))
    mostrarArchivo(nombreArchivo);
  else
    printf("El archivo no existe.");
}

bool existe(char *nombreArchivo)
{
  FILE *pf = NULL;
  // Verificar si el archivo existe
  bool exis = false; // no existe
  if ((pf = fopen(nombreArchivo, "r")) != NULL)
  {
    exis = true;   // existe
    fclose(pf);
  }
  return exis;
}

void mostrarArchivo(char *nombreArchivo)
{
  FILE *pfe = NULL; // identificador del archivo de entrada
  // stdout: identificador del dispositivo de salida
  registro reg;     // definir un registro

  // Abrir el archivo nombreArchivo para leer "r"
  if ((pfe = fopen(nombreArchivo, "rb")) == NULL)
  {
    printf("El archivo no puede abrirse.");
    exit(EXIT_FAILURE);
  }

  // Leer datos del archivo y mostrarlos en la salida estándar
  fread(&reg, sizeof(reg), 1, pfe);
  while (!ferror(pfe) && !feof(pfe))
  {
    system("cls"); // limpiar la pantalla
    fprintf(stdout, "Nombre:    %s\n", reg.nombre);
    fprintf(stdout, "Dirección: %s\n", reg.direccion);
    fprintf(stdout, "Teléfono:  %ld\n\n", reg.telefono);

    // Hacer una pausa
    printf("Pulse <Entrar> para continuar ");
    while (getchar() != '\n');

    // Leer el siguiente registro del archivo
    fread(&reg, sizeof(reg), 1, pfe);
  }

  if (ferror(pfe))
    perror("Error durante la lectura");
  fclose(pfe);
  fclose(stdout);
}
