/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:23:45 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 18:23:58 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *value, t_spec *spec, int *len)
{
	char *res;

	res = ft_itoa_base((size_t)value, 16);
	if (!res)
		return (0);
	ft_putstr("0x");
	ft_putstr(ft_strlower(res));
	free(res);
	*len += ft_strlen(res) + 2;
	return (1);
}
