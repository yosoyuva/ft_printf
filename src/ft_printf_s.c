/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:00:16 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/03 18:42:41 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char  *get_arg_string(char *arg)
{
  char  *str;

  //ft_putstr(arg);
  if (arg == NULL)
    return (NULL);
  str = ft_calloc(ft_strlen(arg), sizeof(char *) + 1);
  str = ft_memcpy(str, arg, ft_strlen(arg));
  return (str);
}

char	*ft_printf_s(t_fpt *var)
{
  /*char  *s;
  char  *tmp;*/
  //char  *str;
//  int i;

  //str = ft_strnew(5000);

  //s = (char *)(va_arg(var->list, char *));
  if (var->zero)
  {}
  //tmp = ft_calloc(ft_strlen(s), sizeof(char *) + 1);
  //tmp = ft_memcpy(tmp, s, ft_strlen(s));
//  i = ft_strchr(s, '\0');
//  str = ft_strnew(5000);
//  str = ft_strcpy(str, (char *)s);
  return (get_arg_string(va_arg(var->list, char *)));
}
