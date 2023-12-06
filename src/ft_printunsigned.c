
#include "ft_printf.h"


char	*ft_utoa(unsigned int nbr, int count, t_flags *flags)
{
	char	*array;
	int		i;

	i = count;
	array = create_array(ft_int_len(nbr), flags);
	if (!array)
		return(0);
	while (nbr > 0)
	{
		array[i] = "0123456789"[nbr % 10];
		nbr /= 10;
		i--;
	}
	if (nbr < 0)
		array[0] = '-';
	array[i] = 0;
	i = 0;
	while (i <= count)
	{
		ft_printchar(array[i]);
		i++;
	}
	return (array);
}

int	ft_printunsigned(unsigned int nbr, t_flags *flags)
{
	int	count;

	count = ft_int_len(nbr);
	if (nbr == 0)
	{
		ft_printchar('0');
		return (1);
	}
	free(ft_utoa(nbr, count, flags));
	return (count);
}
