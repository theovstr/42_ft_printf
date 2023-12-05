#include "ft_printf.h"


int	integer_handler(int n, t_flags *flags)
{
	int 	len;
	char	*str;

	ret = 0;
	//printf("%s", "here");
	len = ft_int_len(n);
	//printf("need this len = %d\n", len);
	str = ft_itoa(n, flags, len);

	ret += justify_putflags_integer(str, flags, n);
	return (ret + len);
}