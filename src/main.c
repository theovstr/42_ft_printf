
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
	// ft_printf("'(nil)' : '%   ++++++  p'\n", -0);

	// ft_printf("-----------end of test\n");
	// ft_printf("\n");
	// ft_printf("TEST FOR %%xX \n");

	// ft_printf("'fffffffc' : '%x'\n", -4);
	// ft_printf("0X2D : '% ###X'\n", 45);
	// ft_printf("0 : '%x'\n", 0);
	// ft_printf("FFFFF79D : '%X'\n", -2147);
	// ft_printf("'0xc' : '%##x'\n", 12);
	// ft_printf("2DX : '%XX'\n", 45);
	// ft_printf("'0XE3F' : '%#X'\n", 3647);

	// ft_printf("-----------end of test\n");

	// //precision and jusitfy for %d and %i 
	// ft_printf("test for precision and width together ---\n\n");
	// ft_printf("00001     '// %-10.5d'\n", 1);
    // ft_printf("'+00001'// '%+.5i'\n", 1);
    // ft_printf("'     0000000056'// '%015.10d'\n", 56);
   	// ft_printf("'  785'// '%5.2d'\n", 785);
   	// ft_printf("''// '%.0d'\n", 0);
    // ft_printf("'  -2147483648'// '%  #13.5i'\n", -2147483648);
	// ft_printf("' 0000000056'// '% .10d'\n", 56);
	// ft_printf("'  +2147483647'// '%  #+13.5i'\n", 2147483647);
	// ft_printf("'      +00214'// '%  #+13.5i'\n", 214);
	// char *null_str = NULL;
	// ft_printf("'%.7s'\n", null_str);

	ft_printf("%.11u\n", -2483647);
}
