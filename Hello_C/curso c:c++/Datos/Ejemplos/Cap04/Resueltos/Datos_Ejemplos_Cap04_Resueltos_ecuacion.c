/********** Soluci�n de una ecuaci�n de segundo grado **********/
/* ecuacion.c
*/
#include <stdio.h>  // necesario para scanf y printf
#include <stdlib.h> // necesario para system
#include <math.h>   // necesario para sqrt
void ec2grado(double a, double b, double c, double *px1, double *px2);

int main(void)
{
  double a, b, c, x1, x2;

  system("cls");

  /* Entrada de datos */
  printf("Introducir los coeficientes a b c: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  ec2grado(a, b, c, &x1, &x2);

  /* Escribir resultados */
  printf("x1 = %g\nx2 = %g\n", x1, x2);
}

void ec2grado(double a, double b, double c, double *px1, double *px2)
{
  double d;
  /* Comprobar si las ra�ces son reales */
  d = b * b - 4 * a * c;
  (d < 0) ? printf("Las ra�ces son complejas\n"), exit(0)
    : printf("Las ra�ces reales son:\n");

  /* C�lculo de las soluciones */
  d = sqrt(d);
  *px1 = (-b + d) / (2 * a);
  *px2 = (-b - d) / (2 * a);
}
