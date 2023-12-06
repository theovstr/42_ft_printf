#include "ft_printf.h"


int	justify_putflags_precisize(t_flags *flags, int n)
{
	int ret;
	int	i;

	i = 0;
    ret = 0;
	if (n < 0)
		ft_integer_flag('-');
	if (n >= 0 && flags->plus == 1)
		ft_integer_flag('+');
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
    while (i++ < flags->width) //ok
		ret += write(1, " ", 1);
	write(1, 0, 0);
    return(ret);
}

int	integer_handler(int n, t_flags *flags)
{
	int 	len;
	int		ret;
	char	*str;

	ret = 0;
	len = ft_int_len(n);
	//printf("len = %d\n", len);
	str = ft_itoa(n, flags, len);
	//printf("''%s''\n", str);
	if (flags->precision == 1 && n != 0)
		ret += justify_putflags_integer(str, flags, n);
	else if (flags->precision == 0 && flags->zero == 1)
		ret += justify_putflags_zero(str, flags, n);
	else if (flags->precision == 0)
		ret +=  justify_putflags_integer(str, flags, n);
	else if (n == 0 && flags->precision == 1 && flags->precisize == 0)
		ret += justify_putflags_precisize(flags, n);
	else if (n == 0 && flags->precisize > 0)
		ret += justify_putflags_zero(str, flags, n);
	free(str);
	return (ret);
}
