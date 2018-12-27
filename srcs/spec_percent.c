/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:06:30 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 22:07:48 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

int	print_percent(void *value, t_spec *spec, int *len)
{
	char ch;

	(void)value;
	ch = '%';
	return (print_char(&ch, spec, len));
}
