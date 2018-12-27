/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 14:30:18 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_extend_itoa(long long n, int discharges, int need_sign)
{
	long long	unsig_n;
	int			tmp;
	char		*res;
	char		sign;

	sign = (n < 0);
	tmp = 1;
	unsig_n = n;
	while ((n /= 10))
		tmp++;
	discharges = discharges > tmp ? discharges : tmp;
	discharges += (sign || need_sign);
	res = ft_strnew(discharges);
	if (res)
	{
		while (discharges)
		{
			n = unsig_n % 10;
			res[--discharges] = ABS(n) + '0';
			unsig_n /= 10;
		}
		if (sign || need_sign)
			res[0] = sign ? '-' : '+';
	}
	return (res);
}

static char	*get_value(void *value, t_spec *spec)
{
	if (spec->accuracy || *((long long*)value))
	{
		if (spec->size == SIZE_l)
			return (ft_extend_itoa(
				*((long*)value), spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_ll)
			return (ft_extend_itoa(
				*((long long*)value), spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_h)
			return (ft_extend_itoa(
				*((short int*)value), spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_hh)
			return (ft_extend_itoa(
				*((signed char*)value), spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_z)
			return (ft_extend_itoa(
				*((ssize_t*)value), spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else
			return (ft_extend_itoa(
				*((int*)value), spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
	}
	return (ft_strnew(0));
}

int			print_number(void *value, t_spec *spec)
{
	char	*res;
	int		len;

	if (spec->accuracy == -1
		&& CHECK_FLAG(FLAG_ZERO) && !CHECK_FLAG(FLAG_MINUS))
	{
		if (*((long long*)value) < 0 || CHECK_FLAG(FLAG_PLUS))
			spec->width--;
		spec->accuracy = spec->accuracy > spec->width ?
			spec->accuracy : spec->width;
		spec->width = 0;
	}
	res = get_value(value, spec);
	if (!res)
		return (-1);
	len = ft_str_fixlen(&res, ' ', spec->width, CHECK_FLAG(FLAG_MINUS));
	if (!spec->width && spec->flags == FLAG_SPACE && *((long long*)value) > 0)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putstr(res);
	free(res);
	return (len);
}
