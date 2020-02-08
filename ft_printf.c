/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:15 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/08 15:22:33 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_hex(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * (-1);
	}
	else
		nbr = nb;
	if (nbr > 15)
		ft_putnbr(nbr / 16);
	ft_putchar(nbr % 16 + 48);
}

void	ft_printf_c(va_list *ap)
{
  char  c = va_arg(*ap, int);
  ft_putchar(c);
}

void	ft_printf_s(va_list *ap)
{
  char  *s = va_arg(*ap, char *);
  ft_putstr(s);
}

void	ft_printf_p(va_list *ap)
{
  void  *p = va_arg(*ap, void *);
  ft_putnbr_hex((int)p);
}

void	ft_printf_d(va_list *ap)
{
  int d = va_arg(*ap, int);
  ft_putnbr(d);
}

/*void	ft_printf_i(va_list *ap)
{
  char  c = va_arg(*ap, char);
  ft_putchar(c);
}*/

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

void    *ft_funcpy(void (*dst[4]) (va_list *))
{

        dst[0] = ft_printf_c;
        dst[1] = ft_printf_s;
        dst[2] = ft_printf_p;
        dst[3] = ft_printf_d;
        return (dst);
}

int	ft_printf(const char *format, ...)
{
  t_declare dec;

  ft_strcpy(dec.tabIndex, "cspdiuxX%-0.*");
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
      (dec.red)++;
			dec.tabFunction[find_index(dec.tabIndex, format[dec.red])] (&dec.ap);
			(dec.red)++;
    }
  }
  va_end(dec.ap);
  return (dec.red);
}

int main(void)
{
	int	a = 5;
	ft_printf("hello %s commect ca va ?\n", "yuv", "hey");
	printf("hello %s commect ca va ?\n", "yuv", "hey");
//  ft_printf("ft: je suis %s et j'ai %d ans", "yuv", 7);
//	printf("printf: je suis %s et j'ai %p ans\n", "yuv", &a);
  return (0);
}
