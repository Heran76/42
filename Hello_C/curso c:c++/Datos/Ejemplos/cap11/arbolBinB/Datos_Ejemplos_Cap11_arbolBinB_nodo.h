/* nodo.h
 */
#pragma once

// Tipo Nodo (un elemento del �rbol) ///////////////////////
typedef struct s
{
  void *datos;          // �rea de datos
  struct s *izquierdo;  // ra�z del sub�rbol izquierdo
  struct s *derecho;    // ra�z del sub�rbol derecho
} Nodo;
