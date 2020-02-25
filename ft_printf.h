/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:59:02 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/25 12:10:34 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_flag
{
  int zero;
  int minus;
}               t_flag;

typedef struct  s_declare
{
  char    tabIndex[15];
  int     tmpIndex;
  void (*tabFunction[15]) (va_list *, const char *, int *, t_flag *);
}               t_declare

int ft_printf(const char *, ...);
void    *ft_funcpy(void (*dst[13]) (va_list *, const char *, int *, t_flag *));
int   is_flag(char c);
int   is_type(char c);
int   ft_check(char *str, int i);
int   ft_parsing(const char *str, va_list list);

#endif
