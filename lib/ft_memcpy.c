/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:06:49 by ymehdi            #+#    #+#             */
/*   Updated: 2019/12/13 18:08:21 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char		*copydst;
	char		*copysrc;

	i = 0;
	copydst = (char *)dst;
	copysrc = (char *)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		copydst[i] = copysrc[i];
		i++;
	}
	return (copydst);
}
