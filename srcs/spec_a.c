/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 15:49:38 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static int	ft_anorm(long double *num, int power)
{
	if (ABS(*num) < 1.0)
	{
		*num = *num * 2.0;
		power--;
	}
	else if (ABS(*num) >= 2.0)
	{
		*num = *num / 2.0;
		power++;
	}
	else
	{
		return (power);
	}
	return (ft_anorm(num, power));
}

static char	*ft_aa(long double num, int acc)
{
	int		power;
	char	*res;
	char	*buf;
	char	*exp;

	power = ft_anorm(&num, 0);
	res = ft_numtohex(num, acc);
	if (power < 0)
		buf = ft_strjoin("p", "-");
	else
		buf = ft_strjoin("p", "+");
	exp = ft_strjoin(buf, ft_itoa_base(ABS(power), 10));
	free(buf);
	res = ft_strjoin(res, exp);
	free(exp);
	return (res);
}

static char	*ft_afloattostr(va_list *ap, t_spec *spec)
{
	char	*res;

	if (spec->size == SIZE_L)
		res = ft_aa(va_arg(*ap, long double), spec->accuracy);
	else
		res = ft_aa(va_arg(*ap, double), spec->accuracy);
	return (res);
}

int			print_afloat(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_afloattostr(ap, spec)) == NULL)
		return (0);
	write(1, "0x", 3);
	if (spec->width - ft_strlen(res) > 0)
		side = (CHECK_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width - 2, side);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
	{
		str = res;
		res = ft_strjoin(" ", res);
		free(str);
		tmp++;
	}
	write(1, res, tmp);
	free(res);
	*len += tmp + 2;
	return (1);
}

int			print_afloat_upper(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	char	*str;
	char	c;
	int		tmp;
	int		side;

	side = 0;
	c = (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO) ? '0' : ' ');
	if ((res = ft_afloattostr(ap, spec)) == NULL)
		return (0);
	write(1, "0x", 3);
	if (spec->width - ft_strlen(res) > 0)
		side = (CHECK_FLAG(FLAG_MINUS) ? 1 : 0);
	tmp = ft_str_fixlen(&res, c, spec->width - 2, side);
	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
	{
		str = res;
		res = ft_strjoin(" ", res);
		free(str);
		tmp++;
	}
	ft_strupper(res);
	write(1, res, tmp);
	free(res);
	*len += tmp + 2;
	return (1);
}

// int			print_afloat(va_list *ap, t_spec *spec, int *len)
// {
// 	char	*res;
// 	int		i;
// 	char	c;
// 	int		ast;

// 	c = ' ';
// 	if (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO))
// 		c = '0';
// 	ast = (spec->accuracy == -1 ? -1 : 0);
// 	spec->accuracy = spec->accuracy == -1 ? 13 : spec->accuracy;
// 	if (spec->size == SIZE_L)
// 		res = ft_aA(va_arg(*ap, long double), spec->accuracy, ast);
// 	else
// 		res = ft_aA(va_arg(*ap, double), spec->accuracy, ast);
// 	if (!res)
// 		return (0);
// 	ft_putstr("0x");
// 	i = spec->width - ft_strlen(res);
// 	if (i > 0 && !CHECK_FLAG(FLAG_MINUS))
// 		ft_printchr(i - 2, c);
// 	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
// 		ft_printchr(1, ' ');
// 	ft_putstr(res);
// 	if (i > 0 && CHECK_FLAG(FLAG_MINUS))
// 		ft_printchr(i, c);
// 	free(res);
// 	*len += (i > 0 ? spec->width : spec->width - i);
// 	return (1);
// }

// int			print_afloat_upper(va_list *ap, t_spec *spec, int *len)
// {
// 	char	*res;
// 	int		i;
// 	char	c;
// 	int		ast;

// 	c = ' ';
// 	if (!CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_ZERO))
// 		c = '0';
// 	spec->accuracy = spec->accuracy == -1 ? 13 : spec->accuracy;
// 	ast = spec->accuracy == -1 ? -1 : 0;
// 	if (spec->size == SIZE_L)
// 		res = ft_aA(va_arg(*ap, long double), spec->accuracy, ast);
// 	else
// 		res = ft_aA(va_arg(*ap, double), spec->accuracy, ast);
// 	ft_strupper(res);
// 	if (!res)
// 		return (0);
// 	ft_putstr("0x");
// 	i = spec->width - ft_strlen(res);
// 	if (i > 0 && !CHECK_FLAG(FLAG_MINUS))
// 		ft_printchr(i - 2, c);
// 	if (CHECK_FLAG(FLAG_MINUS) && CHECK_FLAG(FLAG_SPACE))
// 		ft_printchr(1, ' ');
// 	ft_putstr(res);
// 	if (i > 0 && CHECK_FLAG(FLAG_MINUS))
// 		ft_printchr(i, c);
// 	free(res);
// 	*len += (i > 0 ? spec->width : spec->width - i);
// 	return (1);
// }
