/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:36 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:50:33 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(va_list *ap, const char *format, int *red, t_flag *flag)
{
  unsigned int d = va_arg(*ap, int);
  ft_putnbr_u(d);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
