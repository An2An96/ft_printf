/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 21:48:33 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

int		find_specifier(const char ch)
{
	int i;

	i = 0;
	while (g_dispatcher[i].type_specifier)
	{
		if (ch == g_dispatcher[i].type_specifier)
			return (i);
		i++;
	}
	return (-1);
}

/*
**	spec_idx == 4 -- для обработки синонима %O = %lo
**	spec_idx == 6 -- для обработки синонима %U = %lu
*/

static int	specifier_handler(int spec_idx, char **body, va_list *ap, int *len)
{
	t_value_types	value;
	t_spec			spec;

	parse_spec_body(*body, &spec);
	ft_strdel(body);
	if (spec_idx == 4 || spec_idx == 6)
		spec.size = SIZE_l;
	if (g_dispatcher[spec_idx].arg_type == TYPE_PTR)
		value.p_value = va_arg(*ap, void*);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_INT)
		int_handler(&spec, &value, ap);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_DOUBLE)
		double_handler(&spec, &value, ap);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_UNSIGNED)
		unsigned_handler(&spec, &value, ap);
	if (g_dispatcher[spec_idx].func(value.p_value, &spec, len))
		return (1);
	else
	{
		*len = -1;
		return (0);
	}
}

static int	spec_body_handler(
	const char *format, char **start, va_list *ap, int *len)
{
	int spec_idx;

	if ((spec_idx = find_specifier(*format)) >= 0)
	{
		*start = ft_strsub(*start, 1, format - *start);
		return (specifier_handler(spec_idx, start, ap, len));
	}
	else if (!is_spec_body_char(*format))
	{
		ft_putchar(*format);
		(*len)++;
		*start = NULL;
	}
	return (1);
}

static void	format_handler(const char *format, va_list *ap, int *len)
{
	char	*start;

	start = NULL;
	while (*format)
	{
		if (start)
		{
			if (spec_body_handler(format, &start, ap, len) == 0)
				return ;
		}
		else if (*format == '%')
			start = (char*)format;
		else
		{
			ft_putchar(*format);
			(*len)++;
		}
		format++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	format_handler(format, &ap, &len);
	va_end(ap);
	return (len);
}
