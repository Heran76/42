#include <stdio.h>
 
int main(void)
{
  int i = 1, j = 1;
   
  while ( i <= 3 )   // mientras i sea menor o igual que 3
  {
    printf("Para i = %d: ", i);
    while ( j <= 4 ) // mientras j sea menor o igual que 4
    {
      printf("j = %d, ", j);
      j++;           // aumentar j en una unidad
    }
    printf("\n");    // avanzar a una nueva línea
    i++;             // aumentar i en una unidad
    j = 1;           // iniciar j de nuevo a 1
  }
}
