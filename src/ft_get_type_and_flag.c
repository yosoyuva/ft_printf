/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type_and_flag.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:44:31 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/10 20:31:02 by ymehdi           ###   ########.fr       */
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
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s, zero = %d\n", flag->prc, size_arg, flag->digit, flag->minus, s, flag->zero);
  if((flag->prc > size_arg || (flag->prc == size_arg && s[0] == '-'))  && (dec->tmpIndex < 8 && dec->tmpIndex > 2))
  {
    if (dec->tmpIndex == 3 && s[0] == '0')
      ft_memset(s, 0, size_arg);
    if (s[0] == '-' && (dec->tmpIndex < 8 && dec->tmpIndex > 2))
    {
      //  result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero(flag->prc - ft_strlen(s));
      //  ft_strcpy_wout_frst_c(s, s);
    }
    else
      min = ft_strnew_zero(flag->prc - ft_strlen(s) - 1);
  //  printf("s de prc = %s\n", s);
  /*  s = ft_strjoin(min, s); */
  //  printf("min de prc = %s\n", min);
//    size_arg = ft_strlen(min) + size_arg;
    if (s[0] == '-' && (dec->tmpIndex < 8 && dec->tmpIndex > 2))
      s = ft_strcpy_from_pos(s, ft_strjoin(min, ft_strcpy_wout_frst_c(s)), 1);
  //    ft_strcpy_from_pos(ft_strjoin(min, ft_strcpy_wout_frst_c(s, s)), 1);
    else
       s = ft_strjoin(min, s);
//    printf("s prc = %s\n", s);
  }
  else if (flag->prc < size_arg && dec->tmpIndex == 1 && flag->prc > -1)
      s = ft_strndup(s, flag->prc);
  else if (flag->prc == 0 && (dec->tmpIndex < 8 && dec->tmpIndex > 2) && s[0] == '0')
  {
    ft_memset(s, 0, size_arg);
    size_arg = 0;
  }
  else if(flag->zero > size_arg /*|| (flag->zero == size_arg && s[0] == '-')*/)
  {
//    printf("zero\n");
    if (s[0] == '-' && (dec->tmpIndex < 8 && dec->tmpIndex > 2))
    {
        result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero(flag->zero - size_arg - 1);
        s = ft_strcpy_wout_frst_c(s);
    }
    else
      min = ft_strnew_zero(flag->zero - size_arg - 1);
    s = ft_strjoin(min, s);
  //  printf("s de zero = %s\n", s);
  }
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s\n", flag->prc, size_arg, flag->digit, flag->minus, s);
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
      if (s[0] == '-' && (dec->tmpIndex < 8 && dec->tmpIndex > 2) && flag->ignr_zero == 1 && flag->prc < 0 && flag->zero_was_ignrd == 1)
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
      result_s = ft_strjoin(result_s, min);
  //    printf("min de digit = %s\n", min);
  //    printf("s de prc = %s\n", s);
  }
  result_s = ft_strjoin(result_s, s);
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s\n", flag->prc, size_arg, flag->digit, flag->minus, s);
  if (flag->minus > (int)ft_strlen(s) || (flag->minus == (int)ft_strlen(s) && s[0] == 0 && flag->minus > 0))
  {
    //printf("min********\n");
    if (flag->minus == (int)ft_strlen(s) && s[0] == 0)
      min = ft_strnew_space(flag->minus - ft_strlen(s));
    else
      min = ft_strnew_space(flag->minus - ft_strlen(s) - 1);
    result_s = ft_strjoin(result_s, min);
  }
  return (result_s);
}
