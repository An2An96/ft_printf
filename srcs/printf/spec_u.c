/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:55:39 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/25 20:20:04 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_unsigned(unsigned long long n)
{
	if (n / 10)
		ft_putnbr_unsigned((n / 10));
	ft_putchar((n % 10) + '0');
}

int		print_unsigned(void *value, t_spec spec)
{
	if (spec.size == SIZE_l)
		ft_putnbr_unsigned(*((unsigned long*)value));
	else if (spec.size == SIZE_ll)
		ft_putnbr_unsigned(*((unsigned long long*)value));
	else
		ft_putnbr_unsigned(*((unsigned int*)value));
	return (1);
}
