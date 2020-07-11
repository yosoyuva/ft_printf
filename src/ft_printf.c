/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:00:13 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/30 21:49:16 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int ft_printf(const char *format, ...)
{
  va_list list;
  int     result;
  t_declare dec;
  t_flag    flag;

/* start reading the first arg */
  va_start(list, format);
/* parsing args */
  result = ft_parsing(format, &list, &dec, &flag);
/* close reading arg */
  va_end(list);
  return (result);
}
