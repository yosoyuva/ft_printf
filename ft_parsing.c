/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:10:30 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/24 18:56:24 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   ft_parsing(const char *str, va_list list)
{
  char  *result_s;
  int   i;

  i = 0;
  result_s = ft_strnew(1);
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
      }
      else
        return (-1);
    }
    i++;
  }
  /* On print le resultat finale */
  ft_putstr(result_s);
  return(ft_strlen(result_s));
}
