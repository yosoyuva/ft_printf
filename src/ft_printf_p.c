/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:38 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/14 16:56:42 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_printf_p(t_fpt *var)
{
	char	*s;
	char	*arg;

	if (var->zero)
		var->zero = var->zero;
	arg = ft_itoa_hex_long_p(va_arg(var->list, long int));
	s = ft_strjoin("0x", arg);
	free(arg);
	return (s);
}
