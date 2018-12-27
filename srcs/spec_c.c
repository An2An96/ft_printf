/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 21:42:58 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(void *value, t_spec *spec, int *len)
{
	int	i;

	i = 0;
	if (CHECK_FLAG(FLAG_MINUS))
	{
		ft_putchar(*((char*)value));
		while (++i < spec->width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < spec->width)
			ft_putchar(CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
		ft_putchar(*((char*)value));
	}
	*len += spec->width > 1 ? spec->width : 1;
	return (1);
}
