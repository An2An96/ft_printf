/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:06:30 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 13:20:29 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_percent(va_list *ap, t_spec *spec, int *len)
{
	// char ch;

	(void)ap;
	// ch = '%';
	// return (print_char(&ch, spec, len));

	int	i;

	i = 0;
	if (CHECK_FLAG(FLAG_MINUS))
	{
		ft_putchar('%');
		while (++i < spec->width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < spec->width)
			ft_putchar(CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
		ft_putchar('%');
	}
	*len += spec->width > 1 ? spec->width : 1;
	return (1);
}
