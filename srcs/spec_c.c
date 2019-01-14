/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:09:14 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 19:00:34 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_char(va_list *ap, t_spec *spec, int *len)
{
	int		i;
	wchar_t	ch;

	i = 0;
	if (spec->size == SIZE_l)
		ch = va_arg(*ap, wchar_t);
	else
		ch = va_arg(*ap, int);
	if (CHECK_FLAG(FLAG_MINUS))
	{
		ft_putchar(ch);
		while (++i < spec->width)
			ft_putchar(' ');
	}
	else
	{
		while (++i < spec->width)
			ft_putchar(CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
		ft_putchar(ch);
	}
	*len += spec->width > 1 ? spec->width : 1;
	return (1);
}

int	print_long_char(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_char(ap, spec, len));	
}
