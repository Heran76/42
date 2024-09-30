/* por_referencia.c
 */
#include <stdio.h>

void sumar(double, double, double *);
void restar(double, double, double *);

int main(void)
{
  double op1 = 0, op2 = 0, resultado = 0;

  // Introducir datos:
  printf("Operando 1: ");
  scanf("%lf", &op1);
  printf("Operando 2: ");
  scanf("%lf", &op2);

  // Suma
  sumar(op1, op2, &resultado);
  printf("Suma = %g\n", resultado);

  // Resta
  restar(op1, op2, &resultado);
  printf("Resta = %g\n", resultado);
}

void sumar(double x, double y, double *p)
{
  double z;
  z = x + y;
  *p = z;
}

void restar(double x, double y, double *p)
{
  double z;
  z = x - y;
  *p = z;
}
