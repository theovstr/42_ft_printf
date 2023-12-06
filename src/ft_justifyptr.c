#include "ft_printf.h"

int	ft_ptr_flag(char sign)
{
	if (sign == ' ')
		return(ft_printchar(' '));
	else if (sign == '+')
		return(ft_printchar('+'));
	return (0);
}

void	print_width_flags_ptr(char *str, t_flags *flags, int len)
{
	if (flags->plus == 1)
		ft_ptr_flag('+');
	else if (flags->plus == 0 && flags->space == 1)
		ft_ptr_flag(' ');
	write(1, "0x", 2);
	write(1, str, len);
}

int set_v_ptr(t_flags *flags)
{
	int ret;

	ret = 0;
	if (flags->plus == 1)
		ret += 1;
	else if (flags->plus == 0 && flags->space == 1)
		ret += 1;
	return (ret + 2);
}
 /**
  * Cas possible ;
  * minus = 1 et zero = 1 / precision peut importe - print left justified blank -- sign devant le nombre
  * minus = 0 et zero = 1 // precision = 1 - print left justified blanck -- sign devant le nombre
  * zero = 1 // precision = 0 - print 0 before number --sign devant le zero
 */


int	justify_putflags_zero_ptr(char *str, t_flags *flags)
{
	int ret;
    int	len;
	int v;
	int	i;

	i = 0;
	len = ft_strlen(str);
    ret = 0;
	v = set_v_ptr(flags);
	if (flags->plus == 1)
		ft_ptr_flag('+');
	else if (flags->plus == 0 && flags->space == 1)
		ft_ptr_flag(' ');
	write(1, "0x", 2);
    while (i++ < (flags->width - (len + v))) //ok
		ret += write(1, "0", 1);
	if (str[0] == 0)
		len++;
	write(1, str, len);
    return(ret + len + v);
}

int justify_putflags_ptr(char *str, t_flags *flags)
{
    int ret;
    int	len;
	int v;
	int	i;

	i = 0;
	len = ft_strlen(str);
    ret = 0;
	v = set_v_ptr(flags);
	//printf("ICIICIICIICI");
    if (flags->minus == 1)
		print_width_flags_ptr(str, flags, len);
    while (i++ < (flags->width - (len + v))) //ok
	{
		if (flags->zero == 1 && flags->precision == 1)
			ret += write(1, " ", 1);
		else if (flags->zero == 1 && flags->precision == 0)
			ret += write(1, "0", 1);
		else
			ret += write(1, " ", 1);
	}
	// printf("A\n");
    if (flags->minus == 0)
		print_width_flags_ptr(str, flags, len);
    return(ret + len + v);
}
