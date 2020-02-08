/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:08:06 by ymehdi            #+#    #+#             */
/*   Updated: 2019/04/09 20:20:00 by ymehdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (s)
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
}