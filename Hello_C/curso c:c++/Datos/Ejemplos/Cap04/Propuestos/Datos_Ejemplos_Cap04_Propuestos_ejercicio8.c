/* n primeros elementos de la serie de Fibonacci
 *
 * Cap4\ejercicio8.c
 */
#include <stdio.h>
#define N 100

void serieFibonacci(int f[], int n);
double leerInt(int *dato);
void escribirResultado(int f[], int n);

int main(void)
{
  int f[N] = { 0 }, n;

  // Leer n: número de elementos a calcular de la serie
  printf("Número de elementos a calcular de la serie: ");
  leerInt(&n);
  while (n > N)
  {
    printf("El valor introducido no puede ser mayor que %d. Introduzca otro: ", N);
    leerInt(&n);
  }
  printf("Calculando los elementos de la serie.\n");
  serieFibonacci(f, n);
  printf("Elementos de la serie:\n");
  escribirResultado(f, n);
  printf("\n");
}

void serieFibonacci(int f[], int n)
{
  // Serie de Fibonacci
  // f(0) = 0, f(1) = 1, f(2) = f(0) + f(1), ... , f(i) = f(i-2) + f(i-1)

  int i;

  // Mostrar los 10 primeros números de la serie
  f[0] = 0;
  f[1] = 1;
  for (i = 2; i < n; i++)
  {
    f[i] = f[i - 2] + f[i - 1];
  }
}

double leerInt(int *dato)
{
  int r = 0;
  r = scanf("%d", dato);
  while (r != 1)
  {
    while (getchar() != '\n');
    printf("El dato no es correcto, vuélvalo a introducir: ");
    r = scanf("%d", dato);
  }
  return *dato;
}

void escribirResultado(int f[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", f[i]);
  }
}
