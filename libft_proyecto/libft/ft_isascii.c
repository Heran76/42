/*
la función ft_isascii verifica si un caracter dado (representado como un entero)
está dentro del rango de los caracteres AscII, que son los códigos de 0 al 127.
retorna1 si el caracter es ASCII y 0 en caso Contrario.
*/
#include <stdio.h>
int ft_isascii(int c)
{
    if(c >= 0 && c <= 127)
     return(1);
    return(0); 
}

int main()
{   
     int c;
     c = 128;

     if(ft_isascii(c))
      printf("El valor %c es AscII \n", c);
     else 
      printf("El valor %c no es ASCII \n",c);
    return 0;
}