/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:59:40 by ymehdi            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_printf_c(t_fpt *var)
{
	char	*c;

	if (var->zero)
		var->zero = var->zero;
	c = ft_strnew(1);
	c = ft_add_c_to_end_of_s(c, va_arg(var->list, int));
	//if (c[0] == 0)
	//printf("c[0] =%c, c[1] =%c\n", c[0], c[1]);
	return (c);
}

void		ft_printf_c_bin(t_fpt *var)
{
	var->size_arg = 1;
	if (var->digit > 1)
	{
		var->min = ft_strnew_space_f(var->min, \
			var->digit - var->size_arg - 1);
		//printf("size =%d, var->min =%s\ne", var->digit -1, var->min);
		ft_putstr(var->min);
		var->size_read = ft_strlen(var->min) + var->size_read;
		//var->result_s = ft_strjoin_fo(var->result_s, var->min);
	}
	ft_putchar(0);
	var->size_read++;
	//var->result_s = ft_strjoin_fo(var->result_s, var->s);

	if (var->minus > 1 || \
	(var->minus == 1 && var->minus - 2 >= 0 && var->minus > 0))
	{
		if (var->minus == 1 && var->s[0] == 0)
			var->min = ft_strnew_space_f(var->min, \
				var->minus - 2);
		else if (var->tmpindex == 0)
			var->min = ft_strnew_space_f(var->min, \
					var->minus - var->size_arg - 1);
		else
			var->min = ft_strnew_space_f(var->min, \
				var->minus - 1 - 1);
		ft_putstr(var->min);
		var->size_read = ft_strlen(var->min) + var->size_read;
		//var->result_s = ft_strjoin_fo(var->result_s, var->min);
	}
}
