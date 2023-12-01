

#include "../include/libftprintf.h"

t_flags	*create_struct(void)
{
	t_flags *elem;

	elem = malloc(sizeof(t_flags));
	if (!elem)
		return (NULL);
}

int	ft_checktype(va_list args, const char type, t_flags *flags)
{
	if (type == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if ((type == 'd') || (type == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_printchar('%'));
	return (1);
}