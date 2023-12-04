#include "ft_printf.h"

int	integer_handler(int n, t_flags *flags)
{
	int 	len;
	int 	ret;
	char	*str;
	int		i;

	i = 0;
	ret = 0;
	str = ft_itoa(n, flags);
	len = ft_int_len(n);
	// while (str[i] != '\0')
	// {
	// 	printf("%c\n", str[i]);
	// 	i++;
	// }
	len += flags->precisize - len;
	if (flags->minus == 1)
		write(1, str, len);
	while (i++ < flags->width - len)
		ret += write(1, " ", 1);
	if (flags->minus == 0)
		write(1, str, len);
	return (ret);
}