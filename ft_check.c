/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:41:11 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/24 19:08:33 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   is_flag(char c)
{
  if (c == '-' || c == '.' || c == '0' || c == '*' || ft_isdigit(ft_atoi(c)))
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

int   ft_check(char *str, int i)
{
  while (is_flag(str[i]) && str[i] && !is_type(str[i]))
    (i)++;
  if (str[i] && is_type(str[i]))
    return (1);
  return (0);
}
