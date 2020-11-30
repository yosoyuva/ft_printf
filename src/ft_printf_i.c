/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:19 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/15 01:21:50 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_i(t_fpt *var)
{
	/*int  i;
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
	}*/
	if (var->zero)
  {}
	return (ft_itoa(va_arg(var->list, int)));
}
