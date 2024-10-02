/*
 se usa para validar si un caracter es un número decimal. Puede ser útil cuando
 se necista procesar o filtar entradas, como al leer cadenas de texto y asegurarse
 de que contiene solo números.
*/
#include "libft.h"
#include <stdio.h>

int ft_isdigit(int c)
{
    if(c >='0' && c <='9')
     return(1);
    return(0); 
}

int main()
{
    char text_digit[]={'0','t','9','5','%'};
    int tex_num = sizeof(text_digit) / sizeof(text_digit[0]);

    for(int i = 0; i<tex_num; i++)
    {
        if(ft_isdigit(text_digit[i]))
         printf("ft_isdigit(%c) es un digito\n",text_digit[i]);
        else
        printf("ft_isdigit(%c) no es un digito\n",text_digit[i]); 
    }
    return(0);
}