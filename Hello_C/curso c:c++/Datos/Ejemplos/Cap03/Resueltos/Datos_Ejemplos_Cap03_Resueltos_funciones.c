/* funciones.c - Cómo es un número. Contar.
 */
#include <stdio.h>

void par_impar(int);
void positivo_negativo(int);
int cuadrado(int);
int cubo(int);
int contar(void);

int main(void)
{
  int n = 10;
  par_impar(n);
  positivo_negativo(n);
  printf("cuadrado de %d = %d\n", n, cuadrado(n));
  printf("cubo de %d = %d\n", n, cubo(n));
  printf("\nContar hasta tres: ");
  for (int i = 0; i < 3; ++i)
    printf("%d ", contar());
}

void par_impar(int n)
{
  printf("%d es %s\n", n, (n % 2 == 0) ? "par" : "impar");
}

void positivo_negativo(int n)
{
  printf("%d es %s\n", n, (n >= 0) ? "positivo" : "negativo");
}

int cuadrado(int n)
{
  return n * n;
}

int cubo(int n)
{
  return n * n * n;
}

int contar(void)
{
  static int n = 1;
  return n++;
}
