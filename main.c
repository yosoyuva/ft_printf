#include <stdio.h>
#include "inc/ft_printf.h"
#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)



int main(void)
{
	int		j = 0;
/*	ft_printf(" --- Return : %d\n", ft_printf("%u, %x, %X", j, j, j));
	printf("--- return = %d\n", printf("printf :x = %.0x, X = %.0X, u = %.0u, d = %.0d, d3 = %.0d, 5.d = %5.d, 1d = %1d, 02d = %02d", j,j,j, 0, 3, 0, 3, 3) + 3);
	printf("--- return = %d\n", ft_printf("ft_printf :x = %.0x, X = %.0X, u = %.0u, d = %.0d, d3 = %.0d, 5.d = %5.d, 1d =%1d, 02d = %02d", j,j,j, 0, 3, 0, 3, 3));
	printf("return :%d\n", ft_printf("ft%", "test"));
	printf("return :%d", ft_printf("mon printf :% %"));
	printf("printf % %");*/
/*	printf("--- return = %d\n", printf("printf :0*d = %0*d", 4, -12) + 3);
	printf("--- return = %d\n", ft_printf("ft_printf :0*d = %0*d", 4, -12));*/
	printf("--- return = %d\n", printf("printf :p = %p", NULL) + 3);
	printf("--- return = %d\n", ft_printf("ft_printf :p = %p", NULL));
	//printf("--- return = %d\n", printf("%x", -12));
	//printf("--- return = %d\n", ft_printf("%x", -12));
	return 0;
}
