/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:03:49 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:51:27 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_xm(va_list *ap, const char *format, int *red, t_flag *flag)
{
  void  *p = va_arg(*ap, void *);
	ft_putstr("0x");
  ft_putnbr_hexm((long long int)p);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
