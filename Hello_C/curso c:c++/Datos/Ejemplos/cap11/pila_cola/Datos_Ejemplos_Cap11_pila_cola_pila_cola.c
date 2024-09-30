//////////////////////////////////////////////////////////////////
// Pilas y colas
//
// pila_cola.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_pila_cola.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

void mostrarLista(void *lista, int tipo)
{
  // Mostrar todos los elementos de la lista
  Datos *alumno = NULL;
  do
  {
    if (tipo == 0) // pila
      alumno = (Datos *)sacarDePila(lista);
    else // cola
      alumno = (Datos *)sacarDeCola(lista);
    if (alumno)
    {
      printf("%s %g\n", alumno->nombre, alumno->nota);
      free(alumno);
    }
  }
  while (alumno != NULL);
  if (alumno == NULL && tipo == 0)
    printf("pila vacía\n");
  if (alumno == NULL && tipo == 1)
    printf("cola vacía\n");
}

void liberarMemoria(void *lista)
{
  // Borrar todos los elementos de la lista
  Datos *alumno = NULL;
  // borrar: borra siempre el primer elemento
  alumno = borrar(lista);
  while (alumno)
  {
    free(alumno); // borrar el área de datos del elemento eliminado
    alumno = borrar(lista); // borrar elemento de la lista
  }
}

void error1(void *pila, void *cola)
{
  liberarMemoria(pila);
  liberarMemoria(cola);
  error();
}

void error2(Datos *alumno, void *pila, void *cola)
{
  free(alumno); // último creado y no asignado
  liberarMemoria(pila);
  liberarMemoria(cola);
  error();
}

int main(void)
{
  char nombre[50];
  double nota;
  Datos *alumno = NULL;

  // Pila y cola vacías
  tpila pila;
  tcola cola;
  iniciarPila(&pila);
  iniciarCola(&cola);

  // Leer datos y añadirlos a la pila y a la cola
  printf("Introducir datos. Finalizar con eof.\n");
  printf("Nombre: ");
  while (scanf("%[^\n]", nombre) != EOF)
  {
    printf("Nota:   ");
    scanf("%lf", &nota); while (getchar() != '\n');
    // Crear un objeto de tipo Datos para la pila
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error1(&pila, &cola);
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    if (!meterEnPila(alumno, &pila)) error2(alumno, &pila, &cola);
    // Crear un objeto de tipo Datos para la cola
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error1(&pila, &cola);
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    if (!meterEnCola(alumno, &cola)) error2(alumno, &pila, &cola);
    printf("\nNombre: ");
  }

  printf("\n");
  // Mostrar la pila
  printf("\nPila:\n");
  mostrarLista(&pila, 0);
  // Mostrar la pila por segunda vez
  printf("\nPila:\n");
  mostrarLista(&pila, 0);

  printf("\n");
  // Mostrar la cola
  printf("\nCola:\n");
  mostrarLista(&cola, 1);
  // Mostrar la cola por segunda vez
  printf("\nCola:\n");
  mostrarLista(&cola, 1);

  // Borrar la pila y la cola
  liberarMemoria(&pila);
  liberarMemoria(&cola);
}

