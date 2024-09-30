// matpuntfuns.c
//
#include <stdio.h>
#include <math.h>

double cuadrado(double);
double pot(double, double);

typedef double (*t_ptFuncion)();

int main(void)
{
  // Definir una matriz de punteros a funciones de tipo t_ptFuncion
  t_ptFuncion ptFuncion[10];

  // Asignar las direcciones de las funciones cuadrado y pot
  ptFuncion[0] = cuadrado;
  ptFuncion[1] = pot;
  /* Otras asignaciones */

  // Llamar a las funciones referenciadas por la matriz
  printf("%g\n", ptFuncion[0](12.0));
  printf("%g\n", ptFuncion[1](12.0, 2.0));
}

double cuadrado(double a)
{
  return (a * a);
}

double pot(double x, double y)
{
  return exp(y * log(x));
}

