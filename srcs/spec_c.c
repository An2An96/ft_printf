/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 13:23:04 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_char(va_list *ap, t_spec *spec, int *len)
{
	int	i;

	i = 0;
	if (CHECK_FLAG(FLAG_MINUS))
	{
		ft_putchar(va_arg(*ap, int));
		while (++i < spec->width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < spec->width)
			ft_putchar(CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
		ft_putchar(va_arg(*ap, int));
	}
	*len += spec->width > 1 ? spec->width : 1;
	return (1);
}
