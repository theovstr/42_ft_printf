#include "../include/ft_printf.h"

/**
 * File that handle the length counter of 
 * int
 * hexa
 * unsigned
*/


int	ft_get_integer_length(int nbr)
{
	int	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_get_hexadecimal_length(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}