/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:10:27 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/13 05:34:22 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlength(int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*s;

	if (!(s = (char *)malloc(sizeof(char) * (ft_nlength(n) + 1))))
		return (NULL);
	i = ft_nlength(n);
	s[i] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	else
		while (--i >= 0)
		{
			s[i] = n % 10 + 48;
			n = n / 10;
		}
	while (--i > 0)
	{
		s[i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (s);
}
