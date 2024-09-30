//////////////////////////////////////////////////////////////////
// Crear una lista lineal simplemente enlazada (llse)
// ListaLinealSE.c
//
#include <stdio.h>
#include <stdlib.h>
#include "interfaz_llse.h"

void liberarMemoria(Elemento *llse)
{
  int i = 0;
  double *n = (double *)obtener(i, llse);
  while (n != NULL)
  {
    free(n);
    i++;
    n = (double *)obtener(i, llse);
  }
  // Borrar la lista
  borrarTodos(llse);
}

int main(void)
{
  int i = 0;

  // Definir una lista lineal vac�a: llse
  Elemento *llse = NULL;
  
  // Leer los datos y a�adirlos a la lista
  double *n = NULL, d = 0;

  printf("Introducir datos. Finalizar con eof.\n");
  printf("Valor double: ");
  while (scanf("%lf", &d) != EOF)
  {
    n = (double *)malloc(sizeof(double));
    if (!n) { liberarMemoria(llse); error(); }
    *n = d;
    if (!anyadirAlPrincipio(n, &llse))
    {
      free(n); // �ltimo dato creado din�micamente y no a�adido
      liberarMemoria(llse); 
      error();
    }
    printf("Valor double: ");
  }

  // Mostrar la lista de datos
  printf("\n");
  n = (double *)obtener(i, llse);
  i = 0;
  while (n != NULL)
  {
    printf("%g ", *n);
    i++;
    n = (double *)obtener(i, llse);
  }
  printf("\n");

  // Borrar las �reas de datos y los elementos de la lista
  liberarMemoria(llse);
}
