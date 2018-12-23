/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 18:03:29 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(void *value, char flags, int width, int accuracy, char size)
{
	/* 
		+ не обрабатывать флаги кроме FLAG_MINUS
		+ не обрабатывать accuracy
		- не обрабатывать размер кроме l
	*/
	char *res;

	if (flags & FLAG_MINUS)
	{
		width = width <= 0 ? 1 : width;
		res = ft_strnew(width);
		if (res)
		{
			res[0] = *((char*)value);
			ft_memset(res + 1, ' ', width - 1);
			ft_putstr(res);
		}
	}
	else
		ft_putchar(*((char*)value));
}
