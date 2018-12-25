/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:28:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:14:06 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_octal(void *value, t_spec spec)
{
	char *res;

	res = ft_itoa_base(*((int*)value), 8);
	if (res)
		ft_putstr(res);
	return (ft_strlen(res));
}
