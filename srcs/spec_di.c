/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_di.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:22:47 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:24:41 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number(void *value, char flags, int width, int accuracy, char size)
{
	printf("flag [-]: %s\n", flags & FLAG_MINUS ? "yes" : "no");
	printf("flag [+]: %s\n", flags & FLAG_PLUS ? "yes" : "no");
	printf("flag [ ]: %s\n", flags & FLAG_SPACE ? "yes" : "no");
	printf("flag [#]: %s\n", flags & FLAG_OCTOP ? "yes" : "no");
	printf("flag [0]: %s\n", flags & FLAG_ZERO ? "yes" : "no");
	printf("width: %d\n", width);
	printf("accuracy: %d\n", accuracy);
	printf("size: %d\n", size);
	ft_putnbr(*((int*)value));
}
