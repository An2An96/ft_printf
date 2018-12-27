/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:23:45 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 21:58:52 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *value, t_spec *spec, int *len)
{
	char *res;

	(void)spec;
	if ((size_t)value)
	{
		res = ft_itoa_base((size_t)value, 16);
		if (!res)
			return (0);
		ft_putstr("0x");
		ft_putstr(ft_strlower(res));
		free(res);
		*len += ft_strlen(res);
	}
	else
	{
		res = ft_strdup("");
		ft_str_fixlen(&res, ' ', spec->width - 3, 1);
		ft_putstr(res);
		ft_putstr("0x0");
	}
	*len += 2;
	return (1);
}
