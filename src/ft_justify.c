#include "ft_printf.h"

int	ft_integer_flag(char sign)
{
	if (sign == ' ')
		return(ft_printchar(' '));
	else if (sign == '+')
		return(ft_printchar('+'));
	return (0);
}

void	print_width_flags(char *str, t_flags *flags, int n, int len)
{
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
	if (n >= 0 && flags->plus == 1)
		ret += 1;
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ret += 1;
	return (ret);
}

int justify_putflags_integer(char *str, t_flags *flags, int n)
{
    int ret;
    int	len;
	int v;
	int	i;

	i = 0;
	len = ft_strlen(str);
	//printf("taille strlen = %d\n", len);
    ret = 0;
	//printf("%s\n","arrive ici");
	v = set_v(n, flags);
    if (flags->minus == 1)
		print_width_flags(str, flags, n, len);
	//printf("width flag = %d", flags->width);
	//printf("ret =%d", ret);
    while (i++ < (flags->width - (len + v))) //ok
	{
		//printf("boucle\n");
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
