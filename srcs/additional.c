/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:09:37 by rschuppe          #+#    #+#             */
/*   Updated: 2019/01/14 17:33:24 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inside.h"

void	parse_spec_body(char *body, va_list *ap, t_spec *spec)
{
	int i;
	int find_star;

	spec->flags = get_flags(&body);

	i = 0;
	find_star = 0;
	while (body[i] && body[i] != '.')
	{
		if (body[i] == '*')
		{
			spec->width = va_arg(*ap, int);
			find_star = 1;
			break ;
		}
		i++;
	}
	if (spec->width < 0)
	{
		spec->width *= -1;
		spec->flags = FLAG_MINUS;
	}
	if (!find_star)
		spec->width = ft_atoi(body);

	spec->accuracy = get_accuracy(body, ap);
	spec->size = get_size(body);
}

int		is_spec_body_char(char ch)
{
	return (ft_isdigit(ch) || ch == ' ' || ch == '-' || ch == '+' || ch == '#'
		|| ch == '.' || ch == '*' || ch == 'l' || ch == 'h' || ch == 'L'
		|| ch == 'z' || ch == 'j');
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

int		get_accuracy(char *body, va_list *ap)
{
	char	*start;

	if (body && (start = ft_strchr(body, '.')))
	{
		if (*(start + 1) == '*')
			return (va_arg(*ap, int));
		return (ft_atoi(start + 1));
	}
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
			else if (body[0] == 'j')
				size = SIZE_j;
			body++;
		}
	}
	return (size);
}
