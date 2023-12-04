

#include "ft_printf.h"

/**
 * File that handle the converstion of %d and %i
 * take an int as input
 * Return a string of char, use to print the number
*/

int	ft_lenght_of_precisize(t_flags *flag)
{
	int	i;

	i = 0;
	while (flag->precisize > 0)
	{
		flag->precisize /= 10;
		i++;
	}
	return (i);
}

char	*malloc_zero(int len, t_flags *flag)
{
	char	*res;
	int	precisize;

	precisize = ft_lenght_of_precisize(flag);
	res = malloc(sizeof(char) * (len + 1) + precisize);
	if (!res)
		return (NULL);
	res[0] = '0';
	return (res);
}

char	*add_zero(int n, t_flags *flag)
{
	int		precisize;
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_int_len(n);
	str = malloc_zero(len, flag);
	precisize = ft_lenght_of_precisize(flag);
	while (precisize > 0)
	{
		str[i] = '0';
		precisize /= 10;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n, t_flags *flag)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = ft_int_len(nbr);
	result = add_zero(n, flag);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = 0;
	return (result);
}
