/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:52 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 18:45:37 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flag
{
  int zero;
  int minus;
} t_flag;

typedef struct s_declare
{
  va_list ap;
  int     red;
  char    tabIndex[15];
  //char    tabFlag[4];
  int     tmpIndex;
  void (*tabFunction[15]) (va_list *, const char *, int *, t_flag *);
} t_declare;


int		ft_printf(const char *format, ...);
void	ft_printf_minus(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_zero(va_list *ap, const char *format, int *red, t_flag *flag);
#endif
