/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:55:39 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 19:04:42 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	_u_putnbr(unsigned int n)
{
	if (n / 10)
		_u_putnbr((n / 10));
	ft_putchar((n % 10) + '0');
}

void	print_unsigned(void *value, char flags, int width, int accuracy, char size)
{
	_u_putnbr(*((unsigned int*)value));
}
