/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:55:39 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 18:54:52 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_value(void *value, t_spec *spec)
{
	char	*res;

	if (*((int*)value) != 0 || spec->accuracy != 0)
	{
		if (spec->size == SIZE_l)
			res = ft_uitoa_base(*((unsigned long*)value), 10);
		else if (spec->size == SIZE_ll)
			res = ft_uitoa_base(*((unsigned long long*)value), 10);
		else if (spec->size == SIZE_z)
			res = ft_uitoa_base(*((ssize_t*)value), 10);
		else
			res = ft_uitoa_base(*((unsigned int*)value), 10);
		ft_str_fixlen(&res, '0', spec->accuracy, 0);
	}
	else
		res = ft_strnew(0);
	return (res);
}

int		print_unsigned(void *value, t_spec *spec, int *len)
{
	int		tmp;
	char	*res;

	res = get_value(value, spec);
	if (!res)
		return (0);
	tmp = ft_strlen(res);
	if (spec->flags & FLAG_MINUS)
		tmp = ft_str_fixlen(&res, ' ',
			spec->width, spec->flags & FLAG_MINUS);
	else if (spec->accuracy == -1 && CHECK_FLAG(FLAG_ZERO))
		tmp = ft_str_fixlen(&res, '0', spec->width, 0);
	else
		tmp = ft_str_fixlen(&res, ' ', spec->width, 0);
	ft_putstr(res);
	free(res);
	*len += tmp;
	return (1);
}
