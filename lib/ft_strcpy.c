/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:04:42 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 19:57:17 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		pos;

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

char	*ft_strcpy_wout_frst_c(char *src)
{
	int		pos;
	char	*dst;

	pos = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2))))
		return (NULL);
	dst[ft_strlen(src) + 2] = '\0';
	ft_strcpy(dst, src);
	while (src[pos + 1] != '\0')
	{
		dst[pos] = src[pos + 1];
		pos++;
	}
	if (src[pos + 1] == '\0')
		dst[pos] = '\0';
	free(src);
	return (dst);
}

char	*ft_strcpy_from_pos(char *dst, const char *src, int pos)
{
	int		i;
	char	*s;

	s = ft_strnew(ft_strlen(dst));
	i = 0;
	while (src[i] != '\0')
	{
		s[i + pos] = src[i];
		i++;
	}
	if (src[i] == '\0')
		s[i + pos] = '\0';
	free(dst);
	return (s);
}

char	*ft_strcpy_wout_frst_c_nofree(char *src)
{
	int		pos;
	char	*dst;

	pos = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 2))))
		return (NULL);
	dst[ft_strlen(src) + 2] = '\0';
	ft_strcpy(dst, src);
	while (src[pos + 1] != '\0')
	{
		dst[pos] = src[pos + 1];
		pos++;
	}
	if (src[pos + 1] == '\0')
		dst[pos] = '\0';
	return (dst);
}
