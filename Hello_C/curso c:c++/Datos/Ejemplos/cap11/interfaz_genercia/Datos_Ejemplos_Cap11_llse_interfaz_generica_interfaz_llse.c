//////////////////////////////////////////////////////////////////
// Manipular una lista lineal simplemente enlazada (llse)
// interfaz_llse.c
//
#include <stdio.h>
#include <stdlib.h>
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

void iniciarLlse(tllse *lista)
{
  lista->pllse = NULL;
  lista->numeroDeElementos = 0;
}

int anyadir(int i, void *e, tllse *lista)
{
  int n = 0;
  Elemento *q = NULL, *p = lista->pllse; // cabecera
  Elemento *elemAnterior = p, *elemActual = p;

  // Añadir un elemento en la posición i
  if (i > lista->numeroDeElementos || i < 0)
    return -1; // índice fuera de límites
  
  // Crear el elemento a añadir
  q = nuevoElemento();
  if (!q) return 0;
  q->dato = e; // asignar el puntero que referencia los datos
  q->siguiente = NULL;
  
  // Si la lista apuntada por p está vacía, añadirlo sin más 
  if (lista->numeroDeElementos == 0)
  {
    // Añadir el primer elemento
    lista->pllse = q;
    lista->numeroDeElementos++;
    return 1;
  }
  
  // Si la lista no está vacía, encontrar el punto de inserción.
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
  {
    elemAnterior = elemActual;
    elemActual = elemActual->siguiente;
  }
  // Dos casos:
  // 1) Insertar al principio de la lista
  // 2) Insertar después del anterior (incluye insertar al final)
  if ( elemAnterior == elemActual ) // insertar al principio
  {
    q->siguiente = p;
    p = q; // cabecera
  }
  else // insertar después del anterior
  {
    q->siguiente = elemActual;
    elemAnterior->siguiente = q;
  }

  lista->pllse = p;
  lista->numeroDeElementos++;
  return 1;
}

int anyadirAlPrincipio(void *e, tllse *lista)
{
  // Añadir un elemento al principio
  return anyadir(0, e, lista);
}

int anyadirAlFinal(void *e, tllse *lista)
{
  // Añadir un elemento al final
  return anyadir(lista->numeroDeElementos, e, lista);
}

void *borrar(int i, tllse *lista)
{
  int n = 0;
  Elemento *p = lista->pllse; // cabecera
  Elemento *elemAnterior = p, *elemActual = p;
  void *datos = NULL;

  // Borrar el elemento de la posición i
  if (i >= lista->numeroDeElementos || i < 0)
    return NULL; // índice fuera de límites
  
  // Entrar en la lista y encontrar el índice del elemento.
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
  {
    elemAnterior = elemActual;
    elemActual = elemActual->siguiente;
  }
  // Dos casos:
  // 1) Borrar el primer elemento de la lista
  // 2) Borrar el siguiente a elemAnterior (elemActual)
  if ( elemActual == p ) // 1)
    p = p->siguiente; // cabecera
  else // 2)
    elemAnterior->siguiente = elemActual->siguiente;
  datos = elemActual->dato; // datos del elemento a borrar
  free(elemActual);

  lista->pllse = p;
  lista->numeroDeElementos--;
  // Devolver los datos del elemento borrado
  return datos;
}

void *borrarPrimero(tllse *lista)
{
  // Borrar el primer elemento
  return borrar(0, lista);
}

void *borrarUltimo(tllse *lista)
{
  // Borrar el último elemento
  return borrar(lista->numeroDeElementos - 1, lista);
}

void *obtener(int i, tllse lista)
{
  int n = 0;
  Elemento *q = lista.pllse; // apunta al primer elemento
  // Obtener el elemento de la posición i
  if (i >= lista.numeroDeElementos || i < 0)
    return NULL; // índice fuera de límites
  
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
    q = q->siguiente;
  
  // Retornar los datos
  return q->dato;
}

void *obtenerPrimero(tllse lista)
{
  // Retornar el primer elemento
  return obtener(0, lista);
}

void *obtenerUltimo(tllse lista)
{
  // Retornar el último elemento
  return obtener(lista.numeroDeElementos - 1, lista);
}
//////////////////////////////////////////////////////////////////
