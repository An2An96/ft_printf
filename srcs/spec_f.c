/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 15:50:16 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

char	*ft_floattostr(va_list *ap, t_spec *spec)
{
	char	*res;

	spec->accuracy = spec->accuracy == -1 ? 6 : spec->accuracy;
	if (spec->size == SIZE_L)
		res = ft_dtoa(va_arg(*ap, long double), spec->accuracy);
	else
		res = ft_dtoa(va_arg(*ap, double), spec->accuracy);
	return (res);
}

int		print_float(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
	res = ft_floattostr(ap, spec);
	if (!res)
		return (0);
	if (spec->width - ft_strlen(res) > 0)
		side = (CHECK_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width, side);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
	{
		str = res;
		res = ft_strjoin(" ", res);
		free(str);
		tmp++;
	}
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}
