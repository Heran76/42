#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
int     ft_isprint(int c);
int     ft_isdigit(int c);
int     ft_isascii(int c);
int     ft_isalpha(int c);
int     ft_isalnum(int c);
int     ft_strlen(const char *str);
void    *ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);


#endif