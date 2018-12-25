/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 21:02:13 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_uitoa_base(unsigned long long n, int base)
{
	unsigned long long	unsig_n;
	int			discharges;
	char		*res;
	char		sign;

	sign = (n < 0);
	discharges = sign + 1;
	unsig_n = ABS(n);
	while ((n /= base))
		discharges++;
	res = ft_strnew(discharges);
	if (res)
	{
		while (discharges > sign)
		{
			n = unsig_n % base;
			res[--discharges] = n + ((n < 10) ? '0' : 'A' - 10);
			unsig_n /= base;
		}
		if (sign)
			res[--discharges] = '-';
	}
	return (res);
}

int	print_hex(void *value, t_spec spec)
{
	char	*res;
	int		len;

	res = NULL;
	if (spec.size == SIZE_l)
		res = ft_uitoa_base(*((unsigned long*)value), 16);
	else if (spec.size == SIZE_l)
		res = ft_uitoa_base(*((unsigned long long*)value), 16);
	else
		res = ft_uitoa_base(*((unsigned int*)value), 16);
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
		len = spec.width;
	}
	else
	{
		if (spec.flags & FLAG_OCTOP)
			ft_putstr("0X");
		ft_putstr(res);
	}
	ft_strdel(&res);
	return (len + (2 * spec.flags & FLAG_OCTOP));
}

int	print_hex_lower(void *value, t_spec spec)
{
	char	*res;
	int		len;

	res = NULL;
	if (spec.size == SIZE_l)
		res = ft_strlower(ft_uitoa_base(*((unsigned long*)value), 16));
	else if (spec.size == SIZE_l)
		res = ft_strlower(ft_uitoa_base(*((unsigned long long*)value), 16));
	else
		res = ft_strlower(ft_uitoa_base(*((unsigned int*)value), 16));
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
		len = spec.width;
	}
	else
	{
		if (spec.flags & FLAG_OCTOP)
			ft_putstr("0x");
		ft_putstr(res);
	}
	return (len + (2 * spec.flags & FLAG_OCTOP));
}
