/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:34:19 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:24:35 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number(void *value, char flags, int width, int accuracy, char size)
{
	ft_printf("flag [-]: %s\n", flags & FLAG_MINUS ? "yes" : "no");
	ft_printf("flag [+]: %s\n", flags & FLAG_PLUS ? "yes" : "no");
	ft_printf("flag [ ]: %s\n", flags & FLAG_SPACE ? "yes" : "no");
	ft_printf("flag [#]: %s\n", flags & FLAG_OCTOP ? "yes" : "no");
	ft_printf("flag [0]: %s\n", flags & FLAG_ZERO ? "yes" : "no");
	printf("accuracy: %d\n", accuracy);
	ft_putnbr(*((int*)value));
}

void	print_char(void *value, char flags, int width, int accuracy, char size)
{
	ft_putchar(*((char*)value));
}

void	print_string(void *value, char flags, int width, int accuracy, char size)
{
	ft_putstr((char*)value);
}

void	print_pointer(void *value, char flags, int width, int accuracy, char size)
{
	ft_putnbr((int)value);
}
