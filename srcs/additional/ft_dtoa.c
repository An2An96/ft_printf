/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:19:27 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/27 15:14:34 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_str_bigger(char **str, char c, int acc)
{
	int		i;
	int		len;
	char	*new;
	char	ch;

	ch = 0;
	len = ft_strlen(*str);
	new = (char *)malloc(sizeof(char) * (acc + 1));
	new[acc] = '\0';
	i = -1;
	while (++i < acc)
	{
		if ((*str)[i] == '\0')
			ch = 1;
		if (ch == 0)
			new[i] = (*str)[i];
		else
			new[i] = '0';
	}
	*str = new;
}

char		*ft_dtoa(long double num, int acc)
{
	ssize_t		nbr;
	char		*fraction;
	char		*buf;
	char		*res;
	size_t		eps;

	eps = (size_t)ft_pow(10, acc);
	nbr = (ssize_t)((num + 0.5 / eps) * eps);
	if (acc == 0)
		return (ft_stoa(nbr / eps));
	fraction = ft_stoa(ABS(nbr % eps));
	if (ft_strlen(fraction) < acc)
	{
		buf = fraction;
		ft_str_bigger(&fraction, '0', acc);
		free(buf);
	}
	buf = ft_strjoin(ft_stoa(nbr / eps), ".");
	res = ft_strjoin(buf, fraction);
	free(buf);
	return (res);
}
