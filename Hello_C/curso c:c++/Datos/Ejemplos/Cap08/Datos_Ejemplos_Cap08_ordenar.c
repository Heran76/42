/******************** Punteros a funciones ********************/
/* ordenar.c
*/
#include <stdio.h>

// Tipo puntero a función
typedef int (*t_comparar)(double, double);

int compararDosElementos(double x, double y)
{
  return x > y;
}

void ordenar(double vector[], int nElementos, t_comparar comparar);
void visualizar(double v[], int ne);

int main(void)
{
  double x[] = { 1, 3, 5, 7, 2, 4, 6 }; // matriz x
  // Definir un puntero a función de tipo t_comparar
  t_comparar delegado = compararDosElementos;
  ordenar(x, sizeof(x)/sizeof(double), delegado);

  visualizar(x, sizeof(x)/sizeof(double));
}

void ordenar(double vector[], int nElementos, t_comparar comparar)
{
  // Método de inserción
  int i, k;
  double x;
  // Desde el segundo elemento
  for (i = 1; i < nElementos; i++)
  {
    x = vector[i];
    k = i - 1;
    // Para k = -1, se ha alcanzado el extremo izquierdo
    while (k >= 0 && comparar(x, vector[k]))
    {
      vector[k + 1] = vector[k]; // hacer hueco para insertar
      k--;
    }
    vector[k + 1] = x; // insertar x en su lugar
  }
}

void visualizar(double v[], int ne)
{
  int i;
  for (i = 0; i < ne; i++)
    printf("%g ", v[i]);
  printf("\n");
}
