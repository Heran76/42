/*
La funcion strlen es util para determinar cuantos caracteres hay en una cadena,
(excluyendo el carácter nulo) lo que es ensencial en muchas operaciones de 
manipulación de cadenas en c
*/
#include "libft.h"
#include <stdio.h>

int ft_strlen(const char *src)
{
    int indx;
    indx = 0;

    while(src[indx])
     indx++;
   return(indx);  
}

int main()
{
    char input[100];
    printf("introduzca una cadena: ");
    scanf("%99s", input);

    size_t lenght=ft_strlen(input);
    printf("la longitud de la cadena es %zu\n ",lenght);
    return 0;
}