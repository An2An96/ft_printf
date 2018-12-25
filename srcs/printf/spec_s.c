/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 19:09:18 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(void *value, t_spec spec)
{
	int len;

	len = ft_strlen(value);
	if (spec.width > 1 && spec.width - len > 0)
	{
		if (spec.flags & FLAG_MINUS)
		{
			ft_putstr((char*)value);
			ft_printchr(spec.width - len, ' ');
		}
		else
		{
			ft_printchr(spec.width - len, ' ');
			ft_putstr((char*)value);
		}
	}
	else
		ft_putstr((char*)value);
	return (len > spec.width ? len : spec.width);
}
