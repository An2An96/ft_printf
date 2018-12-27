/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 14:01:15 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_float(void *value, t_spec *spec)
{
	char	*res;
	int		i;
	char	c;

	c = ' ';
	if (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO))
		c = '0';
	spec->accuracy = spec->accuracy > 0 ? spec->accuracy : 6;
	if (spec->size == SIZE_L)
		res = ft_dtoa(*((long double*)value), spec->accuracy);
	else
		res = ft_dtoa(*((double*)value), spec->accuracy);
	if (!res)
		return (-1);
	i = spec->width - ft_strlen(res);
	if (i > 0 && !CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
		ft_printchr(1, ' ');
	ft_putstr(res);
	if (i > 0 && CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	free(res);
	return (i > 0 ? spec->width : spec->width - i);
}
