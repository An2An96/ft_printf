/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:05:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_float(void *value, t_spec spec)
{
	double		d_value;
	long double ld_value;

	spec.accuracy = spec.accuracy > 0 ? spec.accuracy : 6;
	if (spec.size == SIZE_L)
	{
		ld_value = *((long double*)value);
		ft_putstr(ft_dtoa(ld_value, spec.accuracy));
	}
	else
	{
		d_value = *((double*)value);
		ft_putstr(ft_dtoa(d_value, spec.accuracy));
	}
	return (1);
}
