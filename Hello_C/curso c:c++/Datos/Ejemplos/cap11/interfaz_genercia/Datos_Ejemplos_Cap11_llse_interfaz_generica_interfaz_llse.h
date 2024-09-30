/* interfaz_llse.h
 */
#pragma once

// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una llse //////////////////////////////
//
// Par�metros de la lista
typedef struct
{
  Elemento *pllse;       // apuntar� siempre al primer elemento
  int numeroDeElementos; // n�mero de elementos de la lista
} tllse;

// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Iniciar los par�metros de la lista
void iniciarLlse(tllse *lista);

// A�adir un elemento en la posici�n i
int anyadir(int i, void *e, tllse *lista);

// A�adir un elemento al principio de la lista
int anyadirAlPrincipio(void *e, tllse *lista);

// A�adir un elemento al final de la lista
int anyadirAlFinal(void *e, tllse *lista);

// Borrar el elemento i de la lista
void *borrar(int i, tllse *lista);

// Borrar el primer elemento de la lista
void *borrarPrimero(tllse *lista);

// Borrar el �ltimo elemento de la lista
void *borrarUltimo(tllse *lista);

// Obtener el elemento i de la lista
void *obtener(int i, tllse lista);

// Obtener el primer elemento de la lista
void *obtenerPrimero(tllse lista);

// Obtener el �ltimo elemento de la lista
void *obtenerUltimo(tllse lista);
