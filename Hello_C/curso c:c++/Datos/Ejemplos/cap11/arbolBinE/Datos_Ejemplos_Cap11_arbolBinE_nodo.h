/* nodo.h
 */
#pragma once

// Tipo Nodo (un elemento del árbol) ///////////////////////
typedef struct s
{
  int numeroDeNodos;    // nodos del subárbol que tiene esta raíz
  void *datos;          // área de datos
  struct s *izquierdo;  // raíz del subárbol izquierdo
  struct s *derecho;    // raíz del subárbol derecho
} Nodo;

