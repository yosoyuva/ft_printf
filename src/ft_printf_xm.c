/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:03:49 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 12:39:07 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_xm(va_list *ap, t_flag *flag)
{
  char  *s;

  s = ft_strnew(1);
  s = ft_strjoin_free_first(s, ft_itoa_hex_m(va_arg(*ap, long int)));
  if (flag->zero)
  {}
  return(s);
}
