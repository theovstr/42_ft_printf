

#include "ft_printf.h"

/**
 * File that handle the converstion of %d and %i
 * take an int as input
 * Return a string of char, use to print the number
*/


char	*malloc_zero(int len, int precisize)
{
	char	*ret;
	// condition a ajouter
	ret = malloc(sizeof(char) * (len + 1) + (precisize - len));
	if (!ret)
		return (NULL);
	ret[0] = '0';
	return (ret);
}

void	add_zero(char *str, int precisize, int len)
{
	int		i;
	int		precis;

	i = 0;
	precis = precisize - len;
	while (precis >= 0)
	{
		str[i] = '0';
		precis--;
		i++;
	}
}

char	*ft_itoa(int n, t_flags *flag)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	i = 0;
	nbr = n;
	len = ft_int_len(n);
	result = malloc_zero(len, flag->precisize);
	if (!result)
		return (NULL);
	add_zero(result, flag->precisize, len);
	if (nbr < 0)
		nbr = -nbr;
	result[len + (flag->precisize - len)] = 0;
	i = len + (flag->precisize - len) - 1;
	while (nbr > 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
