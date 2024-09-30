/* Escribir los valores de una matriz.
 * Versión con aritmética de punteros.
 * punt03.c
 */
#include <stdio.h>
 
int main(void)
{ 
  int lista[] = {24, 30, 15, 45, 34}; 
  int *plista = lista;
   
  for (int ind = 0; ind < 5; ind++) 
    printf("%d  ", *plista++); 
}
