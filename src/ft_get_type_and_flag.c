/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:44:31 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/08 20:05:30 by ymehdi           ###   ########.fr       */
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
  s = dec->tabFunction[dec->tmpIndex] (list, flag);
  size_arg = ft_strlen(s);
//  printf("prc = %d, arg = %d, digit = %d\n", flag->prc, size_arg, flag->digit);
  if(flag->prc > size_arg /*|| (flag->prc == size_arg && s[0] == '-')*/)
  {
  /*  if (s[0] == '-')
    {
        result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero(flag->prc - size_arg);
        ft_strcpy_wout_frst_c(s, s);
    }
    else*/
      min = ft_strnew_zero(flag->prc - size_arg - 1);
    result_s = ft_strjoin(result_s, min);
  }
  else if (flag->prc < size_arg && dec->tmpIndex == 1 && flag->prc > -1)
      s = ft_strndup(s, flag->prc);
  else if (flag->prc == 0 && dec->tmpIndex == 3 && s[0] == '0')
    ft_memset(s, 0, size_arg);
  else if(flag->zero > size_arg /*|| (flag->zero == size_arg && s[0] == '-')*/)
  {
  /*  if (s[0] == '-')
    {
        result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero(flag->zero - size_arg);
        ft_strcpy_wout_frst_c(s, s);
    }
    else*/
    min = ft_strnew_zero(flag->zero - size_arg - 1);
    result_s = ft_strjoin(result_s, min);
  }
  if(flag->digit > (int)ft_strlen(s))
  {
      /* do the substraction between flag->digit and size of the result of tabfunction */
      /* and fil the diff with space in the start and strjoin to result_s */
      /*min = dec.tabFunction[dec.tmpIndex] (&list, str, &i, &flag);
      min = ft_strjoin(ft_strnew_space(flag->digit - size_arg), min);
      result_s = ft_strjoin(result_s, min);*/
      min = ft_strnew_space(flag->digit - ft_strlen(s) - 1);
      result_s = ft_strjoin(result_s, min);
  }
  result_s = ft_strjoin(result_s, s);
  if (flag->minus > (int)ft_strlen(s))
  {
    min = ft_strnew_space(flag->minus - ft_strlen(s) - 1);
    result_s = ft_strjoin(result_s, min);
  }
  return (result_s);
}
