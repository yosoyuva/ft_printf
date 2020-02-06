#include <stdio.h>

int	main(void)
{
	int a = 1;
	void *p = &a;
	printf("%p\n", &p);
	return(0);
}
