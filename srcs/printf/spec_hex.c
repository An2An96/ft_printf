/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:13:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(void *value, t_spec spec)
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
	return (ft_strlen(res));
}

int	print_hex_lower(void *value, t_spec spec)
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
	return (ft_strlen(res));
}
