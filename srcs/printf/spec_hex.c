/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 19:38:19 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_iina(void *value, char size, int len)
{
	char	*res;

	if (size == SIZE_l)
		res = pf_uitoa_base(*((unsigned long*)value), 16, len);
	else if (size == SIZE_ll)
		res = pf_uitoa_base(*((unsigned long long*)value), 16, len);
	else
		res = pf_uitoa_base(*((unsigned int*)value), 16, len);
	return (res);
}

static int	checkacc(void *value, t_spec *spec, char **res, int *ox)
{
	char	*buf;

	*ox = 0;
	if (spec->accuracy == -1 || spec->accuracy > 0)
	{
		buf = *res;
		if (CHECK_FLAG(FLAG_OCTOP) && (*((long long*)value) != 0))
			*ox = 2;
		if (CHECK_FLAG(FLAG_ZERO) && !(CHECK_FLAG(FLAG_MINUS)))
			spec->accuracy = (spec->accuracy == -1
				? (spec->width - *ox) : spec->accuracy);
		else
			spec->accuracy = (spec->accuracy > 0 ? spec->accuracy : 0);
		if ((*res = ft_iina(value, spec->size, spec->accuracy)) == NULL)
			return (-1);
		free(buf);
		return (1);
	}
	else
		return (0);
}

static void	ft_getstr(char **res, void *value, t_spec *spec)
{
	int		ox;
	char	*buf;

	if (checkacc(value, spec, res, &ox) == -1)
		return ;
	if (spec->width > 1 && spec->width - (ft_strlen(*res) + ox) > 0)
	{
		if (ox != 0)
		{
			buf = *res;
			*res = ft_strjoin("0x", *res);
			free(buf);
			ox = 0;
		}
		ft_str_fixlen(res, ' ', spec->width - ox, (spec->flags & FLAG_MINUS));
	}
	if (ox != 0)
	{
		buf = *res;
		*res = ft_strjoin("0x", *res);
		free(buf);
	}
}

int			print_hex(void *value, t_spec *spec)
{
	char	*res;

	res = ft_strdup("");
	ft_getstr(&res, value, spec);
	if (res == NULL)
		return (-1);
	ft_putstr(res);
	free(res);
	return (ft_strlen(res));
}

int			print_hex_upper(void *value, t_spec *spec)
{
	char	*res;

	res = ft_strdup("");
	ft_getstr(&res, value, spec);
	if (res == NULL)
		return (-1);
	ft_strupper(res);
	ft_putstr(res);
	free(res);
	return (ft_strlen(res));
}
