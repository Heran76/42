/*
la función ft_isascii verifica si un caracter dado (representado como un entero)
está dentro del rango de los caracteres AscII, que son los códigos de 0 al 127 caracteres imprimibles.
retorna 1 si el caracter es ASCII y 0 en caso Contrario.
*/
#include "libft.h"
#include <stdio.h>

int ft_isascii(int c)
{
    if(c>=0 && c <=127)
     return(1);
    return(0); 
}

int main()
{
    int text_char[]={65,128,35,127,160};
    int text_num = sizeof(text_char) / sizeof(text_char[0]);

    for(int i = 0; i < text_num; i++)
    {
        if(ft_isascii(text_char[i]))
         printf("ft_isalascii(%d) = '%c' es valor ASCII\n",text_char[i],text_char[i]);
        else
        printf("ft_isalascii(%d) = %c no es valor ASCII\n",text_char[i],text_char[i]); 
    }
    return(0);
}