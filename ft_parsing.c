/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/25 12:48:01 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int find_index(char *tabIndex, char c)
{
  int i;

  i = 0;
  while (tabIndex[i] != 0)
  {
    if (tabIndex[i] == c)
      return (i);
    else if (ft__isdegit(tabIndex[i])
      return (14);
    i++;
  }
  return (-1);
}

char  *ft_parse_inner(const char *str, int *i, va_list *list, char *result_s)
{
  char  *s;

  s = ft_strnew(ft_strlen(result_s) + 1);
  ft_strcpy(s, result_s);
  s[reslut_s] = '\0';
  return (s);
}

int   ft_parsing(const char *str, va_list list)
{
  char      *result_s;
  int       i;
  t_declare dec;

  i = 0;
  result_s = ft_strnew(1);
  ft_strcpy(dec.tabIndex, "cspdiuxX%-0.*");
  ft_funcpy(dec.tabFunction);
  while (str[i])
  {
    while (str[i] != '%' && str[i])
    {
      /* ajoute char lu a la fin de result_s */
      result_s = ft_add_c_to_end_of_s(result_s, str);
      i++;
    }
    if (str[i] && str[i] == '%')
    {
      i++;
      if (ft_check(str, i))
      {
        /* On analyse ce qu'il ya entre '%' et et le flag type */
        dec.tmpIndex = find_index(dec.tabIndex, str[i]);
        dec.tabFunction[dec.tmpIndex] (str, &i, &list, result_s);
        ft_parse_inner(str, &i, &list, result_s);
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
