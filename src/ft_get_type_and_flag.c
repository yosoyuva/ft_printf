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

/* Isoler le cas ou var->tmpindex == 1 pour ne jamais calculer sa taille et eviter un READ access*/

char  *ft_get_type_and_flag(const char *str, t_fpt *var, t_dec *dec)
{
  char  *s;
  char  *min;
  int   size_arg;
//  char  *tmp;
  //char  *copy;

  var->tmpindex = find_index(var->tabindex, str[var->pos]);
//  min = ft_strnew_space(flag->digit);
  s = dec->tabfunction[var->tmpindex] (var);
  //s = copy;
  if (s == NULL)
    return (NULL);
  min = ft_strnew(1);
  size_arg = ft_strlen(s);
  if (var->tmpindex == 1)
  {

  }
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s, zero = %d\n", flag->prc, size_arg, flag->digit, flag->minus, s, flag->zero);
  if((var->prc > size_arg || (var->prc == size_arg && s[0] == '-'))  && (var->tmpindex < 8 && var->tmpindex > 2))
  {
    if (var->tmpindex == 3 && s[0] == '0')
      ft_memset(s, 0, size_arg);
    if (s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2))
    {
      //  result_s = ft_add_c_to_end_of_s(result_s, '-');
        min = ft_strnew_zero_f(min, var->prc - ft_strlen(s));
      //  ft_strcpy_wout_frst_c(s, s);
    }
    else
      min = ft_strnew_zero_f(min, var->prc - ft_strlen(s) - 1);
  //  printf("s de prc = %s\n", s);
  /*  s = ft_strjoin(min, s); */
  //  printf("min de prc = %s\n", min);
//    size_arg = ft_strlen(min) + size_arg;
    if (s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2))
      s = ft_strcpy_from_pos_f(s, ft_strjoin_ft(min, ft_strcpy_wout_frst_c(s)), 1);
  //    ft_strcpy_from_pos(ft_strjoin(min, ft_strcpy_wout_frst_c(s, s)), 1);
    else
       s = ft_strjoin_ft(min, s);
//    printf("s prc = %s\n", s);
  }
  else if (var->prc < size_arg && var->tmpindex == 1 && var->prc > -1)
      s = ft_strndup_fo(s, var->prc);
  else if (var->prc == 0 && (var->tmpindex < 8 && var->tmpindex > 2) && s[0] == '0')
  {
    ft_memset(s, 0, size_arg);
    size_arg = 0;
  }
  else if(var->zero > size_arg /*|| (flag->zero == size_arg && s[0] == '-')*/)
  {
//    printf("zero\n");
    if (s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2))
    {
        var->result_s = ft_add_c_to_end_of_s(var->result_s, '-');
        min = ft_strnew_zero_f(min, var->zero - size_arg - 1);
        s = ft_strcpy_wout_frst_c_f(s);
    }
    else
    { /* ICI cas special si tmpindex == 1 (donc ft_printf_s) */
      min = ft_strnew_zero_f(min, var->zero - size_arg - 1);
    }
    s = ft_strjoin_ft(min, s);
  //  printf("s de zero = %s\n", s);
  }
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s\n", flag->prc, size_arg, flag->digit, flag->minus, s);
  if(var->digit > (int)ft_strlen(s))
  {
  //  printf("digit\n");
      size_arg = ft_strlen(s);
      /* do the substraction between flag->digit and size of the result of tabfunction */
      /* and fil the diff with space in the start and strjoin to result_s */
      /*min = dec.tabFunction[dec.tmpindex] (&list, str, &i, &flag);
      min = ft_strjoin(ft_strnew_space(flag->digit - size_arg), min);
      result_s = ft_strjoin(result_s, min);*/
      //if (flag->ignr_zero == 1 && )
      if (s[0] == '-' && (var->tmpindex < 8 && var->tmpindex > 2) && var->ignr_zero == 1 && var->prc < 0 && var->zero_was_ignrd == 1)
      {
          var->result_s = ft_add_c_to_end_of_s(var->result_s, '-');
          s = ft_strcpy_wout_frst_c_f(s);
      }
      if (var->ignr_zero == 1 && var->prc < 0 && var->zero_was_ignrd == 1)
      {
    //    printf("digit to zero\n");
          min = ft_strnew_zero_f(min, var->digit - size_arg - 1);
      }
      else
        min = ft_strnew_space_f(min, var->digit - size_arg - 1);
      var->result_s = ft_strjoin_fo(var->result_s, min);
  //    printf("min de digit = %s\n", min);
  //    printf("s de prc = %s\n", s);
  }
  var->result_s = ft_strjoin_fo(var->result_s, s);
//  printf("prc = %d, arg = %d, digit = %d, minus = %d, s = %s\n", flag->prc, size_arg, flag->digit, flag->minus, s);
  if (var->minus > (int)ft_strlen(s) || (var->minus == (int)ft_strlen(s) && s[0] == 0 && var->minus > 0))
  {
    //printf("min********\n");
    if (var->minus == (int)ft_strlen(s) && s[0] == 0)
      min = ft_strnew_space_f(min, var->minus - ft_strlen(s));
    else
      min = ft_strnew_space_f(min, var->minus - ft_strlen(s) - 1);
    var->result_s = ft_strjoin_fo(var->result_s, min);
  }
  //if (min)
    free(min);
    free(s);
  //free(copy);
  return (var->result_s);
}
