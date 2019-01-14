/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:25:25 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 20:10:26 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int				print_string(va_list *ap, t_spec *spec, int *len)
{
	int		tmp;
	wchar_t	*value;
	wchar_t	*res;

	if (spec->size == SIZE_l)
		value = va_arg(*ap, wchar_t*);
	else	
		value = (wchar_t*)va_arg(*ap, char*);
	if (!value)
	{
		// if (!spec->width)
		value = ft_wcsjoin(value, L"(null)");
		// else
		// 	value = ft_strnew(0);
	}
	else
		value = ft_wcsdup(value);
	if (spec->accuracy >= 0)
		res = ft_wcscut(value, spec->accuracy);
	else
		res = value;
	if (!res)
		return (0);
	if (CHECK_FLAG(FLAG_MINUS))
		tmp = ft_wcsfixlen(&res, ' ', spec->width, 1);
	else
		tmp = ft_wcsfixlen(&res,
			CHECK_FLAG(FLAG_ZERO) ? '0' : ' ', spec->width, 0);
	ft_putwstr(res);
	free(res);
	*len += tmp;
	return (1);
}

int				print_long_string(va_list *ap, t_spec *spec, int *len)
{
	spec->size = SIZE_l;
	return (print_string(ap, spec, len));
}
