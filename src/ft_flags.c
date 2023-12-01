// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_flags.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/12/01 09:45:57 by ael-mank          #+#    #+#             */
// /*   Updated: 2023/12/01 09:58:31 by ael-mank         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "../include/libftprintf.h"

int	ft_isflag(const char c)
{
	if (c == '-' || c == '+' || c == '0' || c == ' ' || c == '+')
		return (1);
	else
		return (0);
}
int	ft_setflags(flags,const char *str)
{
	int i

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
}