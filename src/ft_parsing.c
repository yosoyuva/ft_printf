/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/09 17:20:48 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		find_index(char *tabindex, char c)
{
	int i;

	i = 0;
	while (tabindex[i] != 0)
	{
		if (tabindex[i] == c)
			return (i);
		else if (ft_isdigit(tabindex[i]))
			return (14);
		i++;
	}
	return (-1);
}

void	ft_init_var(t_fpt *var)
{
	var->zero = -1;
	var->minus = -1;
	var->digit = -1;
	var->prc = -1;
	var->zero_was_ignrd = 0;
	var->result = 0;
	var->result_s = ft_strnew(1);
	var->ignr_zero = 0;
	var->pos = 0;
}

void	ft_init_flag(t_fpt *var)
{
	var->zero = -1;
	var->minus = -1;
	var->digit = -1;
	var->prc = -1;
	var->zero_was_ignrd = 0;
}

void	ft_parse_flag(const char *str, t_fpt *var)
{
	ft_init_flag(var);
	while (str[var->pos] && is_flag(str[var->pos]))
	{
		if (str[var->pos] == '*')
		{
			ft_get_star(var, str);
		}
		else if (ft_isdigit(str[var->pos]) && (!(str[var->pos] == '0' && \
		str[var->pos - 1] == '%') || var->ignr_zero == 1))
			ft_get_digit(str, var);
		else if (str[var->pos] == '0' && str[var->pos - 1] == '%' && \
		var->ignr_zero == 0)
		{
			(var->pos)++;
			ft_get_zero(str, var);
		}
		else if (str[var->pos] == '.')
			ft_get_prc(str, var);
		else if (str[var->pos] == '-')
		{
			(var->pos)++;
			ft_init_flag(var);
			ft_get_minus(str, var);
		}
	}
}

int		ft_parsing(const char *str, t_fpt *var, t_dec *dec)
{
	ft_strcpy(var->tabindex, "cspdiuxX%-0.*");
	ft_funcpy(dec->tabfunction);
	while (str[var->pos] && var->pos < (int)ft_strlen(str))
	{
		while (str[var->pos] != '%' && str[var->pos])
		{
			var->result_s = ft_add_c_to_end_of_s(var->result_s, str[var->pos]);
			(var->pos)++;
		}
		if (str[var->pos] && str[var->pos] == '%')
		{
			(var->pos)++;
			if (ft_check(str, var))
			{
				ft_parse_flag(str, var);
				ft_get_type_and_flag(str, var, dec);
				var->ignr_zero = 0;
			}
			else
				return (-1);
		}
		(var->pos)++;
	}
	ft_putstr(var->result_s);
	return (ft_strlen(var->result_s));
}
