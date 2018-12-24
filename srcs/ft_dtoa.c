/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:19:27 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/24 18:54:19 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dtoa(long double num, int acc)
{
	ssize_t		whole;
	ssize_t		fraction;
	char		*res;
	char		*buf;
	long double	eps;

	eps = 0.5 / ft_pow(10, acc);
	whole = (ssize_t)num;
	fraction = (size_t)(ABS(num - (long double)whole + eps) * ft_pow(10.0, acc));
	buf = ft_strjoin(ft_stoa(whole), ".");
	res = ft_strjoin(buf, ft_stoa(fraction));
	free(buf);
	return (res);
}