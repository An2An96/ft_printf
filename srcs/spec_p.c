/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:23:45 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/15 20:37:26 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_pointer(va_list *ap, t_spec *spec, int *len)
{
	char	*res;
	void	*value;
	int		tmp;

	(void)spec;
	value = va_arg(*ap, void*);
	if ((size_t)value)
		res = ft_itoa_base((size_t)value, 16);
	else
		res = ft_strdup(spec->accuracy ? "0" : "");
	if (!res)
		return (0);
	ft_str_fixlen(&res, '0', spec->accuracy, 0);
	value = ft_strjoin("0x", ft_strlower(res));
	free(res);
	res = value;
	ft_str_fixlen(&res, ' ', spec->width, CHECK_FLAG(FLAG_MINUS));
	tmp = ft_strlen(res);
	write(1, res, tmp);
	free(res);
	*len += tmp;
	return (1);
}
