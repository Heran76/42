/* interfaz_llse.h
 */
#pragma once

// Tipo Elemento (un elemento de la lista) ///////////////////////
#include "elemento.h"

// Interfaz para manipular una llse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error();

// Crear un nuevo elemento
Elemento *nuevoElemento();

// Añadir un elemento al principio de la lista
int anyadirAlPrincipio(void *e, Elemento **lista);

// Obtener el elemento de la lista
void *obtener(int i, Elemento *q);

// Borrar todos los elementos de la lista
void borrarTodos(Elemento *lista);
