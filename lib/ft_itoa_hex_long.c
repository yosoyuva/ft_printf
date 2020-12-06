/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:18:34 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/06 21:09:18 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlength_hex_long(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_hex_long(unsigned int nb)
{
	int				i;
	char			*s;

	//if (!(s = (char *)malloc(sizeof(char) * (ft_nlength_hex_long(nb)))))
	//	return (NULL);
	s = ft_strnew(ft_nlength_hex_long(nb));
	i = ft_nlength_hex_long(nb) - 1;
	//printf("\ni = %u\n", nb);
	s[i] = '\0';
	while (i >= 0 && s[i] != '-')
	{
		if (nb % 16 < 10)
		{
			s[i] = nb % 16 + 48;
			nb = nb / 16;
		}
		else
		{
			s[i] = (nb % 16) % 10 + 'a';
			nb = nb / 16;
		}
		i--;
	}
	return (s);
}

char	*ft_itoa_hex_long_m(unsigned int nb)
{
	int				i;
	char			*s;

	//if (!(s = (char *)malloc(sizeof(char) * (ft_nlength_hex_long(nb)))))
	//	return (NULL);
	s = ft_strnew(ft_nlength_hex_long(nb));
	i = ft_nlength_hex_long(nb) - 1;
	//printf("\ni = %u\n", nb);
	s[i] = '\0';
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
