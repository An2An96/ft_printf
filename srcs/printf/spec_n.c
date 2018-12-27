/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:15:44 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 18:19:59 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_len(void *value, t_spec *spec, int *len)
{
	size_t *ptr;

	ptr = (size_t*)value;
	*ptr = *len;
	return (1);
}
