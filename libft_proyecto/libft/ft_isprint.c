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
    if(c >=32 && c <=126)
     return(1);
    return(0); 
}

int main(){
    
    char test_char[]={65,35,48,40,32};
    int num_test = sizeof(test_char) / sizeof(test_char[0]);
    
    for(int i = 0; i <num_test; i++)
    {
        if(ft_isprint(test_char[i]))
         printf("ft_isprint(%d) = %c es imprible.\n ",test_char[i],test_char[i]);
        else
         printf("ft_isprint(%d) = %c no es imprimible.\n ",test_char[i], test_char[i]);
         
    }
    return 0;
}