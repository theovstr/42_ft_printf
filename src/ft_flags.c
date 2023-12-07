/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:39:30 by theveste          #+#    #+#             */
/*   Updated: 2023/12/07 01:39:31 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(const char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '+' || c == '#')
		return (1);
	else
		return (0);
}

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

int	ft_getwidth(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		flags->width = flags->width * 10 + (str[i] - '0');
		i++;
	}
	return (i);
}

int	ft_getprecision(t_flags *flags, const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		flags->precision = 1;
		i++;
		while (ft_isdigit(str[i]))
		{
			flags->precisize = flags->precisize * 10 + (str[i] - '0');
			i++;
		}
	}
	return (i);
}

int	ft_re_setflags(t_flags *flags, const char *str)
{
	int	len;

	ft_bzero(flags, sizeof(t_flags));
	len = ft_setflags(flags, str);
	len += ft_getwidth(flags, &str[len]);
	len += ft_getprecision(flags, &str[len]);
	// printf("width: %d\n", flags->width);
	return (len);
}
