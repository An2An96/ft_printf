/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:54:16 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_float(void *value, t_spec spec)
{
	char	*str;
	int		i;
	char	c;

	c = spec.flags & FLAG_ZERO ? '0' : ' ';
	spec.accuracy = spec.accuracy > 0 ? spec.accuracy : 6;
	if (spec.size == SIZE_L)
		str = ft_dtoa(*((long double*)value), spec.accuracy);
	else
		str = ft_dtoa(*((double*)value), spec.accuracy);
	i = spec.width - ft_strlen(str);
	if (i > 0 && !(spec.flags & FLAG_MINUS))
		ft_printchr(i, c);
	ft_putstr(str);
	if (i > 0 && (spec.flags & FLAG_MINUS))
		ft_printchr(i, c);
	if (i > 0)
		return (spec.width);
	else
		return (spec.width - i);
}
