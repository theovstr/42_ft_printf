/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:45:49 by ael-mank          #+#    #+#             */
/*   Updated: 2023/12/01 09:45:53 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_checktype(va_list args, const char type)
{
	if (type == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if ((type == 'd') || (type == 'i'))
		return (ft_putnbr(va_arg(args, int)));
	else if (type == '%')
		return (ft_printchar('%'));
	return (1);
}