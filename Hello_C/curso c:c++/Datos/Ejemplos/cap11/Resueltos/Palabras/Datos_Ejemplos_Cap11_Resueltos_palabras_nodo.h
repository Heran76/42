/* nodo.h
 */
#pragma once

// Tipo Nodo (un elemento del árbol) ///////////////////////
typedef struct s
{
  void *datos;          // área de datos
  struct s *izquierdo;  // puntero al elemento anterior
  struct s *derecho;    // puntero al elemento siguiente
} Nodo;

