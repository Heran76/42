#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char alfb;
	alfb = 'z';
	while(alfb >= 'a')
	{
	 write(1, &alfb, 1);
	 alfb--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
	return(0);
}
