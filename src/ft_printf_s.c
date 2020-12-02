/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/03 18:42:41 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*get_arg_string(char *arg)
{
	char	*str;

	if (arg == NULL)
		return (NULL);
	str = ft_calloc(ft_strlen(arg), sizeof(char *) + 1);
	str = ft_memcpy(str, arg, ft_strlen(arg));
	return (str);
}

char		*ft_printf_s(t_fpt *var)
{
	if (var->zero)
		var->zero = var->zero;
	return (get_arg_string(va_arg(var->list, char *)));
}
