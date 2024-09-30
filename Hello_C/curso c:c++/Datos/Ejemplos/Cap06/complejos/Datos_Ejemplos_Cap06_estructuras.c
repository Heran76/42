/********** Operaciones con estructuras **********/
/* estructuras.c
 */
#include <stdio.h>
#include <locale.h>
#include <string.h>
char *leerCadena(char *, int);

typedef struct
{
  int dia, mes, anyo;
} tfecha;

typedef struct
{
  char nombre[40];
  char direccion[40];
  long telefono;
  tfecha fecha_nacimiento;
} tficha;

int main(void)
{
  setlocale(0, ""); // configuraci�n regional predeterminada
  tficha persona, otra_persona;

  // Introducir datos
  printf("Nombre:          ");
  leerCadena(persona.nombre, sizeof(persona.nombre));
  printf("Direcci�n:       ");
  leerCadena(persona.direccion, sizeof(persona.direccion));
  printf("Tel�fono:        ");
  scanf("%ld", &persona.telefono);
  printf("Fecha de nacimiento:\n");
  printf("  D�a:           ");
  scanf("%d", &persona.fecha_nacimiento.dia);
  printf("  Mes:           ");
  scanf("%d", &persona.fecha_nacimiento.mes);
  printf("  A�o:           ");
  scanf("%d", &persona.fecha_nacimiento.anyo);

  // Copiar una estructura en otra
  otra_persona = persona;

  // Escribir los datos de la nueva estructura
  printf("\n\n");
  printf("Nombre:      %s\n", otra_persona.nombre);
  printf("Direcci�n:   %s\n", otra_persona.direccion);
  printf("Tel�fono:    %ld\n", otra_persona.telefono);
  printf("Fecha de nacimiento:\n");
  printf("  D�a:       %d\n", otra_persona.fecha_nacimiento.dia);
  printf("  Mes:       %d\n", otra_persona.fecha_nacimiento.mes);
  printf("  A�o:       %d\n", otra_persona.fecha_nacimiento.anyo);
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
