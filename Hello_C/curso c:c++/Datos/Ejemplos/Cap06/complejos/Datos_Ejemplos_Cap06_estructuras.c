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
  setlocale(0, ""); // configuración regional predeterminada
  tficha persona, otra_persona;

  // Introducir datos
  printf("Nombre:          ");
  leerCadena(persona.nombre, sizeof(persona.nombre));
  printf("Dirección:       ");
  leerCadena(persona.direccion, sizeof(persona.direccion));
  printf("Teléfono:        ");
  scanf("%ld", &persona.telefono);
  printf("Fecha de nacimiento:\n");
  printf("  Día:           ");
  scanf("%d", &persona.fecha_nacimiento.dia);
  printf("  Mes:           ");
  scanf("%d", &persona.fecha_nacimiento.mes);
  printf("  Año:           ");
  scanf("%d", &persona.fecha_nacimiento.anyo);

  // Copiar una estructura en otra
  otra_persona = persona;

  // Escribir los datos de la nueva estructura
  printf("\n\n");
  printf("Nombre:      %s\n", otra_persona.nombre);
  printf("Dirección:   %s\n", otra_persona.direccion);
  printf("Teléfono:    %ld\n", otra_persona.telefono);
  printf("Fecha de nacimiento:\n");
  printf("  Día:       %d\n", otra_persona.fecha_nacimiento.dia);
  printf("  Mes:       %d\n", otra_persona.fecha_nacimiento.mes);
  printf("  Año:       %d\n", otra_persona.fecha_nacimiento.anyo);
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
