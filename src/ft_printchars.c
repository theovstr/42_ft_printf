

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

int	ft_printstr_flag(char *str, t_flags *flags)
{
	if (!str)
		return (write(1, "(null)", 6));
	if (flags->precision == 1)
	{
		if (flags->precisize > ft_strlen(str))
			flags->precisize = ft_strlen(str);
		return (write(1, str, flags->precisize));
	}
	else
		return (write(1, str, ft_strlen(str)));
}
