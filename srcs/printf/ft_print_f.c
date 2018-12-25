/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:28:03 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/25 17:44:33 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_f(long double db, t_flags tflags)
{
	char	*str;
	int		i;
	char	c;

	if (tflags.flags & FLAG_N)
		c = '0';
	else
		c = ' ';
	str = ft_dtoa(db, tflags.fraction);
	i = tflags.width - ft_strlen(str);
	if (i > 0 && !(tflags.flags & FLAG_M))
		ft_printchr(i, c);
	ft_putstr(ft_dtoa(db, tflags.fraction));
	if (i > 0 && (tflags.flags & FLAG_M))
		ft_printchr(i, c);
	if (i > 0)
		return (tflags.width);
	else
		return (tflags.width - i);
}