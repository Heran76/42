/* complejos.c
 */
#include <complex.h>
#include <stdio.h>

int main(void)
{
  double complex c1 = 1.5 + 2*I, c2 = -1.5 + 0.5I;
  double complex c3;
  c3 = c1 + c2;
  printf("c3 = %.2f%+.2fi\n", creal(c3), cimag(c3));
  c3 = 1/c2;
  printf("1/c2 = %.2f%+.2fi\n", creal(c3), cimag(c3));
  c3 = csqrt(c1);
  printf("Raíz cuadrada de c1 = %.2f%+.2fi\n",
          creal(c3), cimag(c3));
}
