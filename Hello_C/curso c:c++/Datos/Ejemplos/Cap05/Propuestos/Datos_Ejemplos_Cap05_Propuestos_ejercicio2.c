/* Suma de múltiplos de 5
 *
 * Cap05 - ejercicio2.c
 */

#include <stdio.h>

int main(void)
{
  long int a, b, c, sum = 0;
  printf("Introduzca los límites a y b.\n");

    // Obsérvese cómo se ha empleado el operador coma en la siguiente expresión
  while(((printf("a = "), scanf("%ld", &a)) != 1) || a < 0);
    // Si a es negativo, pide de nuevo una entrada

  while(((printf("b = "), scanf("%ld", &b)) != 1) || b < 0);
    // Si b es negativo, pide de nuevo una entrada

  if(a > b)       // Si a es mayor que b, intercambia los valores
  {
    long int temp = a;
    a = b;
    b = temp;
  }


  while (a % 5) a++; // primer múltiplo de 5
  for (c = a; c <= b; c+=5)
  {
    printf("%ld\t", c);
    sum += c;         // sum almacena los múltiplos de 5
  }
  printf("\nLa suma de los múltiplos de 5 es: %ld", sum);
}
