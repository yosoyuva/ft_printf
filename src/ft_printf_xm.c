/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:03:49 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/06 21:07:53 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_xm(t_fpt *var)
{
	if (var->zero)
		var->zero = var->zero;
	return (ft_itoa_hex_long_m(va_arg(var->list, long int)));
}
