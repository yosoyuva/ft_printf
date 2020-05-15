/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:04:28 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/15 01:23:24 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_percent(va_list *ap, t_flag *flag)
{
  char  *c;

  c = ft_strnew(1);
  if (ap[0])
  {}
  c = ft_add_c_to_end_of_s(c, '%');
  ft_init_flag(flag);
  return (c);
}
