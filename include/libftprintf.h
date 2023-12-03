

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
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
}		t_flags;

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_strlen(char *str);
int		ft_checktype(va_list args, const char type, t_flags *flags);
char	*ft_itoa(int n);
int		int_len(long nbr);
char	*malzero(int len);
int		ft_putnbr(int n, t_flags *flag);
void	ft_bzero(void *ptr, size_t n);
int		get_length(unsigned int nbr);
char	*create_array(unsigned int nb);
void	ft_puthexa(unsigned int nbr, char c);
int		ft_printhexa(unsigned int nbr, char c, t_flags *flags);
t_flags	*create_struct(void);
int	ft_setflags(t_flags *flags, const char *str);
int		ft_setflags(t_flags *flags, const char *str);
void	ft_toupper(char *str);
int		int_len_u(unsigned int nbr);
void	ft_putunsigned(unsigned int nbr);
int		ft_printunsigned(unsigned int nbr);
int		ft_re_setflags(t_flags *flags, const char *str);
int		ft_isdigit(int character);
void	integer_flag_plus(int n);
void	integer_flag_space(int n);

#endif