/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 18:23:29 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strcut(char const *s, size_t len)
{
	unsigned int	i;
	char			*res;
	int				src_len;

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

int			print_string(void *value, t_spec *spec, int *len)
{
	int		tmp;
	char	*res;

	if (!value)
		value = ft_strjoin(value, "(null)");
	else
		value = ft_strdup(value);
	if (spec->accuracy > 0)
		res = ft_strcut(value, spec->accuracy);
	else
		res = value;
	if (!res)
		return (0);
	tmp = ft_str_fixlen(&res, ' ', spec->width, spec->flags & FLAG_MINUS);
	ft_putstr(res);
	free(res);
	*len += tmp;
	return (1);
}
