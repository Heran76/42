// interfaz_abe.c
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_abe.h" // estructura Nodo

/////////////////////////////////////////////////////////////////
// Interfaz abe: �rbol binario equilibrado. Para utilizar las
// funciones proporcionadas por esta interfaz, tendremos que
// definir en la aplicaci�n que la utilice las funciones:
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
  // Construye un �rbol de n nodos perfectamente equilibrado.
  // Los datos se almacenan en los nodos seg�n el orden en el
  // que son accedidos con la forma "inorden".
  Nodo *nodo = NULL;
  int ni = 0, nd = 0;

  if ( n == 0 )
    return NULL;
  else
  {
    ni = n / 2;      // nodos del sub�rbol izquierdo
    nd = n - ni - 1; // nodos del sub�rbol derecho
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
  // Esta funci�n permite devolver los datos del nodo i.
  // Los nodos se consideran numerados (0, 1, 2, ...) seg�n
  // el orden en el que son accedidos con la forma "inorden".
  int ni = 0, n = 0;
  if (raiz) n = raiz->numeroDeNodos;
  if (raiz == NULL || nodo_i < 0 || nodo_i > n) return NULL;

  ni = n / 2;      // nodos del sub�rbol izquierdo
  if ( nodo_i == ni )
    return raiz->datos; // nodo actual (ra�z sub�rbol)
  else if ( nodo_i < ni )
    // Sub�rbol izquierdo
    return obtenerNodo(nodo_i, raiz->izquierdo);
  else
    // Sub�rbol derecho; ajustar el �ndice en este sub�rbol
    // descontando los nodos del sub�rbol izquierdo y el actual
    return obtenerNodo(nodo_i - ni - 1, raiz->derecho);
  return NULL;
}

void *buscar(void *datos, Nodo *raiz, int *pos)
{
  // Buscar un determinado nodo en el �rbol. Llama a buscarNodo
  // asegurando as� que inicialmente el valor de res sea NULL.
  int i = 0; // nodo inicial
  void *res = NULL;
  buscarNodo(datos, raiz, &res, pos, &i);
  return res;
}

void buscarNodo(void *datos, Nodo *raiz, void **res, int *pos, int *i)
{
  // La funci�n buscar permite acceder a un determinado nodo.
  // Si los datos especificados por "datos" se localizan en el
  // �rbol apuntado por "ra�z", a partir de la posici�n *pos,
  // "buscar" devuelve en *res un puntero a esos datos;
  // en otro caso, devuelve NULL.
  // Los nodos se consideran numerados (0, 1, 2, ...) seg�n
  // el orden en el que son accedidos con la forma "inorden".
  // *i es la posici�n del nodo en proceso.
  // *pos devuelve la posici�n del nodo encontrado.
  Nodo *actual = raiz;

  if ( actual != NULL && *res == NULL )
  {
    buscarNodo(datos, actual->izquierdo, res, pos, i);
    if (*res == NULL && (*pos)-- <= 0)
    {
      // La primera condici�n que aparece en el if anterior es
      // necesaria para que, una vez encontrado el nodo, en el
      // camino de retorno por la pila de llamadas no se
      // decremente *pos (segunda condici�n) ya que almacena
      // la posici�n del nodo encontrado.
      if ( comparar( datos, actual->datos ) == 0 )
      {
        *res = actual->datos;  // nodo encontrado
        *pos = *i;
      }
    }
    (*i)++; // posici�n del siguiente nodo que ser� accedido
    buscarNodo(datos, actual->derecho, res, pos, i);
  }
}

void inorden(Nodo *raiz)
{
  // La funci�n recursiva inorden visita los nodos del �rbol
  // utilizando la forma inorden; esto es, primero visita
  // el sub�rbol izquierdo, despu�s visita la ra�z y, por
  // �ltimo, el sub�rbol derecho.
  Nodo *actual = raiz;

  if ( actual != NULL )
  {
    inorden( actual->izquierdo ); // visitar el sub�rbol izquierdo
    // Procesar los datos del nodo visitado
    procesar( actual->datos );
    inorden( actual->derecho );   // visitar el sub�rbol derecho
  }
}

void borrarArbol(Nodo **raiz)
{
  // La funci�n recursiva borrarArbol visita los nodos del �rbol
  // utilizando la forma postorden para liberar la memoria
  // asignada a cada uno de ellos.
  Nodo *actual = *raiz;

  if ( actual != NULL )
  {
    borrarArbol( &actual->izquierdo ); // sub�rbol izquierdo
    borrarArbol( &actual->derecho );   // sub�rbol derecho
    liberarmem( actual->datos );
    free( actual );
  }
  *raiz = NULL;
}
/////////////////////////////////////////////////////////////////
