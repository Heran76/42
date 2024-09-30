/* nodo.h
 */
#pragma once

// Tipo Nodo (un elemento del árbol) ///////////////////////
typedef struct s
{
  void *datos;          // área de datos
  struct s *izquierdo;  // raíz del subárbol izquierdo
  struct s *derecho;    // raíz del subárbol derecho
} Nodo;
