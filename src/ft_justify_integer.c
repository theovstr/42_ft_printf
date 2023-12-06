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

void	print_width_flags(char *str, t_flags *flags, int n, int len)
{
	if (n < 0)
		ft_integer_flag('-');
	if (n >= 0 && flags->plus == 1)
		ft_integer_flag('+');
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
	write(1, str, len);
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

int add_zero_flag(t_flags *flags, char *str)
{
	int len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (flags->plus == 1)
	{
		ft_integer_flag('+');
		i = 1;
	}
	else if (flags->plus == 0 && flags->space == 1)
	{
		ft_integer_flag(' ');
		i = 1;
	}
	if (flags->precision == 1 && flags->precisize == 0)
	{
		write(1, 0, 0);
		return (0);
	}
	write(1, str, len);
	return (i);
}

int	justify_putflags_zero2(char *str, t_flags *flags) 
{
	int ret;
    int	len;
	int	i;
	int v;

	v = 0;
	i = 0;
	if (flags->plus == 1 || flags->space == 1)
		v = 1;
	if (flags->precision == 1 && flags->precisize == 0)
		i = -1;
	len = ft_strlen(str);
    ret = 0;
	if (flags->minus == 1)
		add_zero_flag(flags, str);
    while (i++ < (flags->width - (len + v))) //ok
	{
		if (flags->zero == 1 && flags->precision == 0 && flags->minus == 0)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1); 

	}
	if (flags->minus == 0)
		add_zero_flag(flags, str);
	if (flags->precision == 1 && flags->precisize == 0)
		v--;
    return(ret + len + v);
}


int	justify_putflags_zero(char *str, t_flags *flags, int n) // laaaa
{
	int ret;
    int	len;
	int v;
	int	i;

	i = 0;
	len = ft_strlen(str);
    ret = 0;
	v = set_v(n, flags);
	if (n < 0)
		ft_integer_flag('-');
	if (n >= 0 && flags->plus == 1)
		ft_integer_flag('+');
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
    while (i++ < (flags->width - (len + v))) //ok
		ret += write(1, "0", 1);
	if (str[0] == 0)
		len++;
	write(1, str, len);
    return(ret + len + v);
}


int justify_putflags_integer(char *str, t_flags *flags, int n)
{
    int ret;
    int	len;
	int v;
	int	i;

	i = 0;
	len = ft_strlen(str);
    ret = 0;
	v = set_v(n, flags);
    if (flags->minus == 1)
		print_width_flags(str, flags, n, len);
    while (i++ < (flags->width - (len + v))) //ok
	{
		if (flags->zero == 1 && flags->precision == 1)
			ret += write(1, " ", 1);
		else if (flags->zero == 1 && flags->precision == 0)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
    if (flags->minus == 0)
		print_width_flags(str, flags, n, len);
    return(ret + len + v);
}