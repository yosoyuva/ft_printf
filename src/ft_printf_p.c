/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:38 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/10 22:05:59 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_p(va_list *ap, t_flag *flag)
{
  char  *s;
  char  *arg;
  char  nil[1];

  if (flag->zero)
  {}
  nil[0] = '0';
  s = ft_strnew(1);
  arg = ft_strnew(1);
  arg = ft_itoa_hex_long(va_arg(*ap,long int));
  if (!ft_strcmp(arg, nil))
  {
    return (arg);
  }
  else
    s = ft_strjoin("0x", arg);
  return(s);
  //return(ft_itoa_hex_long(va_arg(*ap, long int)));
}
