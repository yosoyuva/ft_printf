/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:47:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 18:54:17 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;

	printf("deand\n");
	if ((s = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	printf("deand2\n");
	ft_memset(s, '\0', size + 1);
	printf("deand3\n");
	return (s);
}
