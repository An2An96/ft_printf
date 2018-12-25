/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 19:11:01 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(void *value, t_spec spec)
{
	char	*res;
	int		len;

	res = NULL;
	if (spec.size == SIZE_l)
		res = ft_itoa_base(*((long*)value), 16);
	else
		res = ft_itoa_base(*((int*)value), 16);
	len = ft_strlen(res);
	if (spec.width > 1 && spec.width - len > 0)
	{
		if (spec.flags & FLAG_MINUS)
		{
			if (spec.flags & FLAG_OCTOP)
				ft_putstr("0X");
			ft_putstr(res);
			ft_printchr(spec.width - len, ' ');
		}
		else
		{
			ft_printchr(spec.width - len, ' ');
			if (spec.flags & FLAG_OCTOP)
				ft_putstr("0X");
			ft_putstr(res);
		}
	}
	else
	{
		if (spec.flags & FLAG_OCTOP)
			ft_putstr("0X");
		ft_putstr(res);
	}
	return (len > spec.width ? len : spec.width);
}

int	print_hex_lower(void *value, t_spec spec)
{
	char	*res;
	int		len;

	res = NULL;
	if (spec.size == SIZE_l)
		res = ft_strlower(ft_itoa_base(*((long*)value), 16));
	else
		res = ft_strlower(ft_itoa_base(*((int*)value), 16));
	len = ft_strlen(res);
	if (spec.width > 1 && spec.width - len > 0)
	{
		if (spec.flags & FLAG_MINUS)
		{
			if (spec.flags & FLAG_OCTOP)
				ft_putstr("0x");
			ft_putstr(res);
			ft_printchr(spec.width - len, ' ');
		}
		else
		{
			ft_printchr(spec.width - len, ' ');
			if (spec.flags & FLAG_OCTOP)
				ft_putstr("0x");
			ft_putstr(res);
		}
	}
	else
	{
		if (spec.flags & FLAG_OCTOP)
			ft_putstr("0x");
		ft_putstr(res);
	}
	return (len > spec.width ? len : spec.width);
}
