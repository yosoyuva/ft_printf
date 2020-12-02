/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:54 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/04 10:12:31 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_x(t_fpt *var)
{
	if (var->zero)
		var->zero = var->zero;
	return (ft_itoa_hex_long(va_arg(var->list, unsigned int)));
}
