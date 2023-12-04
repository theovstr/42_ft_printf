
#include "../include/ft_printf.h"


void	ft_puthexa(unsigned int nbr, char c)
{
	int		n;
	char	*array;

	n = 0;
	array = create_array(nbr, 'x');
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

	len = ft_get_hexadecimal_length(nbr);
	if (nbr == 0)
	{
		ft_printchar('0');
		return (1);
	}
	if (flags->hash == 1)
	{
		if (c == 'x')
			ft_printstr("0x");
		else if (c == 'X')
			ft_printstr("0X");
		len += 2;
	}
	ft_puthexa(nbr, c);
	return (len);
}