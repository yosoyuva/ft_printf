#include "inc/ft_printf.h"

int main ()
{
    ft_printf("ft :%2p, %.p, %5.p, %2.p\n", NULL, NULL, NULL, NULL);
    printf("printf :%2p, %.p, %5.p, %2.p", NULL, NULL, NULL, NULL);
    return (0);
}
