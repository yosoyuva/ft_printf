/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_c_to_end_of_s.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:24:25 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/24 16:33:54 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_c_to_end_of_s(char *s, char c)
{
  char  *str;

  str = ft_strnew(ft_strlen(s) + 1);
  ft_strcpy(str, s);
  str[ft_strlen(s)] = c;
  return (str);
}
