//////////////////////////////////////////////////////////////////
// Crear una lista lineal simplemente enlazada (llse)
// ListaLinealSE.c
//
#include <stdio.h>
#include <stdlib.h>

// Tipo Elemento (un elemento de la lista) ///////////////////////
typedef struct s
{
  double dato;         // área de datos
  struct s *siguiente; // puntero al siguiente elemento
} Elemento;
//////////////////////////////////////////////////////////////////

// Interfaz para manipular una llse //////////////////////////////
//
// Mostrar un mensaje de error y abortar el programa
void error()
{
  printf("Insuficiente memoria\n");
  exit(1);
}

// Crear un nuevo elemento
Elemento *nuevoElemento()
{
  Elemento *q = (Elemento *)malloc(sizeof(Elemento));
  return q;
}

// Borrar todos los elementos de la lista
void borrarTodos(Elemento *p)
{
  Elemento *q = NULL;

  // Recorrer la lista
  while (p != NULL)
  {
    q = p;
    p = p->siguiente;
    free(q);
  }
}

// Añadir un elemento al principio de la lista
int anyadirAlPrincipio(double n, Elemento **lista)
{
  Elemento *p = *lista;
  Elemento *q = nuevoElemento();
  if (!q) return 0;
  q->dato = n;      // asignación de valores
  q->siguiente = p; // reasignación de punteros
  p = q;
  *lista = p;
  return 1;
}
/*
// Mostrar todos los elementos de la lista
void mostrarTodos(Elemento *p)
{
// Recorrer la lista
Elemento *q = p; // puntero al primer elemento

while (q != NULL)
{
printf("%g ", q->dato);
q = q->siguiente;
}
}
*/
Elemento *obtener(int i, Elemento *q)
{
  int n = 0;

  if (q == NULL)
  {
    printf("lista vacía\n");
    return NULL;
  }
  if (i >= 0)
  {
    // Posicionarse en el elemento i
    for (n = 0; q != NULL && n < i; n++)
      q = q->siguiente;

    // Retornar el elemento
    if (q != NULL) return q;
  }

  // Índice fuera de límites
  return NULL;
}
//////////////////////////////////////////////////////////////////

// Aplicación ListaLinealSE //////////////////////////////////////
int main(void)
{
  int i = 0;
  // Definir una lista lineal vacía: llse
  Elemento *llse = NULL, *q = NULL;
  // Leer los datos y añadirlos a la lista
  double n;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Valor double: ");
  while (scanf("%lf", &n) != EOF)
  {
    if (!anyadirAlPrincipio(n, &llse))
    {
      borrarTodos(llse);
      error();
    }
    printf("Valor double: ");
  }

  // Mostrar la lista de datos
  printf("\n");
  i = 0;
  q = obtener(i, llse);
  while (q != NULL)
  {
    printf("%g ", q->dato);
    i++;
    q = obtener(i, llse);
  }

  // Borrar la lista
  borrarTodos(llse);
}
