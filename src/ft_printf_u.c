/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:36 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 12:37:34 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_u(va_list *ap, t_flag *flag)
{
  char  *s;

  s = ft_strnew(1);
  s = ft_strjoin_free_first(s, ft_itoa_u(va_arg(*ap, unsigned int)));
  if (flag->zero)
  {}
  return(s);
}
