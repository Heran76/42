/*
Toma un caracter ( o mejor dicho su valor entero equivalente, al codigo AsCII)
como argumento y verifica si ese caracter es una letra o un dígito, si lo es 
devuelve 1 (verdero) si no devuelve 0 (falso)
*/

#include <stdio.h>
int ft_isalnum(int c)
{
    if(
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
        return(1);
       return(0); 
}

int main()
{
    char test_char[]={'A','b','3','4','%'};

    for(int i = 0; i < sizeof(test_char); i++)
    {
       if(ft_isalnum(test_char[i]))
        printf("ft_isalnum(%c)es un numero alfanumerico\n",test_char[i]);
       else
        printf("ft_isalnum(%c)no es un numero alfanumerioco, \n",test_char[i]); 
    }
    return 0;
}