/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 13:06:02 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/09 13:08:31 by ymehdi           ###   ########.fr       */
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
	return (c);
}

void		ft_printf_c_bin(t_fpt *var)
{
	var->size_arg = 1;
	if (var->digit > 1)
	{
		var->min = ft_strnew_space_f(var->min, \
			var->digit - var->size_arg - 1);
		ft_putstr(var->min);
		var->size_read = ft_strlen(var->min) + var->size_read;
	}
	ft_putchar(0);
	var->size_read++;
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
	}
}

void		ft_printf_c_bin_a(t_fpt *var)
{
	var->size_read = ft_strlen(var->result_s) + var->size_read;
	ft_putstr(var->result_s);
	ft_printf_c_bin(var);
	free(var->result_s);
	var->result_s = ft_strdup("");
	free(var->s);
	free(var->min);
}
