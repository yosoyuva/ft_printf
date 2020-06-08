/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:04:42 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/08 19:29:29 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	pos;

	pos = 0;
	while (src[pos] != '\0')
	{
		dst[pos] = src[pos];
		pos++;
	}
	if (src[pos] == '\0')
		dst[pos] = '\0';
	return (dst);
}

char	*ft_strcpy_wout_frst_c(char *dst, const char *src)
{
	int	pos;

	pos = 0;
	while (src[pos + 1] != '\0')
	{
		dst[pos] = src[pos + 1];
		pos++;
	}
	if (src[pos + 1] == '\0')
		dst[pos] = '\0';
	return (dst);
}
