/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:09:37 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/27 21:48:48 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_spec_body(char *body, t_spec *spec)
{
	spec->flags = get_flags(&body);
	spec->width = ft_atoi(body);
	spec->accuracy = get_accuracy(body);
	spec->size = get_size(body);
}

int		is_spec_body_char(char ch)
{
	return (ft_isdigit(ch) || ch == ' ' || ch == '-' || ch == '+' || ch == '#'
		|| ch == '.' || ch == 'l' || ch == 'h' || ch == 'L' || ch == 'z');
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

	if (body && (start = ft_strchr(body, '.')))
		return (ft_atoi(start + 1));
	return (-1);
}

char	get_size(char *body)
{
	t_sp_size size;

	size = SIZE_NONE;
	if (body)
	{
		while (*body && size == SIZE_NONE)
		{
			if (body[0] == 'L' && body[1] == '\0')
				size = SIZE_L;
			else if (body[0] == 'l')
				size = body[1] == 'l' ? SIZE_ll : SIZE_l;
			else if (body[0] == 'h')
				size = body[1] == 'h' ? SIZE_hh : SIZE_h;
			else if (body[0] == 'z')
				size = SIZE_z;
			body++;
		}
	}
	return (size);
}