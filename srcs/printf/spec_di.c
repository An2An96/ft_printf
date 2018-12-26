/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 20:09:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define CHECK_FLAG(f)	(spec.flags & f)

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
			res[--discharges] = ABS(n) + '0';		//	ПОФИКСИТЬ ЭТО ГОВНО
			unsig_n /= 10;
		}
		if (sign)
			res[0] = '-';
		else if (need_sign)
			res[0] = '+';
	}
	return (res);
}

int			print_number(void *value, t_spec spec)
{
	char	*res;
	int		len;

	if (spec.accuracy == -1 && CHECK_FLAG(FLAG_ZERO) && !CHECK_FLAG(FLAG_MINUS))
	{
		if (*((long long*)value) < 0 || CHECK_FLAG(FLAG_PLUS))
			spec.width--;
		spec.accuracy = spec.accuracy > spec.width ? spec.accuracy : spec.width;
		spec.width = 0;
	}
	if (spec.accuracy || *((long long*)value))
	{
		if (spec.size == SIZE_l)
			res = ft_extend_itoa(*((long*)value), spec.accuracy, CHECK_FLAG(FLAG_PLUS));
		else if (spec.size == SIZE_ll)
			res = ft_extend_itoa(*((long long*)value), spec.accuracy, CHECK_FLAG(FLAG_PLUS));
		else if (spec.size == SIZE_h)
			res = ft_extend_itoa(*((short int*)value), spec.accuracy, CHECK_FLAG(FLAG_PLUS));
		else if (spec.size == SIZE_hh)
			res = ft_extend_itoa(*((signed char*)value), spec.accuracy, CHECK_FLAG(FLAG_PLUS));
		else
			res = ft_extend_itoa(*((int*)value), spec.accuracy, CHECK_FLAG(FLAG_PLUS));
	}
	else
		res = ft_strnew(0);
	len = ft_str_fixlen(&res, ' ', spec.width, CHECK_FLAG(FLAG_MINUS));
	if (!spec.width && spec.flags == FLAG_SPACE && *((long long*)value) > 0)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putstr(res);
	return (len);
}
