/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:44:25 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 19:44:27 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(long long int n)
{
	if (n >= 16)
		ft_putnbr_hex(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'a' - 10;
	write(1, &n, 1);
}

void	ft_putnbr_hexm(long long int n)
{
	if (n >= 16)
		ft_putnbr_hexm(n / 16);
	n = n % 16;
	n += n < 10 ? '0' : 'A' - 10;
	write(1, &n, 1);
}

void	ft_putnbr_oct(long long int n)
{
	if (n >= 8)
		ft_putnbr_oct(n / 8);
	n = n % 8;
	write(1, &n, 1);
}

void	ft_putnbr_u(unsigned int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
