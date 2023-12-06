
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
	// ft_printf("'%.9x'\n", -3147483649);
	// ft_printf("00004 : '%.5x'\n", 2);
	// ft_printf("'FFFFF79D' : '%010x'\n", -2147);
	// ft_printf("'%#  05x'\n", 12);
	// ft_printf("2DX : '%-010.5XX'\n", 45);
	// printf("2DX : '%-010.5XX'\n", 45);
	// ft_printf("'0XE3F' : '%#10.5X'\n", 3647);

	// ft_printf("-----------end of test\n");

	// // //precision and jusitfy for %d and %i 
	// ft_printf("test for precision and width together ---\n\n");
	// ft_printf("00001     '// %-10.5d'\n", 1);
    // ft_printf("'+00001'// '%+.5i'\n", 1);
    // ft_printf("'     0000000056'// '%015.10d'\n", 56);
   	// ft_printf("'  785'// '%5.2d'\n", 785);
   	// ft_printf("''// '%.0d'\n", 0);
    // ft_printf("'  -2147483648'// '%  #13.11i'\n", -2147483648);
	// ft_printf("' 0000000056'// '% .10d'\n", 56);
	// ft_printf("'  +2147483647'// '%  #+13.11i'\n", 2147483647);
	// ft_printf("'      +00214'// '%  #+13.5i'\n", 214);
	// // char *null_str = NULL;
	// // ft_printf("'%.7s'\n", null_str);


	// ft_printf("'  +2147483647'// '%013.11i'\n", 2147483647);
	// ft_printf("'      +00214'// '%-013i'\n", 214);
	// ft_printf("%.11i\n", -2147483647);

	// ft_printf("'%-+15.i'\n", 0);
	// ft_printf("'%-1.8i'\n", 0);
	// ft_printf("Bla %.2ii bla %.5isbla bla %.ix bla %.i\n", 127, 42, 1023, 0);
	// ft_printf("'%.3d'\n", 0);
	// ft_printf("'%01.3d'\n", 0);
	//ft_printf("'%01.3d'\n", 0);
	//ft_printf("%.5x", 0);
	// char a = 'd';
	// ft_printf("'%-30.20p'\n", &a);
	// ft_printf("'%030p'\n", &a);
	// ft_printf("'%+.20p'\n", &a);
	// ft_printf("'% .5p'\n", &a);
	//ft_printf(" %3.2d ", 0);
	//ft_printf("'%-1p' '%-2p' ", 0, 0);
	//ft_printf("'%05.2i'\n", 0);
	// ft_printf("'%04.2i'\n", 1);
	// ft_printf("'%- 4.2i'\n", 8);
}
