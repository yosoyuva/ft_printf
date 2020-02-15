/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:59:40 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:45:14 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(va_list *ap, const char *format, int *red, t_flag *flag)
{
  char  c = va_arg(*ap, int);
  ft_putchar(c);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
