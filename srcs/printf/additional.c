/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:09:37 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/26 16:35:03 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_specifier(const char ch, const t_formatter *dispatcher)
{
	int i;

	i = 0;
	while (dispatcher[i].type_specifier)
	{
		if (ch == dispatcher[i].type_specifier)
			return (i);
		i++;
	}
	return (-1);
}

void	parse_spec_body(char *body, t_spec *spec)
{
	if (body && *body)
	{
		spec->flags = get_flags(&body);
		spec->width = ft_atoi(body);
		spec->accuracy = get_accuracy(body);
		spec->size = get_size(body);
	}
	else
	{
		spec->flags = 0;
		spec->width = 0;
		spec->accuracy = 0;
		spec->size = 0;
	}
}

char	get_flags(char **body)
{
	char flags;

	flags = 0;
	if (body && *body)
	{
		while (**body)
		{
			if (**body == '-')
				flags |= FLAG_MINUS;
			else if (**body == '+')
				flags |= FLAG_PLUS;
			else if (**body == ' ')
				flags |= FLAG_SPACE;
			else if (**body == '#')
				flags |= FLAG_OCTOP;
			else if (**body == '0')
				flags |= FLAG_ZERO;
			else
				break ;
			(*body)++;
		}
	}
	return (flags);
}

int		get_accuracy(char *body)
{
	char *start;

	if ((start = ft_strchr(body, '.')) && ft_isdigit(*(start + 1)))
		return (ft_atoi(start + 1));
	return (1);
}

char	get_size(char *body)
{
	t_sp_size size;

	size = SIZE_NONE;
	while (*body && size == SIZE_NONE)
	{
		if (body[0] == 'L')
			size = SIZE_L;
		else if (body[0] == 'l')
			size = body[1] == 'l' ? SIZE_ll : SIZE_l;
		else if (body[0] == 'h')
			size = body[1] == 'h' ? SIZE_hh : SIZE_h;
		body++;
	}
	return (size);
}
