/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:52:43 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/25 18:55:15 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static size_t	ft_digits(size_t num, int base)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		i++;
		num /= base;
	}
	return (i);
}

char			*ft_convert(size_t num, int base)
{
	char	*res;
	size_t	digs;
	ssize_t	i;

	digs = ft_digits(num, base);
	res = (char *)malloc(sizeof(char) * (digs + 1));
	i = digs;
	while (--i >= 0)
	{
		if (num % base < 10)
			res[i] = num % base + '0';
		else
			res[i] = num % base + 87;
		num /= base;
	}
	res[digs] = '\0';
	return (res);
}