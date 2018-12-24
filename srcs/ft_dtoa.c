/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:19:27 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/24 15:18:23 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dtoa(long double num, int acc)
{
	ssize_t		whole;
	ssize_t		fraction;
	char		*res;
	char		*buf;

	whole = (ssize_t)num;
	fraction = (ssize_t)(ABS(num - (long double)whole) * ft_pow(10, acc));
	buf = ft_strjoin(ft_itoa(whole), ".");
	res = ft_strjoin(buf, ft_itoa(fraction));
	free(buf);
	return (res);
}