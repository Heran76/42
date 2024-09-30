/*
verifica si un caracter representado por su valor ASCII es imprimible. Devuelve 1 si el caracter
es imprimible, esta en el rango de 32 a 126 en la tabla ASCII y 0 si no lo es. Esta funcion es util
para validar caracteres en programas que necesiten diferenciar entre caracterers imprimibles y no 
inprimibles, como espacios o caracteres de control
*/

#include "libft.h"
#include <stdio.h>
int ft_isprint(int c)
{
    if(c >=32 && c <= 126)
     return(1);
    return(0); 
}

int main()
{
    int c = 65;
    int b = 140;
    int d = ' ';

    if(ft_isprint(c))
     printf("El caracter %c es imprimible \n",c);
    else
     printf("El caracter %c no es imprimible \n",c);

     if(ft_isprint(b))
     printf("El caracter %c es imprimible \n",b);
     else
     printf("El caracter %c no es imprible \n",b);

     if(ft_isprint(d))
      printf("El caracter %c es imprimible \n",d);
     else
      printf("El caracter %c no es imprimible \n",d);
  return 0;      
}