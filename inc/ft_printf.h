/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:59:02 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/18 18:52:01 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../lib/libft.h"
# include <stdio.h>

typedef struct  s_flag
{
  int zero;
  int minus;
  int digit;
  int prc;
  int ignr_zero;
  int zero_was_ignrd;
}               t_flag;

typedef struct  s_declare
{
  char    tab_index[15];
  int     tmp_index;
  char    *(*tab_function[15]) (va_list *, t_flag *);
}               t_declare;

int ft_printf(const char *format, ...);
int find_index(char *tab_index, char c);
char  *ft_parse_inner(const char *str, int *i, va_list *list, char *result_s);
void	ft_init_flag(t_flag *flag);
void	ft_parse_flag(const char *str, int *i, t_flag *flag, va_list *ap);
int   ft_parsing(const char *str, va_list *list);
char  *ft_get_type_and_flag(const char *str, int *i, t_flag *flag, va_list *list, char *result_s, t_declare *dec);
void	ft_get_zero(const char *str, int *i, t_flag *flag);
void	ft_get_minus(const char *str, int *i, t_flag *flag);
void	ft_get_digit(const char *str, int *i, t_flag *flag);
char  *ft_write_zero(t_flag *flag, char *result_s);
int   is_flag(char c);
int   is_type(char c);
int   ft_check(const char *str, int i, t_flag *flag);
char	*ft_add_c_to_end_of_s(char *s, char c);
char	*ft_printf_c(va_list *ap, t_flag *flag);
char	*ft_printf_d(va_list *ap, t_flag *flag);
char	*ft_printf_s(va_list *ap, t_flag *flag);
char	*ft_printf_p(va_list *ap, t_flag *flag);
char	*ft_printf_u(va_list *ap, t_flag *flag);
char	*ft_printf_i(va_list *ap, t_flag *flag);
char	*ft_printf_xm(va_list *ap, t_flag *flag);
char	*ft_printf_x(va_list *ap, t_flag *flag);
char	*ft_printf_percent(va_list *ap, t_flag *flag);
void    *ft_funcpy(char *(*dst[13]) (va_list *, t_flag *));
void    ft_get_star(int *i, t_flag *flag, va_list *ap, const char *str);
void    ft_get_prc(const char *str, int *i, t_flag *flag);
#endif
