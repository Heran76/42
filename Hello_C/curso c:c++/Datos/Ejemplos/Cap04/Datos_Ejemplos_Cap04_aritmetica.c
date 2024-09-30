/* aritmetica.c */
#include "stdio.h"

double sumar(double, double);
double restar(double, double);
int leerDouble(double *);
void fflushstdin(void);

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

int leerDouble(double *pdato)
{
  int r = 0;
  while (r == 0)
  {
    r = scanf("%lf", pdato);
    if (r == 0)
    {
      printf("Dato incorrecto. Introduzca otro: ");
    }
    fflushstdin(); // eliminar el dato incorrecto
  }
  return r;
}

void fflushstdin(void)
{
  if (!feof(stdin) && !ferror(stdin))
    while ((getchar()) != '\n');
}
