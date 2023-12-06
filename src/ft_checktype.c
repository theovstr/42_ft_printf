

#include "ft_printf.h"

/**
 * Creating the structure that control the flag on / off
*/
t_flags	*create_struct(void)
{
	t_flags	*elem;

	elem = malloc(sizeof(t_flags));
	if (!elem)
		return (NULL);
	return (elem);
}

/**
 * Checking the type of value that we are getting,
 * Will serve later to handle different conversion >
*/

int	ft_checktype(va_list args, const char type, t_flags *flags)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int), flags));
	else if (type == 's')
		return (ft_printstr_flag(va_arg(args, char *), flags));
	else if (type == 'p')
		return (ft_printptr(va_arg(args, unsigned long long), flags));
	else if ((type == 'd') || (type == 'i'))
		return (ft_putnbr(va_arg(args, int), flags));
	else if (type == 'x')
		return (ft_printhexa(va_arg(args, unsigned int), 'x', flags));
	else if (type == 'X')
		return (ft_printhexa(va_arg(args, unsigned int), 'X', flags));
	else if (type == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int), flags));
	else if (type == '%')
		return (ft_printchar('%'));
	return (1);
}
