
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int precisize;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

int		ft_printf(const char *str, ...);
int		ft_putchar(char c, t_flags *flags);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printstr_flag(char *str, t_flags *flags);
int		ft_printptr(unsigned long long ptr, t_flags *flag);
int		ft_strlen(char *str);
int		ft_checktype(va_list args, const char type, t_flags *flags);
char	*ft_itoa(int n, t_flags *flag);
char	*malloc_zero(int len, int precisize);
int		ft_putnbr_before_flag(int n, t_flags *flag);
int		ft_putnbr(int n, t_flags *flag);
void	ft_bzero(void *ptr, size_t n);
int		ft_get_hexadecimal_length(unsigned int nbr);
char	*create_array(unsigned int nb, char c);
void	ft_puthexa(unsigned int nbr, char c);
int		ft_printhexa(unsigned int nbr, char c, t_flags *flags);
t_flags	*create_struct(void);
int		ft_setflags(t_flags *flags, const char *str);
int		ft_setflags(t_flags *flags, const char *str);
void	ft_toupper(char *str);
int		ft_get_integer_length(int nbr);
char	*ft_putunsigned_in_array(unsigned int nbr);
int		ft_printunsigned(unsigned int nbr);
int		ft_re_setflags(t_flags *flags, const char *str);
int		ft_isdigit(int character);
int		ft_justify_right(int length_word, int width);
int		ft_justify_left(int length_word, int width, char c, char sign);
int		ft_printstr_precision(char *str, int len, t_flags *flags);
void	integer_flag(char sign);
int		ft_int_len(long nbr);
void	add_zero(char *str, int precisize, int len);
char	*ft_itoa(int n, t_flags *flag);
int		integer_handler(int n, t_flags *flags);

#endif