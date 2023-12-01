/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:37:56 by ael-mank          #+#    #+#             */
/*   Updated: 2023/11/30 10:52:30 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

size_t lenhexptr(unsigned long long ptr)
{
	size_t i;

	i = 0;
	while(ptr > 0)
	{
		ptr >>= 4;
		i++;
	}
	return (i);
}

size_t	puthex(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		puthex(ptr / 16);
		puthex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
	return (lenhexptr(ptr));
}

int	ft_printptr(unsigned long long ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + puthex(ptr));
}