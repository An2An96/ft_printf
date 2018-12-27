/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:03:21 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/27 22:04:32 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits(unsigned long long num, int base)
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

char		*pf_uitoa_base(unsigned long long num, int base, int len)
{
	char	*res;
	int		digs;
	int		i;

	digs = ft_digits(num, base);
	digs = (digs > len ? digs : len);
	if ((res = (char *)malloc(sizeof(char) * (digs + 1))) == NULL)
		return (NULL);
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
