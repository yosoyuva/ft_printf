/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 05:59:40 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/25 17:35:19 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(char *str, int *i, va_list *list, char *result_s)
{
  char  c;

  c = va_arg(*list, int);
  result_s = ft_add_c_to_end_of_s(result_s, c);
}
