
#include "ft_printf.h"


void	ft_putunsigned(unsigned int nbr, t_flags *flags)
{
	char	*array;
	int		i;

	i = 0;
	array = create_array(nbr, 'd', flags);
	if (array == NULL)
	{
	};
	while (nbr > 0)
	{
		array[i] = "0123456789"[nbr % 10];
		nbr /= 10;
		i++;
	}
	array[i] = 0;
	i -= 1;
	while (i >= 0)
	{
		ft_printchar(array[i]);
		i--;
	}
	free(array); // freed
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
	ft_putunsigned(nbr, flags);
	return (count);
}
