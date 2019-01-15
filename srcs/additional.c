/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:09:37 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/15 17:52:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

void	parse_spec_body(char *body, va_list *ap, t_spec *spec)
{
	int res;

	spec->flags = 0;
	spec->size = SIZE_NONE;
	spec->accuracy = -1;
	spec->width = 0;
	while (*body)
	{
		res = 0;
		res = get_flags(*body, &(spec->flags));
		!res && (res = get_size(body, &(spec->size)));
		!res && (res = get_accuracy(body, ap, &(spec->accuracy)));
		!res && (res = get_width(body, ap, spec));
		body += res;
	}
}

int		is_spec_body_char(char ch)
{
	return (ft_isdigit(ch) || ch == ' ' || ch == '-' || ch == '+' || ch == '#'
		|| ch == '.' || ch == '*' || ch == 'l' || ch == 'h' || ch == 'L'
		|| ch == 'z' || ch == 'j');
}

int		get_number_width(int number)
{
	int discharges;

	discharges = number < 0;
	if (number == 0)
		return (discharges + 1);
	while (number / 10 || number % 10)
	{
		number /= 10;
		discharges++;
	}
	return (discharges);
}

int		get_width(char *body, va_list *ap, t_spec *spec)
{
	if (*body == '*')
	{
		spec->width = va_arg(*ap, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			spec->flags = FLAG_MINUS;
		}
		return (1);
	}
	else
		spec->width = ft_atoi(body);
	return (get_number_width(spec->width));
}

int		get_flags(char ch, char *flags)
{
	if (ch == '-')
	{
		*flags |= FLAG_MINUS;
		return (1);
	}
	else if (ch == '+')
	{
		*flags |= FLAG_PLUS;
		return (1);
	}
	else if (ch == ' ')
	{
		*flags |= FLAG_SPACE;
		return (1);
	}
	else if (ch == '#')
	{
		*flags |= FLAG_OCTOP;
		return (1);
	}
	else if (ch == '0')
	{
		*flags |= FLAG_ZERO;
		return (1);
	}
	return (0);
}

int		get_accuracy(char *body, va_list *ap, int *accuracy)
{
	if (*body == '.')
	{
		if (*(body + 1) == '*')
		{
			*accuracy = va_arg(*ap, int);
			if (*accuracy < 0)
				*accuracy = -1;
			return (1 + 1);
		}
		else if (ft_isdigit(*(body + 1)))
		{
			*accuracy = ft_atoi(body + 1);
			return (get_number_width(*accuracy) + 1);
		}
		else
		{
			*accuracy = 0;
			return (1);
		}
	}
	return (0);
}

char	get_size(char *body, char *size)
{
	if (*body == 'L')
		return (*size = SIZE_L);
	else if (*body == 'l')
	{
		if (*(body + 1) == 'l')
		{
			*size = SIZE_ll;
			return (2);
		}
		else
			*size = SIZE_l;
		return (1);
	}
	else if (*body == 'h')
	{
		if (*(body + 1) == 'h')
		{
			*size = SIZE_hh;
			return (2);
		}
		else
			*size = SIZE_h;
		return (1);
	}
	else if (*body == 'z')
		return (*size = SIZE_z);
	else if (*body == 'j')
		return (*size = SIZE_j);
	return (0);
}
