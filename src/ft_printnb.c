

#include "ft_printf.h"


int	integer_flag(int n, char c, int len)
{
	char	*nbr;

	nbr = ft_itoa(n);
	if (c == ' ')
		len += ft_printchar(' ');
	else if (c == '+')
		len += ft_printchar('+');
	len += ft_printstr(nbr);
	free(nbr);
	return (len);
}

int	ft_putnbr_before_flag(int n, t_flags *flag)
{
	char	*nbr;
	int		len;

	len = 0;
	nbr = ft_itoa(n);
	if (((flag->plus == 1 && flag->space == 1) || flag->plus == 1)
		 && n >= 0)
	{
		if (flag->zero == 1)
			len += integer_flag(n, '-', len);
		else
			len += integer_flag(n, '+', len);
	}
	else if ((flag->space == 1 && n >= 0) && flag->width == 0)
		len += integer_flag(n, ' ', len);
	else
		len += ft_printstr(nbr);
	free(nbr);
	return (len);
} 


int	ft_putnbr(int n, t_flags *flag)
{
	int len;

	len = int_len(n);
	if (((flag->width > 0 && flag->minus == 1 && flag->zero == 1))
		|| (flag->width > 0 && flag->minus == 1))
	{
		ft_putnbr_before_flag(n, flag);
		ft_justify_left(len, flag->width, ' ', ' ');
	}
	else if (flag->width > 0 && flag->zero == 1)
	{
		if (flag->plus == 1)
			ft_justify_left(len, flag->width, '0', '+');
		else
			ft_justify_left(len, flag->width, '0', ' ');
		ft_putnbr_before_flag(n , flag);
	}
	else if (flag->minus == 0 && flag->zero == 0 && flag->width > 0)
	{
		ft_justify_right(len, flag->width);
		ft_putnbr_before_flag(n, flag);
	}
	else
		ft_putnbr_before_flag(n, flag);
	return (len);
}

