/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 18:52:23 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_s(va_list *ap, t_flag *flag)
{
  char  *s;
  size_t size;
  char *str;

  if (flag->zero)
  {}
  str = va_arg(*ap, char *);
  size = ft_strlen(str);
  printf("size = %zu\n", size);
  s = ft_strnew(size);
  s = ft_strcpy(s, str);
  return (s);
}
