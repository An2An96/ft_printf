/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:19:52 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/23 17:01:46 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(long long n, int base)
{
	long long	unsig_n;
	int			discharges;
	char		*res;
	char		sign;

	sign = (n < 0);
	discharges = sign + 1;
	unsig_n = ABS(n);
	while ((unsig_n /= base))
		discharges++;
	res = ft_strnew(discharges);
	if (res)
	{
		while (discharges > sign)
		{
			unsig_n = n % base;
			res[--discharges] = unsig_n + ((unsig_n < 10) ? '0' : 'A' - 10);
			n /= base;
		}
		if (sign)
			res[--discharges] = '-';
	}
	return (res);
}
