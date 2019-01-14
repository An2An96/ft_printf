/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 16:26:34 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static int	ft_enorm(long double *num, int power)
{
	if (ABS(*num) < 1)
	{
		*num = *num * 10.0;
		power--;
	}
	else if (ABS(*num) > 10.0)
	{
		*num = *num * 0.1;
		power++;
	}
	else
	{
		return (power);
	}
	return (ft_enorm(num, power));
}

static char	*ft_eE(long double num, int acc)
{
	int		power;
	char	*res;
	char	*buf;
	char	*exp;

	power = ft_enorm(&num, 0);
	if (power < 0)
		buf = ft_strjoin("e", "-");
	else
		buf = ft_strjoin("e", "+");
	if (ABS(power) < 10)
	{
		exp = ft_strjoin(buf, "0");
	}
	else
	{
		exp = ft_strdup(buf);
	}
	free(buf);
	buf = ft_strjoin(exp, ft_itoa_base(ABS(power), 10));
	res = ft_strjoin(ft_dtoa(num, acc), buf);
	free(buf);
	return (res);

}

int	print_efloat(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		i;
	char	c;

	c = ' ';
	if (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO))
		c = '0';
	spec->accuracy = spec->accuracy == -1 ? 6 : spec->accuracy;
	if (spec->size == SIZE_L)
		res = ft_eE(va_arg(*ap, long double), spec->accuracy);
	else
		res = ft_eE(va_arg(*ap, double), spec->accuracy);
	if (!res)
		return (0);
	i = spec->width - ft_strlen(res);
	if (i > 0 && !CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
		ft_printchr(1, ' ');
	ft_putstr(res);
	if (i > 0 && CHECK_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	free(res);
	*len += (i > 0 ? spec->width : spec->width - i);
	return (1);
}
