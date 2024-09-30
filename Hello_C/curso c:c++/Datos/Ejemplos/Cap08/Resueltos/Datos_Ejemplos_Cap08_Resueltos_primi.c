/************ Números aleatorios en un intervalo dado ************/
/* primi.c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define C 6

void ordenar(int [], int);
double rnd(long *);

int main(void)
{
  long random = time(NULL) % 65536;  // semilla
  int limiteSup = 49, limiteInf = 1;
  int n[C];
  for (int i = 0; i < C; i++)
  {
    // Obtener un número aleatorio
    n[i] = (int)((limiteSup - limiteInf + 1) * rnd(&random) + limiteInf);
    // Verificar si ya existe el último número obtenido
    for (int k = 0; k < i; k++)
      if (n[k] == n[i]) // ya existe
      {
        i--;   // i será incrementada por el for externo
        break; // salir de este for
      }
  }
  // Ordenar la matriz
  ordenar(n, C);
  // Mostrar la matriz
  for (int i = 0; i < C; i++)
    printf("%d ", n[i]);
  printf("\n");
}

void ordenar(int a[], int ne)
{
  int aux = 0;  // variable auxiliar 
  int i = 0, s = 1;
  while ((s == 1) && (--ne > 0))
  {
    s = 0;  // no permutación 
    for (i = 1; i <= ne; i++)
      if (a[i-1] > a[i])
      {
        aux = a[i-1];
        a[i-1] = a[i];
        a[i] = aux;
        s = 1;  // permutación 
      }
  }
}

double rnd(long *prandom)
{
  *prandom = (25173 * *prandom + 13849) % 65536;
  return((double)*prandom / 65536); // valor >=0 y <1
}
