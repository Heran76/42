/*
la funcion memset es útil para inicializar bloques de memoria, como estructuras de buffuers
a un valor constante, y es fundamental en programacion de sisitemas y manipulación de memoria
se utiliza para inicializar bloques de memoria
*/

#include "libft.h"
#include <stdio.h>
void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *p;
    p = s;

    while(n--)
    {
       *p++ = (unsigned char)c;
    }
    return(s);
}

int main()
{
    char array[10];
    ft_memset(array, 'A', sizeof(array));

    printf("El contenido del array despues de pasar por ft_meset : ");
    for(size_t i = 0; i <sizeof(array); i++)
    {
        printf("%c ",array[i]);
    }
    return 0;

    
}


