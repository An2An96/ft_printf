/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:41:30 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 22:07:55 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

void	double_handler(t_spec *spec, t_value_types *value, va_list *ap)
{
	if (spec->size == SIZE_L)
	{
		value->ld_value = va_arg(*ap, long double);
		value->p_value = (void*)(&value->ld_value);
	}
	else
	{
		value->d_value = va_arg(*ap, double);
		value->p_value = (void*)(&value->d_value);
	}
}

void	int_handler(t_spec *spec, t_value_types *value, va_list *ap)
{
	if (spec->size == SIZE_l)
		value->l_value = va_arg(*ap, long);
	else if (spec->size == SIZE_ll)
		value->l_value = va_arg(*ap, long long);
	else if (spec->size == SIZE_z)
	{
		value->z_value = va_arg(*ap, ssize_t);
		value->p_value = (void*)(&value->z_value);
		return ;
	}
	else
		value->l_value = va_arg(*ap, int);
	value->p_value = (void*)(&value->l_value);
}

void	unsigned_handler(t_spec *spec, t_value_types *value, va_list *ap)
{
	if (spec->size == SIZE_l)
		value->l_value = va_arg(*ap, unsigned long);
	else if (spec->size == SIZE_ll)
		value->l_value = va_arg(*ap, unsigned long long);
	else if (spec->size == SIZE_z)
	{
		value->z_value = va_arg(*ap, ssize_t);
		value->p_value = (void*)(&value->z_value);
		return ;
	}
	else
		value->l_value = va_arg(*ap, unsigned int);
	value->p_value = (void*)(&value->l_value);
}
