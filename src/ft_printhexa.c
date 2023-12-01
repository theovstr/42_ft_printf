
#include "../include/libftprintf.h"

int	get_length(unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

char	*create_array(unsigned int nb)
{
	char			*array;
	unsigned int	n;

	n = get_length(nb);
	array = malloc(sizeof(n) * 1);
	if (!array)
		return (NULL);
	return (array);
}

void	ft_puthexa(unsigned int nbr)
{
	int			n;
	char		*array;

	n = 0;
	array = create_array(nbr);
	while (nbr > 0)
	{
		array[n] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
		n++;
	}
	while (n >= 0)
	{
		ft_printchar(array[n]);
		n--;
	}
	free (array);
}


int ft_printhexa(unsigned int nbr)
{
	ft_puthexa(nbr);
	return (get_length(nbr));
}