/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:59:02 by ymehdi            #+#    #+#             */
/*   Updated: 2020/12/02 13:50:52 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../lib/libft.h"
# include <stdio.h>

typedef struct	s_fpt
{
	int			zero;
	int			minus;
	int			digit;
	int			prc;
	int			ignr_zero;
	int			zero_was_ignrd;
	char		tabindex[15];
	int			tmpindex;
	va_list		list;
	int			result;
	char		*result_s;
	int			pos;
	int			size_arg;
	char		*s;
	char		*min;
}				t_fpt;

typedef struct	s_dec
{
	char		*(*tabfunction[15]) (t_fpt *);
}				t_dec;

int				ft_printf(const char *format, ...);
int				find_index(char *tabindex, char c);
char			*ft_parse_inner(const char *str, int *i, \
	va_list *list, char *result_s);
void			ft_init_flag(t_fpt *var);
void			ft_parse_flag(const char *str, t_fpt *var);
int				ft_parsing(const char *str, t_fpt *var, t_dec *dec);
char			*ft_get_type_and_flag(const char *str, t_fpt *var, t_dec *dec);
void			ft_get_zero(const char *str, t_fpt *var);
void			ft_get_minus(const char *str, t_fpt *var);
void			ft_get_digit(const char *str, t_fpt *var);
int				is_flag(char c);
int				is_type(char c);
int				ft_check(const char *str, t_fpt *var);
char			*ft_add_c_to_end_of_s(char *s, char c);
char			*ft_printf_c(t_fpt *var);
char			*ft_printf_d(t_fpt *var);
char			*ft_printf_s(t_fpt *var);
char			*ft_printf_p(t_fpt *var);
char			*ft_printf_u(t_fpt *var);
char			*ft_printf_i(t_fpt *var);
char			*ft_printf_xm(t_fpt *var);
char			*ft_printf_x(t_fpt *var);
char			*ft_printf_percent(t_fpt *var);
void			*ft_funcpy(char *(*dst[13]) (t_fpt *));
void			ft_get_star(t_fpt *var, const char *str);
void			ft_get_prc(const char *str, t_fpt *var);
void			ft_init_var(t_fpt *var);
int				ft_get_type_and_flag_a(t_fpt *var);
int				ft_get_type_and_flag_b(t_fpt *var);
int				ft_get_type_and_flag_c(t_fpt *var);
void			ft_get_type_and_flag_d(t_fpt *var);
void			ft_get_type_and_flag_e(t_fpt *var);

#endif
