/*
La función ft_bzero es útil cuando queremos "limpiar" o "reiniciar" una parte de la memoria en nuestro programa, como borrar una parte de un dibujo para empezar de nuevo en esa sección.
*/

#include "libft.h"
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
    unsigned char *p;
    p = s;

    while(n)
    {
        *p++=0;
        --n;
    }
}

int main()
{
    char str[50]="Hola mundo";
    printf("Antes de ft_bzero %s\n", str);

    ft_bzero(str, 5);
    printf("despues de ft_bzero:");

    for(int i = 0; i < 15; i++)
    {
        if(str[i] == '\0')
         printf("\\0");
        else
        printf("%c",str[i]); 
    }
    printf("\n");
    return 0;
}