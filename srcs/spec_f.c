/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 13:51:44 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_float(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		i;
	char	c;

	c = ' ';
	if (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO))
		c = '0';
	spec->accuracy = spec->accuracy == -1 ? 6 : spec->accuracy;
	if (spec->size == SIZE_L)
		res = ft_dtoa(va_arg(*ap, long double), spec->accuracy);
	else
		res = ft_dtoa(va_arg(*ap, double), spec->accuracy);
	if (!res)
		return (0);
	i = spec->width - ft_strlen(res);
	if (i > 0 && !CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
		ft_printchr(1, ' ');
	ft_putstr(res);
	if (i > 0 && CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	free(res);
	*len += (i > 0 ? spec->width : spec->width - i);
	return (1);
}
