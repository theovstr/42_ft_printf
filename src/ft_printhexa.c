
#include "../include/libftprintf.h"

int	get_length(unsigned int nbr)
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

char	*create_hex_array(unsigned int nb)
{
	char			*array;
	unsigned int	n;

	n = get_length(nb);
	array = malloc((n + 1) * sizeof(char));
	if (!array)
		return (NULL);
	return (array);
}

char	*create_array(unsigned int nb)
{
	char			*array;
	unsigned int	n;

	n = int_len(nb);
	array = malloc((n + 1) * sizeof(char));
	if (!array)
		return (NULL);
	return (array);
}

void	ft_puthexa(unsigned int nbr, char c)
{
	int		n;
	char	*array;

	n = 0;
	array = create_hex_array(nbr);
	while (nbr > 0)
	{
		array[n] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
		n++;
	}
	array[n] = 0;
	n -= 1;
	if (c == 'X')
		ft_toupper(array);
	while (n >= 0)
	{
		ft_printchar(array[n]);
		n--;
	}
	free(array); // freed
}

int	ft_printhexa(unsigned int nbr, char c, t_flags *flags)
{
	int len;

	len = get_length(nbr);
	if (flags->hash == 1)
	{
		if (c == 'x')
			ft_printstr("0x");
		else if (c == 'X')
			ft_printstr("0x");
		len += 2;
	}
	if (nbr == 0)
	{
		ft_printchar('0');
		return (1);
	}
	ft_puthexa(nbr, c);
	return (len);
}