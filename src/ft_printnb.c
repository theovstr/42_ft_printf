

#include "../include/libftprintf.h"

int	ft_putnbr(int n, t_flags *flag)
{
	char	*nbr;

	nbr = ft_itoa(n);
	ft_printstr(nbr);
	free(nbr);
	return (int_len(n));
}
// corrected and freed