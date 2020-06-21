/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:54 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 12:38:21 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_x(va_list *ap, t_flag *flag)
{
  char  *s;

  s = ft_strnew(1);
  s = ft_strjoin_free_first(s, ft_itoa_hex_long(va_arg(*ap, unsigned int)));
  if (flag->zero)
  {}
  return(s);
}
