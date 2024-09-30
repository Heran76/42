/*
la función ft_isascii verifica si un caracter dado (representado como un entero)
está dentro del rango de los caracteres AscII, que son los códigos de 0 al 127 caracteres imprimibles.
retorna 1 si el caracter es ASCII y 0 en caso Contrario.
*/
#include "libft.h"
#include <stdio.h>

int ft_isascii(int c)
{
    if(c >= 0 && c <= 127)
     return(1);
    return(0); 
}

int main()
{
    int c = 65;
    int b = 68;

    if(ft_isascii(c))
     printf("ft_isacii(%c)= %d\n",c,c);
    else
     printf("ft_isascii(%c)= %d\n",c,c);

     if(ft_isascii(b))
      printf("ft_isacii(%c) = %d",b,b);
     else
      printf("ft_isacii(%c) = %d",b,b); 
    return 0;  
}