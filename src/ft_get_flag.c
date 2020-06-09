/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:07:46 by ymehdi            #+#    #+#             */
/*   Updated: 2020/06/09 17:19:51 by ymehdi           ###   ########.fr       */
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
  if (str[*i] == '0')
    flag->zero_was_ignrd = 1;
  while(ft_isdigit(str[*i]))
  {
    n = n * 10 + (str[*i] - 48);
    (*i)++;
  }
//  printf("n = %d", n);
  flag->digit = n /* - la taille de l'arguement */ ;
}

void    ft_get_star(int *i, t_flag *flag, va_list *ap, const char *str)
{
  int arg;

  arg = va_arg(*ap, long int);
  if (str[*i - 1] == '.' || flag->prc > -1)
    flag->prc = arg;
  else if (str[*i - 1] == '-' || flag->minus > -1 || arg < 0)
  {
    if (arg < 0)
      flag->minus = -1 * arg;
    else
      flag->minus = arg;
  }
  else if ((str[*i - 1] == '0' || flag->zero > -1) && flag->ignr_zero == 0)
    flag->zero = arg;
  else
    flag->digit = arg;
  (*i)++;
}

void	ft_get_prc(const char *str, int *i, t_flag *flag)
{
  int n;

  (*i)++;
  n = 0;
  while(ft_isdigit(str[*i]))
  {
    n = n * 10 + (str[*i] - 48);
    (*i)++;
  }
  flag->prc = n;
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
