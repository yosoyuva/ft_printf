/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:50:04 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(va_list *ap, const char *format, int *red, t_flag *flag)
{
  char  *s = va_arg(*ap, char *);
  ft_putstr(s);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
