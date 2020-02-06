/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:15 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/06 13:56:47 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/*void	ft_printf_p(va_list *ap)
{
  void  *p = va_arg(*ap, void *);
  ft_putnbr_hex(p);
}*/

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

int	ft_printf(const char *format, ...)
{
  t_declare dec;

  dec.tabIndex = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%', '-', '0', '.', '*', 0};
  //(*tabFunction[13]) (va_list *) = {ft_printf_c, ft_printf_s, ft_printf_p, ft_printf_d, ft_printf_i, ft_printf_u, ft_printf_x, ft_printf_X, ft_printf_%, ft_printf_less, ft_printf_zero, ft_printf_dot, ft_printf_star};
  dec.(*tabFunction[4]) (va_list *) = {ft_printf_c, ft_printf_s, ft_printf_p, ft_printf_d);
  va_start(dec.ap, format);
  while(format[dec.red])
  {
    while(format[dec.red] != '%')
    {
      ft_putchar(format[dec.red]);
      (dec.red)++;
    }
    if (format[dec.red] == '%')
    {
      (dec.red)++;
      dec.tmpIndex = find_index(dec.tabIndex, format[dec.red]);
      if (dec.tmpIndex != -1)
        (*(dec.tabFunction)[dec.tmpIndex]) (&(dec.ap));

    }
  }
  va_end(dec.ap);
  return (dec.red);
}

int main(void)
{
  ft_printf("%d", 7);
  return (0);
}
