/******************* Operaciones aritméticas *******************/
// ejercicio02.c

#include <stdio.h>

int main(void)
{
  double dato1 = 0, dato2 = 0, dato3 = 0, resultado = 0;

  printf("dato1: "); scanf("%lg", &dato1);
  printf("dato2: "); scanf("%lg", &dato2);
  printf("dato3: "); scanf("%lg", &dato3);

  // Suma
  resultado = dato1 + dato2 + dato3;
  printf("%g + %g + %g = %g\n", dato1, dato2, dato3, resultado);

  // Resta
  resultado = dato1 - dato2 - dato3;
  printf("%g - %g - %g = %g\n", dato1, dato2, dato3, resultado);

  // Producto
  resultado = dato1 * dato2 * dato3;
  printf("%g * %g * %g = %g\n", dato1, dato2, dato3, resultado);

  // Cociente
  resultado = dato1 / dato2 / dato3;
  printf("%g / %g / %g = %g\n", dato1, dato2, dato3, resultado);

  // Combinar operaciones aritmeticas
  resultado = dato1 * dato2 + dato3;
  printf("%g * %g + %g = %g\n", dato1, dato2, dato3, resultado);
}
