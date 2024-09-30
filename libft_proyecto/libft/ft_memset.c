/*
la funcion memset es útil para inicializar bloques de memoria, como estructuras de buffuers
a un valor constante, y es fundamental en programacion de sisitemas y manipulación de memoria
se utiliza para inicializar bloques de memoria
*/

#include "libft.h"
#include <stdio.h>

void *ft_memset(void *str, int c, size_t n)
{
    size_t indx;
    indx = 0;

    while(indx < n)
    {
        *((unsigned char*)str + indx) = c;
        indx++;
    }
    return(str);
}

int main()
{
    char array[10];
    ft_memset(array, 'A', sizeof(array));
    printf("El contendio del array despues de pasar por ft_memset ");
    for(size_t i = 0; i < sizeof(array); i++)
    {
      printf("%c ",array[i]);
    }
    return 0;
}


