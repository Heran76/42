void ft_putchar(char c)
{
	write(1, &c, 1);
}

void print_digit(char first, char second, char third)
{
	ft_putchar(first);
	ft_putchar(second);
	ft_putchar(third);

	if(!(first == '7' && second == '8' && third == '9'))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void ft_print_comb(void)
{
	char firts_digit;
	char second_digit;
	char third_digit;

	firts_digit = '0';
	while(firts_digit <= '7')
	{
	 second_digit = firts_digit +1;
	 while(second_digit <= '8')
	 {
	   third_digit = second_digit +1;
	   while(third_digit <= '9')
	   {
            print_digit(firts_digit, second_digit, third_digit);
	    third_digit++;
	   } 
	   second_digit++;
	
           }
         firts_digit++;
	}
}

int main(void)
{
 ft_print_comb();
 return(0);
}
