// busquedaBin2.c
//
#include <stdio.h>
#include "tiempo.h"

int busquedaBin1(double m[], int n, double v)
{
  // La función busquedaBin devuelve como resultado la posición
  // del valor. Si el valor no se localiza devuelve -1.

  int mitad, inf = 0, sup = n - 1;
  if (n == 0) return -1;

  do
  {
    mitad = (inf + sup) / 2;
    if (v > m[mitad])
      inf = mitad + 1;
    else
      sup = mitad - 1;
  }
  while( m[mitad] != v && inf <= sup);

  if (m[mitad] == v)
    return mitad;
  else
    return -1;
}

int busquedaBin2(double m[], int n, double v)
{
  // La función busquedaBin devuelve como resultado la posición
  // del valor. Si el valor no se localiza devuelve -1.

  int mitad, inf = 0, sup = n - 1;
  if (n == 0) return -1;

  do
  {
    mitad = (inf + sup) / 2;
    if (v > m[mitad])
      inf = mitad + 1;
    else
      sup = mitad;

  }
  while ( inf < sup );

  if (m[inf] == v)
    return inf;
  else
    return -1;
}

int main(void)
{
  double a[125000];
  int n = 125000;
  int r = 0;

  for (int i = 0; i < n; i++)
    a[i] = i+1;

  // Versión 1
  T_INICIAL(Búsqueda binaria versión 1);
  r = busquedaBin1(a, n, 0);
  for (int i = 0; i < n; i++)
    r = busquedaBin1(a, n, i+1);
  r = busquedaBin1(a, n, n+1);
  T_FINAL;

  // Versión 2
  T_INICIAL(Búsqueda binaria versión 2);
  r = busquedaBin2(a, n, 0);
  for (int i = 0; i < n; i++)
    r = busquedaBin2(a, n, i+1);
  r = busquedaBin2(a, n, n+1);
  T_FINAL;
}
