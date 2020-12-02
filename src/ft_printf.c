/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <ymehdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:00:13 by ymehdi            #+#    #+#             */
/*   Updated: 2020/05/14 15:33:52 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_fpt fpt;
	t_dec dec;

	ft_init_var(&fpt);
	va_start(fpt.list, format);
	fpt.result = ft_parsing(format, &fpt, &dec);
	va_end(fpt.list);
	free(fpt.result_s);
	return (fpt.result);
}
