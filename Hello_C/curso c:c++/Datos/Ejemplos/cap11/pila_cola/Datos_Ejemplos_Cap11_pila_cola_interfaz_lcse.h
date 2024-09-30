/* interfaz_lcse.h
 */
#pragma once

// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una lcse //////////////////////////////
//
// Parámetros de la lista
typedef struct
{
  Elemento *ultimo;      // apuntará siempre al último elemento
  int numeroDeElementos; // número de elementos de la lista
} tlcse;

// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Iniciar los parámetros de la lista
void iniciarLcse(tlcse *lista);

// Añadir un elemento al principio de la lista
int anyadirAlPrincipio(void *e, tlcse *lista);

// Añadir un elemento al final de la lista
int anyadirAlFinal(void *e, tlcse *lista);

// Borrar el elemento primero de la lista
void *borrar(tlcse *p);

// Obtener el elemento i de la lista
void *obtener(int i, tlcse lista);
