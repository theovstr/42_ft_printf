

#include "ft_printf.h"

/**
 * 
*/

int		ft_putchar(char c, t_flags *flags)
{
	int	len;
	int	ret;
	int	i;

	i = 0;
	len = 1;
	ret = len;
	if (flags->precision == 1 && flags->precisize < len)
	{
		len = flags->precisize;
		ret = len;
	}
	if (flags->minus == 1)
		write(1, &c, len);
	while (i++ < flags->width - len)
		ret += write(1, " ", 1);
	if (flags->minus == 0)
		write(1, &c, len);
	return (ret);
}

int		ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (0);
	}
	else
		return (write(1, str, ft_strlen(str)));
}


int	ft_printnullstr(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	if (!*str && flags->width >= 1)
	{
		while (flags->width-- > 0)
			i += write(1, " ", 1);
		return (i);
	}
	else if (!*str)
		return (0);
	if (flags->precision == 1 && flags->precisize < 6)
		return (0);
	while (i++ < flags->width - 6)
		write(1, " ", 1);
	return (write(1, "(null)", 6) + i - 1);
}

int	ft_printstr_flag(char *str, t_flags *flags)
{
	int	len;
	int	ret;
	int	i;

	i = 0;
	if (!str || !*str)
		return (ft_printnullstr(flags, str));
	len = ft_strlen(str);
	ret = len;
	if (flags->precision == 1 && flags->precisize < len)
	{
		len = flags->precisize;
		ret = len;
	}
	if (flags->minus == 1)
		write(1, str, len);
	while (i++ < flags->width - len)
		ret += write(1, " ", 1);
	if (flags->minus == 0)
		write(1, str, len);
	return (ret);
}
