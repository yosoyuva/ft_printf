/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:36 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/04 09:50:09 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_u(t_fpt *var)
{
	if (var->zero)
		var->zero = var->zero;
	return (ft_itoa_u(va_arg(var->list, unsigned int)));
}
