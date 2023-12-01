
#include "../include/libftprintf.h"

int	int_len_u(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_putunsigned(unsigned int nbr)
{
	char	*array;
	int		i;

	i = 0;
	array = create_array(nbr);
	if (array == NULL)
		{};
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

int	ft_printunsigned(unsigned int nbr)
{
	if (nbr == 0)
	{
		ft_printchar('0');
		return (1);	
	}
	ft_putunsigned(nbr);
	return (int_len_u(nbr));
}
