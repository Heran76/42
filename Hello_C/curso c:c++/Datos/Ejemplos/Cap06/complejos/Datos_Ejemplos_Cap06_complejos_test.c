/* Operaciones con complejos: test.c */
#include <stdio.h>
#include "complejo.h"

int main(void)
{
  tcomplejo c1, c2, c3;

  c1 = leerComplejo();
  c2 = leerComplejo();
  c3 = sumarComplejos(c1, c2);
  printf("La suma es: ");
  mostrarComplejo(c3);
  c3 = multiplicarComplejos(c1, c2);
  printf("\nEl producto es: ");
  mostrarComplejo(c3);
  printf("\n");
}
