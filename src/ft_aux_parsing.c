/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 20:23:09 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/30 21:46:42 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_parse_flag(const char *str, t_declare *dec, t_flag *flag, va_list *ap)
{
	while (str[dec->i] && is_flag(str[dec->i]))
	{
		if (str[dec->i] == '*')
		{
			ft_get_star(dec, flag, ap, str);
		}
		else if (ft_isdigit(str[dec->i]) && (!(str[dec->i] == '0' \
			&& str[dec->i - 1] == '%') || flag->ignr_zero == 1))
			ft_get_digit(str, dec, flag);
		else if (str[dec->i] == '0' && str[dec->i - 1] == '%' && flag->ignr_zero == 0)
		{
			(dec->i)++;
			ft_get_zero(str, dec, flag);
		}
		else if (str[dec->i] == '.')
			ft_get_prc(str, dec, flag);
		else if (str[dec->i] == '-')
		{
			(dec->i)++;
			ft_init_flag(flag);
			ft_get_minus(str, dec, flag);
		}
	}
}

void ft_parse_pfunction(t_flag *flag, t_declare *dec)
{
  ft_strcpy(dec->tab_index, "cspdiuxX%-0.*");
  ft_funcpy(dec->tab_function);
  flag->ignr_zero = 0;
}

void ft_parse_after_check(t_flag *flag, t_declare *dec, const char *str,
  va_list *list)
{
  ft_init_flag(flag);
  ft_parse_flag(str, dec, flag, list);
}

void ft_parse_after_check_two(t_flag *flag, t_declare *dec, va_list *list,
  char *result_s)
{
  result_s = ft_get_type_and_flag(flag, list, result_s, dec);
  flag->ignr_zero = 0;
}
