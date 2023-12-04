#include "ft_printf.h"

int	ft_justify_left(int length_word, int width, char c, char sign)
{
	int	i;

	i = 0;
	if (sign == '+')
	{
		ft_printchar('+');
		i++;
	}
	while ((width - length_word) > 0)
	{
		if (c == '0')
			ft_printchar('0');
		else if (c == ' ')
			ft_printchar(' ');
		width--;
		i++;
	}
	return (i);
}

int ft_justify_right(int length_word, int width)
{
	int	i;

	i = 0;
	while ((width - length_word) > 0)
	{
		ft_printchar(' ');
		width--;
		i++;
	}
	return (i);
}