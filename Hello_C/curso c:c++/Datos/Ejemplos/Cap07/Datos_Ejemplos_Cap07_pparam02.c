/****************** Miembros que son punteros ******************/
/* pparam02.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  unsigned long dni;
  char *nombre;
} tpersona;

tpersona *asigmem(void);
int asignarDni(tpersona *, long);
char *asignarNombre(tpersona *, char *);
void mayusculas(tpersona);

int main(void)
{
  tpersona per1 = {0, 0};
  unsigned long DNI;
  char nombre[80];

  // Asignar datos y mostrar resultados
  do
  {
    printf("DNI: "); scanf("%lu", &DNI); while (getchar() != '\n');
  }
  while (!asignarDni(&per1, DNI));
  printf("Nombre: "); fgets(nombre, sizeof(nombre), stdin);
  if (!asignarNombre(&per1, nombre)) return -1;
  mayusculas(per1);
  printf("%lu %s\n", per1.dni, per1.nombre);
  // Cambiar el nombre
  printf("Nombre: "); fgets(nombre, sizeof(nombre), stdin);
  asignarNombre(&per1, nombre);
  printf("%lu %s\n", per1.dni, per1.nombre);

  tpersona *pper2 = 0;
  // Asignar memoria para otra estructura
  pper2 = asigmem();
  if (pper2 == NULL) return -1;
  // ¿Qué ocurre si realizamos la siguiente operación?
  //*pper2 = per1;
  // Ahora, las dos estructuras comparten el mismo nombre.
  // Para evitarlo realizar la copia así:
  pper2->dni = per1.dni;
  asignarNombre(pper2, per1.nombre);
  printf("Persona 1: %lu %s\n", per1.dni, per1.nombre);
  printf("Persona 2: %lu %s\n", pper2->dni, pper2->nombre);
  // Liberar la memoria asignada
  free(per1.nombre);
  free(pper2->nombre);
  free(pper2);
  return 0;
}

tpersona *asigmem(void)
{
  tpersona *p = (tpersona *)malloc(sizeof(tpersona));
  memset(p, 0, sizeof(tpersona));
  return p;
}

int asignarDni(tpersona *p, long n)
{
  if (n > 0) p->dni = n;
  return n > 0;
}

char *asignarNombre(tpersona *p, char * nom)
{
  if (p->nombre != 0) free(p->nombre);
  if ((p->nombre = (char *)malloc(strlen(nom)+1)) == 0)
    return 0;
  return strcpy(p->nombre, nom);
}

void mayusculas(tpersona per)
{
  for (int i = 0; per.nombre[i]; i++)
    per.nombre[i] = toupper(per.nombre[i]);
}
