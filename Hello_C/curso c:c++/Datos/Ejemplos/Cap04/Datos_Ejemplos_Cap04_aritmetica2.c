/* aritmetica2.c */
#include <stdio.h>
#include "entrada-salida.h"

double sumar(double, double);
double restar(double, double);

int main(void)
{
  double op1 = 0, op2 = 0, resultado = 0;

  // Introducir datos:
  printf("Operando 1: "); leerDouble(&op1);
  printf("Operando 2: "); leerDouble(&op2);
  // Suma
  resultado = sumar(op1, op2);
  printf("Suma = %g\n", resultado);
  // Resta
  resultado = restar(op1, op2);
  printf("Resta = %g\n", resultado);
}

double sumar(double x, double y)
{
  double z;
  z = x + y;
  return z;
}

double restar(double x, double y)
{
  double z;
  z = x - y;
  return z;
}
