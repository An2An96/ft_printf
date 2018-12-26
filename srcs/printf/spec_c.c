/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 16:30:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(void *value, t_spec spec)
{
	size_t	i;

	i = 0;
	if (spec.flags & FLAG_MINUS)
	{
		ft_putchar(*((char*)value));
		while (++i < spec.width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < spec.width)
			ft_putchar(' ');
		ft_putchar(*((char*)value));
	}
	return (spec.width > 1 ? spec.width : 1);
}
