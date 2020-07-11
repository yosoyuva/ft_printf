/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:44:31 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/30 21:46:59 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char  *ft_get_type_and_flag(t_flag *flag, va_list *list, char *result_s, t_declare *dec)
{
  char  *s;
  char  *min;
  int   size_arg;

  s = ft_strnew(1);
//  s = dec->tab_function[dec->tmp_index] (list, flag);
  s = ft_strjoin_free(s, dec->tab_function[dec->tmp_index] (list, flag));
  size_arg = ft_strlen(s);
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s, zero = %d\n", flag->prc, size_arg, flag->digit, flag->minus, s, flag->zero);
  if((flag->prc > size_arg || (flag->prc == size_arg && s[0] == '-'))  && (dec->tmp_index < 8 && dec->tmp_index > 2))
  {
    if (dec->tmp_index == 3 && s[0] == '0')
      ft_memset(s, 0, size_arg);
    if (s[0] == '-' && (dec->tmp_index < 8 && dec->tmp_index > 2))
    {
      //  result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero(flag->prc - ft_strlen(s));
      //  ft_strcpy_wout_frst_c(s, s);
    }
    else
      min = ft_strnew_zero(flag->prc - ft_strlen(s) - 1);
    if (s[0] == '-' && (dec->tmp_index < 8 && dec->tmp_index > 2))
      s = ft_strcpy_from_pos(s, ft_strjoin(min, ft_strcpy_wout_frst_c_nofree(s)), 1);
    else
       s = ft_strjoin_free_last(min, s);
  }
  else if (flag->prc < size_arg && dec->tmp_index == 1 && flag->prc > -1)
      s = ft_strndup_free(s, flag->prc);
  else if (flag->prc == 0 && (dec->tmp_index < 8 && dec->tmp_index > 2) && s[0] == '0')
  {
    ft_memset(s, 0, size_arg);
    size_arg = 0;
  }
  else if(flag->zero > size_arg)
  {
    if (s[0] == '-' && (dec->tmp_index < 8 && dec->tmp_index > 2))
    {
        result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero(flag->zero - size_arg - 1);
        s = ft_strcpy_wout_frst_c(s);
    }
    else
      min = ft_strnew_zero(flag->zero - size_arg - 1);
    s = ft_strjoin_free_last(min, s);
  }
  if(flag->digit > (int)ft_strlen(s))
  {
  //  printf("digit\n");
      size_arg = ft_strlen(s);
      /* do the substraction between flag->digit and size of the result of tabfunction */
      /* and fil the diff with space in the start and strjoin to result_s */
      /*min = dec.tabFunction[dec.tmpIndex] (&list, str, &i, &flag);
      min = ft_strjoin(ft_strnew_space(flag->digit - size_arg), min);
      result_s = ft_strjoin(result_s, min);*/
      //if (flag->ignr_zero == 1 && )
      if (s[0] == '-' && (dec->tmp_index < 8 && dec->tmp_index > 2) && flag->ignr_zero == 1 && flag->prc < 0 && flag->zero_was_ignrd == 1)
      {
          result_s = ft_add_c_to_end_of_s(result_s, '-');
          s = ft_strcpy_wout_frst_c(s);
      }
      if (flag->ignr_zero == 1 && flag->prc < 0 && flag->zero_was_ignrd == 1)
      {
    //    printf("digit to zero\n");
          min = ft_strnew_zero(flag->digit - size_arg - 1);
      }
      else
        min = ft_strnew_space(flag->digit - size_arg - 1);
      result_s = ft_strjoin_free_first(result_s, min);
  }
  result_s = ft_strjoin_free_first(result_s, s);
  if (flag->minus > (int)ft_strlen(s) || (flag->minus == (int)ft_strlen(s) && s[0] == 0 && flag->minus > 0))
  {
    if (flag->minus == (int)ft_strlen(s) && s[0] == 0)
      min = ft_strnew_space(flag->minus - ft_strlen(s));
    else
      min = ft_strnew_space(flag->minus - ft_strlen(s) - 1);
    result_s = ft_strjoin_free_first(result_s, min);
  }
  free(s);
  if (min[0] == ' ' || min[0] == '0')
    free(min);
  return (result_s);
}
