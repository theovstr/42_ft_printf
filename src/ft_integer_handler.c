#include "ft_printf.h"

void print_flag_nb(const char str, int len, t_flags flags);

int justify_putflags(const char *str, int len, t_flags *flags)
{
	int ret;
	int i;
	
	ret = 0;
	i = 0;
	if (flags->minus == 1)
		write(1, str, len);
	while (i++ < flags->width - len)
		ret += write(1, " ", 1);
	if (flags->minus == 0)
		write(1, str, len);
	return(ret);
}

int	integer_handler(int n, t_flags *flags)
{
	int 	len;
	char	*str;
	int		ret;
	int		i;

	i = 0;
	str = ft_itoa(n, flags);
	len = ft_int_len(n);
	// while (str[i] != '\0')
	// {
	// 	printf("%c\n", str[i]);
	// 	i++;
	// }
	len += flags->precisize - len;
	ret = justify_putflags(str, len, flags);
	return (ret);
}