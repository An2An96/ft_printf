/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:55:39 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 17:11:06 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unsigned(void *value, t_spec spec)
{
	int len;
	char *res;

	if (spec.size == SIZE_l)
		res = ft_uitoa_base(*((unsigned long*)value), 10);
	else if (spec.size == SIZE_ll)
		res = ft_uitoa_base(*((unsigned long long*)value), 10);
	else
		res = ft_uitoa_base(*((unsigned int*)value), 10);
	len = ft_str_fixlen(&res, '0', spec.accuracy, 0);
	len = ft_str_fixlen(&res, spec.flags & FLAG_ZERO ? '0' : ' ', spec.width, spec.flags & FLAG_MINUS);
	ft_putstr(res);
	return (len);
}
