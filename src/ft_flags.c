

#include "../include/ft_printf.h"

/**
 * Simple function that control if we are on a flag or not
 * Will serve for iterating trough the % -- > s string
*/

int	ft_isflag(const char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '+' || c == '#')
		return (1);
	else
		return (0);
}

/**
 * Setting in the structure the on / off value of the flags
*/

int	ft_setflags(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	while (ft_isflag(str[i]))
	{
		if (str[i] == '-')
			flags->minus = 1;
		else if (str[i] == '+')
			flags->plus = 1;
		else if (str[i] == ' ')
			flags->space = 1;
		else if (str[i] == '#')
			flags->hash = 1;
		else if (str[i] == '0')
			flags->zero = 1;
		i++;
	}
	return (i);
}

/**
 * Get the width of the width specifier
 * And store it into the struct
*/

int ft_getwidth(t_flags *flags, const char *str)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		flags->width = flags->width * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

/**
 * Using the functions together to create the structure
 * Completing it with the necessecary value
 * and returning the lenght of the all % --> format
*/

int ft_re_setflags(t_flags *flags, const char *str)
{
	int len;

	ft_bzero(flags, sizeof(t_flags));
	len = ft_setflags(flags, str);
	len += ft_getwidth(flags, &str[len]);
	//printf("width: %d\n", flags->width);
	return(len);
}