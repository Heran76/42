/* interfaz_pila_cola.h
 */
#pragma once

// Incluir el tipo Elemento y la interfaz lcse ///////////////////
#include "interfaz_lcse.h"

// Interfaz para manipular una pila //////////////////////////////
//
typedef tlcse tpila;
typedef tlcse tcola;

// Iniciar los parámetros de la lista
void iniciarPila(tpila *lista);

// Iniciar los parámetros de la lista
void iniciarCola(tcola *lista);

// Meter un elemento en la pila
int meterEnPila(void *e, tpila *lista);

// Sacar un elemento de la pila
void *sacarDePila(tpila *lista);

// Interfaz para manipular una cola //////////////////////////////
//
// Meter un elemento en la cola
int meterEnCola(void *e, tcola *lista);

// Sacar un elemento de la cola
void *sacarDeCola(tcola *lista);
