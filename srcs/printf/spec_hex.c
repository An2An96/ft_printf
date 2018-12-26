/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 19:34:29 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_iina(void *value, char size)
{
	char	*res;

	if (size == SIZE_l)
		res = ft_uitoa_base(*((unsigned long*)value), 16);
	else if (size == SIZE_ll)
		res = ft_uitoa_base(*((unsigned long long*)value), 16);
	else
		res = ft_uitoa_base(*((unsigned int*)value), 16);
	return (res);
}

static int	checkacc(void *value, t_spec *spec, char **res, int *ox)
{
	char	*buf;

	*ox = 0;
	if (spec->accuracy != 0)
	{
		buf = *res;
		*res = ft_iina(value, spec->size);
		free(buf);
		if ((spec->flags & FLAG_OCTOP) && (*((long long*)value) != 0))
			*ox = 2;
		return (1);
	}
	else
		return (0);
}

static char	*ft_getstr(void *value, t_spec spec)
{
	char	*res;
	int		len;
	char	c;
	int		ox;

	c = ' ';
	if ((spec.flags & FLAG_ZERO) && !(spec.flags & FLAG_MINUS))
		c = '0';
	res = ft_strdup("");
	checkacc(value, &spec, &res, &ox);
	len = ft_strlen(res) + ox;
	if (spec.width > 1 && spec.width - len > 0)
	{
		if (spec.flags & FLAG_MINUS)
			ft_str_fixlen(&res, c, spec.width - ox, 1);
		else
		{
			if (ox != 0 && c == ' ')
				print_ox(&res, &ox);
			ft_str_fixlen(&res, c, spec.width - ox, 0);
		}
	}
	if (ox != 0)
		print_ox(&res, &ox);
	return (res);
}

int			print_hex(void *value, t_spec spec)
{
	char	*res;

	res = ft_getstr(value, spec);
	ft_putstr(res);
	return (ft_strlen(res));
}

int			print_hex_upper(void *value, t_spec spec)
{
	char	*res;

	res = ft_getstr(value, spec);
	ft_strupper(res);
	ft_putstr(res);
	return (ft_strlen(res));
}
