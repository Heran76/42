#include <stdio.h>
int main(void)
{
  double dato1 = 0, dato2 = 0, dato3 = 0, resultado;
  printf("introduce dato1 = "); scanf("%lg", &dato1);
  printf("introduce dato2 = "); scanf("%lg", &dato2);
  printf("introduce dato3 = "); scanf("%lg", &dato3);

 //SUMA
 resultado = dato1 + dato2 + dato3 ;
 printf("Suma: \n");
 printf("%g + %g + %g = %g \n", dato1, dato2, dato3, resultado);

 //RESTA
 resultado = dato1 - dato2 - dato3;
 printf("Resta: \n");
 printf("%g - %g - %g = %g \n", dato1, dato2, dato3, resultado); 

 //PRODUCTO
 resultado = dato1 * dato2 * dato3;
 printf("Producto: \n"),
 printf("%g * %g * %g = %g \n", dato1, dato2, dato3, resultado);
 
 //COCIENTE
 resultado = dato1 / dato2 / dato3;
 printf("Cosciente \n");
 printf("%g / %g / %g = %g \n", dato1, dato2, dato3, resultado);
}
