#include "../include/ft_printf.h"

/**
 * Create an array of type 'char' 
 * It's given an number as unsigned int, and a 'char'
 * will specify if it's hexa or integer
*/

char	*create_array(unsigned int nb, char c)
{
	char			*array;
	unsigned int	n;
	
	if (c == 'x')
		n = ft_get_hexadecimal_length(nb);
	else
		n = ft_get_integer_length(nb);
	array = malloc((n + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (array);
}