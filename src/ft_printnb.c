

#include "../include/libftprintf.h"

int	ft_putnbr(int n)
{
	char *nbr;

	nbr = ft_itoa(n);
	return(ft_printstr(nbr), free(nbr));
}