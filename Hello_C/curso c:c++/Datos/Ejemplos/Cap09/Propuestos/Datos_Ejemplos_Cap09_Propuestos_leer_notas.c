// leer_notas.c
//
#include <stdio.h>
#include <stdlib.h>
#define LONG 61

typedef struct
{
  unsigned char nombre[LONG];
  float nota;
} registro;

int existe(char *nombreArchivo);
void visualizarArchivo(char *nombreArchivo);

int main(void)
{
  char nombreArchivo[30]; // nombre del archivo
  char resp = 's';
  
  // Solicitar el nombre del archivo
  printf("Nombre del archivo: ");
  gets(nombreArchivo);
  
  // Verificar si el archivo existe
  if (existe(nombreArchivo))
    visualizarArchivo(nombreArchivo);
  else
    printf("El archivo no existe\n");
}

int existe(char *nombreArchivo)
{
  FILE *pf = NULL;
  // Verificar si el archivo existe
  int exis = 0; // no existe
  if ((pf = fopen(nombreArchivo, "r")) != NULL)
  {
    exis = 1;   // existe
    fclose(pf);
  }
  return exis;
}

void visualizarArchivo(char *nombreArchivo)
{
  FILE *pf = NULL;   // identifica el archivo
  registro reg = {"", 0.0};      // definir un registro
  char resp;

  // Abrir el archivo nombreArchivo para escribir "w"
  if ((pf = fopen(nombreArchivo, "rb")) == NULL)
  {
    printf("El archivo no puede abrirse.");
    exit(1);
  }

  // Leer datos de la entrada estándar y escribirlos
  // en el archivo
  fread(&reg, sizeof(reg), 1, pf);
  while (!feof(pf))
  {
    printf("Nombre: %s,   ", reg.nombre);
    printf("Nota: %g\n", reg.nota);
    
    printf("¿desea escribir otro registro? (s/n) ");
    resp = getchar(); fflush(stdin);
    if (resp != 's') break;
    fread(&reg, sizeof(reg), 1, pf);
  }
}
