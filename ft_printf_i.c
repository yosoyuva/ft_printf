/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:19 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:48:38 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_i(va_list *ap, const char *format, int *red, t_flag *flag)
{

	int  i;
	char	*s;

	i = va_arg(*ap, int);
	s = ft_itoa(i);
	if (s[0] == '0' && s[1] == 'x')
		ft_putnbr_hex((long long int)i);
	else if (s[0] == 0)
		ft_putnbr_oct((long long int)i);
  else
		ft_putnbr(i);
	while (flag->minus != 0)
	{
		ft_putchar(' ');
		flag->minus--;
	}
}
