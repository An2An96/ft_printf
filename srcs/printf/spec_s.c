/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 12:25:21 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(void *value, t_spec *spec)
{
	int		len;
	char	*res;

	if (!value)
		value = ft_strjoin(value, "(null)");
	else
		value = ft_strdup(value);
	if (spec->accuracy > 0)
		res = ft_strsub(value, 0, spec->accuracy);
	else
		res = value;
	len = ft_str_fixlen(&res, ' ', spec->width, spec->flags & FLAG_MINUS);
	ft_putstr(res);
	return (len);
}
