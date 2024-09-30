//////////////////////////////////////////////////////////////////
// Crear un árbol binario perfectamente equilibrado.
// ArbolBinE.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_abe.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

/////////////////////////////////////////////////////////////////
// Definir las funciones: leerDatos, comparar, procesar y
// liberarmem, según los prototipos especificados en
// interfaz_abe.h, para adaptarlas a nuestras necesidades.
//
// Leer los datos que serán referenciados por un nodo del árbol.
void *leerDatos()
{
  char nombre[50];
  double nota;
  Datos *alumno = NULL;

  printf("nombre: ");
  scanf("%[^\n]", nombre);
  printf("nota:   ");
  scanf("%lf", &nota); while (getchar() != '\n');
  // Crear un objeto de tipo Datos
  alumno = (Datos *)malloc(sizeof(Datos));
  if (!alumno) return 0;
  strcpy(alumno->nombre, nombre);
  alumno->nota = nota;
  return (void *)alumno;
}

// Permite comparar los datos de dos nodos.
int comparar(void *datos1, void *datos2)
{
  char *nom1 = ((Datos *)datos1)->nombre;
  char *nom2 = ((Datos *)datos2)->nombre;
  return strcmp(nom1, nom2);
}

// Permite mostrar los datos del nodo visitado.
void procesar(void *datos)
{
  Datos *alumno = (Datos *)datos;
  if (!alumno) return;
  printf("%s %g\n", alumno->nombre, alumno->nota);
}

// Liberar la memoria del área de datos del nodo visitado.
void liberarmem(void *datos)
{
  if (datos) free((Datos *)datos);
}
/////////////////////////////////////////////////////////////////

void mostrarArbol(Nodo *raiz)
{
  inorden(raiz);
}

int main(void)
{
  Nodo *raiz = NULL; // árbol binario equilibrado
  Datos *alumno = NULL, *alumBuscado;
  int numeroDeNodos = 0, pos = 0;

  printf("Número de nodos: ");
  scanf("%d", &numeroDeNodos); while (getchar() != '\n');
  raiz = construirArbol(numeroDeNodos);
  if (raiz == NULL) return 0; // árbol vacío

  // Mostrar el árbol
  printf("\nArbol:\n");
  mostrarArbol(raiz);

  // Obtener los datos del nodo i
  printf("Nodo (0,1,2,...):   ");
  scanf("%d", &pos); while (getchar() != '\n');
  alumno = obtenerNodo(pos, raiz);
  if ( alumno == NULL )
    printf("La búsqueda falló\n");
  else
    printf("Alumno %s, nota es %g\n", alumno->nombre, alumno->nota);

  // Buscar datos
  printf("Buscar todas las ocurrencias de nombre en el árbol.\n");
  alumno = leerDatos();
  if (alumno)
  {
    alumBuscado = buscar(alumno, raiz, &pos);
    if (alumBuscado == NULL) printf("La búsqueda falló\n");
    while (alumBuscado != NULL)
    {
      printf("Nodo %2d, nota es %g\n", pos, alumBuscado->nota);
      pos++;
      alumBuscado = buscar(alumno, raiz, &pos);
    }
    free(alumno);
  }
  else
    printf("Insuficiente memoria\n");

  // Borrar el árbol
  borrarArbol(&raiz);

  return 0;
}

