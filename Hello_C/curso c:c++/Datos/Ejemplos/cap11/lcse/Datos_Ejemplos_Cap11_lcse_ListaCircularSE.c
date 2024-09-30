//////////////////////////////////////////////////////////////////
// Crear una lista circular simplemente enlazada (lcse)
// ListaCircularSE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_lcse.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

void mostrarLista(tlcse lista)
{
  // Mostrar todos los elementos de la lista
  int i = 0;
  Datos *alumno = NULL;
  while (i < lista.numeroDeElementos)
  {
    alumno = (Datos *)obtener(i, lista);
    printf("%s %g\n", alumno->nombre, alumno->nota);
    i++;
  }
  if (lista.numeroDeElementos == 0) printf("lista vacía\n");
}

void liberarMemoria(tlcse *lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;
  // borrar: borra siempre el primer elemento
  alumno = (Datos *)borrar(lista);
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = (Datos *)borrar(lista);
  }
}

void error1(tlcse *lista)
{
  liberarMemoria(lista);
  error();
}

void error2(Datos *alumno, tlcse *lista)
{
  free(alumno); // último creado y no asignado
  liberarMemoria(lista);
  error();
}

int main(void)
{
  char nombre[50];
  double nota;
  Datos *alumno = NULL;

  // Lista circular vacía
  tlcse lcse;
  iniciarLcse(&lcse);

  // Leer datos y añadirlos a la lista
  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (scanf("%[^\n]", nombre) != EOF)
  {
    printf("Nota: ");
    scanf("%lf", &nota); while (getchar() != '\n');
    // Crear un objeto de tipo Datos
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error1(&lcse);
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    if (!anyadirAlFinal(alumno, &lcse)) error2(alumno, &lcse);
    printf("\nNombre: ");
  }

  // Añadir un objeto al principio
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error();
  strcpy(alumno->nombre, "alumno x");
  alumno->nota = 10;
  if (!anyadirAlPrincipio(alumno, &lcse)) error2(alumno, &lcse);

  printf("\n\n");
  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(lcse);

  // Borrar el elemento primero
  if (alumno = (Datos *)borrar(&lcse))
    free(alumno); // borrar área de datos
  
  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(lcse);

  // Borrar la lista
  liberarMemoria(&lcse);
}

