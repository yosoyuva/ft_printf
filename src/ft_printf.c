/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:15 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/16 14:44:47 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int find_index(char *tabIndex, char c)
{
  int i;

  i = 0;
  while (tabIndex[i] != 0)
  {
    if (tabIndex[i] == c)
      return (i);
    i++;
  }
  return (-1);
}

/*int find_flag(char *tabIndex, char c)
{
  int i;

  i = 0;
  while (tabFlag[i] != 0)
  {
    if (tabFlag[i] == c)
      return (i);
    i++;
  }
  return (-1);
}*/

void    *ft_funcpy(void (*dst[13]) (va_list *, const char *, int *, t_flag *))
{

        dst[0] = ft_printf_c;
        dst[1] = ft_printf_s;
        dst[2] = ft_printf_p;
        dst[3] = ft_printf_d;
				dst[4] = ft_printf_i;
				dst[5] = ft_printf_u;
				dst[6] = ft_printf_x;
				dst[7] = ft_printf_xm;
				dst[8] = ft_printf_percent;
				dst[9] = ft_printf_minus;
				dst[10] = ft_printf_zero;
				/*dst[11] = ft_printf_dot;
				dst[12] = ft_printf_star;*/
        return (dst);
}

/*void    *ft_funcpy_flg(void (*dst[4]) (va_list *, const char *, int *))
{
				dst[0] = ft_printf_minus;
				dst[1] = ft_printf_zero;
				dst[2] = ft_printf_dot;
				dst[3] = ft_printf_star;
        return (dst);
}*/

int	ft_printf(const char *format, ...)
{
  t_declare 			dec;
	static t_flag		flag;

	flag.minus = 0;
	ft_strcpy(dec.tabIndex, "cspdiuxX%-0.*");
//	ft_strcpy(dec.tabFlag, "-0.*");
  ft_funcpy(dec.tabFunction);
  va_start(dec.ap, format);
  dec.red = 0;
  while(format[dec.red])
  {
		while(format[dec.red] != '%' && format[dec.red])
    {
			ft_putchar(format[dec.red]);
      (dec.red)++;
    }
    if (format[dec.red] == '%')
    {
			while (is_flg(format[dec.red + 1]))
			{
				dec.tmpIndex = find_index(dec.tabIndex, format[dec.red + 1]);
				dec.tabFunction[dec.tmpIndex] (&dec.ap, format, &dec.red, &flag);
				dec.red++;
			}
			if (is_flg_conv(format[dec.red + 1]) == -1)
				return (-1);
			dec.tmpIndex = find_index(dec.tabIndex, format[dec.red + 1]);
			dec.tabFunction[dec.tmpIndex] (&dec.ap, format, &dec.red, &flag);
			(dec.red)+=2;
    }
  }
  va_end(dec.ap);
  return (dec.red);
}

int main(void)
{
	//int	a = 5;

	ft_printf("hello %-10d %%\n", 5);
	printf("hello %-10d %%\n", 5);
  return (0);
}
