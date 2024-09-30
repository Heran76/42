/* Escribir los valores de una matriz.
 * Versión utilizando indexación.
/* punt01.c
 */
#include <stdio.h>

int main(void) 
{ 
  int lista[] = {24, 30, 15, 45, 34}; 
 
  for (int ind = 0; ind < 5; ind++) 
    printf("%d  ", lista[ind]); 
}
