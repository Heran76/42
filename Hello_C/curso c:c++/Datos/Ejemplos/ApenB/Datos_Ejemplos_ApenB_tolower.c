/* tolower
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char car;
  do
  {
    printf("¿Desea continuar? s/n ");
    car = getchar();
    fflush(stdin);
  }
  while (tolower(car) != 'n' && tolower(car) != 's');
}
