/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:44:31 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:20:39 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char  *ft_get_type_and_flag(const char *str, int *i, t_flag *flag, va_list *list, char *result_s, t_declare *dec)
{
  char  *s;
  char  *min;
  int   size_arg;

  dec->tmpIndex = find_index(dec->tabIndex, str[*i]);
//  min = ft_strnew_space(flag->digit);
  s = dec->tabFunction[dec->tmpIndex] (list, str, i, flag);
  size_arg = ft_strlen(s);
  if(flag->digit > size_arg)
  {
      /* do the substraction between flag->digit and size of the result of tabfunction */
      /* and fil the diff with space in the start and strjoin to result_s */
      /*min = dec.tabFunction[dec.tmpIndex] (&list, str, &i, &flag);
      min = ft_strjoin(ft_strnew_space(flag->digit - size_arg), min);
      result_s = ft_strjoin(result_s, min);*/
      min = ft_strnew_space(flag->digit - size_arg - 1);
      result_s = ft_strjoin(result_s, min);
  }
  if(flag->zero > size_arg)
  {
    min = ft_strnew_zero(flag->zero - size_arg - 1);
    result_s = ft_strjoin(result_s, min);
  }
  result_s = ft_strjoin(result_s, s);
  if (flag->minus > size_arg)
  {
    min = ft_strnew_space(flag->digit - size_arg - 1);
    result_s = ft_strjoin(result_s, min);
  }
  return (result_s);
}
