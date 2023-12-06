#include "ft_printf.h"

/**
 * Create an array of type 'char' 
 * It's given an number as unsigned int, and a 'char'
 * will specify if it's hexa or integer
*/

char	*create_array(int len, t_flags *flags)
{
	char	*ret;
	int		untouched_len;
	int		precisize = flags->precision;

	
	untouched_len = len;
	if (precisize > 0 && len < precisize)
		len += (precisize - len);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (precisize > 0 && untouched_len < precisize)
		add_zero(ret, precisize, untouched_len);
	ret[0] = '0';
	return (ret);
}
