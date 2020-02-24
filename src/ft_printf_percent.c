/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:04:28 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:49:19 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_percent(va_list *ap, const char *format, int *red, t_flag *flag)
{
  ft_putchar('%');
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
