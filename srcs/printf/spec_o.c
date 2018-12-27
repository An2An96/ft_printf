/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:28:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 12:29:48 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_value(void *value, t_spec *spec)
{
	char	*res;

	if (*((int*)value) != 0 || spec->accuracy != 0)
	{
		if (spec->size == SIZE_l)
			res = ft_uitoa_base(*((unsigned long*)value), 8);
		else if (spec->size == SIZE_ll)
			res = ft_uitoa_base(*((unsigned long long*)value), 8);
		else
			res = ft_uitoa_base(*((unsigned int*)value), 8);
		ft_str_fixlen(&res, '0', spec->accuracy, 0);
	}
	else
		res = ft_strnew(0);
	return (res);
}

int			print_octal(void *value, t_spec *spec)
{
	int		len;
	char	*res;

	res = get_value(value, spec);
	len = ft_strlen(res);
	if (res[0] != '0' && spec->flags & FLAG_OCTOP)
	{
		value = ft_strjoin("0", res);
		free(res);
		res = value;
	}
	if (spec->flags & FLAG_MINUS)
		len = ft_str_fixlen(&res, ' ',
			spec->width, spec->flags & FLAG_MINUS);
	else
		len = ft_str_fixlen(&res, spec->flags & FLAG_ZERO ? '0' : ' ',
			spec->width, 0);
	ft_putstr(res);
	free(res);
	return (len);
}
