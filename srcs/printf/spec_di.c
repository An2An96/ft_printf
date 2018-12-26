/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 17:17:09 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_number(void *value, t_spec spec)
{
	char	*res;
	int		len;

	if (spec.size == SIZE_l)
		res = ft_itoa(*((long*)value));
	else if (spec.size == SIZE_ll)
		res = ft_itoa(*((long long*)value));
	else
		res = ft_itoa(*((int*)value));
	len = ft_str_fixlen(&res, '0', spec.accuracy, 0);
	len = ft_str_fixlen(&res, spec.flags & FLAG_ZERO ? '0' : ' ',
		spec.width, spec.flags & FLAG_MINUS);
	ft_putstr(res);
	return (len);
}
