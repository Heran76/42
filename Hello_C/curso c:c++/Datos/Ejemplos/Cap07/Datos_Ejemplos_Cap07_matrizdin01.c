/*************** Matriz dinámica de una dimensión ***************/
/* matrizdin01.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <memory.h> // necesaria para memset

void *insertarElemento(int *m, int *pnElementos, int pos);
void asignarValoresAleatorios(int *m, int n);
void mostrarMatriz(int *m, int n);

int main(void)
{
  int *m = NULL, *q = NULL;
  int correcto = 0, nElementos = 0;

  do
  {
    printf("Número de elementos de la matriz: ");
    correcto = scanf("%d", &nElementos);
    while (getchar() != '\n'); // limpiar buffer
  }
  while (!correcto || nElementos < 1);

  // Crear la matriz
  if ((m = (int *)malloc(nElementos * sizeof(int))) == NULL)
  {
    printf("Insuficiente espacio de memoria\n");
    return -1;
  }

  // Iniciar los elementos de la matriz a 0
  for (int i = 0; i < nElementos; i++)
    m[i] = 0;

  // Los elementos de la matriz pueden también ser puestos
  // a 0 así:
  // memset(m, 0, nBytes);

  // Operaciones
  // ...

  asignarValoresAleatorios(m, nElementos);
  mostrarMatriz(m, nElementos);

  // Insertar un elemento en la posición 5
  int pos = 5;
  if ((q = (int *)insertarElemento(m, &nElementos, pos)) == NULL)
    printf("No es posible realizar la inserción\n");
  else
    m = q;

  // Insertar un elemento al final
  pos = nElementos;
  if ((q = (int *)insertarElemento(m, &nElementos, pos)) == NULL)
    printf("No es posible realizar la inserción\n");
  else
    m = q;

  mostrarMatriz(m, nElementos);

  free(m);
  return 0;
}

void *insertarElemento(int *m, int *pnElementos, int pos)
{
  int n = *pnElementos;

  if (pos < 0 || pos > n) return 0;
  m = (int *)realloc(m, (n + 1) * sizeof(int));
  if (m != 0)
  {
    for (int i = n; i > pos; i--)
      m[i] = m[i - 1];
    m[pos] = 0; // elemento insertado
    // Actualizar el número de elementos de la matriz
    *pnElementos = n + 1;
  }
  return m; // puntero al nuevo bloque de memoria asignado
}

void asignarValoresAleatorios(int *m, int n)
{
  srand((unsigned)time(NULL));
  for (int i = 0; i < n; i++)
    m[i] = rand();
}

void mostrarMatriz(int *m, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", m[i]);
  printf("\n");
}
