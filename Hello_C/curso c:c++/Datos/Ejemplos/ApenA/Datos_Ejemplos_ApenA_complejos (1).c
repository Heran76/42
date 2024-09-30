#include <stdio.h>
#include <complex.h>

int main(void)
{
  double complex cx = 1.2 + 4.0*I;
  double complex  cy = 1.0 - 3.5*I;
  printf("cx = %g%+gi\n", creal(cx), cimag(cx));
  printf("cy = %g%+gi\n\n", creal(cy), cimag(cy));

  double complex csum = cx + cy;
  printf("cx + cy = %.2f%+.2fi\n", creal(csum), cimag(csum));

  double complex cres = cx - cy;
  printf("cx - cy = %.2f%+.2fi\n", creal(cres), cimag(cres));

  double complex cpro = cx * cy;
  printf("cx * cy = %.2f%+.2fi\n",creal(cpro), cimag(cpro));

  double complex cdiv = cx / cy;
  printf("cx / cy = %.2f%+.2fi\n", creal(cdiv), cimag(cdiv));

  double complex cconj = conj(cx);
  printf("conjugado de cx = %.2f%+.2fi\n", creal(cconj), cimag(cconj));

  return 0;
}
