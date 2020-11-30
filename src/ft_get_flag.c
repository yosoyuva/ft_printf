/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:07:46 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/09 17:19:51 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_get_zero(const char *str, t_fpt *var)
{
	int n;

	n = 0;
	while (ft_isdigit(str[var->pos]))
	{
		n = n * 10 + (str[var->pos] - 48);
		(var->pos)++;
	}
	var->zero = n;
}

void	ft_get_minus(const char *str, t_fpt *var)
{
	int n;

	n = 0;
	while (ft_isdigit(str[var->pos]))
	{
		n = n * 10 + (str[var->pos] - 48);
		(var->pos)++;
	}
	var->minus = n;
}

void	ft_get_digit(const char *str, t_fpt *var)
{
	int n;

	n = 0;
	if (str[var->pos] == '0')
		var->zero_was_ignrd = 1;
	while (ft_isdigit(str[var->pos]))
	{
		n = n * 10 + (str[var->pos] - 48);
		(var->pos)++;
	}
	var->digit = n;
}

void	ft_get_star(t_fpt *var, const char *str)
{
	int arg;

	arg = va_arg(var->list, long int);
	if (str[var->pos - 1] == '.' || var->prc > -1)
		var->prc = arg;
	else if (str[var->pos - 1] == '-' || var->minus > -1 || arg < 0)
	{
		if (arg < 0)
			var->minus = -1 * arg;
		else
			var->minus = arg;
	}
	else if ((str[var->pos - 1] == '0' || var->zero > -1) && \
	var->ignr_zero == 0)
		var->zero = arg;
	else
		var->digit = arg;
	(var->pos)++;
}

void	ft_get_prc(const char *str, t_fpt *var)
{
	int n;

	(var->pos)++;
	n = 0;
	while (ft_isdigit(str[var->pos]))
	{
		n = n * 10 + (str[var->pos] - 48);
		(var->pos)++;
	}
	var->prc = n;
}
