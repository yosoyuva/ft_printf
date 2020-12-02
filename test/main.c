#include "../inc/ft_printf.h"

#define BPRINT(x, ...) PRINT("\"%s\" // 1st '*' = %d, 2nd '*' = %d\n", x, a, b)

int main()
{
  ft_printf(" --- Return : %d\n", ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));
  printf(" --- Return : %d\n", printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL));

  //ft_printf("bonjour %s\n", "");
  //printf("bonjour %s\n", "");
}
/*to test : make re && gcc -o test/myprog test/main.c  -L. -lftprintf */
/* to test leaks : valgrind --tool=memcheck ./myprog  */
