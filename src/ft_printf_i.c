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
	if (var->zero)
		var->zero = var->zero;
	return (ft_itoa(va_arg(var->list, int)));
}
