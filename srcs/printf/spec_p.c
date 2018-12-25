/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:23:45 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:14:00 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *value, t_spec spec)
{
	char *res;

	res = ft_itoa_base((long long)value, 16);
	if (res)
	{
		ft_putstr("0x");
		ft_putstr(ft_strlower(res));
	}
	return (ft_strlen(res) + 2);
}
