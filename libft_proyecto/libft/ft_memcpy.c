#include "libft.h"
#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t indx;

    if(dest == src || !n)
     return(dest);

    indx = 0;
    while(indx < n)
    {
        *((char *)dest + indx)= *((char *)src + indx);
        indx++;
    }
    return(dest); 
}

int main()
{
    char src[] = "Hola";
    char dest[5];
    
    ft_memcpy(dest, src, 5);
    
    printf("Cadena original: %s\n", src);
    printf("Cadena copiada: %s\n", dest);
    
    return 0;
}