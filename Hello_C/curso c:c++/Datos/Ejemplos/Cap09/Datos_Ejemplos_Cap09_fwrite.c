/*** Escribir datos en un archivo registro a registro ***/
/* fwrite.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
} registro;      // tipo registro

bool existe(char *nombreArchivo);
void crearArchivo(char *nombreArchivo);
void fflushstdin(void);
char *leerCadena(char *, int);

int main(void)
{
  char nombreArchivo[30]; // nombre del archivo
  char resp = 's';

  // Solicitar el nombre del archivo
  printf("Nombre del archivo: ");
  leerCadena(nombreArchivo, sizeof(nombreArchivo));

  // Verificar si el archivo existe
  if (existe(nombreArchivo))
  {
    printf("El archivo existe ¿desea sobrescribirlo? (s/n) ");
    resp = getchar();
    fflushstdin();
  }
  if (resp == 's')
  {
    crearArchivo(nombreArchivo);
  }
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

void crearArchivo(char *nombreArchivo)
{
  FILE *pf = NULL;   // identificador del archivo
  registro reg;      // definir un registro
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
    printf("nombre:    ");
    leerCadena(reg.nombre, sizeof(reg.nombre));
    printf("dirección: ");
    leerCadena(reg.direccion, sizeof(reg.direccion));
    printf("teléfono:  ");
    scanf("%ld", &reg.telefono);
    fflushstdin();

    // Almacenar un registro en el archivo
    fwrite(&reg, sizeof(reg), 1, pf);
    if (ferror(pf))
    {
      perror("Error durante la escritura");
      exit(2);
    }

    printf("¿desea escribir otro registro? (s/n) ");
    resp = getchar();
    fflushstdin();
  }
  while (resp == 's');
}

void fflushstdin(void)
{
  if (!feof(stdin) && !ferror(stdin))
    while ((getchar()) != '\n');
}

char *leerCadena(char *str, int n)
{
  char *fin, *c = 0;
  fin = fgets(str, n, stdin);
  if (c = strchr(str, '\n'))
    *c = 0; // reemplazar '\n'
  else if (!feof(stdin))
    while (getchar() != '\n'); // limpiar buffer stdin
  return fin;
}
