/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mank <ael-mank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:02:22 by ael-mank          #+#    #+#             */
/*   Updated: 2023/12/01 10:26:25 by ael-mank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int	zero;
	int	minus;
	int	width;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}				t_flags;

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_strlen(char *str);
int		ft_checktype(va_list args, const char type);
char	*ft_itoa(int n);
int		int_len(long nbr);
char	*malzero(int len);
size_t	ft_putnbr(int n);
void	ft_bzero(void *ptr, size_t n);


#endif