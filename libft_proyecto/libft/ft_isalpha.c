/*
 isalpha : esta función verifica si un carácter es una letra mayuscula o minuscula.
 bandose en su valor Asci. mostrando 1 verdadero, 0 falso,
*/
#include <stdio.h>
#include "libft.h"

int ft_isalpha(int c)
{
  if((c >='a' && c <='z') || c >='A' && c <='Z')
   return(1);
  return(0); 
}

int main()
{
  int text_char[]={'A','2','z','%','v'};
  int num_text = sizeof(text_char) / sizeof(text_char[0]);

  for(int i= 0; i < num_text; i++)
  {
    printf("ft_isalpha(%c)=%d\n",text_char[i],ft_isalpha(text_char[i]));
  }
  return(0);
}


