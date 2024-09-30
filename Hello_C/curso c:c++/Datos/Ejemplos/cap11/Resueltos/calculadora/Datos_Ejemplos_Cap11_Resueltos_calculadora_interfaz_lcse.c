//////////////////////////////////////////////////////////////////
// Manipular una lista circular simplemente enlazada (lcse)
// interfaz_lcse.c
//
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_lcse.h"

// Interfaz para manipular una lcse //////////////////////////////
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

void iniciarLcse(tlcse *lista)
{
  lista->ultimo = NULL;
  lista->numeroDeElementos = 0;
}
  
int anyadirAlPrincipio(void *e, tlcse *lista)
{
  // Añade un elemento al principio de la lista.
  Elemento *ultimo = lista->ultimo;

  // Crear el nuevo elemento
  Elemento *q = nuevoElemento();
  if (!q) return 0;
  q->dato = e;
  q->siguiente = NULL;

  if( ultimo != NULL ) // existe una lista
  {         
    q->siguiente = ultimo->siguiente;
    ultimo->siguiente = q;
  }    
  else  // inserción del primer elemento
  {
    ultimo = q;
    ultimo->siguiente = q;
  }

  lista->numeroDeElementos++;
  lista->ultimo = ultimo;
  return 1;
}

int anyadirAlFinal(void *e, tlcse *lista)
{
  // Añade un elemento al final de la lista.
  // Por lo tanto, último referenciará este nuevo elemento. 
  Elemento *ultimo = lista->ultimo;

  // Crear el nuevo elemento.
  Elemento *q = nuevoElemento();
  if (!q) return 0;
  q->dato = e;
  q->siguiente = NULL;
    
  if( ultimo != NULL ) // existe una lista
  {       
    q->siguiente = ultimo->siguiente;
    ultimo = ultimo->siguiente = q;
  }
  else  // inserción del primer elemento
  {
    ultimo = q;
    ultimo->siguiente = q;
  }

  lista->numeroDeElementos++;
  lista->ultimo = ultimo;
  return 1;
}

void *borrar(tlcse *lista)
{
  // Borra el primer elemento de la lista.
  // Devuelve NULL si la operación de borrar fracasa.
  Elemento *q = NULL, *ultimo = lista->ultimo;
  void *datos = NULL;

  if( ultimo == NULL )
    return NULL; // lista vacía

  q = ultimo->siguiente;
  if( q == ultimo ) // sólo hay un elemento
    lista->ultimo = NULL;
  else
    ultimo->siguiente = q->siguiente;
  datos = q->dato;
  free(q);

  lista->numeroDeElementos--;
  return datos;
}

void *obtener(int i, tlcse lista)
{
  // Obtener el elemento de la posición i
  int n = 0;
  Elemento *q = NULL;

  if (i >= lista.numeroDeElementos || i < 0)
    return NULL; // índice fuera de límites

  q = lista.ultimo->siguiente; // primer elemento
  // Posicionarse en el elemento i
  for (n = 0; n < i; n++)
    q = q->siguiente;
  
  // Retornar los datos
  return q->dato;
}
//////////////////////////////////////////////////////////////////
