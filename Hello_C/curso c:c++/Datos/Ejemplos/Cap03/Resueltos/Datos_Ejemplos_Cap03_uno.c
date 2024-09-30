/***************************************************************
                      Archivo fuente uno.c
***************************************************************/
#include <stdio.h>

void funcion_1();
void funcion_2();

extern int var; /* declaraci�n de var que hace referencia a la
                   variable var definida a continuaci�n */
int main(void)
{
  var++;
  printf("%d\n", var); /* se escribe 6 */
  funcion_1();
}

int var = 5; /* definici�n de var */

void funcion_1()
{
  var++;
  printf("%d\n", var); /* se escribe 7 */
  funcion_2();
}
