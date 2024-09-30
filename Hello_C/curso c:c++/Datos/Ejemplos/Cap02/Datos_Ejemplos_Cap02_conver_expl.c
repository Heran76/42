/********** Conversiones explícitas **********/
// conver_expl.c
#include <stdio.h>

int main(void)
{
  int i = 1234567890;
  float f = 0;
  double d = 0;

  f = (float)i;      // float <-- int (pérdida de precisión)
  printf("%f\n", f); // 1234567936.000000

  d = i;             // double <-- int (correcto)
  printf("%f\n", d); // 1234567890.000000
}
