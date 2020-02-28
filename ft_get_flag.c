/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:07:46 by ymehdi            #+#    #+#             */
/*   Updated: 2020/02/27 14:54:54 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char  *ft_write_zero(t_list flag, char *result_s)
{
  char  *s;
  int   i;

  i = 0;
  if (flag->zero)
  {
    s = ft_strnew(ft_strlen(result_s) + flag->zero + 1);
    ft_strcpy(s, result_s);
    s[ft_strlen(reslut_s) + flag->zero] = '\0';
    while (s[ft_strlen(reslut_s) + i])
    {
      s[ft_strlen(reslut_s) + i] = '0';
      i++;
    }
  }
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
}
