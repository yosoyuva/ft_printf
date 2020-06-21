/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_c_to_end_of_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:24:25 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/19 22:09:12 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_add_c_to_end_of_s(char *s, char c)
{
	char	*str;

/*	if (!s)
	{
		str = ft_strnew(1);
		str[0] = c;
		return (str);
	}*/
	str = ft_strnew(ft_strlen(s) + 1);
	ft_strcpy(str, s);
	str[ft_strlen(s)] = c;
	free(s);
	return (str);
}
