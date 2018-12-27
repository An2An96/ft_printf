/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 16:08:21 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 15:12:52 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

/*
**	spec_idx == 5 -- для обработки синонима %U = %lu
*/

static int	specifier_handler(int spec_idx, char **body, va_list *ap, int *len)
{
	t_value_types	value;
	t_spec			spec;
	int				res;
	int				body_len;

	body_len = ft_strlen(*body);
	if (spec_idx == 255)
	{
		ft_putstr(*body + 1);
		ft_strdel(body);
		*len += body_len - 1;
		return (1);
	}
	(*body)[body_len - 1] = '\0';
	parse_spec_body(*body, &spec);
	ft_strdel(body);
	if (spec_idx == 5)
		spec.size = SIZE_l;
	if (g_dispatcher[spec_idx].arg_type == TYPE_PTR)
		value.p_value = va_arg(*ap, void*);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_INT)
		int_handler(&spec, &value, ap);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_DOUBLE)
		double_handler(&spec, &value, ap);
	else if (g_dispatcher[spec_idx].arg_type == TYPE_UNSIGNED)
		unsigned_handler(&spec, &value, ap);
	if ((res = g_dispatcher[spec_idx].func(value.p_value, &spec)) == -1)
	{
		*len = -1;
		return (0);
	}
	*len += res;
	return (1);
}

static void	format_handler(const char *format, va_list *ap, int *len)
{
	char	*start;
	int		spec_idx;
	int		res;

	start = NULL;
	while (*format)
	{
		if (start)
		{
			if ((spec_idx = find_specifier(*format, &g_dispatcher)) >= 0)
			{
				start = ft_strsub(start, 1, format - start);
				if ((res = specifier_handler(spec_idx, &start, ap, len)) == 0)
					return ;
			}
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
