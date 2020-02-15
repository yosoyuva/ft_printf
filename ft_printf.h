/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:29:52 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/15 20:03:57 by ymehdi           ###   ########.fr       */
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
void	ft_printf_c(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_s(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_d(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_p(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_i(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_u(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_x(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_xm(va_list *ap, const char *format, int *red, t_flag *flag);
void	ft_printf_percent(va_list *ap, const char *format, int *red, t_flag *flag);
int   is_flg_conv(char c);
int   is_flg(char c);
void	ft_putnbr_hex(long long int n);
void	ft_putnbr_hexm(long long int n);
void	ft_putnbr_oct(long long int n);
void	ft_putnbr_u(unsigned int nbr);

#endif
