/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:59:40 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/15 01:21:31 by ymehdi           ###   ########.fr       */
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
