/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 13:29:25 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

static char	*ft_strcut(char const *s, size_t len)
{
	unsigned int	i;
	char			*res;
	size_t			src_len;

	res = NULL;
	if (s)
	{
		src_len = ft_strlen(s);
		len = len > src_len ? src_len : len;
		res = ft_strnew(len);
		if (res)
		{
			i = 0;
			while (i < len)
			{
				res[i] = s[i];
				i++;
			}
		}
	}
	return (res);
}

int			print_string(va_list *ap, t_spec *spec, int *len)
{
	int		tmp;
	char	*value;
	char	*res;

	value = va_arg(*ap, char*);
	if (!value)
	{
		if (!spec->width)
			value = ft_strjoin(value, "(null)");
		else
			value = ft_strnew(0);
	}
	else
		value = ft_strdup(value);
	if (spec->accuracy >= 0)
		res = ft_strcut(value, spec->accuracy);
	else
		res = value;
	if (!res)
		return (0);
	if (CHECK_FLAG(FLAG_MINUS))
		tmp = ft_str_fixlen(&res, ' ', spec->width, 1);
	else
		tmp = ft_str_fixlen(&res,
			CHECK_FLAG(FLAG_ZERO) ? '0' : ' ', spec->width, 0);
	ft_putstr(res);
	free(res);
	*len += tmp;
	return (1);
}
