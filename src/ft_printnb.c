

#include "../include/ft_printf.h"


void	integer_flag(int n, char c)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (c == ' ')
		ft_printchar(' ');
	else if (c == '+')
		ft_printchar('+');
	ft_printstr(nbr);
	free(nbr);
}

int	ft_putnbr(int n, t_flags *flag)
{
	char	*nbr;
	int		len;

	len = ft_int_len(n);
	nbr = ft_itoa(n);
	if (((flag->plus == 1 && flag->space == 1) || flag->plus == 1) && n >= 0)
	{
		integer_flag(n, '+');
		len += 1;
	}
	else if (flag->space == 1 && n >= 0)
	{
		integer_flag(n, ' ');
		len += 1;
	}
	else
		ft_printstr(nbr);
	free(nbr);
	return (len);
}
