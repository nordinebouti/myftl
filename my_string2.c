#include "ftl.h"

int    					my_putnbr(int nb)
{
	int    				div;
	int    				neg;

	div = 1;
	neg = 0;
	if (nb == -2147483648)
	{
		my_putstr("-2147483648");
		neg = 1;
	}
	if (neg != 1)
	{  
		if (nb < 0)
		{
			my_putchar('-');
			nb = nb * -1;
		}
		while ((nb / div) >= 10)
			div = div * 10;
		while (div > 0)
		{
			my_putchar((nb / div) % 10 + 48);
			div = div / 10;
		}
	}
	return (nb);
}

int			          	my_strlen(const char *str)
{
	int					i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}