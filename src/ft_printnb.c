

#include "ft_printf.h"


void	integer_flag(char sign)
{
	if (sign == ' ')
		ft_printchar(' ');
	else if (sign == '+')
		ft_printchar('+');
}

int	ft_putnbr_before_flag(int n, t_flags *flag)
{
	char	*nbr;
	int ret;

	ret = 0;
	nbr = ft_itoa(n, flag);
	if (((flag->plus == 1 && flag->space == 1) || flag->plus == 1)
		 && n >= 0)
	{
		if (flag->zero == 1)
			integer_flag('-');
		else
		{
			integer_flag('+');
			ret += 1;
		}
	}
	else if ((flag->space == 1 && n >= 0) && flag->width == 0)
		{
			integer_flag(' ');
			ret += 1;
		}
	ft_printstr(nbr);
	free(nbr);
	return(ret);
} 


int	ft_putnbr(int n, t_flags *flag)
{
	int len;
	int ret;

	len = ft_int_len(n) + ft_lenght_of_precisize(flag);
	if ((flag-> minus == 1 || flag->zero == 1) && flag->width > 0) 
	{
		ret = ft_putnbr_before_flag(n, flag);
		if (flag->minus == 1 && flag->minus > 0)
			len += ft_justify_left(len, flag->width, ' ', ' ');
		else
		{
			if (flag->plus == 1)
				len += ft_justify_left(len, flag->width, '0', '+');
			else
				len += ft_justify_left(len, flag->width, '0', ' ');
		}		
	}
	else
	{
		len += ft_justify_right(len, flag->width);
		ret = ft_putnbr_before_flag(n, flag);
	}
	return (len + ret);
}

