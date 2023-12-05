#include "ft_printf.h"

int	ft_putnbr(int n, t_flags *flag)
{
	int ret;

	ret = integer_handler(n , flag);
	return (ret);
}

