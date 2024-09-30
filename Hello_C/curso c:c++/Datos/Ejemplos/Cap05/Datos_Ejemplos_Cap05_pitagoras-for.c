* Teorema de Pitágoras.
 * pitagoras-for.c
 */
#include <stdio.h>
#include <math.h>

int main(void)
{
  printf("%10s %10s %10s\n", "Z", "X", "Y");
  printf("      ___________________________\n");

  for (int x = 1; x <= 50; x++)
  {
    for (int y = x; y <= 50; y++)
    {
      int z = (int)sqrt(x*x + y*y);
      if (z > 50) break;
      if (z*z == x*x + y*y)
        printf("%10d %10d %10d\n", z, x, y);
    }
  }
}
