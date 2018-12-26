/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 15:24:58 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

static void	double_handler(t_spec *spec, t_value_types *value, va_list *ap)
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

static void	int_handler(t_spec *spec, t_value_types *value, va_list *ap)
{
	if (spec->size == SIZE_l)
		value->l_value = va_arg(*ap, long);
	else if (spec->size == SIZE_ll)
		value->l_value = va_arg(*ap, long long);
	else
		value->l_value = va_arg(*ap, int);
	value->p_value = (void*)(&value->l_value);
}

static void	unsigned_handler(t_spec *spec, t_value_types *value, va_list *ap)
{
	if (spec->size == SIZE_l)
		value->l_value = va_arg(*ap, unsigned long);
	else if (spec->size == SIZE_ll)
		value->l_value = va_arg(*ap, unsigned long long);
	else
		value->l_value = va_arg(*ap, unsigned int);
	value->p_value = (void*)(&value->l_value);
}

static int	specifier_handler(int spec_idx, char **body, va_list *ap)
{
	t_value_types	value;
	t_spec			spec;

	parse_spec_body(*body, &spec);
	ft_strdel(body);
	if (g_dispatcher[spec_idx].arg_type == TYPE_PTR)
		value.p_value = va_arg(*ap, void*);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_INT)
		int_handler(&spec, &value, ap);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_DOUBLE)
		double_handler(&spec, &value, ap);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_UNSIGNED)
		unsigned_handler(&spec, &value, ap);
	return (g_dispatcher[spec_idx].func(value.p_value, spec));
}

int			ft_printf(const char *format, ...)
{
	int				spec_idx;
	char			*start;
	va_list			ap;
	int				len;

	va_start(ap, format);
	start = NULL;
	len = 0;
	while (*format)
	{
		if (start)
		{
			if ((spec_idx = find_specifier(*format, &g_dispatcher)) >= 0)
			{
				start = ft_strsub(start, 1, format - start - 1);
				len += specifier_handler(spec_idx, &start, &ap);
			}
		}
		else if (*format == '%')
			start = (char*)format;
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
