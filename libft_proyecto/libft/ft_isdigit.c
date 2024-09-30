/*
 se usa para validar si un caracter es un número decimal. Puede ser útil cuando
 se necista procesar o filtar entradas, como al leer cadenas de texto y asegurarse
 de que contiene solo números.
*/

#include <stdio.h>
int ft_isdigit(int c)
{
    if(c >= '0' && c <='9')
     return(1);
    return(0); 
}

int main(){

     char test1 = '9';
     char test2 = 'z';
     char test3 = '3';

     if(ft_isdigit(test1))
      printf("ft_isdigit(%c) = es un digito. \n", test1);
     else
      printf("ft_isdigit(%c) = no es un digito\n", test1);

      if(ft_isdigit(test2))
       printf("ft_isdigit(%c) = es un digito. \n", test2);
      else
       printf("ft_isdigit(%c) = no es un digito. \n", test2);

       if(ft_isdigit(test3))
        printf("ft_isdigit(%c) = Es un digito. \n", test3);
       else
        printf("ft_isdigit(%c) = No es un digito. \n",test3); 
     
    return(0);
}