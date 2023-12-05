

#include "../include/ft_printf.h"

size_t	lenhexptr(unsigned long long ptr)
{
	size_t	i;

	i = 0;
	while (ptr > 0)
	{
		ptr >>= 4;
		i++;
	}
	return (i);
}

size_t	puthex(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		puthex(ptr / 16);
		puthex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
	return (lenhexptr(ptr));
}

int	ft_printptr_r(unsigned long long ptr, t_flags *flag)
{
	if ((flag->plus == 1 && flag->space == 1) || flag->plus == 1)
	{
		ft_printchar('+');
		return (write(1, "0x", 2) + puthex(ptr));
	}
	else if (flag->space == 1)
	{
		ft_printchar(' ');
		return (write(1, "0x", 2) + puthex(ptr));
	}
	else
		return (write(1, "0x", 2) + puthex(ptr));
}

int	ft_printptr(unsigned long long ptr, t_flags *flag)
{
	size_t i = 2;
	int ret = 0;

	if (!ptr)
	{
		if (flag->width > 5)
		{
			while (i++ < (size_t)flag->width - 3)
				ret += write(1, " ", 1);
		}
		return (ret + write(1, "(nil)", 5));
	}
	if (flag->minus == 1)
		ret = ft_printptr_r(ptr, flag);
	if (flag->width > (int)lenhexptr(ptr))
	{
		while (i++ < flag->width - lenhexptr(ptr))
			ret += write(1, " ", 1);
	}
	if (flag->minus == 0)
		ret += ft_printptr_r(ptr, flag);
	return (ret);
}