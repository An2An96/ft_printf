/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 14:28:14 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

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

static char	*get_value(intmax_t value, t_spec *spec)
{
	if (value || spec->accuracy)
	{
		if (spec->size == SIZE_l)
			return (ft_extend_itoa(
				(long)value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_ll)
			return (ft_extend_itoa(
				(long long)value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_h)
			return (ft_extend_itoa(
				(short int)value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_hh)
			return (ft_extend_itoa(
				(signed char)value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_j)
			return (ft_extend_itoa(
				value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else if (spec->size == SIZE_z)
			return (ft_extend_itoa(
				(size_t)value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
		else
			return (ft_extend_itoa(
				(int)value, spec->accuracy, CHECK_FLAG(FLAG_PLUS)));
	}
	return (ft_strnew(0));
}

int			print_number(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		tmp;
	intmax_t value;

	value = va_arg(*ap, intmax_t);
	if (spec->accuracy == -1
		&& CHECK_FLAG(FLAG_ZERO) && !CHECK_FLAG(FLAG_MINUS))
	{
		if (value < 0 || CHECK_FLAG(FLAG_PLUS))
			spec->width--;
		spec->accuracy = spec->accuracy > spec->width ? spec->accuracy
			: spec->width - (CHECK_FLAG(FLAG_SPACE) && !CHECK_FLAG(FLAG_PLUS));
		spec->width = 0;
	}
	if ((res = get_value(value, spec)) == 0)
		return (0);
	tmp = ft_str_fixlen(&res, ' ', spec->width, CHECK_FLAG(FLAG_MINUS));
	if (!spec->width && CHECK_FLAG(FLAG_SPACE)
		&& !CHECK_FLAG(FLAG_PLUS) && value >= 0)
	{
		ft_putchar(' ');
		tmp++;
	}
	ft_putstr(res);
	free(res);
	*len += tmp;
	return (1);
}
