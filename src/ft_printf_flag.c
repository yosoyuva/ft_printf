/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 08:02:58 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 18:45:13 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_minus(va_list *ap, const char *format, int *red, t_flag *flag)
{
  while (format[*red] <= '9' && format[*red] >= '0')
  {
    flag->minus++;
    (*red)++;
  }
}

void	ft_printf_zero(va_list *ap, const char *format, int *red, t_flag *flag)
{
  flag->zero = 0;
  while (format[*red] <= '9' && format[*red] >= '0')
  {
    flag->zero++;
    (*red)++;
  }
  while(flag->zero != 0)
  {
    ft_putchar('0');
    flag->zero--;
  }
}
