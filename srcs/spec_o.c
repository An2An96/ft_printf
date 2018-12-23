/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:28:02 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 19:05:28 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_octal(void *value, char flags, int width, int accuracy, char size)
{
	char *res = ft_itoa_base(*((int*)value), 8);
	if (res)
		ft_putstr(res);
}