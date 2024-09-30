/* interfaz_lcse.h
 */
#pragma once

// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una lcse //////////////////////////////
//
// Par�metros de la lista
typedef struct
{
  Elemento *ultimo;      // apuntar� siempre al �ltimo elemento
  int numeroDeElementos; // n�mero de elementos de la lista
} tlcse;

// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Iniciar los par�metros de la lista
void iniciarLcse(tlcse *lista);

// A�adir un elemento al principio de la lista
int anyadirAlPrincipio(void *e, tlcse *lista);

// A�adir un elemento al final de la lista
int anyadirAlFinal(void *e, tlcse *lista);

// Borrar el elemento primero de la lista
void *borrar(tlcse *p);

// Obtener el elemento i de la lista
void *obtener(int i, tlcse lista);
