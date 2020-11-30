/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:47:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/03/07 09:18:18 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_space(size_t size)
{
	void	*s;

	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	ft_memset(s, ' ', size + 1);
	return (s);
}

char	*ft_strnew_space_f(char *str, size_t size)
{
	void	*s;

	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	ft_memset(s, ' ', size + 1);
	free(str);
	return (s);
}
