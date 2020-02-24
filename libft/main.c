#include "libft.h"

char	*ft_add_c_to_end_of_s(char *s, char c)
{
  char  *str;

  str = ft_strnew(ft_strlen(s) + 1);
  ft_strcpy(str, s);
  str[ft_strlen(s)] = c;
  return (str);
}

int main()
{
	char *s;
	
	s = ft_strnew(3);
	s = "bo";
	s = ft_add_c_to_end_of_s(s, 'd');
	printf("s = %s\n", s);
	printf("%-5-10-1d\n", 7);
}
