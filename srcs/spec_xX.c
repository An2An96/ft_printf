/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_xX.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/24 19:28:38 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(void *value, t_spec spec)
{
	char *res;

	res = NULL;
	if (spec.size == SIZE_l)
	{
		res = ft_itoa_base(*((long*)value), 16);
	}
	else
	{
		res = ft_itoa_base(*((int*)value), 16);
	}
	ft_putstr(res);
}

void	print_hex_lower(void *value, t_spec spec)
{
	char *res;

	res = NULL;
	if (spec.size == SIZE_l)
	{
		res = ft_strlower(ft_itoa_base(*((long*)value), 16));
	}
	else
	{
		res = ft_strlower(ft_itoa_base(*((int*)value), 16));
	}
	ft_putstr(res);
}
