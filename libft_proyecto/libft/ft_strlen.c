/*
La funcion strlen es util para determinar cuantos caracteres hay en una cadena,
(excluyendo el carácter nulo) lo que es ensencial en muchas operaciones de 
manipulación de cadenas en c
*/
#include "libft.h"
#include <stdio.h>

int ft_strlen(const char *str)
{
    int indx = 0;
    while(str[indx])
    indx++;
    return(indx);
}

int main()
{
    char input[100];
    printf("Escribe una cadena de caracteres : ");
    scanf("%99s",input);

    size_t longitud=ft_strlen(input);
    printf("La longitud de la cadena '%s' es : %zu\n", input, longitud);
    return 0;
}