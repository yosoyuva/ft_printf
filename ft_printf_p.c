/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:38 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:46:40 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(va_list *ap, const char *format, int *red, t_flag *flag)
{
  void  *p = va_arg(*ap, void *);
	ft_putstr("0x");
  ft_putnbr_hex((long long int)p);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
