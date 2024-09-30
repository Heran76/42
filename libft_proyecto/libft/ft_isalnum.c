/*
Toma un caracter para comprobar si es alfanumerioco ( o mejor dicho su valor entero equivalente, al codigo AsCII)
como argumento y verifica si ese caracter es una letra o un dígito, si lo es 
devuelve 1 (verdero) si no devuelve 0 (falso)
*/
#include "libft.h"
#include <stdio.h>
int ft_isalnum(int c)
{
    if((c >='a' &&  c <='z') || (c >='A' || c <='Z') ||( c <= '0' && c <= '9'))
      return(1);
    return(0);  
}

int main(){
    char text_char[]={'A','%','z','&','3'};
    int alfnum_text = sizeof(text_char) / sizeof(text_char[0]);

    for(int i=0; i<alfnum_text; i++)
    {
        if(ft_isalnum(text_char[i]))
         printf("ft_isalnum(%c) es alfanúmerioco \n",text_char[i]);
        else
         printf("ft_isalnum(%c) no es alfanumerico \n",text_char[i]);
   
    } 
    return 0; 
}