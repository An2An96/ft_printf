/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_X.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:25:16 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(void *value, char flags, int width, int accuracy, char size)
{
	char *res;

	res = NULL;
	if (size == SIZE_l)
	{
		res = ft_itoa_base(*((long*)value), 16);
	}
	else
	{
		res = ft_itoa_base(*((int*)value), 16);
	}
	ft_putstr(res);
}
