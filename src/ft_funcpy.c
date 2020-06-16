/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:06:27 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/15 01:18:32 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	*ft_funcpy(char *(*dst[13]) (va_list *, t_flag *))
{
	dst[0] = ft_printf_c;
	dst[1] = ft_printf_s;
	dst[2] = ft_printf_p;
	dst[3] = ft_printf_d;
	dst[4] = ft_printf_i;
	dst[5] = ft_printf_u;
	dst[6] = ft_printf_x;
	dst[7] = ft_printf_xm;
	dst[8] = ft_printf_percent;
	return (dst);
}
