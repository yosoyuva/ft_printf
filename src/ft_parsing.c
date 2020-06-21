/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/19 22:08:48 by ymehdi           ###   ########.fr       */
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

void	ft_parse_flag(const char *str, int *i, t_flag *flag, va_list *ap)
{
	while (str[*i] && is_flag(str[*i]))
	{
		if (str[*i] == '*')
		{
			ft_get_star(i, flag, ap, str);
		}
		else if (ft_isdigit(str[*i]) && (!(str[*i] == '0' \
			&& str[*i - 1] == '%') || flag->ignr_zero == 1))
			ft_get_digit(str, i, flag);
		else if (str[*i] == '0' && str[*i - 1] == '%' && flag->ignr_zero == 0)
		{
			(*i)++;
			ft_get_zero(str, i, flag);
		}
		else if (str[*i] == '.')
			ft_get_prc(str, i, flag);
		else if (str[*i] == '-')
		{
			(*i)++;
			ft_init_flag(flag);
			ft_get_minus(str, i, flag);
		}
	}
}

int	ft_parsing(const char *str, va_list *list)
{
	char		*result_s;
	int		i;
	t_declare	dec;
	t_flag		flag;

	i = 0;
	result_s = ft_strnew(1);
	ft_strcpy(dec.tab_index, "cspdiuxX%-0.*");
	ft_funcpy(dec.tab_function);
	flag.ignr_zero = 0;
	while (str[i] && i < (int)ft_strlen(str))
	{
		while (str[i] != '%' && str[i])
		{
			result_s = ft_add_c_to_end_of_s(result_s, str[i]);
			i++;
		}
		if (str[i] && str[i] == '%')
		{
			i++;
			if (ft_check(str, i, &flag))
			{
				ft_init_flag(&flag);
				ft_parse_flag(str, &i, &flag, list);
				result_s = ft_get_type_and_flag(str, &i, &flag, list, result_s, &dec);
				flag.ignr_zero = 0;
			}
			else
			{
				/* tout free */
				free(result_s);
				return (-1);
			}
		}
		i++;
	}
	/* On print le resultat finale */
	ft_putstr(result_s);
	i = ft_strlen(result_s);
	free(result_s);
	//return (ft_strlen(result_s));
	return (i);
}
