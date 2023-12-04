#include "../include/ft_printf.h"

int main(void)
{

	// ft_printf("TEST FOR %%d and %%i \n");

	// ft_printf("-4555 : '% +i'\n", -4555);
	// ft_printf("+4555 : '% +d'\n", 4555);
	// ft_printf("+4555 : '%+d'\n", 4555);
	// ft_printf("-2147483647 : '%+d'\n", -2147483647);
	// ft_printf("' 12' : '%     i'\n", 12);
	// ft_printf("+45 : '%+  #d'\n", 45);
	// ft_printf("' 3647' : '%       d'\n", 3647);
	// ft_printf("'+0' : '%   ++++++  i'\n", -0);

	// ft_printf("-----------end of test\n");
	// ft_printf("\n");
	// ft_printf("TEST FOR %%p \n");

	// ft_printf("'+0xfffffffc : '% +p'\n", -4);
	// ft_printf("+0x2d : '% +p'\n", 45);
	// ft_printf("(nill) : '%+p'\n", 0);
	// ft_printf("+0xfffff79d : '%+p'\n", -2147);
	// ft_printf("' 0xc' : '%     p'\n", 12);
	// ft_printf("+0x2d : '%+  #p'\n", 45);
	// ft_printf("' 0xe3f' : '%       p'\n", 3647);
	// ft_printf("'(nill)' : '%   ++++++  p'\n", -0);

	// ft_printf("-----------end of test\n");
	// ft_printf("\n");
	// ft_printf("TEST FOR %%xX \n");

	// ft_printf("'fffffffc' : '%x'\n", -4);
	// ft_printf("0X2d : '% ###X'\n", 45);
	// ft_printf("0 : '%x'\n", 0);
	// ft_printf("FFFFF79D : '%X'\n", -2147);
	// ft_printf("'0xc' : '%##x'\n", 12);
	// ft_printf("2Dd : '%XX'\n", 45);
	// ft_printf("'0XE3F' : '%#X'\n", 3647);

	// ft_printf("-----------end of test\n");

	ft_printf("'%.0s'", "test");
}
