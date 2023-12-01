

#include "../include/libftprintf.h"

t_flags	*create_struct(void)
{
	t_flags *elem;

	elem = malloc(sizeof(t_flags));
	if (!elem)
		return (NULL);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	t_flags *flags;
	
	i = -1;
	len = 0;
	flags = create_struct();
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			ft_bzero(flags, sizeof(t_flags));
			ft_setflags(flags, str + i + 1);
			len += ft_checktype(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
	}
	va_end(args);
	//free (flags)
	return (len);
}

int main(void)
{
	ft_printf("Hello %s\n", "World !!");
	return (0);
}