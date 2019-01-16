/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:37:13 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/16 13:55:44 by rschuppe         ###   ########.fr       */
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

static char	*ft_numtohex(long double num, int acc, int ast)
{
	char		*res;
	int			i;
	int			dig;

	num = num - 1.0;
	res = (char *)malloc(sizeof(char) * (acc + 3));
	res[0] = '1';
	res[1] = '.';
	i = 1;
	while (++i < acc + 2)
	{
		dig = (int)(num * 16);
		if (dig == 0 && ast == -1)
			break ;
		if (dig > 9)
			res[i] = dig + 87;
		else
			res[i] = dig + '0';
		num = num * 16 - dig;
	}
	if ((dig = (int)(num * 16)) >= 8)
	{
		if (res[i - 1] >= '9' && res[i - 1] < 'a')
			res[i - 1] = 'a';
		else
			res[i - 1] = res[i - 1] + 1;
	}
	res[i] = '\0';
	return (res);
}

static char	*ft_aA(long double num, int acc, int ast)
{
	int		power;
	char	*res;
	char	*buf;
	char	*exp;

	power = ft_anorm(&num, 0);
	res = ft_numtohex(num, acc, ast);
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

int			print_afloat(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		i;
	char	c;
	int		ast;

	c = ' ';
	if (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO))
		c = '0';
	ast = (spec->accuracy == -1 ? -1 : 0);
	spec->accuracy = spec->accuracy == -1 ? 13 : spec->accuracy;
	if (spec->size == SIZE_L)
		res = ft_aA(va_arg(*ap, long double), spec->accuracy, ast);
	else
		res = ft_aA(va_arg(*ap, double), spec->accuracy, ast);
	if (!res)
		return (0);
	ft_putstr("0x");
	i = spec->width - ft_strlen(res);
	if (i > 0 && !IS_FLAG(FLAG_MINUS))
		ft_printchr(i - 2, c);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
		ft_printchr(1, ' ');
	ft_putstr(res);
	if (i > 0 && IS_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	free(res);
	*len += (i > 0 ? spec->width : spec->width - i);
	return (1);
}

int			print_afloat_upper(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	int		i;
	char	c;
	int		ast;

	c = ' ';
	if (!IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_ZERO))
		c = '0';
	spec->accuracy = spec->accuracy == -1 ? 13 : spec->accuracy;
	ast = spec->accuracy == -1 ? -1 : 0;
	if (spec->size == SIZE_L)
		res = ft_aA(va_arg(*ap, long double), spec->accuracy, ast);
	else
		res = ft_aA(va_arg(*ap, double), spec->accuracy, ast);
	ft_strupper(res);
	if (!res)
		return (0);
	ft_putstr("0x");
	i = spec->width - ft_strlen(res);
	if (i > 0 && !IS_FLAG(FLAG_MINUS))
		ft_printchr(i - 2, c);
	if (IS_FLAG(FLAG_MINUS) && IS_FLAG(FLAG_SPACE))
		ft_printchr(1, ' ');
	ft_putstr(res);
	if (i > 0 && IS_FLAG(FLAG_MINUS))
		ft_printchr(i, c);
	free(res);
	*len += (i > 0 ? spec->width : spec->width - i);
	return (1);
}
