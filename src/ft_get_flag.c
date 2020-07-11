/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:07:46 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/30 21:06:44 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_get_zero(const char *str, t_declare *dec, t_flag *flag)
{
	int n;

	n = 0;
	while (ft_isdigit(str[dec->i]))
	{
		n = n * 10 + (str[dec->i] - 48);
		(dec->i)++;
	}
	flag->zero = n;
}

void	ft_get_minus(const char *str, t_declare *dec, t_flag *flag)
{
	int n;

	n = 0;
	while (ft_isdigit(str[dec->i]))
	{
		n = n * 10 + (str[dec->i] - 48);
		(dec->i)++;
	}
	flag->minus = n;
}

void	ft_get_digit(const char *str, t_declare *dec, t_flag *flag)
{
	int n;

	n = 0;
	if (str[dec->i] == '0')
		flag->zero_was_ignrd = 1;
	while (ft_isdigit(str[dec->i]))
	{
		n = n * 10 + (str[dec->i] - 48);
		(dec->i)++;
	}
	flag->digit = n;
}

void	ft_get_star(t_declare *dec, t_flag *flag, va_list *ap, const char *str)
{
	int arg;

	arg = va_arg(*ap, long int);
	if (str[dec->i - 1] == '.' || flag->prc > -1)
		flag->prc = arg;
	else if (str[dec->i - 1] == '-' || flag->minus > -1 || arg < 0)
	{
		if (arg < 0)
			flag->minus = -1 * arg;
		else
			flag->minus = arg;
	}
	else if ((str[dec->i - 1] == '0' || flag->zero > -1) && flag->ignr_zero == 0)
		flag->zero = arg;
	else
		flag->digit = arg;
	(dec->i)++;
}

void	ft_get_prc(const char *str, t_declare *dec, t_flag *flag)
{
	int n;

	(dec->i)++;
	n = 0;
	while (ft_isdigit(str[dec->i]))
	{
		n = n * 10 + (str[dec->i] - 48);
		(dec->i)++;
	}
	flag->prc = n;
}
