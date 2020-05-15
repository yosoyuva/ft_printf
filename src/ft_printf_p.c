/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:38 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/15 01:21:59 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_p(va_list *ap, t_flag *flag)
{
  char  *s;

  if (flag->zero)
  {}
  s = ft_strnew(1);
  s = ft_strjoin("0x", ft_itoa_hex_long(va_arg(*ap,long int)));
  return(s);
  //return(ft_itoa_hex_long(va_arg(*ap, long int)));
}
