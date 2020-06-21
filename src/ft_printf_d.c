/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 06:01:01 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/20 10:17:34 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_printf_d(va_list *ap, t_flag *flag)
{
  /* ** je pensais mettre le retour des itoa dans str puis le renvoyer afin d'eviter
  les probleme dans ft_strjoin_free_first (je fait un strcat sur string qui est sensé avoir un \0 ** */
  char *str;
  if (flag->zero)
  {}
  str = ft_strnew(1);
  str = ft_strjoin_free_first(str, ft_itoa(va_arg(*ap, int)));
  return (str);
//  return(ft_itoa(va_arg(*ap, int)));
}
