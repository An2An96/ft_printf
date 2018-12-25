/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:04:59 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(void *value, t_spec spec)
{
	char *res;

	if (spec.width > 1)
	{
		res = ft_strnew(spec.width);
		if (res)
		{
			if (spec.flags & FLAG_MINUS)
			{
				res[0] = *((char*)value);
				ft_memset(res + 1, ' ', spec.width - 1);
			}
			else
			{
				res[spec.width - 1] = *((char*)value);
				ft_memset(res, ' ', spec.width - 1);
			}
			ft_putstr(res);
		}
		return (spec.width);
	}
	else
		ft_putchar(*((char*)value));
	return (1);
}
