/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 17:05:28 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_number(void *value, t_spec spec)
{
	if (spec.size == SIZE_l)
	{
		ft_putnbr(*((long*)value));
	}
	else if (spec.size == SIZE_ll)
	{
		ft_putnbr(*((long long*)value));
	}
	else
		ft_putnbr(*((int*)value));
	return (1);	//	возвращать количество напечатаных разрядов
}
