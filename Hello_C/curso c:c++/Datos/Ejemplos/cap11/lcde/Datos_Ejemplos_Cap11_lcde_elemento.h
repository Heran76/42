/* elemento.h
 */
#pragma once

// Tipo Elemento (un elemento de la lista) ///////////////////////
typedef struct s
{
  void *dato;          // área de datos
  struct s *anterior;  // puntero al elemento anterior
  struct s *siguiente; // puntero al elemento siguiente
} Elemento;

