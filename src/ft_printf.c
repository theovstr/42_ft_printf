

#include "../include/libftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int 	format;
	t_flags *flags;
	
	i = -1;
	len = 0;
	flags = create_struct();
	va_start(args, str);
	while (str[++i])
	{
		format = 0;
		if (str[i] == '%')
		{
			ft_bzero(flags, sizeof(t_flags));
			format = ft_setflags(flags, str + i + 1);
			len += ft_checktype(args, str[i + 1 + format], flags);
			i += format + 1;
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
    int num = 42;
    char *str = "Hello, World!";
    double dbl = 3.14159;

    // Test ft_printf with various flags
    ft_printf("Number with zero padding: %10d\n", num);
    ft_printf("Number with left justification: %-10d\n", num);
    ft_printf("String with precision: %.5s\n", str);
    ft_printf("Floating point number with precision: %.2f\n", dbl);
    ft_printf("Hexadecimal representation: %#x\n", num);

    return 0;
}