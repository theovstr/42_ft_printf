#include "../include/libftprintf.h"

int main(void)
{
	ft_printf("-4555 : '% +i'\n", -4555);
	ft_printf("+4555 : '% +d'\n", 4555);
	ft_printf("+4555 : '%+d'\n", 4555);
	ft_printf("-2147483647 : '%+d'\n", -2147483647);
	ft_printf("' 12' : '%     i'\n", 12);
}