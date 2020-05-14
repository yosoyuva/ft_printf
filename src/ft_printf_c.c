/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:59:40 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:17:14 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_c(va_list *ap, const char *format, int *red, t_flag *flag)
{
  char  *c;

  c = ft_strnew(1);
  c = ft_add_c_to_end_of_s(c, va_arg(*ap, int));
  return (c);
}
