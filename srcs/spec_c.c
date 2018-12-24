/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/24 19:25:45 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(void *value, t_spec spec)
{
	/* 
		+ не обрабатывать флаги кроме FLAG_MINUS
		+ не обрабатывать accuracy
		- не обрабатывать размер кроме l
	*/
	char *res;

	if (spec.flags & FLAG_MINUS)
	{
		spec.width = spec.width <= 0 ? 1 : spec.width;
		res = ft_strnew(spec.width);
		if (res)
		{
			res[0] = *((char*)value);
			ft_memset(res + 1, ' ', spec.width - 1);
			ft_putstr(res);
		}
	}
	else
		ft_putchar(*((char*)value));
}
