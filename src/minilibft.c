/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:59:19 by theveste          #+#    #+#             */
/*   Updated: 2023/12/07 01:59:22 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[++i])
		;
	return (i);
}

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*ptrchar;

	i = 0;
	ptrchar = (char *)ptr;
	while (i < n)
	{
		ptrchar[i] = 0;
		i++;
	}
}

void	ft_toupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (1);
	return (0);
}
