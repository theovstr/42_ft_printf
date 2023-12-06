#include "ft_printf.c"

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