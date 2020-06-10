/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_m.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:51:19 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/10 20:21:37 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlength_hex_m(long int n)
{
	int	size;

	size = 0;
	if (n < 0)
		size++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char			*ft_itoa_hex_m(long int n)
{
	int				i;
	unsigned long int nb;
	char			*s;

	if (!(s = (char *)malloc(sizeof(char) * (ft_nlength_hex_m(n)))))
		return (NULL);
	i = ft_nlength_hex_m(n) - 1;
	s[i] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;
	while (i >= 0 && s[i] != '-')
	{
		if (nb % 16 < 10)
		{
			s[i] = nb % 16 + 48;
			nb = nb / 16;
		}
		else
		{
			s[i] = (nb % 16) % 10 + 'A';
			nb = nb / 16;
		}
		i--;
	}
	return (s);
}
