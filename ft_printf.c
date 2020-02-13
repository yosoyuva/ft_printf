/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:15 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/13 06:03:41 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putnbr_hex(long long int n)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

void	ft_putnbr_hexm(long long int n)
{
	if (n >= 16)
		ft_putnbr_hexm(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'A' - 10;
	write(1, &n, 1);
}

void	ft_putnbr_oct(long long int n)
{
	if (n >= 8)
		ft_putnbr_oct(n / 8);
	n = n % 8;
	write(1, &n, 1);
}

void	ft_putnbr_u(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
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
	ft_putstr("0x");
  ft_putnbr_hex((long long int)p);
}

void	ft_printf_d(va_list *ap)
{
  int d = va_arg(*ap, int);
  ft_putnbr(d);
}

void	ft_printf_i(va_list *ap)
{

	int  i;
	char	*s;

	i = va_arg(*ap, int);
	s = ft_itoa(i);
	if (s[0] == '0' && s[1] == 'x')
		ft_putnbr_hex((long long int)i);
	else if (s[0] == 0)
		ft_putnbr_oct((long long int)i);
  else
		ft_putnbr(i);
}

void	ft_printf_u(va_list *ap)
{
  unsigned int d = va_arg(*ap, int);
  ft_putnbr_u(d);
}

void	ft_printf_x(va_list *ap)
{
  void  *p = va_arg(*ap, void *);

  ft_putnbr_hex((long long int)p);
}

void	ft_printf_xm(va_list *ap)
{
  void  *p = va_arg(*ap, void *);
	ft_putstr("0x");
  ft_putnbr_hexm((long long int)p);
}

void	ft_printf_percent(va_list *ap)
{
  ft_putchar('%');
}

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
				dst[4] = ft_printf_i;
				dst[5] = ft_printf_u;
				dst[6] = ft_printf_x;
				dst[7] = ft_printf_Xm;
				dst[8] = ft_printf_percent;
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
	//int	a = 5;

	ft_printf("hello %x %%\n", -5);
	printf("hello %x %%\n", -5);
  return (0);
}
