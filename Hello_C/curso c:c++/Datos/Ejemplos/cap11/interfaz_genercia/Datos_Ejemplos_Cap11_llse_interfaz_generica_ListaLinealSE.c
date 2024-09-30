//////////////////////////////////////////////////////////////////
// Trabajar con una lista lineal simplemente enlazada (llse)
// ListaLinealSE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_llse.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

void mostrarLista(tllse lista)
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
}

void liberarMemoria(tllse *lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;
  alumno = (Datos *)borrarPrimero(lista); // borrar elemento de la lista
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = (Datos *)borrarPrimero(lista); // borrar elemento de la lista
  }
}

void error1(tllse *lista)
{
  liberarMemoria(lista);
  error();
}

void error2(Datos *alumno, tllse *lista)
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
  int r, pos;

  // Definir una lista lineal vacía: llse
  tllse llse;
  iniciarLlse(&llse);
  
  // Leer los datos y añadirlos a la lista
  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (scanf("%[^\n]", nombre) != EOF)
  {
    printf("Nota:   ");
    scanf("%lf", &nota); while (getchar() != '\n');
    // Crear un objeto de tipo Datos
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error1(&llse);
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    if (!anyadirAlFinal(alumno, &llse)) error2(alumno, &llse);
    printf("\nNombre: ");
  }

  // Añadir un objeto al principio
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error1(&llse);
  strcpy(alumno->nombre, "alumno x");
  alumno->nota = 10;
  if (!anyadirAlPrincipio(alumno, &llse)) error2(alumno, &llse);

  // Añadir un objeto en la posición pos
  pos = 1;
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) error1(&llse);
  strcpy(alumno->nombre, "alumno y");
  alumno->nota = 9.5;
  if (!(r = anyadir(pos, alumno, &llse)))
    error2(alumno, &llse);
  else if (r == -1)
    printf("Índice fuera de límites\n");

  printf("\n\n");
  // Mostrar el primero
  alumno = (Datos *)obtenerPrimero(llse);
  if (alumno)
    printf("Primero: %s %g\n", alumno->nombre, alumno->nota);
  
  // Mostrar el último
  alumno = (Datos *)obtenerUltimo(llse);
  if (alumno)
    printf("Último: %s %g\n", alumno->nombre, alumno->nota);

  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(llse);

  // Borrar el elemento de índice 2
  if (alumno = (Datos *)borrar(2, &llse))
  {
    free(alumno); // borrar área de datos
  }
  else
    printf("Índice fuera de límites\n");
  
  // Modificar el elemento de índice 1
  alumno = (Datos *)obtener(1, llse);
  if (alumno) alumno->nota = 9;

  // Mostrar todos
  printf("\nLista:\n");
  mostrarLista(llse);

  // Borrar la lista
  liberarMemoria(&llse);
}

