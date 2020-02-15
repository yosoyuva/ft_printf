/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:01 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:48:04 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_d(va_list *ap, const char *format, int *red, t_flag *flag)
{
  int d = va_arg(*ap, int);
  ft_putnbr(d);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
