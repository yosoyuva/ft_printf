/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:04:28 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/14 15:31:08 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_printf_percent(t_fpt *var)
{
	char	*c;

	c = ft_strnew(1);
	if (var->zero)
		var->zero = var->zero;
	c = ft_add_c_to_end_of_s(c, '%');
	//ft_init_flag(var);
	return (c);
}
