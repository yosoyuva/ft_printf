/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_c_to_end_of_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:24:25 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:21:00 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_add_c_to_end_of_s(char *s, char c)
{
	char	*str;
	int		size;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	str = ft_strnew(size + 1);
	ft_strcpy(str, s);
	free(s);
	str[size] = c;
	return (str);
}
