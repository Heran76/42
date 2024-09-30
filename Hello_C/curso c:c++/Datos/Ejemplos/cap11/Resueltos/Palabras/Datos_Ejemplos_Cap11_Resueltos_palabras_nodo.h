/* nodo.h
 */
#pragma once

// Tipo Nodo (un elemento del �rbol) ///////////////////////
typedef struct s
{
  void *datos;          // �rea de datos
  struct s *izquierdo;  // puntero al elemento anterior
  struct s *derecho;    // puntero al elemento siguiente
} Nodo;

