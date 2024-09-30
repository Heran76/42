/* nodo.h
 */
#pragma once

// Tipo Nodo (un elemento del �rbol) ///////////////////////
typedef struct s
{
  int numeroDeNodos;    // nodos del sub�rbol que tiene esta ra�z
  void *datos;          // �rea de datos
  struct s *izquierdo;  // ra�z del sub�rbol izquierdo
  struct s *derecho;    // ra�z del sub�rbol derecho
} Nodo;

