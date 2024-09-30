//////////////////////////////////////////////////////////////////
// Trabajar con una lista lineal simplemente enlazada y ordenada
// ListaLinealSEO.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_llseo.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

/////////////////////////////////////////////////////////////////
// Definir la función comparar según el prototipo especificado
// en interfaz_llseo.h, para adaptarlas a nuestras necesidades.
//
// Permite comparar los datos de dos elementos.
int comparar(void *datos1, void *datos2)
{
  char *nom1 = ((Datos *)datos1)->nombre;
  char *nom2 = ((Datos *)datos2)->nombre;
  return strcmp(nom1, nom2);
}

void mostrarLista(tllseo *lista)
{
  // Mostrar todos los elementos de la lista
  Datos *alumno = (Datos *)obtenerPrimero(lista);
  while (alumno)
  {
    printf("%s %g\n", alumno->nombre, alumno->nota);
    alumno = (Datos *)obtenerSiguiente(lista);
  }
}

void liberarMemoria(tllseo *lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = (Datos *)borrarPrimero(lista);
  while (alumno)
  {
    free(alumno); // borrar el área de datos
    alumno = (Datos *)borrarPrimero(lista); // borrar elemento
  }
}

Datos *leerDatosAlumno()
{
  Datos *alumno = NULL;
  char nombre[50];
  double nota;

  printf("\nNombre: ");
  scanf("%[^\n]", nombre);
  printf("Nota:   ");
  scanf("%lf", &nota); while (getchar() != '\n');
  // Crear un objeto de tipo Datos
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) return 0;
  strcpy(alumno->nombre, nombre);
  alumno->nota = nota;
  return alumno;
}

void error1(tllseo *lista)
{
  liberarMemoria(lista);
  error();
}

void error2(Datos *alumno, tllseo *lista)
{
  free(alumno); // último creado y no asignado
  liberarMemoria(lista);
  error();
}

int main(void)
{
  char resp = 's';
  Datos *alumno = NULL;

  // Definir una lista lineal vacía
  tllseo llseo;
  iniciarLista(&llseo);

  // Leer datos y añadirlos a la lista
  while (resp == 's')
  {
    alumno = leerDatosAlumno();
    if (!alumno) error1(&llseo);
    if (!anyadir(alumno, &llseo)) error2(alumno, &llseo);

    printf("¿desea insertar otro alumno? (s/n) ");
    resp = getchar(); while (getchar() != '\n');
  } 

  // Borrar un elemento
  printf("\nBorrar el alumno:");
  alumno = leerDatosAlumno();
  if (alumno)
  {
    free(borrar(alumno, &llseo));
    free(alumno);
  }
  else
    printf("Insuficiente memoria\n");

  // Obtener siguiente
  alumno = (Datos *)obtenerSiguiente(&llseo);
  if (alumno)
    printf("%s %g\n", alumno->nombre, alumno->nota);

  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(&llseo);

  // Borrar la lista
  liberarMemoria(&llseo);
}

