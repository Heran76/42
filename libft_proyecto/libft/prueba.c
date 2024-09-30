#include <stdio.h>

int ft_isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int ft_isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}

int ft_islower(int c)
{
    return (c >= 'a' && c <= 'z');
}

int main()
{
    char tex_char[] = {'A', 'Z', 'a', 'z', 'V', '5', '!'};
    int num_text = sizeof(tex_char) / sizeof(tex_char[0]);

    for(int i = 0; i < num_text; i++)
    {
        if(ft_isalpha(tex_char[i]))
        {
            if(ft_isupper(tex_char[i]))
                printf("ft_isalpha(%c) es Mayuscula\n", tex_char[i]);
            else
                printf("ft_isalpha(%c) es minuscula\n", tex_char[i]);
        }
        else
        {
            printf("ft_isalpha(%c) no es una letra\n", tex_char[i]);
        }
    }
    return 0;
}