/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:38 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:17:35 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_p(va_list *ap, const char *format, int *red, t_flag *flag)
{
  char  *s;

  s = ft_strnew(1);
  s = ft_strjoin("0x", ft_itoa_hex_long(va_arg(*ap,long int)));
  return(s);
  //return(ft_itoa_hex_long(va_arg(*ap, long int)));
}
