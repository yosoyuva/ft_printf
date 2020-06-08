/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/08 17:19:33 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int find_index(char *tabIndex, char c)
{
  int i;

  i = 0;
  while (tabIndex[i] != 0)
  {
    if (tabIndex[i] == c)
      return (i);
    else if (ft_isdigit(tabIndex[i]))
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
}

void	ft_parse_flag(const char *str, int *i, t_flag *flag, va_list *ap)
{
  while(str[*i] && is_flag(str[*i]))
  {
    if (str[*i] == '*')
    {
      ft_get_star(i, flag, ap, str);
    }
    else if (ft_isdigit(str[*i]) && (!(str[*i] == '0' && str[*i - 1] == '%') || flag->ignr_zero == 1))
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

int   ft_parsing(const char *str, va_list *list)
{
  char      *result_s;
  int       i;
  t_declare dec;
  t_flag    flag;

  i = 0;
  result_s = ft_strnew(1);
  ft_strcpy(dec.tabIndex, "cspdiuxX%-0.*");
  ft_funcpy(dec.tabFunction);
  flag.ignr_zero = 0;
  while (str[i] && i < (int)ft_strlen(str))
  {
    while (str[i] != '%' && str[i])
    {
      /* ajoute char lu a la fin de result_s */
      result_s = ft_add_c_to_end_of_s(result_s, str[i]);
      i++;
    }
  //  printf("i = %d\n", i);
    if (str[i] && str[i] == '%')
    {
    //  printf("i = %d\n", i);
      i++;
      if (ft_check(str, i, &flag))
      {
/* On analyse ce qu'il ya entre '%' et et le flag type */
        /*dec.tmpIndex = find_index(dec.tabIndex, str[i]);
        dec.tabFunction[dec.tmpIndex] (str, &i, &list, result_s);
        ft_parse_inner(str, &i, &list, result_s);*/
/* init all flags containers */
        ft_init_flag(&flag);
        ft_parse_flag(str, &i, &flag, list);
      //  ft_write_zero(&flag, result_s);
        result_s = ft_get_type_and_flag(str, &i, &flag, list, result_s, &dec);
        flag.ignr_zero = 0;
      }
      else
      {
        /* tout free */
        return (-1);
      }
    }
    i++;
  }
  /* On print le resultat finale */
  ft_putstr(result_s);
  return(ft_strlen(result_s));
}
