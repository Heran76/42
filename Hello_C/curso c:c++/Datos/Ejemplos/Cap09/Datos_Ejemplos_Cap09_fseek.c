/**************** Acceso aleatorio a un archivo ****************/
/* fseek.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
} registro;      // tipo registro

void mostrarReg(FILE *pf, int nreg);
void modificarReg(FILE *pf, int nreg);
void fflushstdin(void);
char *leerCadena(char *, int);

int main(void)
{
  FILE *pf = NULL;            // puntero a un flujo
  int totalreg = 0;           // número total de registros
  int nreg = 0;               // número de registro
  char nombreArchivo[30];     // nombre del archivo
  int c = 0, respuesta = 0;

  // Solicitar el nombre del archivo
  printf("Nombre del archivo: ");
  leerCadena(nombreArchivo, sizeof(nombreArchivo));

  // Abrir el archivo para leer y escribir "r+"
  if ((pf = fopen(nombreArchivo, "r+b")) == NULL)
  {
    printf("Error: no se puede abrir el archivo\n");
    exit(EXIT_FAILURE);
  }

  // Calcular el n.º total de registros del archivo
  fseek(pf, 0L, SEEK_END);
  totalreg = (int)ftell(pf)/sizeof(registro);

  // Presentar un registro en pantalla y modificarlo si procede
  do
  {
    printf("Nº registro entre 1 y %d (0 para salir): ", totalreg);
    c = scanf("%d", &nreg);
    fflushstdin();
    if (c && (nreg >= 1) && (nreg <= totalreg))
    {
      mostrarReg(pf, nreg);
      // Preguntar si se desea modificar el registro seleccionado
      do
      {
        printf ("¿Desea modificar este registro? (s/n)  ");
        respuesta = getchar();
        fflushstdin();
      }
      while (tolower(respuesta != 's') && tolower(respuesta) != 'n');

      if (respuesta == 's')
        modificarReg(pf, nreg);
    }
  }
  while (nreg);
  fclose(pf);
}

void mostrarReg(FILE *pf, int nreg)
{
  long desp = 0; // desplazamiento en bytes
  registro reg;  // variable de tipo registro
  int bytesPorReg = sizeof(registro);

  // Visualizar un registro
  desp = (long)(nreg - 1) * bytesPorReg;
  fseek(pf, desp, SEEK_SET);
  fread(&reg, bytesPorReg, 1, pf);
  if (ferror(pf))
  {
    printf("Error al leer un registro del archivo.\n");
    return;
  }
  printf("Nombre:    %s\n", reg.nombre);
  printf("Dirección: %s\n", reg.direccion);
  printf("Teléfono:  %ld\n\n", reg.telefono);
}

void modificarReg(FILE *pf, int nreg)
{
  registro reg;  // variable de tipo registro
  int bytesPorReg = sizeof(registro);

  printf("Nombre:    ");
  leerCadena(reg.nombre, sizeof(reg.nombre));
  printf("Dirección: ");
  leerCadena(reg.direccion, sizeof(reg.direccion));
  printf("Teléfono:  ");
  scanf("%ld", &reg.telefono);
  fflushstdin();
  // Escribir un registro en el archivo
  fseek(pf, -bytesPorReg, SEEK_CUR);
  fwrite (&reg, bytesPorReg, 1, pf);
  if (ferror(pf))
  {
    printf("Error al escribir un registro en el archivo.\n");
    return;
  }
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
