/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:52 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/08 01:36:07 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_declare
{
  va_list ap;
  int     red;
  char    tabIndex[14];
  //int     tmpIndex;
  void (*tabFunction[3]) (va_list *);
} t_declare;
int		ft_printf(const char *format, ...);

#endif
