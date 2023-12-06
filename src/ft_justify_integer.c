#include "ft_printf.h"

#include "ft_printf.h"

int	ft_integer_flag(char sign)
{
	if (sign == ' ')
		return(ft_printchar(' '));
	else if (sign == '+')
		return(ft_printchar('+'));
	else if (sign == '-')
		return(ft_printchar('-'));
	return (0);
}

void	print_width_flags(t_flags *flags, int n)
{
	if (n < 0)
		ft_integer_flag('-');
	if (n >= 0 && flags->plus == 1)
		ft_integer_flag('+');
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
}

int set_v(int n, t_flags *flags)
{
	int ret;

	ret = 0;
	if (n < 0)
		ret += 1;
	if (n >= 0 && flags->plus == 1)
		ret += 1;
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ret += 1;
	return (ret);
}
 /**
  * Cas possible ;
  * minus = 1 et zero = 1 / precision peut importe - print left justified blank -- sign devant le nombre
  * minus = 0 et zero = 1 // precision = 1 - print left justified blanck -- sign devant le nombre
  * zero = 1 // precision = 0 - print 0 before number --sign devant le zero
 */


int	justify_putflags_zero(char *str, t_flags *flags, int n)
{
	int ret;
    int	len;
	int v;
	int	i;

	i = 0;
	len = ft_strlen(str);
    ret = 0;
	v = set_v(n, flags);
	print_width_flags(flags, n);
    while (i++ < (flags->width - (len + v))) //ok
	{
		if (n == 0)
			ret += write(1, " ", 1);
		else
			ret += write(1, "0", 1);
	}
	if (str[0] == 0)
		len++;
	write(1, str, len);
    return(ret + len + v);
}
int	width_added(t_flags *flags, int len, int v)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
    while (i++ < (flags->width - (len + v))) //ok
	{
		if (flags->zero == 1 && flags->precision == 1)
			ret += write(1, " ", 1);
		else if (flags->zero == 1 && flags->precision == 0)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	return (ret);
}

int justify_putflags_integer(char *str, t_flags *flags, int n)
{
    int ret;
    int	len;
	int v;

	len = ft_strlen(str);
    ret = 0;
	v = set_v(n, flags);
    if (flags->minus == 1)
	{
		print_width_flags(flags, n);
		write(1, str, len);
	}
	ret = width_added(flags, len, v);
    if (flags->minus == 0)
	{
		print_width_flags(flags, n);
		write(1, str, len);
	}
    return(ret + len + v);
}
