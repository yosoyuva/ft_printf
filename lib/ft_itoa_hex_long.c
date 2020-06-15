/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 17:18:34 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/10 21:44:12 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nlength_hex_long(unsigned int n)
{
	int	size;

	size = 0;
/*	if (n < 0)
		size++;*/
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char			*ft_itoa_hex_long(unsigned int nb)
{
	int				i;
//	unsigned long int nb;
	char			*s;

	if (!(s = (char *)malloc(sizeof(char) * (ft_nlength_hex_long(nb)))))
		return (NULL);
	i = ft_nlength_hex_long(nb) - 1;
//	printf("i = %d\n", i);
	s[i] = '\0';
	/*if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;*/
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
//	printf("s = %s\n", s);
	return (s);
}
/*
int main()
{
  int a = 1;
  printf("%s\n", ft_itoa_hex_long(140721173330004));
  printf("%lx\n", 140721173330004);
//  printf("%li\n", &a);

}*/
//140721173330004
//
