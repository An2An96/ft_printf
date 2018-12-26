/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 20:38:46 by anorjen          ###   ########.fr       */
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

static void	ft_getstr(char **res, void *value, t_spec spec)
{
	char	c;
	int		ox;
	char	*buf;

	c = ' ';
	if ((spec.flags & FLAG_ZERO) && !(spec.flags & FLAG_MINUS))
		c = '0';
	checkacc(value, &spec, res, &ox);
	if (spec.width > 1 && spec.width - (ft_strlen(*res) + ox) > 0)
	{
		if (ox != 0 && c == ' ')
		{
			buf = *res;
			*res = ft_strjoin("0x", *res);
			free(buf);
			ox = 0;
		}
		ft_str_fixlen(res, c, spec.width - ox, (spec.flags & FLAG_MINUS));
	}
	if (ox != 0)
	{
		buf = *res;
		*res = ft_strjoin("0x", *res);
		free(buf);
	}
}

int			print_hex(void *value, t_spec spec)
{
	char	*res;

	res = ft_strdup("");
	ft_getstr(&res, value, spec);
	ft_putstr(res);
	free(res);
	return (ft_strlen(res));
}

int			print_hex_upper(void *value, t_spec spec)
{
	char	*res;

	res = ft_strdup("");
	ft_getstr(&res, value, spec);
	ft_strupper(res);
	ft_putstr(res);
	free(res);
	return (ft_strlen(res));
}
