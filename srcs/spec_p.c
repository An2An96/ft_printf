/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:23:45 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/28 13:12:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_pointer(void *value, t_spec *spec, int *len)
{
	char *res;

	(void)spec;
	if ((size_t)value)
		res = ft_itoa_base((size_t)value, 16);
	else
		res = ft_strdup(spec->accuracy ? "0" : "");
	if (!res)
		return (0);
	ft_str_fixlen(&res, '0', spec->accuracy, 0);
	value = ft_strjoin("0x", ft_strlower(res));
	free(res);
	res = value;
	ft_str_fixlen(&res, ' ', spec->width, CHECK_FLAG(FLAG_MINUS));
	ft_putstr(res);
	*len += ft_strlen(res);
	free(res);
	return (1);
}
