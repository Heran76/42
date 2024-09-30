// interfaz_pila_cola.c
//
#include "interfaz_lcse.h"
#include "interfaz_pila_cola.h"

//////////////////////////////////////////////////////////////////
// Pila: lista en la que todas las inserciones y supresiones se
// hacen en un extremo de la misma.
//
// Invoca a las funciones anyadirAlPrincipio y borrar
// de interfaz_lcse.c
//
void iniciarPila(tpila *lista)
{
  iniciarLcse(lista);
}

int meterEnPila(void *e, tpila *lista)
{
  return anyadirAlPrincipio(e, lista);
}

void *sacarDePila(tpila *lista)
{
  return borrar(lista);
}
//////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////
// Cola: lista en la que todas las inserciones se hacen por un
// extremo de la lista (por el final) y todas las supresiones se
// hacen por el otro extremo (por el principio).
//
// Invoca a las funciones anyadirAlFinal y borrar
// de interfaz_lcse.c
//
void iniciarCola(tcola *lista)
{
  iniciarLcse(lista);
}

int meterEnCola(void *e, tcola *lista)
{
  return anyadirAlFinal(e, lista);
}

void *sacarDeCola(tcola *lista)
{
  return borrar(lista);
}
//////////////////////////////////////////////////////////////////
