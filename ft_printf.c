/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:15 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/05 13:42:53 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
  t_declare dec;

  va_start(dec.ap, format);
  while(format[dec.red])
  {
    while(format[dec.red] != '%')
    {
      ft_putchar(format[de.red]);
      red++;
    }
    if (format[dec.red] == '%')
    {

    }
    ft_putchar();
    if (!ap)
      return (0);
  }
  va_end(dec.ap);
  return (dec.red);
}
