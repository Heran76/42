//////////////////////////////////////////////////////////////////
// Crear un árbol binario de búsqueda.
// ArbolBinB.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interfaz_abb.h"

typedef struct
{
  char nombre[50];
  double nota;
} Datos;

/////////////////////////////////////////////////////////////////
// Definir las funciones: comparar, copiar, procesar y liberarmem,
// según los prototipos especificados en interfaz_abb.h, para
// adaptarlas a nuestras necesidades.
//
// Permite comparar los datos de dos nodos.
int comparar(void *datos1, void *datos2)
{
  char *nom1 = ((Datos *)datos1)->nombre;
  char *nom2 = ((Datos *)datos2)->nombre;
  return strcmp(nom1, nom2);
}

// Copiar los datos de un nodo en otro
void copiar(void *datos1, void *datos2)
{
  *((Datos *)datos1) = *((Datos *)datos2);
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
  free((Datos *)datos);
}
/////////////////////////////////////////////////////////////////

void mostrarArbol(Nodo *raiz)
{
  inorden(raiz);
}

void error1(Nodo *raiz)
{
  borrarArbol(&raiz);
  error();
}

void error2(Datos *alumno, Nodo *raiz)
{
  free(alumno); // último creado y no asignado
  borrarArbol(&raiz);
  error();
}

int main(void)
{
  int cod = 0;
  char nombre[50];
  double nota;
  
  Nodo *raiz = NULL; // árbol binario de búsqueda
  Datos *alumno = NULL, *aux = NULL;

  printf("Introducir datos. Finalizar con eof.\n");

  printf("nombre: ");
  while (scanf("%[^\n]", nombre) != EOF)
  {
    printf("nota:   ");
    scanf("%lf", &nota); while (getchar() != '\n');
    // Crear un objeto de tipo Datos
    alumno = (Datos *)malloc(sizeof(Datos));
    if (!alumno) error1(raiz);
    strcpy(alumno->nombre, nombre);
    alumno->nota = nota;
    cod = insertar(alumno, &raiz);
    if (cod == 0) error2(alumno, raiz);
    if (cod == 2) // ya existe
    {
      // Si ya existe, distinguimos dos casos:
      // 1. nota nueva >= 0; cambiamos la nota
      // 2. nota nueva < 0; borramos el nodo
      if (nota >= 0)
      {
        aux = (Datos *)buscar(alumno, raiz);
        aux->nota = nota;
      }
      else
      {
        aux = borrar(alumno, &raiz);
        free(aux);
        printf("nodo borrado\n");
      }
      free(alumno); // ya existe
    }
    printf("nombre: ");
  }
  printf("\n");

  // Mostrar el árbol
  printf("\nArbol:\n");
  mostrarArbol(raiz);

  // Borrar el árbol
  borrarArbol(&raiz);
}

