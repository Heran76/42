/* parametro.c
 */
#include <stdio.h>
void CopiarMatriz(int [], int [], int);
void VisualizarMatriz(int [], int);

int main(void)
{
  int x[] = { 10, 20, 30, 40, 50 };
  int t = sizeof(x)/sizeof(int);
  int y[t];
  CopiarMatriz(y, x, t); // copiar x en y
  VisualizarMatriz(y, t);
}

void CopiarMatriz(int a[], int b[], int n)
{
  // Copiar b en a
  for (int i = 0; i < n; ++i)
    a[i] = b[i];
}

void VisualizarMatriz(int m[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", m[i]);
}
