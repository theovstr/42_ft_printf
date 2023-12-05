
#include "ft_printf.h"


char	*ft_puthexa(unsigned int nbr, char c, t_flags *flags)
{
	int		n;
	char	*array;

	n = ft_get_hexadecimal_length(nbr) + (flags->precisize - ft_get_hexadecimal_length(nbr));
	array = create_array(nbr, 'x', flags);
	if (!array)
		return (NULL);
	add_zero(array, flags->precisize, ft_get_hexadecimal_length(nbr));
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
	return(array);
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
	free(ft_puthexa(nbr, c, flags));
	return (len);
}
