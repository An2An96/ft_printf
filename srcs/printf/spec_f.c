/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 12:24:09 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_float(void *value, t_spec *spec)
{
	char	*str;
	int		i;
	char	c;

	c = ' ';
	if (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO))
		c = '0';
	spec->accuracy = spec->accuracy > 0 ? spec->accuracy : 6;
	if (spec->size == SIZE_L)
		str = ft_dtoa(*((long double*)value), spec->accuracy);
	else
		str = ft_dtoa(*((double*)value), spec->accuracy);
	i = spec->width - ft_strlen(str);
	if (i > 0 && !CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
		ft_printchr(1, ' ');
	ft_putstr(str);
	if (i > 0 && CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	if (i > 0)
		return (spec->width);
	else
		return (spec->width - i);
}
