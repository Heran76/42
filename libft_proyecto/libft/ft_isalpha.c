/*
 isalpha : esta función verifica si un carácter es una letra mayuscula o minuscula.
 bandose en su valor Asci. mostrando 1 verdadero, 0 falso,
*/
#include <stdio.h>

int ft_isalpha(int c)
{
  if((c >= 'a' && c <='z') || (c >='A' && c <='z'))
   return(1);
  return(0); 
}

int main()
{
    char muestra_char[]={'a','0','Z','v','%'};
    int test_num = sizeof(muestra_char) / sizeof(muestra_char[0]);

    for(int i = 0; i < test_num; i++)
    {
        char c = muestra_char[i];
        int num_test = ft_isalpha(c);

        printf("ft_isalpha(%c) = %d\n", c, num_test);
    }
}