

#include "ft_printf.h"

/**
 * File that handle the converstion of %d and %i
 * take an int as input
 * Return a string of char, use to print the number
*/


void	add_zero(char *str, int precisize, int len)
{
	int		i;
	int		precis;

	i = 0;
	precis = precisize - len;
	//printf("precis = %d\n", precis);
	while (precis > 0)
	{
		str[i] = '0';
		precis--;
		i++;
	}
}

char	*malloc_zero(int len, int precisize)
{
	char	*ret;
	int		untouched_len;

	untouched_len = len;
	if (precisize > 0 && len < precisize)
		len += (precisize - len);
	//printf("precicize in malloc = %d\n", precisize); // ok
	//printf("len = %d\n", len); //ok
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	//printf("ad zero precisize = %d, len = %d\n", precisize, untouched_len);
	if (precisize > 0 && untouched_len < precisize)
		add_zero(ret, precisize, untouched_len);
	ret[0] = '0';
	// int i = 0;
	// while (ret[i] != '\0')
	// {
	// 	printf("valeur %i = %c \n", i, ret[i]);  //seems ok OK
	// 	i++;
	// }
	return (ret);
}

char	*ft_itoa(int n, t_flags *flag, int len)
{
	char	*result;
	long	nbr;

	nbr = n;
	result = malloc_zero(len, flag->precisize);
	if (!result)
		return (NULL);
	if (flag->precisize > 0 && len < flag->precisize)
		len += flag->precisize - len;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		result[len - 1] = '0';
	result[len] = '\0';
	while (nbr > 0)
	{
		result[len - 1] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		len--;
	}
	return (result);
}
/**
 * Seems clear, got to verify
*/