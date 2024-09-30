// interfaz_abe.c
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_abe.h" // estructura Nodo

/////////////////////////////////////////////////////////////////
// Interfaz abe: árbol binario equilibrado. Para utilizar las
// funciones proporcionadas por esta interfaz, tendremos que
// definir en la aplicación que la utilice las funciones:
// leerDatos, comparar, procesar y liberarmem.
//
// Crear un nuevo elemento
Nodo *nuevoNodo()
{
  Nodo *q = (Nodo *)malloc(sizeof(Nodo));
  if (!q) printf("Insuficiente memoria\n");
  return q;
}

Nodo *construirArbol(int n)
{
  // Construye un árbol de n nodos perfectamente equilibrado.
  // Los datos se almacenan en los nodos según el orden en el
  // que son accedidos con la forma "inorden".
  Nodo *nodo = NULL;
  int ni = 0, nd = 0;

  if ( n == 0 )
    return NULL;
  else
  {
    ni = n / 2;      // nodos del subárbol izquierdo
    nd = n - ni - 1; // nodos del subárbol derecho
    nodo = nuevoNodo();
    if (!nodo) return 0;
    nodo->numeroDeNodos = n;
    nodo->izquierdo = construirArbol(ni);
    nodo->datos = leerDatos();
    nodo->derecho = construirArbol(nd);
    return nodo;
  }
}

void *obtenerNodo(int nodo_i, Nodo *raiz)
{
  // Esta función permite devolver los datos del nodo i.
  // Los nodos se consideran numerados (0, 1, 2, ...) según
  // el orden en el que son accedidos con la forma "inorden".
  int ni = 0, n = 0;
  if (raiz) n = raiz->numeroDeNodos;
  if (raiz == NULL || nodo_i < 0 || nodo_i > n) return NULL;

  ni = n / 2;      // nodos del subárbol izquierdo
  if ( nodo_i == ni )
    return raiz->datos; // nodo actual (raíz subárbol)
  else if ( nodo_i < ni )
    // Subárbol izquierdo
    return obtenerNodo(nodo_i, raiz->izquierdo);
  else
    // Subárbol derecho; ajustar el índice en este subárbol
    // descontando los nodos del subárbol izquierdo y el actual
    return obtenerNodo(nodo_i - ni - 1, raiz->derecho);
  return NULL;
}

void *buscar(void *datos, Nodo *raiz, int *pos)
{
  // Buscar un determinado nodo en el árbol. Llama a buscarNodo
  // asegurando así que inicialmente el valor de res sea NULL.
  int i = 0; // nodo inicial
  void *res = NULL;
  buscarNodo(datos, raiz, &res, pos, &i);
  return res;
}

void buscarNodo(void *datos, Nodo *raiz, void **res, int *pos, int *i)
{
  // La función buscar permite acceder a un determinado nodo.
  // Si los datos especificados por "datos" se localizan en el
  // árbol apuntado por "raíz", a partir de la posición *pos,
  // "buscar" devuelve en *res un puntero a esos datos;
  // en otro caso, devuelve NULL.
  // Los nodos se consideran numerados (0, 1, 2, ...) según
  // el orden en el que son accedidos con la forma "inorden".
  // *i es la posición del nodo en proceso.
  // *pos devuelve la posición del nodo encontrado.
  Nodo *actual = raiz;

  if ( actual != NULL && *res == NULL )
  {
    buscarNodo(datos, actual->izquierdo, res, pos, i);
    if (*res == NULL && (*pos)-- <= 0)
    {
      // La primera condición que aparece en el if anterior es
      // necesaria para que, una vez encontrado el nodo, en el
      // camino de retorno por la pila de llamadas no se
      // decremente *pos (segunda condición) ya que almacena
      // la posición del nodo encontrado.
      if ( comparar( datos, actual->datos ) == 0 )
      {
        *res = actual->datos;  // nodo encontrado
        *pos = *i;
      }
    }
    (*i)++; // posición del siguiente nodo que será accedido
    buscarNodo(datos, actual->derecho, res, pos, i);
  }
}

void inorden(Nodo *raiz)
{
  // La función recursiva inorden visita los nodos del árbol
  // utilizando la forma inorden; esto es, primero visita
  // el subárbol izquierdo, después visita la raíz y, por
  // último, el subárbol derecho.
  Nodo *actual = raiz;

  if ( actual != NULL )
  {
    inorden( actual->izquierdo ); // visitar el subárbol izquierdo
    // Procesar los datos del nodo visitado
    procesar( actual->datos );
    inorden( actual->derecho );   // visitar el subárbol derecho
  }
}

void borrarArbol(Nodo **raiz)
{
  // La función recursiva borrarArbol visita los nodos del árbol
  // utilizando la forma postorden para liberar la memoria
  // asignada a cada uno de ellos.
  Nodo *actual = *raiz;

  if ( actual != NULL )
  {
    borrarArbol( &actual->izquierdo ); // subárbol izquierdo
    borrarArbol( &actual->derecho );   // subárbol derecho
    liberarmem( actual->datos );
    free( actual );
  }
  *raiz = NULL;
}
/////////////////////////////////////////////////////////////////
