/* elemento.h
 */
#pragma once

// Tipo Elemento (un elemento de la lista) ///////////////////////
typedef struct s
{
  void *dato;          // �rea de datos
  struct s *siguiente; // puntero al siguiente elemento
} Elemento;

