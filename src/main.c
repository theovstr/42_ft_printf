#include "../include/libftprintf.h"

int main(void)
{
	ft_printf("-4555 : '% +i'\n", -4555);
	ft_printf("+4555 : '% +d'\n", 4555);
	ft_printf("+4555 : '%+d'\n", 4555);
	ft_printf("-2147483647 : '%+d'\n", -2147483647);
	ft_printf("' 12' : '%     i'\n", 12);
	ft_printf("+45 : '%+  #d'\n", 45);
	ft_printf("' 3647' : '%       d'\n", 3647);
	ft_printf("'+0' : '%   ++++++  i'\n", -0);
}