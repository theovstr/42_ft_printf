/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:58:36 by theveste          #+#    #+#             */
/*   Updated: 2023/12/07 01:58:41 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	iterate(const char *str, t_flags *flags, va_list args)
{
	int	i;
	int	len;
	int	format;

	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			format = ft_re_setflags(flags, &str[i + 1]);
			len += ft_checktype(args, str[i + 1 + format], flags);
			i += format + 1;
		}
		else
			len += write(1, &str[i], 1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	t_flags	*flags;

	flags = create_struct();
	va_start(args, str);
	len = iterate(str, flags, args);
	va_end(args);
	free(flags);
	return (len);
}
