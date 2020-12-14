/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_flag_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:10:19 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/14 16:09:15 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_get_type_and_flag_a(t_fpt *var)
{
	if ((var->prc > var->size_arg || \
		(var->prc == var->size_arg && var->s[0] == '-')) && \
		(var->tmpindex < 8 && var->tmpindex > 2))
	{
		if (var->tmpindex == 3 && var->s[0] == '0')
			ft_memset(var->s, 0, var->size_arg);
		if (var->s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2))
			var->min = ft_strnew_zero_f(var->min, var->prc - ft_strlen(var->s));
		else
			var->min = ft_strnew_zero_f(var->min, \
				var->prc - ft_strlen(var->s) - 1);
		if (var->s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2))
			var->s = ft_strcpy_from_pos_f(var->s, \
				ft_strjoin_ft(var->min, ft_strcpy_wout_frst_c(var->s)), 1);
		else
			var->s = ft_strjoin_ft(var->min, var->s);
		return (1);
	}
	return (0);
}

int		ft_get_type_and_flag_b(t_fpt *var)
{
	if (var->prc == 0 && (var->tmpindex < 8 && var->tmpindex > 2) && \
	var->s[0] == '0')
	{
		ft_memset(var->s, 0, var->size_arg);
		var->size_arg = 0;
		return (1);
	}
	else if (var->prc == 0 && var->tmpindex == 2 && !ft_strcmp(var->s, "0x0"))
	{
		var->s[2] = '\0';
		return (1);
	}
	return (0);
}

int		ft_get_type_and_flag_c(t_fpt *var)
{
	if (var->zero > var->size_arg)
	{
		if (var->s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2))
		{
			var->result_s = ft_add_c_to_end_of_s(var->result_s, '-');
			var->min = ft_strnew_zero_f(var->min, \
				var->zero - var->size_arg - 1);
			var->s = ft_strcpy_wout_frst_c_f(var->s);
		}
		else
			var->min = ft_strnew_zero_f(var->min, \
				var->zero - var->size_arg - 1);
		var->s = ft_strjoin_ft(var->min, var->s);
		return (1);
	}
	return (0);
}

void	ft_get_type_and_flag_d(t_fpt *var)
{
	if (var->digit > (int)ft_strlen(var->s))
	{
		if (var->tmpindex == 0)
			var->size_arg = 1;
		else
			var->size_arg = ft_strlen(var->s);
		if (var->s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2) && \
		var->ignr_zero == 1 && var->prc < 0 && var->zero_was_ignrd == 1)
		{
			var->result_s = ft_add_c_to_end_of_s(var->result_s, '-');
			var->s = ft_strcpy_wout_frst_c_f(var->s);
		}
		if (var->ignr_zero == 1 && var->prc < 0 && var->zero_was_ignrd == 1)
			var->min = ft_strnew_zero_f(var->min, \
				var->digit - var->size_arg - 1);
		else
			var->min = ft_strnew_space_f(var->min, \
				var->digit - var->size_arg - 1);
		var->result_s = ft_strjoin_fo(var->result_s, var->min);
	}
}

void	ft_get_type_and_flag_e(t_fpt *var)
{
	if (var->minus > (int)ft_strlen(var->s) || \
	(var->minus == (int)ft_strlen(var->s) && var->s[0] == 0 && var->minus > 0))
	{
		if (var->minus == (int)ft_strlen(var->s) && var->s[0] == 0)
			var->min = ft_strnew_space_f(var->min, \
				var->minus - ft_strlen(var->s));
		else if (var->tmpindex == 0)
			var->min = ft_strnew_space_f(var->min, \
					var->minus - var->size_arg - 1);
		else
			var->min = ft_strnew_space_f(var->min, \
				var->minus - ft_strlen(var->s) - 1);
		var->result_s = ft_strjoin_fo(var->result_s, var->min);
	}
}
