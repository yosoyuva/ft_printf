/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:54 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:17:58 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_x(va_list *ap, const char *format, int *red, t_flag *flag)
{
  return(ft_itoa_hex(va_arg(*ap, int)));
}
