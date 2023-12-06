
#include "ft_printf.h"

void	add_zero_hexa(int len, int i, char *array)
{
	while (i < len)
	{
		array[i] = '0';
		i++;
	}
}


void	reversing_array(char *array, int len)
{
	int start;
	int end;
	char temp;

	start = 0;
	end = len - 1;
	while (start < len / 2)
	{
		temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
}

char	*ft_puthexa(unsigned int nbr, char c, t_flags *flags)
{
	int		len;
	char	*array;
	int		i;

	i= 0;
	len = ft_get_hexadecimal_length(nbr);
	if (flags->precisize > len)
		len += (flags->precisize - len);
	array = malloc(sizeof(char) * (len + 1));
	array[len] = '\0'; 
	while (nbr > 0)
	{
		array[i] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
		i++;
	}
	if (flags->precisize > 0)
		add_zero_hexa(len, i, array);
	if (c == 'X')
		ft_toupper(array);
	reversing_array(array, len);
	return (array);
}
/**
 * Call the create array function and obtain a complete (with or without precision)
 * an array of a hexedecimal number
*/

int		ft_printhexa(unsigned int nbr, char c, t_flags *flags)
{
	char *array;

	array = ft_puthexa(nbr, c, flags);
	free(array);
	return (0);
}