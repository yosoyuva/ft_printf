/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:41:11 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/09 17:07:38 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int   is_flag(char c)
{
  if (c == '-' || c == '.' || c == '0' || c == '*' || ft_isdigit(c))
    return (1);
  return (0);
}

int   is_type(char c)
{
  if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
    return (1);
  return (0);
}

int   ft_check(const char *str, int i, t_flag *flag)
{
  while (is_flag(str[i]) && str[i] && !is_type(str[i]))
  {
    if (str[i] == '.')
      flag->ignr_zero = 1;
    (i)++;
  }
  if (str[i] && is_type(str[i]))
    return (1);
  return (0);
}
