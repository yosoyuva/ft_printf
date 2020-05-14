/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:07:46 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:20:43 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_get_zero(const char *str, int *i, t_flag *flag)
{
  int n;

  n = 0;
  while(ft_isdigit(str[*i]))
  {
    n = n * 10 + (str[*i] - 48);
    (*i)++;
  }
  flag->zero = n;
}

void	ft_get_minus(const char *str, int *i, t_flag *flag)
{
  int n;

  n = 0;
  while(ft_isdigit(str[*i]))
  {
    n = n * 10 + (str[*i] - 48);
    (*i)++;
  }
  flag->minus = n;
}

void	ft_get_digit(const char *str, int *i, t_flag *flag)
{
  int n;

  n = 0;
  while(ft_isdigit(str[*i]))
  {
    n = n * 10 + (str[*i] - 48);
    (*i)++;
  }
  flag->digit = n /* - la taille de l'arguement */ ;
}

void    ft_get_star(const char *str, int *i, t_flag *flag, va_list *ap)
{
  flag->digit = va_arg(*ap, long int);
  (*i)++;
}

/*char  *ft_write_zero(t_flag *flag, char *result_s)
{
  char  *s;
  int   i;

  i = 0;
  if (flag->zero)
  {
    s = ft_strnew(ft_strlen(result_s) + flag->zero + 1);
    ft_strcpy(s, result_s);
    s[ft_strlen(result_s) + flag->zero] = '\0';
    while (s[ft_strlen(reslut_s) + i])
    {
      s[ft_strlen(reslut_s) + i] = '0';
      i++;
    }
  }*/
  /*
  else if (flag->digit)
  {
    s = ft_strnew(ft_strlen(result_s) + flag->digit + 1);
    ft_strcpy(s, result_s);
    s[ft_strlen(reslut_s) + flag->digit] = '\0';
    while (s[ft_strlen(reslut_s) + i])
    {
      s[ft_strlen(reslut_s) + i] = ' ';
      i++;
    }
  }*/
//}
