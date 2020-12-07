/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:44:31 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/07 15:40:22 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_get_type_and_flag(const char *str, t_fpt *var, t_dec *dec)
{
	var->tmpindex = find_index(var->tabindex, str[var->pos]);
	var->s = dec->tabfunction[var->tmpindex](var);
	if (var->s == NULL)
		var->s = ft_strdup("(null)");
	var->min = ft_strnew(1);
/* cas spec l'arg est un \0 (%c) */
	if (var->tmpindex == 0 && var->s[0] == 0)
	{
		ft_putstr(var->result_s);
		ft_printf_c_bin(var);
		free(var->result_s);
		var->result_s = ft_strdup("");
		free(var->s);
		free(var->min);
		return (NULL);
	}
	if (var->tmpindex == 0)
		var->size_arg = 1;
	else
		var->size_arg = ft_strlen(var->s);
	if (ft_get_type_and_flag_a(var))
		var->zero = var->zero;
	else if (var->prc < var->size_arg && var->tmpindex == 1 && var->prc > -1)
		var->s = ft_strndup_fo(var->s, var->prc);
	else if (ft_get_type_and_flag_b(var))
		var->zero = var->zero;
	else if (ft_get_type_and_flag_c(var))
		var->zero = var->zero;
	ft_get_type_and_flag_d(var);
	var->result_s = ft_strjoin_fo(var->result_s, var->s);
	ft_get_type_and_flag_e(var);
	free(var->min);
	free(var->s);
	return (var->result_s);
}
