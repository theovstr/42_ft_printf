/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:01:12 by ael-mank          #+#    #+#             */
/*   Updated: 2023/11/30 08:37:30 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}
