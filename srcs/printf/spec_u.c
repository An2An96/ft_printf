/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:55:39 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 12:25:28 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unsigned(void *value, t_spec *spec)
{
	int		len;
	char	*res;

	if (spec->size == SIZE_l)
		res = ft_uitoa_base(*((unsigned long*)value), 10);
	else if (spec->size == SIZE_ll)
		res = ft_uitoa_base(*((unsigned long long*)value), 10);
	else
		res = ft_uitoa_base(*((unsigned int*)value), 10);
	len = ft_str_fixlen(&res, '0', spec->accuracy, 0);
	len = ft_str_fixlen(&res,
		CHECK_FLAG(FLAG_ZERO) ? '0' : ' ', spec->width, CHECK_FLAG(FLAG_MINUS));
	ft_putstr(res);
	return (len);
}
