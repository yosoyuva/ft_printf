/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/30 21:48:39 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	find_index(char *tab_index, char c)
{
	int i;

	i = 0;
	while (tab_index[i] != 0)
	{
		if (tab_index[i] == c)
			return (i);
		else if (ft_isdigit(tab_index[i]))
			return (14);
		i++;
	}
	return (-1);
}

void	ft_init_flag(t_flag *flag)
{
	flag->zero = -1;
	flag->minus = -1;
	flag->digit = -1;
	flag->prc = -1;
	flag->zero_was_ignrd = 0;
}

int	ft_parsing(const char *str, va_list *list, t_declare *dec, t_flag *flag)
{
	char    *result_s;

	result_s = ft_strnew(1);
	dec->i = 0;
	ft_parse_pfunction(flag, dec);
	while (str[dec->i] && dec->i < (int)ft_strlen(str))
	{
		while (str[dec->i] != '%' && str[dec->i])
		{
			result_s = ft_add_c_to_end_of_s(result_s, str[dec->i]);
			(dec->i)++;
		}
		if (str[dec->i] && str[dec->i] == '%')
		{
			(dec->i)++;
			if (ft_check(str, dec, flag))
			{
				ft_parse_after_check(flag, dec, str, list);
				dec->tmp_index = find_index(dec->tab_index, str[dec->i]);
				ft_parse_after_check_two(flag, dec, list, result_s);
			}
			else
			{
				/* tout free */
				free(result_s);
				return (-1);
			}
		}
		(dec->i)++;
	}
	/* On print le resultat finale */
	ft_putstr(result_s);
	dec->i = ft_strlen(result_s);
	free(result_s);
	//return (ft_strlen(result_s));
	return (dec->i);
}
