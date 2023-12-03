

#include "../include/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		format;
	t_flags	*flags;

	i = -1;
	len = 0;
	flags = create_struct();
	va_start(args, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			format = ft_re_setflags(flags, &str[i + 1]);
			len += ft_checktype(args, str[i + 1 + format], flags);
			i += format + 1;
		}
		else
			len += ft_printchar(str[i]);
	}
	va_end(args);
	free(flags);
	return (len);
}

int main(void)
{
	ft_printf("%#4x\n", 42);
}