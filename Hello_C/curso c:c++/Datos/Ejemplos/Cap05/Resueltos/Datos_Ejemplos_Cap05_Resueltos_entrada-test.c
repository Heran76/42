#include <stdio.h>
#include "entrada-salida.h"

int main(void)
{
  int i;
  double d;

  printf("Introducir un valor int: "); leerInt(&i);
  printf("Correcto: %d\n", i);
  printf("Introducir un valor double: "); leerDouble(&d);
  printf("Correcto: %g\n", d);
}
