// crear_notas.c
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
void crearArchivo(char *nombreArchivo);

int main(void)
{
  char nombreArchivo[30]; // nombre del archivo
  char resp = 's';
  
  // Solicitar el nombre del archivo
  printf("Nombre del archivo: ");
  gets(nombreArchivo);
  
  // Verificar si el archivo existe
  if (existe(nombreArchivo))
  {
    printf("El archivo existe ¿desea sobrescribirlo? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  if (resp == 's')
  {
    crearArchivo(nombreArchivo);
  }
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

void crearArchivo(char *nombreArchivo)
{
  FILE *pf = NULL;   // identifica el archivo
  registro reg = {"", 0.0};      // definir un registro
  char resp;

  // Abrir el archivo nombreArchivo para escribir "w"
  if ((pf = fopen(nombreArchivo, "wb")) == NULL)
  {
    printf("El archivo no puede abrirse.");
    exit(1);
  }

  // Leer datos de la entrada estándar y escribirlos
  // en el archivo
  do
  {
    printf("Nombre: "); scanf("%[^\n]", reg.nombre);
    printf("Nota:   ");
    scanf("%f", &reg.nota);
    fflush(stdin);
        
    // Almacenar un registro en el archivo
    fwrite(&reg, sizeof(reg), 1, pf);
    if (ferror(pf))
    {
      perror("Error durante la escritura");
      exit(2);
    }
    
    printf("¿desea escribir otro registro? (s/n) ");
    resp = getchar();
    fflush(stdin);
  }
  while (resp == 's');
}
