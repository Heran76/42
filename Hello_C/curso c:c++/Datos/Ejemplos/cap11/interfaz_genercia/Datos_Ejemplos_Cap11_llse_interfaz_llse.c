//////////////////////////////////////////////////////////////////
// Manipular una lista lineal simplemente enlazada (llse)
// interfaz_llse.c
//
#include <stdio.h>
#include <stdlib.h>
#include "elemento.h"
#include "interfaz_llse.h"

// Interfaz para manipular una llse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}

// Crear un nuevo elemento
Elemento *nuevoElemento()
{
  Elemento *q = (Elemento *)malloc(sizeof(Elemento));
  return q;
}

// Añadir un elemento al principio de la lista
int anyadirAlPrincipio(void *e, Elemento **lista)
{
  Elemento *p = *lista;
  Elemento *q = nuevoElemento();
  if (!q) return 0;
  q->dato = e;      // asignación de datos
  q->siguiente = p; // reasignación de punteros
  p = q;

  *lista = p;
  return 1;
}

// Obtener el elemento de la lista
void *obtener(int i, Elemento *q)
{
  int n = 0;

  if (q == NULL)
  {
    printf("lista vacía\n");
    return NULL;
  }
  
  if (i >= 0)
  {
    // Posicionarse en el elemento i
    for (n = 0; q != NULL && n < i; n++)
      q = q->siguiente;

    // Retornar el elemento
    if (q != NULL) return q->dato;
  }

  // Índice fuera de límites
  return NULL;
}

// Borrar todos los elementos de la lista
void borrarTodos(Elemento *lista)
{
  Elemento *q = NULL;
  // Recorrer la lista
  while (lista != NULL)
  {
    q = lista;
    lista = lista->siguiente;
    free(q); // eliminar el elemento apuntado por q
  }
}
//////////////////////////////////////////////////////////////////
